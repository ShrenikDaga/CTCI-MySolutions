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
	std::cin >> head->data;
	Node* runner = head;
	for (int i = 1; i < 5; i++)
	{
		while (runner->next != NULL)
		{
			runner = runner->next;
		}
		runner->next = new Node;
		runner = runner->next;
		std::cin >> runner->data;
		runner->next = NULL;
	}
	return head;
}

void removeDuplicates(Node* head)
{
	std::vector<int> dataVector;
	Node* runner = head;

	dataVector.push_back(runner->data);

	if (runner->next->next == NULL)
	{
		if (runner->data == runner->next->data)
		{
			runner->next = NULL;
		}
		return;
	}

	while (runner->next != NULL)
	{
		if (std::find(dataVector.begin(), dataVector.end(), runner->next->data) != dataVector.end())
		{
			runner->next = runner->next->next;
		}
		else
		{
			dataVector.push_back(runner->next->data);
			runner = runner->next;
		}
	}
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

int main()
{
	Node *head;
	Node *runner;

	std::cout << "Enter the data for 6 LL:\n";
	head = createLL();

	displayLL(head);
	std::cout << "\nRemoved duplicates:\n";
	removeDuplicates(head);
	displayLL(head);
	
	return 0;

}