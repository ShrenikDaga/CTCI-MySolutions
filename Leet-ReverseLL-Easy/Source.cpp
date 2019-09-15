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
	Node* runner = head;
	for (int i = 1; i < 10; i++)
	{
		while (runner->next != NULL)
		{
			runner = runner->next;
		}
		runner->next = new Node;
		runner = runner->next;
		runner->data = i;
		runner->next = NULL;
	}
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

Node* reverseLL(Node* head) 
{
	Node* left=NULL;
	Node* current = head;

	while (current != NULL)
	{
		Node* temp = current->next;
		current->next = left;
		left = current;
		current = temp;
	}
	return left;
}

Node* reverseLLRec(Node* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	Node* temp = reverseLLRec(head->next);
	head->next->next = head;
	head->next = NULL;
	return temp;
}

int main()
{
	Node* head = createLL();
	displayLL(head);
	//displayLL(reverseLL(head));
	displayLL(reverseLLRec(head));
	return 0;
}