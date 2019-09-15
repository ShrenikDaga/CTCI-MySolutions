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

void createCycle(Node*& head)
{
	Node* runner = head;

	for (int i = 0; i < 5; i++)
	{
		runner = runner->next;
	}

	Node* tail = head;
	
	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	tail->next = runner;

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

bool findIfCycle(Node*& head)
{
	if (head == NULL || head->next==NULL)
		return false;

	Node* slow = head, * fast = head->next;

	while (slow != fast)
	{
		if (fast == NULL || fast->next == NULL)
			return false;
		slow = slow->next;
		fast = fast->next->next;
	}
	return true;
}

int main()
{
	Node* head = createLL();
	/*Do not call displayLL if you uncomment createCycle(head). It wont stop printing values.
	  One of them should be commented out at all times.
	*/

	//createCycle(head);
	displayLL(head);

	std::cout << findIfCycle(head);

	return 0;
}
