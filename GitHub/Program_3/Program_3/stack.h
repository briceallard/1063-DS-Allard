#include <iostream>
#include <string>

using namespace std;

/*
* @FunctionName: Stack
* @Description:
*			Creates a stack in order to store Char types from
			the infix equation input from the user.
*/

class Stack {
private:
///////////////////////////////////////////////////////

	char *S;
	int size;

public:
///////////////////////////////////////////////////////
	int top;

	Stack(int);
	void push(char);
	char pop();
	void printStack();
	bool empty();
	bool full();
	int Peek();
};