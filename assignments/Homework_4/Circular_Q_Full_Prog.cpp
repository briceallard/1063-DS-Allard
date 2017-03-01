#include <iostream>
#include <random>

using namespace std;

class ArrQueue{
private:
  int ArraySize;
  int *Q;
  int Front;
  int Rear;
  int NumItems;
public:
  ArrQueue(int size=10){
    ArraySize = size;
    Q = new int[ArraySize];
    Front = Rear = NumItems = 0;
  }
  
  bool Push(int value){
    if(Full()){
      cout<<"Queue Full!"<<endl;
      return false;
    }
    Q[Rear] = value;
    Rear = (Rear + 1) % ArraySize;
    NumItems++;
    return true;
  }
  
  int Pop(){
    if(Empty()){
      cout<<"Queue Empty!"<<endl;
      return false;
    }
    int Temp = Q[Front];
    Front = (Front + 1) % ArraySize;
    NumItems--;
    return Temp;
  }
  
  bool Empty(){
    return (NumItems == 0);
  }
  
  bool Full(){
    return (NumItems == ArraySize);
  }
  
  void PrintFR(){
    cout << endl;
    cout<<"Front: "<<Front << " Rear: "<<Rear<<endl;
  }
  
  void Print(){
    //FIX ME!
    int Index = Front;
    bool isFull = Full();

    while(Index != Rear || isFull){
      cout<<Q[Index]<<" ";
      Index = ((Index + 1) % (ArraySize));
      isFull = false;
    }
    cout<<endl;  
  }

  
  
};

int main() {
    srand(983475);
    ArrQueue Q;
    int r = 0;
    bool result;
    
    for(int i=0;i<12;i++){
      r = rand()%100;
      result = Q.Push(r);
      if(result)
        cout<<r<< " Pushed" << endl;
    }
    Q.PrintFR();
    Q.Print();
    
    cout<<Q.Pop()<< " Popped" << endl;
    cout<<Q.Pop()<< " Popped" << endl;
    cout<<Q.Pop()<< " Popped" << endl;
    cout<<Q.Pop()<< " Popped" << endl;
    cout<<Q.Pop()<< " Popped" << endl;

    Q.Print();
    cout<<Q.Pop()<< " Popped" << endl;
    cout<<Q.Pop()<< " Popped" << endl;
    cout<<Q.Pop()<< " Popped" << endl;
    for(int i=0;i<3;i++){
      r = rand()%100;
      result = Q.Push(r);
      if(result)
        cout<<r<< " Pushed" << endl;
    }
    Q.PrintFR();
    Q.Print();
    return 0;
}
