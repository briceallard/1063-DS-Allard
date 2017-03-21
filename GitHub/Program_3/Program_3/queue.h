#include <iostream>
#include <string>

using namespace std;

/*
* @functionName: Queue
* @Description:
*			Uses an array to implement a basic queue
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: Mar 2017
*/

class Queue {
private:
///////////////////////////////////////////////////////

	int ArraySize;
	char *Q;
	int Front;
	int Rear;
	int NumItems;

public:
///////////////////////////////////////////////////////

	Queue(int);
	void Push(char);
	char Pop();
	void PrintQueue();
	bool Empty();
	bool Full();
};