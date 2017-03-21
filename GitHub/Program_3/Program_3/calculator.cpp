#include <iostream>
#include <fstream>
#include <string>
#include "stack.h"
#include "queue.h"

using namespace std;

class Convert {
private:
///////////////////////////////////////////////////////

	Stack *S;
	Queue *Q;

public:
///////////////////////////////////////////////////////
	Convert() {
		S = new Stack(20);
		Q = new Queue(20);
	}

	bool IsOperator(char c) {
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^')
			return true;
		else
			return false;
	}

	int OperatorWeight(char c) {
		int weight = -1;

		switch (c) {
		case '+':
		case '-':
			weight = 1;
			break;
		case '*':
		case '/':
		case '%':
			weight = 2;
			break;
		case '^':
			weight = 3;
			break;
		default:
			weight = -1;
			break;
		}
		return weight;
	}

	string InfixToPostfix(string infix) {
		S->push('(');
		infix[infix.length()] = ')';

		while (!S->empty()) {
			for (int i = 0; i < infix.length(); i++) {
				if (isdigit(infix[i])) {
					Q->Push(infix[i]);
				}
				else if (infix[i] = '(') {
					S->push(infix[i]);
				}
				else if (IsOperator(infix[i])) {
					// NOT SURE
					//S->pop();
					S->push(infix[i]);
				}
				else if (infix[i] = ')') {
					//NOT SURE
					//S->pop();
					Q->Push(infix[i]);
				}
			}
		}
		return infix;
	}

	double Evaluate(string postfix) {

	}
};

/*
This main reads an infix expression from stdin, puts the tokens
in a queue, then pops each item off the queue and prints it out.
This is not meant to influence your solution to the program, it
is simply showing basic queue use.
*/
int main() {
	Convert C;
	string infix = "1+2+3";
	string postfix = C.InfixToPostfix(infix);

	cout << postfix << endl;

	system("pause");
	return 0;
}