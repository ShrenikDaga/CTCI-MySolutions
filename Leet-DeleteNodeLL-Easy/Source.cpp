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
public:
	Node* next;
	int data;
	//Node(int x) : data(x), next(NULL) {}
};

Node* CreateLL()
{
	Node* head = new Node;
	head->data = 75;
	head->next = NULL;
	Node* runner = head;

	for (int i = 0;i < 5; i++)
	{
		/*while (runner->next != NULL)
		{
			runner = runner->next;
		}*/

		runner->next = new Node;
		runner = runner->next;
		runner->data = i * 5;
		runner->next = NULL;
	}
	return head;
}

void DisplayLL(Node* head) 
{
	Node* runner = head;
	std::cout << std::endl;
	while (runner->next != NULL)
	{
		std::cout << runner->data << ", ";
		runner = runner->next;
	}
	std::cout << runner->data;
}

void DeleteNode(Node* node)
{
	if (node == NULL)
		return;

	Node* temp = node->next;

	node->data = temp->data;
	node->next = temp->next;
	delete temp;
}

int main()
{
	Node* head = CreateLL();
	DisplayLL(head);
	DeleteNode(head->next->next);
	DisplayLL(head);
	return 0;
}