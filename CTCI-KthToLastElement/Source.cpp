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
	for (int i = 1; i < 16; i++)
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
	while (runner->next != NULL)
	{
		std::cout << runner->data << ",";
		runner = runner->next;
	}
	std::cout << runner->data;
}

int kthElement(Node* head,int k)
{
	if (head == NULL)
		return 0;
	int i = kthElement(head->next,k) + 1;
	if (i == k)
	{
		std::cout << k << "th last element is: " << head->data;
	}
	else
		return i;
	
}

int main()
{
	Node *head;
	Node *runner;
	head = createLL();
	displayLL(head);
	int k;
	std::cout << "\nEnter k:\n";
	std::cin >> k;
	if (k > 0 && k < 17)
		kthElement(head, k);
	else
		std::cout << "\nInvalid input.SOrry!\n";

	return 0;
}