// wumpus.cpp:
//   Implementation of game "Hunt the Wumpus."  Read in a predefined playing
// field (2D maze, with walls as obstacles), place player character & Wumpus
// within it, and keep alternating inputting user moves & moving Wumpus until
// player "catches" Wumpus (moves into same square).
//
// This pgm is optimized for display on a 24 line scrolling display (a la
// NT dos window)
//
// CS302 program 5, Fall 1997, M.M.
#include <bits/stdc++.h>
// wumpus.cpp:
//   Implementation of game "Hunt the Wumpus."  Read in a predefined playing
// field (2D maze, with walls as obstacles), place player character & Wumpus
// within it, and keep alternating inputting user moves & moving Wumpus until
// player "catches" Wumpus (moves into same square).
//
// This pgm is optimized for display on a 24 line scrolling display (a la
// NT dos window)
//
// CS302 program 5, Fall 1997, M.M.

#include <string>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
  // under Vis C++/NT       

#include <iostream>
#include <fstream>
using namespace std;
const string fName = "P:\\course\\cs302\\public\\html\\C++\\wumpus\\maze.1";

#else
  // under g++/Un*X

// #include "bool.h"
#include <iostream.h>
#include <fstream.h>
const string fName("/u/c/s/cs302/public/html/C++/wumpus/maze.1");
// const string fName = "/u/m/a/manville/public/html/302/programs/program5/maze.1";

#endif

// maze input/display chars
const char WALL   = 'X';
const char OPEN   = '.';
const char PLAYER = '*';
const char WUMPUS = '#';

// maze dimensions, maze, file storing maze
const int ROWS = 13;
const int COLS = 24;
char maze [ROWS] [COLS];

// prototypes
bool LoadMaze(string fileName, int& pRow, int& pCol, int& wRow, int& wCol);
     /* Read the maze from a file & initialize player & wumpus position, if found */
void PrintMaze(int playerRow, int playerCol, int wumpusRow, int wumpusCol);
     /* Print the maze (and player/wumpus position within it */
bool GetPlayerMove(int& playRow, int& playCol, int wumpRow, int wumpCol);
     /* Get the player's action */
void GetWumpusMove(int& wumpRow, int& wumpCol, int playRow, int playCol);
     /* Decide The Wumpus' action */
bool IsLegalMove(int row, int col);  
     /* Can player or wumpus move to this position? */

// **************************************************************************
int main () {

  int pRow, pCol;  // player's current row & column in maze array
  int wRow, wCol;  // wumpus'  current row & column in maze array
  int startpRow, startpCol, startwRow, startwCol;
  bool newGame = true;

  if (!LoadMaze(fName, startpRow, startpCol, startwRow, startwCol)) {
    cerr << "Error in loading maze file " << fName << " for a " 
         << ROWS << " by " << COLS << " maze -- aborting.\n\n";
    return 1;
  }

  // loop until we return out of program
  while (1) {

    if (newGame) {
      newGame = false;
      pRow = startpRow;
      pCol = startpCol;
      wRow = startwRow;
      wCol = startwCol;
    }

    // get player move, and check if s/he has quit
    if (!GetPlayerMove(pRow, pCol, wRow, wCol)) {
      cout << "\n\nYou hear the sound of Wumpus laughter (not a pretty "
           << "sound!) as you scurry away\nwith your tail between "
           << "your legs.\n\n\n                      Wumpi Rule!!!\n";
      return 0;
    }

    // check for victory
    if (pRow == wRow && pCol == wCol) {
      
      char input;
      PrintMaze(pRow, pCol, wRow, wCol);
      cout << "\n\nYou've slain the poor, helpless Wumpus!  "
           << "I hope you're proud of yourself!\n";
      
      // find out if we're playing again
      do {
        cout << "Play again? (y or n): ";
        cin >> input;
        input = tolower(input);
      } while (input != 'y' && input != 'n');
      
      if (input == 'y') 
        newGame = true;
      else {
        cout << "Chicken!\n\n";
        return 0;
      }
        
    }  // if (pRow == wRow && pCol == wCol)

    // Wumpus still alive ... let her move
    GetWumpusMove(wRow, wCol, pRow, pCol);
    
  }  // while (1)

  return 0;  // never reached; make compiler happy
}


// **************************************************************************
// LoadMaze:
//   Load maze stored in file fileName into global char array maze.  Return
// true if successfully loaded.
bool LoadMaze(string fileName, int& pRow, int& pCol, int& wRow, int& wCol) {

  ifstream file (fileName.c_str());
  char inChar;
  const int junkSize = 1024;
  char junk[junkSize];

  if (!file) {
    return false;
  }

  // read file contents into global maze 2d char array.  Stop reading &
  // return false if anything unexpected is encountered.
  for (int row=0; row < ROWS; row++) {
    for (int col=0; col < COLS; col++) {

      /* input each char in row & analyze */
      file >> inChar;
      switch (inChar) {
        case PLAYER:  /* player start */
          pRow = row;
          pCol = col;
          maze [row] [col] = '.';  // by def this is an empty space
          break;
        case WUMPUS:  /* wumpus start */
          wRow = row;
          wCol = col;
          maze [row] [col] = '.';  // by def this is an empty space
          break;
        case OPEN:  /* empty space or wall */
        case WALL: 
          maze [row] [col] = inChar;  // by def this is an empty space
          break;
        default:   /* invalid specification character */
          return false;
      }  // switch(inChar)

    }  // for (int col=0 ...

    // if there is anything past col COLS, discard
    file.getline(junk, junkSize);

  }  // for (int row=0 ...

  // also ignore anything past row ROWS
  return true;

}  // LoadMaze()


// **************************************************************************
// PrintMaze:
//   Print board for current game state
void PrintMaze(int playerRow, int playerCol, int wumpusRow, int wumpusCol) {

  for (int row=0; row < ROWS; row++) {
    for (int col=0; col < COLS; col++) {

      /* print player first, in case he's caught wumpus */
      if (row == playerRow && col == playerCol)
        cout << PLAYER;
      else if (row == wumpusRow && col == wumpusCol)
        cout << WUMPUS;
      else
        cout << maze [row] [col];

    }  // for (int col=0 ...

    cout << endl;

  }  // for (int row=0 ...

  // print extra newlines to make it pretty under NT
  for (int i=0; i < (22 - ROWS); i++) {
    cout << endl;
  }

}  // PrintMaze()


// **************************************************************************
// GetPlayerMove:
//   Display current board, input next move for player, verify it is legal 
// (and reinput if it is not), update player position, and return true -- or,
// if q (quit) entered, return false.
bool GetPlayerMove(int& playRow, int& playCol, int wumpRow, int wumpCol) {

  char input;
  bool printErrMsg = false; // true 2nd+ time through loop

  // loop printing board & looking for input until we get something legal 
  // (and return, escaping otherwise endless loop)

  while (1) {

    PrintMaze(playRow, playCol, wumpRow, wumpCol);

    if (printErrMsg)
      cout << "\n" << input << " is not a valid move.\n"; 
    else
      cout << "\n\n";

    cout << "Please input your move, oh great Wumpus Killer! "
       << "(using numeric keypad): ";
    cin >> input;
    
    switch (input) {
      case '1':  /* down & left */
        if (IsLegalMove(playRow+1, playCol-1)) {
          playRow++;
          playCol--;
          return true;
        }
        break;
      case '2':  /* down */
        if (IsLegalMove(playRow+1, playCol)) {
          playRow++;
          return true;
        }
        break;
      case '3':  /* down & right */
        if (IsLegalMove(playRow+1, playCol+1)) {
          playRow++;
          playCol++;
          return true;
        }
        break;
      case '4':  /* left */
        if (IsLegalMove(playRow, playCol-1)) {
          playCol--;
          return true;
        }
        break;
      case '6':  /* right */
        if (IsLegalMove(playRow, playCol+1)) {
          playCol++;
          return true;
        }
        break;
      case '7':  /* up & left */
        if (IsLegalMove(playRow-1, playCol-1)) {
          playRow--;
          playCol--;
          return true;
        }
        break;
      case '8':  /* up */
        if (IsLegalMove(playRow-1, playCol)) {
          playRow--;
          return true;
        }
        break;
      case '9':  /* up & right */
        if (IsLegalMove(playRow-1, playCol+1)) {
          playRow--;
          playCol++;
          return true;
        }
        break;
      case 'q':  /* quit the game */
        return false;
        break;
    }  // switch(input)
    printErrMsg = true;
    
  }  // while (1)

  return true;  // never reached, put here to make compiler happy

}  // GetPlayerMove()

// **************************************************************************
// IsLegalMove:
//   Is the indicated location a valid place to move to?  (it is on the board
// & not a wall)
bool IsLegalMove(int row, int col) {
        
  // note the use of short circuit below ...
  if (row<0 || row>=ROWS || col<0 || col>=COLS || maze [row][col] == WALL)
    return false;
  else
    return true;

}  // IsLegalMove()


// **************************************************************************
// GetWumpusMove:
//   Determine the wumpus' next move.  We'll do a random selection from the
// possibilities (well, sort of random ...)
void GetWumpusMove(int& wumpRow, int& wumpCol, int playRow, int playCol) {

   // see book, p. 302-3
  srand((unsigned int) time(0));
  int firstTry = rand() % 8; 

  for (int i=0; i < 8; i++ ) {
    // try each of four directions in arbitrary order, starting from random one
    // note reliance on short-circuiting for ifs below ...
    switch ( (firstTry+i) % 8 ) {
      case 0:  /* try north */
        if (IsLegalMove(wumpRow+1, wumpCol) && !(wumpRow+1==playRow && wumpCol==playCol)) {
          wumpRow++;
          return;
        }
        break;
      case 1:  /* try south */
        if (IsLegalMove(wumpRow-1, wumpCol) && !(wumpRow-1==playRow && wumpCol==playCol) ) {
          wumpRow--;
          return;
        }
        break;
      case 2:  /* try east */
        if (IsLegalMove(wumpRow, wumpCol+1) && !(wumpRow==playRow && wumpCol+1==playCol)) {
          wumpCol++;
          return;
        }
        break;
      case 3:  /* try west */
        if (IsLegalMove(wumpRow, wumpCol-1) && !(wumpRow==playRow && wumpCol-1==playCol)) {
          wumpCol--;
          return;
        }
        break;
      case 4:  
        if (IsLegalMove(wumpRow-1, wumpCol-1) && !(wumpRow-1==playRow && wumpCol-1==playCol)) {
          wumpRow--;
          wumpCol--;
          return;
        }
        break;
      case 5:  
        if (IsLegalMove(wumpRow-1, wumpCol+1) && !(wumpRow-1==playRow && wumpCol+1==playCol)) {
          wumpRow--;
          wumpCol++;
          return;
        }
        break;
      case 6:  
        if (IsLegalMove(wumpRow+1, wumpCol-1) && !(wumpRow+1==playRow && wumpCol-1==playCol)) {
          wumpRow++;
          wumpCol--;
          return;
        }
        break;
      case 7:  
        if (IsLegalMove(wumpRow+1, wumpCol+1) && !(wumpRow+1==playRow && wumpCol+1==playCol)) {
          wumpRow++;
          wumpCol++;
          return;
        }
        break;
    }  // switch()
  }  // for

  // if we've gotten this far we are surrounded (and most likely doomed, if the
  // player has any brain capacity whatsoever).  Return without moving.
  return;

}  // GetWumpusMove()