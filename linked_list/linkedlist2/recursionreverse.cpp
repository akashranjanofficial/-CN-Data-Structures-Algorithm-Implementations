#include <bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	node *next;

	node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};
node *takeinput()
{
	int data;
	cin >> data;
	node *head = NULL;
	node *tail = NULL;
	while (data != -1)
	{
		node *newnode = new node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = head;
		}
		else
		{
			// node *current = head;
			// while (current->next != NULL)
			// {
			//     current = current->next;
			//             }
			// current->next = newnode;
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}
void print(node *head)
{
	node *curr = head;
	// we are making a curr to travell to linked list;
	while (curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
}
node *reverselinkedlist(node *head)
{
	//base case
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	node *smallcalulations = reverselinkedlist(head->next);
	node *temp = smallcalulations;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = head;
	head->next = NULL;
	return smallcalulations;
}

int main()
{
	node *head = takeinput();
	//print(head);
	// node *head2 = takeinput();
	node *finalhead = reverselinkedlist(head);
	print(finalhead);

	return 0;
}