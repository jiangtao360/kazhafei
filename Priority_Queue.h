#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<iostream>

using namespace std;

const int MAX_SIZE = 1000;
const int MIN = -1;

class PriorityQueue
{
public:
	PriorityQueue();
	void Insert(int key);
	int Maximum();
	int ExtractMax();
	void IncreaseKey(int i, int key);
	void DecreaseKey(int i, int key);
	int Length();

private:
	int array[MAX_SIZE];
	int length;

	void MaxHeapify(int i);
};

PriorityQueue::PriorityQueue()
{
	length = 0;
}

void PriorityQueue::MaxHeapify(int i)
{
	int left, right;
	int largest;
	int temp;

	while(1)
	{
		left = 2*i+1;
		right = 2*i+2;
		if(left < length && array[left] > array[i])
		{
			largest = left;
		}
		else
		{
			largest = i;
		}
		if(right < length && array[right] > array[largest])
		{
			largest = right;
		}
		if(i != largest)
		{
			temp = array[i];
			array[i] = array[largest];
			array[largest] = temp;
			i = largest;
		}
		else
		{
			break;
		}
	}
}

int PriorityQueue::ExtractMax()
{
	if(length < 1)
	{
		cout << "underflow" << endl;
		return -1;
	}
	else
	{
		int max;
		max = array[0];
		array[0] = array[length-1];
		length--;
		MaxHeapify(0);
		return max;
	}
}

int PriorityQueue::Maximum()
{
	if(length == 0)
	{
		cout << "empty" << endl;
		return -1;
	}
	else
	{
		return array[0];
	}
}

void PriorityQueue::IncreaseKey(int i, int key)
{
	if(key < array[i])
	{
		cout << "new key is smaller than current key" << endl;
	}
	else 
	{
		int parents;
		int temp;

		array[i] = key;
		while(1)
		{
			parents = (i-1)/2;
			if(i > 0 && array[parents] < array[i])
			{
				temp = array[i];
				array[i] = array[parents];
				array[parents] = temp;
				i = parents;
			}
			else
			{
				break;
			}
		}
	}
}

void PriorityQueue::Insert(int key)
{
	array[length] = MIN;
	length++;
	IncreaseKey(length-1,key);
}

void PriorityQueue::DecreaseKey(int i, int key)
{
	if(key > array[i])
	{
		cout << "new key is larger than current key" << endl;
	}
	else
	{
		array[i] = key;
		MaxHeapify(i);
	}
}

int PriorityQueue::Length()
{
	return length;
}

#endif