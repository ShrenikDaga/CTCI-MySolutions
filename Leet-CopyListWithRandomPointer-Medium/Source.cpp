///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>

class Node 
{
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) 
	{
		val = _val;
		next = _next;
		random = _random;
	}
};

Node* copyRandomList(Node* head) 
{
	Node* runner = head;

	if (runner == nullptr)
		return nullptr;

	Node returnHead(0, nullptr, nullptr);

	Node* temp, * prev;

	/*
	First create a new node for each node in the original list and assign it next to the original one
	*/
	while (runner)
	{
		temp = new Node(runner->val, nullptr, nullptr);
		temp->next = runner->next;
		runner->next = temp;
		runner = temp->next;
	}

	runner = head;

	/*
	Now assign each original node's random to its corresponding new node
	*/
	while (runner)
	{
		if (runner->random)
			runner->next->random = runner->random->next;
		runner = runner->next->next;
	}

	/*
	Seperate the two lists again and return the new one
	*/
	runner = head;
	Node* dummy = &returnHead;
	while (runner)
	{
		dummy->next = runner->next;
		runner->next = runner->next->next;
		runner = runner->next;
		dummy = dummy->next;
	}

	dummy->next = nullptr;
	return returnHead.next;
}

int main()
{
	Node* head = new Node(1, nullptr, nullptr);
	head->next = new Node(2,nullptr,nullptr);
	head->random = head->next;

	head->next->random = head->next;

	Node* newHead = copyRandomList(head);


	return 0;
}
