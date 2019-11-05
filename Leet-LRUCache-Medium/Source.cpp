///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <deque>
#include <algorithm>
#include <map>
#include <math.h>

class LRUCache {
public:
	std::map<int, int>* values;
	std::deque<int>* frequency;
	size_t size;

	LRUCache(int capacity) 
	{
		values = new std::map<int, int>;
		frequency = new std::deque<int>;
		size = capacity;
		for (int i = 1; i <= capacity; i++)
		{
			frequency->push_back(i);
		}
	}

	void updateKey(int key)
	{
		auto itr = frequency->begin();
		while (itr != frequency->end())
		{
			if (*itr == key)
			{
				frequency->erase(itr);
				break;
			}
			++itr;
		}
		
		frequency->push_back(key);

		while (size < frequency->size())
			frequency->pop_front();
	}

	int get(int key) 
	{
		if (values->find(key) == values->end())
			return -1;

		updateKey(key);
		return values->at(key);
	}

	void put(int key, int value) 
	{
		if (values->find(key) != values->end())
		{
			(*values)[key] = value;
			updateKey(key);
		}
		else if (values->find(key) == values->end() && values->size()<frequency->size())
		{
			(*values)[key] = value;
			updateKey(key);
		}
		else
		{
			values->erase(values->find(frequency->front()));
			(*values)[key] = value;
			frequency->pop_front();
			updateKey(key);
		}
	}
	~LRUCache()
	{
		delete values;
		delete frequency;
	}
};

/*
["LRUCache","put","put","get","put","put","get"]
[       [2],[2,1],[2,2],[2],[1,1],[4,1],[2]]
*/
int main()
{
	LRUCache cache = LRUCache(2 /* capacity */);

	cache.put(2, 1);
	cache.put(2, 2);
	cache.get(2);       // returns 1
	cache.put(1, 1);    // evicts key 2
	cache.put(4, 1);    // evicts key 2
	cache.get(2);       // returns 3     // returns 4
	return 0;
}