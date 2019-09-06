///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct Node
{
	Node* next;
	int data;
};

Node* createLL()
{
	Node* head = new Node;
	head->next = NULL;
	head->data = 0;
	/*Node* runner = head;
	for (int i = 1; i < 6; i++)
	{
		while (runner->next != NULL)
		{
			runner = runner->next;
		}
		runner->next = new Node;
		runner = runner->next;
		runner->data = i;
		runner->next = NULL;
	}*/
	return head;
}

void displayLL(Node* head)
{
	Node* runner = head;
	std::cout << std::endl;
	
	while (runner->next != NULL)
	{
		std::cout << runner->data << ",";
		runner = runner->next;
	}
	std::cout << runner->data;
}

Node* RemoveNthNode(Node* head,int n)
{
	if (head == NULL || n == 0)
		return NULL;

	

	Node* dummyHead = new Node;
	dummyHead->data = -1;
	dummyHead->next = head;

	Node* left, *right;
	left = dummyHead;
	right = dummyHead;

	while (n > 0)
	{
		right = right->next;
		n--;
	}

	while (right->next != NULL)
	{
		left = left->next;
		right = right->next;
	}
	
	Node* temp = left->next;
	left->next = left->next->next;
	delete temp;
	return head;
}


int main()
{
	Node* head = createLL();
	displayLL(head);
	head = RemoveNthNode(head, 1);
	displayLL(head);
	return 0;
}