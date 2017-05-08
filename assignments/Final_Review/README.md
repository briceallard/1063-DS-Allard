# Study Guide
Final Exam: Monday May 8th, 3:30 p.m. - 5:30 p.m.

I uploaded a [final exam](https://github.com/rugbyprof/1063-Data-Structures/blob/master/Assignments/12-FinalExam/CMPS_1053_Final_Exam.fall.12.pdf) from 2012, so you can see that I have actually scaled it back! So be happy :) 

## Pointers

| Memory Snapshot |
|:-------------:|
| ![](https://d3vv6lp55qjaqc.cloudfront.net/items/1s0J3A0J2T3i1l0p2g2b/pointer_memory.png?X-CloudApp-Visitor-Id=1094421) |

| Command           | Result |
|:-----------------:|:------:|
|  `cout<<&D`       |  4000  |
|  `cout<<&E`       |  5000  |
|  `cout<<*D`       |   42   |
|  `cout<<*F`       |   73   |
|  `cout<<F`        |  1000  |
|  `cout<<A`        |   73   |
|  `cout<<*E`       |  Error |
| `cout<<&G`        |  7000  |
| `C = &A; cout<<*C`|   73   |
|  `*F=*D; cout<<*F`|   42   |

(LOOK CLOSE AT `C = &A; cout<<*C` = 73. IT IS TRICKY) <br>
<sub>Solution: https://github.com/rugbyprof/1063-Data-Structures/edit/master/Assignments/06-Test-1/test-1-solution.md</sub>

## Arrays
- Write functions to do the following to a an array:
    - Sum integer values
        - Receives array, its size, and returns the sum of the values. <br>
        ```cpp
        int sum(int array[], int size){
			  int sum = 0;
		
			  while (int i = 0, i < size, i++) {
			  	sum = sum + array[i];
			  }
			  return sum;
		  }
      ```
      
    - Avg integer values
        - Receives array, its size, and returns the sum of the values.
        ```cpp
        int avg(int array[], int size) {
		  	int sum = 0;
			
			  while (int i = 0, i < size, i++) {
			 	  sum = sum + array[i];
			  }
			  avg = sum / size;
			  return avg;
		  }
      ```
    - Max integer
        - Receives array, its size, and returns the maximum value in the array.
        ```cpp
        int Max(int array[], int size) {
		  	int max = 0;
			
			  while (int i = 0, i < size, i++) {
				  if (array[i] > max)
					  max = array[i];
			  }
			  return max;
		  }
      ```
    - Count occurences of a specified string in an array
        - Receives an array of words, a key to search for, and returns the number of times that key occurs in the array.
        ```cpp
        int occurences(string array[], string key, int size) {
			  int occ = 0;
			
			  while (int i = 0, i < size, i++) {
				  if(array[i] == key)
				  	occ++;
			  }
			  return occ;
		  }
      ```


## Lists

- What is the worst case search time for a singly linked list? `O(n)` <br> 
Discuss what advantages / disadvantages a doubly linked list would have for: (1) Searching (2) Inserting (3) Deleting <br>
`1. Advantages` <br>
	`	- Allows traversal forwards and backwards` <br>
	`	- Delete operation is more efficient if pointer to the node to be deleted is given.` <br>
	`2. Disadvantages` <br>
		`- Every node requires extra space for previous pointer. `<br>
		`- Harder to impliment` <br>
-----

- Write a c++ function the will return the largest and smallest values from any given linked list.
```cpp
int big (struct node *head) {
		int max = head->data;
		
		if (head == NULL) {
			cout << "Invalid" << endl;
			return -1;
		}
		
		while {head != NULL) {
			if(head->data > max)
				max = head->data;
				
			head = head->next;
		}
		return max
	}
  
  int small (struct node *head) {
		int min = head->data;
		
		if(head = NULL)) {
			cout << "Invalid" << endl;
			return -1;
		}
		
		while (head != NULL) {
			if (head->data < min)
				min = head->data;
				
			head = head->next;
		}
		return min;
	}
```
 - Write a function to merge two linked lists of integers that are sorted into ascending order. The result should be a third linked list that is the sorted combination of the original lists. Do not destroy the original lists. Do not assume you have a class with methods to complete this problem.

 ![](https://d3vv6lp55qjaqc.cloudfront.net/items/2k1B1k2J0J0L221g2I2a/Image%202017-05-03%20at%202.26.48%20PM.png?X-CloudApp-Visitor-Id=1094421)
 
 ```cpp
Node * List1; //points to List1 above
Node * List2; //points to List2 above
Node * List3; //currently points to NULL;
List3 = MergeLists(List1,List2); //function call to merge the lists.

//Your function will receive two Node*’s and return a 3rd Node* that points to your new merged list.

Node* MergeLists(Node* L1, Node* L2){
  Node* L3 = NULL;
  
  if(L1 == NULL)
  	return L2;
  else if(L2 == NULL;
	return L1;
			
  if (L1->data <= L2->data) {
	L3 = L1;
	L3->next = mergeLists(L1->next, L2);
  } else {
	L3 = L2;
	L3->next = mergeLists(L1,L2->next); 
  }
		
	return L3;		
  }
}
```
-----

- Write a `Count()` function that counts the number of times a given int occurs in a list.

```cpp
void main() {
    List myList;
    myList.BuildOneTwoThree(); // build {1, 2, 3}
    int count = MyList.Count(2); // returns 1 since there's 1 '2' in the list
}
/*
Given a list and an int, return the number of times that int occurs
in the list.
*/
int List::Count(int searchFor) {
  int count = 0;
	if(head = NULL) {
		cout << "Invalid" << endl;
		return -1;
	}
		
	while (head != NULL) {
		if (head == val)
		count++;
				
		head = head->next;
	}
	return count;
}

```
-----

- Write a `Remove()` function that removes the front node from a linked list. Pop takes a non-empty list, deletes the head node, and returns the head node's data. Here is how it could be used:

```cpp
void main() {
    List MyList;
    MyList.BuildOneTwoThree(); // build {1, 2, 3}
    int a = MyList.Remove (); // deletes "1" node and returns 1
    int b = MyList.Remove (); // deletes "2" node and returns 2
    int c = MyList.Remove (); // deletes "3" node and returns 3
    int len = MyList.Length(); // the list is now empty, so len == 0
}
/*
Takes a non-empty list and removes (deletes) the front node, and returns the data which was in that node.
*/
int List::Remove() {
  int Data;
		
	if (head != NULL) {
		Node *temp = new node;
		temp = head;
		head = head->next;
		Data = temp;
		delete(temp);
	}
	return Data;
}

```

## Searching 

Use a standard binary search method to find the value 10  within the following array. Do anything necessary to the array to assist in your binary search. At each step, be sure to label the First, Middle, and Last (you can use F,M and L) locations. 

![](https://d3vv6lp55qjaqc.cloudfront.net/items/1M0N0K1h3N0O2T291I3Z/Image%202017-05-03%20at%209.01.01%20PM.png?X-CloudApp-Visitor-Id=1094421)

```cpp
int Search(int key){
	int left = 0;
	int right = size - 1;
	int middle = (left+right) / 2;
	bool found = false;
	
	while(!found){
		if(Data[middle] == key){
			return middle;
		} else if (middle == left || middle == right) {
			cout << "Key Not Found!" << endl;
			return -1;
		} else {
			if (key < Data[middle])
				right = middle;
			else
				left = middle;
		}
		middle = (left + right) / 2;
	}
	return -1;
}
```

## Using Stacks And Queues
- Below you see a stack ***`S`*** in its initial state. (For this question: Stack uses ***`Push`*** and ***`Pop`*** )
- A queue ***`Q`*** , in its initial state. (For this question: Queue uses ***`Add`*** and ***`Remove`*** )
- And a list ***`L`*** that’s in its FINAL state. (List uses ***`Add`*** )

![](https://d3vv6lp55qjaqc.cloudfront.net/items/091O2N250w1c2h0S0e1W/Image%202017-05-03%20at%208.49.23%20PM.png?X-CloudApp-Visitor-Id=1094421)

- You need to write a series of `push`, `pops`, `adds`, and `removes` to get the values from ***`S`*** and ***`Q`*** into ***`L`*** in the order displayed. 
- ***`L.Add`*** adds the values to the rear of the list.

```cpp
L.Add(Q.Remove);		//Add 16 from Q to L
L.Add(S.Pop);			//Add 1 from S to L
L.Add(S.Pop);			//Add 6 from S to L
L.Add(S.Pop);			//Add 3 from S to L
Q.Add(S.Pop);			//Move 9 from S to Q
Q.Add(S.Pop);			//Move 2 from S to Q
L.Add(S.Pop);			//Move 8 from S to L
L.Add(Q.Remove);		//Move 2 from Q to L
S.Push(Q.Remove);		//Move 9 from Q to S
L.Add(Q.Remove);		//Move 11 from Q to L (Q is now empty)
L.Add(S.Pop);			//Move 9 from S to L (S is not empty)
```

## ~~Array Based Stacks and Queues~~
(concentrate on list implementations)
- ~~Write a complete class implementation of an array based stack~~
- ~~Write a complete class implementation of an array based queue~~
- ~~<sub>https://github.com/rugbyprof/1063-Data-Structures/blob/master/Lectures/Day04.cpp</sub>~~

## List Based Stacks and Queues

- Write a complete class implementation of a list based stack
```cpp
	#include <iostream>
	
	using namespace std;
	
	
	struct Node {
		int Data;
		Node* Next;
	};
	
	class Stack {
	private:
	///////////////////////////////////
	
		Node *Top;
	
	public:
	///////////////////////////////////
		Stack() {
			Top = NULL;
		}
		bool empty() {
			return Top == NULL;
		}
		
		void push(int val) {
			Node *Temp = new Node;
			Temp->Data = val;
			Temp->Next = NULL;
			
			if(Empty()) {
				Top = Temp;
			} else {
				Temp->Next = Top;
				Top = Temp;
			}
		}
		
		int pop() {
			int TempData = Top->Data;
			Node* TempNodePtr = Top;
			Top = Top->Next;
			delete TempNodePtr;
			return TempData;
		}
		
		void print() {
			Node* Temp = Top;
			
			while(Temp) {
				cout << Temp=>Data << "->";
				Temp = Temp->Next;
			}
			cout << endl;
		}
	};
```
- Write a complete class implementation of a list based queue
```cpp
	#include <iostream>
	
	using namespace std;
	
	class Queue {
	private:
	////////////////////////////////////////
	
		Node* Front;
		Node* Rear;
		
	public:
	///////////////////////////////////////
	
		Queue() {
			Front = Rear = NULL;
		}
		
		bool Empty() {
			return Front == NULL;
		}
		
		void Push(int val) {
			Node* Temp = new Node;
			Temp->Data = val;
			Temp->Next = NULL;
			
			if(Empty()) {
				Front = Rear = Temp;
			} else {
				Rear->Next = Temp;
				Rear = Temp;
			}
		}
		
		int Pop() {
			int TempData = Front->Data;
			Node* TempNodePtr = Front;
			Front = Front->Next;
			delete TempNodePtr;
			return TempData;
		}
		
		void Print() {
			Node* Temp = Front;
			
			while(Temp) {
				cout << Temp->Data << "->";
				Temp = Temp->Next;
			}
			cout << endl;
		}
	};
```
- <sub>https://github.com/rugbyprof/1063-Data-Structures/blob/master/Lectures/Day19.cpp</sub>

#### Array vs List
- What are benefits of using an array based implementation? <br>
		`	- Easier to implement` <br>
		`	- Can access elements of the array sequentially <br>
				(allowing for binary search)` <br>
- What are benefits of using a list based implementation? <br>
      `- Dynamic Size` <br>
			`- Easier insertion/deletion` <br>
- Explain why we need to implement a queue using the "circular" technique when using an array, but not when using a list. <br>
       `- List implementation is dynamic, meaning it can change the size` <br>
				`of the queue after deleting or inserting.`<br>
				`A non circular array based queue would run out of space,` <br>
				`and would be a costly operation to reallocate the appropriate` <br>
				`memory locations.` <br>
