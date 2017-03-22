#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

Queue::Queue(int insize) {
	ArraySize = insize;
	Q = new char[ArraySize];
	Front = Rear = NumItems = 0;
}

/**
* @FunctionName: push
* @Description:
*     Adds a character to the queue
* @Params:
*    char c - character to add
* @Returns:
*    void
*/
void Queue::Push(char c) {
	if (Full()) {
		cout << "Queue Full!" << endl;
		return;
	}
	Q[Rear] = c;
	Rear = (Rear + 1) % ArraySize;
	NumItems++;
	return;
}

/**
* @FunctionName: pop
* @Description:
*     Returns a character from the top of the queue
* @Params:
*    None
* @Returns:
*    void
*/
char Queue::Pop() {
	if (Empty()) {
		cout << "Queue Empty!" << endl;
		return false;
	}
	int Temp = Q[Front];
	Front = (Front + 1) % ArraySize;
	NumItems--;
	return Temp;
}

/**
* @FunctionName: printQueue
* @Description:
*     Prints queue to stdout for debugging purposes
* @Params:
*    None
* @Returns:
*    void
*/
void Queue::PrintQueue() {
	for (int i = Front, j = 0; j<NumItems; j++, i = (i + 1) % ArraySize) {
		cout << Q[i] << " ";
	}
	cout << endl;
}

/**
* @FunctionName: empty
* @Description:
*     Checks to see if queue is empty.
* @Params:
*    None
* @Returns:
*    bool - true if empty / false otherwise
*/
bool Queue::Empty() {
	return (NumItems == 0);
}

/**
* @FunctionName: full
* @Description:
*     Checks if queue is full
* @Params:
*    None
* @Returns:
*    bool - true if full / false otherwise
*/
bool Queue::Full() {
	return (NumItems == ArraySize);
}