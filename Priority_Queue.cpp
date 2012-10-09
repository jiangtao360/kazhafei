#include"Priority_Queue.h"

int main()
{
	PriorityQueue pqueue;

	int f = 0;
	int key, i;

	cout << "1.insert a element" << endl;
	cout << "2.return the max" << endl;
	cout << "3.return and delete the max"<< endl;
	cout << "4.return the length" << endl;
	cout << "5.increase i element to key" << endl;
	cout << "6.decrease i element to key" << endl;
	cout << "7.exit" << endl;

	while(f != 7)
	{
		cin >> f;
		switch(f)
		{
		case 1:
			cout<<"input a value:";
			cin >> key;
			pqueue.Insert(key);
			break;
		case 2:
			cout <<"The max value is:" << pqueue.Maximum() << endl;
			break;
		case 3:
			cout << "The max and deleted is:" << pqueue.ExtractMax() << endl;
			break;
		case 4:
			cout << "The length is:" << pqueue.Length() << endl;
			break;
		case 5:
			cout << "input the i and key:";
			cin >> i >> key;
			pqueue.IncreaseKey(i,key);
			break;
		case 6:
			cout << "input the i and key:";
			cin >> i >> key;
			pqueue.DecreaseKey(i,key);
			break;
		default:
			break;
		}
		cout << endl;
	}

	return 0;
}