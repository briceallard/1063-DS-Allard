/**
* @Homework: Homework-4
* @Author: Brice Allard
* @Description: 
*     This is the print function for displaying the queued items in a circular queue
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 29 02 2017
*/

/**
* @FunctionName: Print
* @Description: 
*     The problem was the loop was findind Front and Rear to = 0 and would not print. So I used the already
*       created function for verifying if the loop was full, and if it was, continue print.
* @Params:
*    int Index, bool isFull
* @Returns:
*    NONE
*/

void Print(){
  int Index = Front;
  bool isFull = Full();

  while(Index != Rear || isFull){
    cout<<Q[Index]<<" ";
    Index = ((Index + 1) % (ArraySize));
    isFull = false;
  }
  cout<<endl;  
}
