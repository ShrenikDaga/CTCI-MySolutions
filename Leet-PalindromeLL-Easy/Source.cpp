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
		runner->data = std::abs(i-5);
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

bool palindromeHelper(Node* head, Node* &current)
{
	if (!head) return true;
	if (!palindromeHelper(head->next, current)) return false;
	if (current->data != head->data)return false;
	else { current = current->next; return true; }
}

bool isPalindrome(Node* head)
{
	Node* current = head;
	return palindromeHelper(head,current);
}



int main()
{
	Node* head = createLL();
	Node* temp = head;
	head = head->next;
	delete temp;
	displayLL(head);
	std::cout << isPalindrome(head) << std::endl;
	return 0;
}