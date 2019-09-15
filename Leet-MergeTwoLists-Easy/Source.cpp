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

Node* createLL(int x)
{
	Node* head = new Node;
	head->next = NULL;
	head->data = x;
	Node* runner = head;
	for (int i = 1; i < 10; i++)
	{
		while (runner->next != NULL)
		{
			runner = runner->next;
		}
		runner->next = new Node;
		runner = runner->next;
		runner->data = ++(++x);
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

Node* mergeTwoSortedLists(Node* head1,Node* head2)
{
	if (!head1 && !head2)
		return NULL;

	if (!head1)
		return head2;
	if (!head2)
		return head1;

	Node* newHead;

	if (head1->data > head2->data)
	{
		newHead = head2;
		head2 = head2->next;
	}
	else
	{
		newHead = head1;
		head1 = head1->next;
	}

	Node* returnHead = newHead;

	while (head1 && head2)
	{
		if (head1->data < head2->data)
		{
			newHead->next = head1;
			head1 = head1->next;
		}
		else
		{
			newHead->next = head2;
			head2 = head2->next;
		}
		newHead->next->next = NULL;
		newHead = newHead->next;
	}

	if (head1)
	{
		newHead->next = head1;
	}
	else if (head2)
	{
		newHead->next = head2;
	}
	return returnHead;
}

//Node* mergeTwoListsComp(Node* l1, Node* l2)
//{
//	if (!l1 || l2 && l1->data > l2->data)
//		std::swap(l1,l2);
//	if (l1)
//		l1->next = mergeTwoListsComp(l1->next,l2);
//	return l1;
//}

Node* mergeTwoListsRec(Node* l1, Node* l2)
{
	if (!l1 && !l2) return NULL;
	if (!l1 || !l2) return !l1 ? l2 : l1;
	Node* temp = l1->data < l2->data ? l1 : l2;
	temp->next = mergeTwoListsRec(l1->data < l2->data ? l1->next : l1, l2->data < l1->data ? l2->next : l2);
	return temp;
}

int main()
{
	Node* head1, * head2;

	head1 = createLL(1);
	displayLL(head1);
	head2 = createLL(2);
	displayLL(head2);

	//Node* newhead = mergeTwoSortedLists(head1,head2);
	Node* newhead = mergeTwoListsRec(head1,head2);
	displayLL(newhead);

	return 0;
}