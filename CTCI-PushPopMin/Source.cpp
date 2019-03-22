#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct Node
{
	Node* next;
	int data;
};

int min=NULL;

Node* Push(Node* head)
{
	int value;
	std::cout << "\nEnter value:\n";
	std::cin >> value;

	Node* top = new Node;
	top->data = value;

	if (head == NULL)
	{
		top->next = NULL;
		min = top->data;
	}
	else
	{
		top->next = head;
		min >= top->data ? min = top->data : min=min;
	}
	return top;
}

void Display(Node* head)
{
	if (head==NULL)
	{
		std::cout << "No data";
		return;
	}
	while (head!=NULL)
	{
		std::cout << head->data<<"\n";
		head = head->next;
	}
}

Node* Pop(Node* head)
{
	if (head->next == NULL)
	{
		delete head;
		return NULL;
	}
	else
	{
		head = head->next;
		return head;
		//return head->next;
	}
}

int main()
{
	Node* head=NULL;
	std::cout << "Hello world.\nEnter your choice:\n";
	std::cout << "1. Push.\n";
	std::cout << "2. Pop.\n";
	std::cout << "3. Min.\n";
	std::cout << "4. Display\n";
	std::cout << "5. Exit.\n";
	int choice;
	std::cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
		case 1:
			std::cout << "Pushing:\n";
			head = Push(head);
			break;
		case 2:
			std::cout << "Popping:\n";
			head = Pop(head);
			break;
		case 3:
			std::cout << "Min: "<<min<<"\n";
			break;
		case 4:
			std::cout << "Displaying:\n";
			Display(head);
			break;
		case 5:
			break;
		default:
			std::cout << "Try Again.\n";
		}
		std::cout << "Hello world.\nEnter your choice:\n";
		std::cout << "1. Push.\n";
		std::cout << "2. Pop.\n";
		std::cout << "3. Min.\n";
		std::cout << "4. Display\n";
		std::cout << "5. Exit.\nChoice:";
		std::cin >> choice;
	}
	

	return 0;
}