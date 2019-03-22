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
	std::cin >> head->data;
	Node* runner = head;
	for (int i = 0; i < 2; i++)
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

void displayLL(Node* head)
{
	Node* runner = head;
	while (runner->next != NULL)
	{
		std::cout << runner->data;
		runner = runner->next;
	}
	std::cout << runner->data;
}

Node* sumLL(Node* head1, Node* head2)
{
	Node* runner1, *runner2, *answerHead;
	runner1 = head1;
	runner2 = head2;
	Node* answer = new Node;
	answer->data = 0;
	answer->next = NULL;
	answerHead = answer;
	int total=0, carry=0;
	while (runner1->next!=NULL || runner2->next!=NULL)
	{
		total = runner1->data + runner2->data;
		answer->data += (total % 10);
		answer->next = new Node;
		carry = total / 10;
		answer->next->data = carry;
		answer->next->next = NULL;
		answer = answer->next;
		runner1 = runner1->next;
		runner2 = runner2->next;
	}
	answer->data += runner1->data + runner2->data;
	return answerHead;
}

Node* recursiveSum(Node* head1,Node* head2)
{
	if (head1 == NULL && head2 == NULL)
	{
		Node* answer = new Node;
		answer->next = NULL;
		answer->data = 0;
		return answer;
	}
	Node* answer;
	answer = recursiveSum(head1->next,head2->next);
	answer->data += (head1->data + head2->data) % 10;
	Node* returnAnswer = new Node;
	returnAnswer->next = answer;
	returnAnswer->data = (head1->data + head2->data) / 10;
	return returnAnswer;
}

int main()
{
	Node* head1,* head2, *head3;
	std::cout << "Enter the first number:\n";
	head1 = createLL();
	std::cout << "Enter the second number:\n";
	head2 = createLL();

	displayLL(head1);
	std::cout << "\n";
	displayLL(head2);

	std::cout << "\nAddition:\n";
	//head3 = sumLL(head1,head2);
	//displayLL(head3);
	head3 = recursiveSum(head1,head2);
	//head3->next->data += head3->data;
	displayLL(head3);
}