///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Node
{
	std::string name;
	std::string animal;
	Node* next;
};

Node* Enqueue(Node* dummyTail)
{
	std::string animalKind, animalName;
	Node* tail = new Node;
	tail->next = NULL;
	std::cout<<"Cat or dog?\n";
	std::cin >> animalKind;
	std::cout << "Please enter the " << animalKind << "'s name:\n";
	std::cin >> animalName;
	tail->animal = animalKind;
	tail->name = animalName;
	if (dummyTail!=NULL)
	{
		dummyTail->next = tail;
	}

	return tail;
}

void DisplayQueue(Node* head)
{
	if (head == NULL)
		return;
	DisplayQueue(head->next);
	std::cout<<head->name << " the " << head->animal<<"\n";
	return;
}

Node* Dequeue(std::string choice, Node* head)
{
	Node* temp=NULL;
	Node* localHead=head;

	if (choice == "Any")
	{
		temp = head->next;
		/*std::cout << "Bye-bye " << head->name << " the " << head->animal << "\n";
		delete head;
		return temp;*/
	}

	if (choice == "Cat" || choice == "Dog")
	{
		if (head->animal == choice)
		{
			temp = head->next;
			/*std::cout << "Bye-bye " << head->name << " the " << head->animal << "\n";
			delete head;
			return temp;*/
		}
		if (head->animal != choice)
		{
			while (head->next->animal != choice)
				head = head->next;
			temp = head->next;
			head->next = head->next->next;
			head = temp;
			temp = localHead;
			/*std::cout << "Bye-bye " << head->name << " the " << head->animal << "\n";
			delete head;
			return temp*/;
		}
		
	}
	std::cout << "Bye-bye " << head->name << " the " << head->animal << "\n";
	delete head;
	if (temp == NULL)
		return localHead;
	return temp;
}

int main()
{
	Node* head = NULL;
	Node* tail = NULL;

	int choice;

	std::cout << "Hello.\nEnter your choice:\n";
	std::cout << "1. Enqueue.\n";
	std::cout << "2. DequeueAny.\n";
	std::cout << "3. DequeueCat.\n";
	std::cout << "4. DequeueDog\n";
	std::cout << "5. Display\n";
	std::cout << "6. Exit.\n";
	std::cin >> choice;

	while (choice != 6)
	{
		switch (choice)
		{
		case 1:
			tail = Enqueue(tail);
			if (head == NULL || tail == NULL)
				head = tail;
			break;
		case 2:
			head = Dequeue("Any",head);
			break;
		case 3:
			head = Dequeue("Cat", head);
			break;
		case 4:
			head = Dequeue("Dog", head);
			break;
		case 5:
			DisplayQueue(head);
			break;
		case 6:
			break;
		default:
			std::cout << "Try Again.\n";
		}
		std::cout << "Hello.\nEnter your choice:\n";
		std::cout << "1. Enqueue.\n";
		std::cout << "2. DequeueAny.\n";
		std::cout << "3. DequeueCat.\n";
		std::cout << "4. DequeueDog\n";
		std::cout << "5. Display\n";
		std::cout << "6. Exit.\n";
		std::cin >> choice;
	}
	return 0;
}