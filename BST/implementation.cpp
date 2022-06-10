
/* for every node n=> everything in n's left subtree is less than n's data;
   for  everything in n's right subtree is greater than n's data;
   example->

*/
// binary Tree have not more than two child
// you can have 0,1,2 children but nore than 2
// be focused on the binary trees because most question are asked in company
// structure
/*
 chuki iske 2 hi bache ho skte ha to hm two pointer use kre ge
 |data|address of right child    | address of left child     |
 |    |      /_\ -right subtee   |        /_\   left subtree |

 binarTreenode{
     T data;
     binaryTreenode *left;
     binaryTreenode *right;

 }

*/
#include <bits/stdc++.h>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
template <typename t>
class Node{
    public:
    t data;
    Node *next;
    Node(t data)
    {
        this->data = data;
        this->next = NULL;
    }

};
// destructor

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << "L:" << root->left->data << " ";
    }
    if (root->right != NULL)
    {

        cout << "R:" << root->right->data << " ";
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}
// take input level wise
/* how do i do it so level wise input lena ha so we will use queue;
 */
BinaryTreeNode<int> *takeInputlevelwise()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "enter left child of" << front->data << endl;
        int leftchilddata;
        cin >> leftchilddata;
        if (leftchilddata != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftchilddata);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "enter right child of" << front->data << endl;
        int rightchilddata;
        cin >> rightchilddata;
        if (rightchilddata != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightchilddata);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
// void printlevelwise(BinaryTreeNode<int>* root)
// {

//     if (root == NULL)
//     {
//         cout<<"-1"<<" ";

//         return;
//     }
//     cout<<endl;
//     cout<<root->data<<":";
//     if (root->left != NULL)
//     {
//     cout<<"L"<<root->left->data<<" ";
//     }
//     if (root->right != NULL)
//     {
//     cout<<"R"<<root->right->data<<" ";
//     }
//     cout<<endl;
//     printlevelwise(root->left);
//     printlevelwise(root->right);
// }
// function to find no. of nodes in a binary trees;
int findnodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = findnodes(root->left);
    int right = findnodes(root->right);
    return left + right + 1;
}
bool ispresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }

    return (ispresent(root->right, x) || ispresent(root->left, x));
}
// find the height of the binary tree;
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    // if(root->left==NULL||root->right==NULL)
    // {
    //     return 0;
    // }
    int left = height(root->left);
    int right = height(root->right);
    if (right > left)
    {
        return right + 1;
    }
    else
        return left + 1;
}
void mirrorTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    mirrorTree(root->left);
    mirrorTree(root->right);
    swap(root->left, root->right);
}
void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);

    postorder(root->right);
    cout << root->data << " ";
}
// construct a tree from preorder and in order
// given preorder and inorder;
/*
step 1=figure out the root ;
step 2=figure out the left

INORDER=> LEFT+ROOT+RIGHT;
PREORDER=> ROOT+LEFT+RIGHT;
STEP 1 FIND ROOT
STEP 2 FIND LEFT
STEP 3 FIND RIGHT
STEP 4 CALL RECURSION ON LEFT AND RIGHT

in=>inorder
pre=>preorder
ins=>inorder start;
pres>preorder start;
inE=>inorder end;
preE>preorder end;

 */

BinaryTreeNode<int> *buildtreehelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        // asuming same size of in order and preorder
        return NULL;
    }
    int rootData = pre[preS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    int rInS = rootIndex + 1;
    int rInE = inE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildtreehelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildtreehelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}
BinaryTreeNode<int> *buildtree(int *in, int *pre, int size)
{
    return buildtreehelper(in, pre, 0, size - 1, 0, size - 1);
}
// DIAMETER OF A BINARY tREE;
// MAXM DISTANCE BETWEEN ANY  TWO NODES;
pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    // base Case
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;
    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}
bool searchInBst(BinaryTreeNode<int> *root, int n)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n)
    {
        return true;
    }
    if (root->data > n)
    {
        return searchInBst(root->left, n);
    }
    if (root->data < n)
    {
        return searchInBst(root->right, n);
    }
}
// print element in range k1 and k2 in BST;
void printRangeInBst(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }

    if (k1 < root->data)
    {

        printRangeInBst(root->left, k1, k2);
    }
    if (k1 <= root->data && k2 >= root->data)
        cout << root->data << " ";
    printRangeInBst(root->right, k1, k2);
}
// check bst or not;
int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
bool CheckBstornot(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    int maxleft = maximum(root->left);
    int minRight = minimum(root->right);
    bool output = (maxleft < root->data) && (minRight >= root->data) && CheckBstornot(root->left) && CheckBstornot(root->right);
    return output;
}
// optimised checking of bst;
class isbstreturn
{
public:
    bool isbst;
    int minimum;
    int maximum;

};

isbstreturn isBST2(BinaryTreeNode<int>* root)
{
    if (root == NULL)
    {
        isbstreturn output;
        output.isbst = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    isbstreturn leftoutput = isBST2(root->left);
    isbstreturn rightoutput = isBST2(root->right);
    int minimum = min(root->data, min(leftoutput.minimum, rightoutput.minimum));
    int maximum = max(root->data, max(leftoutput.maximum, rightoutput.maximum));
    bool isbstfinal = (root->data > leftoutput.maximum) && (root->data <= rightoutput.minimum) && leftoutput.isbst && rightoutput.isbst;
    isbstreturn output;
    output.minimum = minimum;
    output.maximum = maximum;
    output.isbst = isbstfinal;
}
//find out the bst using sorted array
//concept middle is root and left pr call and right pr call;
BinaryTreeNode<int>*makebst(int arr[],int start,int end)
{
     if (start > end)
       return NULL;

     int mid = (start + end)/2;   
     BinaryTreeNode<int>*root=new BinaryTreeNode<int>(arr[mid]);

     BinaryTreeNode<int>*lefttree= makebst(arr,start,mid-1);
     BinaryTreeNode<int>*righttree=makebst(arr,mid+1,end);

    root->left=lefttree;
    root->right=righttree;

    return root;

}
//bst to sorted linked list
pair<Node<int> *,Node<int>*>returnlinkedlist(BinaryTreeNode<int>* root){
    if(root==NULL)
    {
        pair<Node<int>*,Node<int>*>p;
         return p;
    }
    pair< Node<int> *,Node<int>*>lfthead= returnlinkedlist(root->left);
    pair< Node<int> *,Node<int>*>rgthead=returnlinkedlist(root->right);
    Node<int>* temp=new Node<int>(root->data);
    if(lfthead.first==NULL&&lfthead.second==NULL )
    {
       pair< Node<int> *,Node<int>*> pan=make_pair(temp,temp);
       return pan;

    }else{
        lfthead.second->next=temp;
        temp->next=rgthead.first;

    }
      pair< Node<int> *,Node<int>*> pans;
      pans.first=lfthead.first;
      pans.second=rgthead.second;
      return pans;
}
Node<int>* constructBST(BinaryTreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    pair <Node<int>*,Node<int>*> p;
    
    p=returnlinkedlist(root);
    
    return p.first;
    
}
//reverse path between  node we are looking for;
vector<int>* returnpath(BinaryTreeNode<int>* root,int data)
{
   if(root==NULL)
   {
       return NULL;
   }
   if(root->data==data)
   {
       vector<int>* output=new vector<int>();
       output->push_back(root->data);
       return output;
   }
    vector<int>* leftop=returnpath(root->left,data);
    if(leftop!=NULL)
    {
        leftop->push_back(root->data);
        return leftop;
    }
    vector<int>* rightop=returnpath(root->right,data);
    if(rightop!=NULL)
    {
        rightop->push_back(root->data);
        return rightop;
    }else{
        return NULL;
    }
}


int main()
{ /*
     BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
     BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
     BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
     root->left = node1;
     root->right = node2;
     */
    BinaryTreeNode<int> *root = takeInputlevelwise();

    // cout<<"NO. OF NODES="<<findnodes(root)<<endl;
    //  if(ispresent(root,10)==1)
    //  cout<<"True";
    //  else cout<<"false";
    // cout<<"height"<<height(root);

    // mirrorTree(root);
    // printTree(root);
    // inorder(root);
    // cout<<" "<<endl;
    // postorder(root);
    // delete (root);
    //----------------------------------------
    //    int in[]={4,2,5,1,8,6,9,3,7};
    //    int pre[]={1,2,4,5,3,6,8,9,7};
    // BinaryTreeNode<int>*root =buildtree(in,pre,9);
    //  printTree(root);
    // pair<int,int>p=heightDiameter(root);
    // cout<<"HEIGHT::"<<p.first<<endl;
    // cout<<"DIAMETER::"<<p.second<<endl;
    //   int n;
    //   cin>>n;
    //   int k=searchInBst(root,n);
    //   if(k==0)
    //   {
    //       cout<<"false";

    //   }else cout<<"true";
    //  int k1,k2;
    //  cin>>k1>>k2;
    //  printRangeInBst(root,k1,k2);
   // cout << CheckBstornot(root);
    // int arr[]={1,2,3,4,5,6,7};
   //BinaryTreeNode<int>*root= makebst(arr,0,6);
   //cout<<root->left->data;
  // printTree(root);
  //----------------------------------------------------------------------------
    // Node<int>* head = constructBST(root);
    // while(head != NULL) {
    //     cout << head -> data << " ";
    //     head = head -> next;
    // }
    //-----------------------------------------------------------------------------
    //-----------------------------------------------------------------------------
    ///================path of nodes--------------------------------------------------
    vector <int>*output=returnpath(root,8);
    for(int i=0;i<output->size();i++)
    {
        cout<<output->at(i)<<endl;
    }
   delete root;

   //return 0;
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
}
// PREORDER=>node->fir left-> fir right;
/*
PREORDER ROOT KEHTI HA PHELE HMKO PRINT KRO FIR CHILDREN KI BARI AATI HA
POST ORDER ME ROOT KEHTI HA PHELE CHILDREN KO PRINT KRO FIR ROOT KO KRNA
post order me :phele left children-> right children fir node

IN BINARY TREEs
CONCEPT :-INORDER MEANS LEFT NODE RIGHT;
postorder means :-left right node;
preorder means=root left right




*/