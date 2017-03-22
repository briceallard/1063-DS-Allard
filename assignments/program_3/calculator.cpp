#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cmath>
#include "stack.h"
#include "queue.h"

using namespace std;

class Calculator {
private:
	///////////////////////////////////////////////////////

	Stack *ans;
	Stack *S;
	Queue *Q;
	int Size;
	string infix;
	string postfix;

	void InfixToPostfix() {
		S->push('(');
		infix += ')';

		while (!S->empty()) {
			//S->printStack();
			for (int i = 0; i < infix.length(); i++) {
				//cout << infix[i] << endl;
				if (infix[i] == ' ')
					continue;
				else if (isdigit(infix[i])) {
					Q->Push(S->pop());
				}
				else if (infix[i] == '(') {
					S->push(infix[i]);
				}
				else if (infix[i] == ')') {
					while (!S->empty() && S->top != '(') {
						Q->Push(S->pop());
					}
				}
				else if (IsOperator(infix[i])) {
					while (S->top != '(' && Precedence(S->top, infix[i])) {
						Q->Push(S->pop());
					}
					S->push(infix[i]);
				}
				
			}
			Q->Push(S->pop());
		}
	}

	int EvaluatePostfix() {
		int x, y, result = 0;

		while (!Q->Empty()) {
			char temp = Q->Pop();

			if (isdigit(temp))
				ans->push(temp);

			if (IsOperator(temp)) {
				x = ans->pop();
				y = ans->pop();

				if (temp == '^')
					result = pow(y, x);
				else if (temp == '*')
					result = y * x;
				else if (temp == '/')
					result = y / x;
				else if (temp == '%')
					result = y % x;
				else if (temp == '+')
					result = y + x;
				else if (temp == '-')
					result = y - x;
			}
		}
		return result;
	}

public:
	///////////////////////////////////////////////////////
	Calculator() {
		infix = "";
		postfix = "";
	}

	int ProcessExpression(string exp) {
		int answer = 0;
		Q = new Queue(exp.length() + 2);
		S = new Stack(exp.length() + 2);
		ans = new Stack(10);
		infix = exp;

		cout << infix << " = ";
		InfixToPostfix();
		answer = EvaluatePostfix();
		delete Q;
		delete S;
		return answer;
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

	int Precedence(char op1, char op2)	{
		int op1Weight = OperatorWeight(op1);
		int op2Weight = OperatorWeight(op2);

		if (op1Weight == op2Weight)
			return true;
 
		return op1Weight > op2Weight ? true : false;
	}
};

/*
This main reads an infix expression from stdin, puts the tokens
in a queue, then pops each item off the queue and prints it out.
This is not meant to influence your solution to the program, it
is simply showing basic queue use.
*/
int main() {
	Calculator C;

	ifstream infile;
	infile.open("exp.txt");
	int numEq;
	infile >> numEq;

	for (int i = 0; i < numEq; i++) {
		string infix;
		infile >> infix;

		cout << C.ProcessExpression(infix) << endl;
	}

	system("pause");
}
