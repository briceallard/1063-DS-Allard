//Catherine Stringfellow (modified by Wuthrich)
//File: SortIt.cpp
//Purpose: Study basic steps in selection and
//insertion sort algorithms

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAXINTS = 25;
typedef int IntArray[MAXINTS];

//Selection sort works by finding the smallest unsorted 
//item in the array and swapping it with the item in the current position 
void selectionSort(IntArray ints, int & comps, int & swaps);

//Insert sort puts elements in ascending order by repeatedly
//putting 1st element in unsorted subarray into proper position of sorted array
void insertSort(IntArray ints, int & comps, int & swaps);

//Quick Sort repeatedly partitions the array around a pivot value
void quickSort(int arr[], int left, int right, int & comps, int & swaps);

//Purpose: To initialize elements of array to random integers
void initRandomArray(IntArray ints);

//Purpose:  Make a copy of an existing array
void copyArray(IntArray ints, IntArray ints2);

//Purpose:  Take an existing array of ints and reverse their order
void reverseArray(IntArray ints);

//Purpose:  display array
void printArray(IntArray ints);

int main()
{

  IntArray ints, ints2, ints3;
  // Keep track of number of compares and swaps (basic steps)
  int selectComps, insertComps, selectSwaps, insertSwaps;
  int quickComps, quickSwaps;

  //set up for random number generator
  srand(time(NULL));

  //initialize the random array and make copies
  initRandomArray(ints);
  copyArray(ints, ints2);
  copyArray(ints, ints3);

  //Sort random array using the selection, insertion, and quick sorts
  cout << "Sorting a random array\n";

  //Display original array
  printArray(ints);

  selectionSort(ints, selectComps, selectSwaps);

  //restore array
  copyArray(ints2, ints);

  insertSort(ints, insertComps, insertSwaps);

  //restore array
  copyArray(ints2, ints);

  // Can't initialize these in the recursive function
  quickComps = 0;
  quickSwaps = 0;

  quickSort(ints, 0, MAXINTS - 1, quickComps, quickSwaps);

  cout << "When sorting numbers that are in random order...." << endl;
  cout << "\n\tThe selection sort made " << selectComps << " comparisons";
  cout << " and " << selectSwaps << " swaps.\n";
  cout << "\tThe insertion sort made " << insertComps << " comparisons";
  cout << " and " << insertSwaps << " swaps.\n";
  cout << "\tThe quick sort made " <<quickComps << " comparisons";
  cout << " and " << quickSwaps << " swaps.\n\n";

  //Now do a "sort" on numbers that are already in order!
  cout << "Sorting an ordered array\n";

  //Display sorted array

  printArray(ints);

  selectionSort(ints, selectComps, selectSwaps);

  //You don't need to restore array...why?
  insertSort(ints, insertComps, insertSwaps);

  // Can't initialize these in the recursive function
  quickComps = 0;
  quickSwaps = 0;

  quickSort(ints, 0, MAXINTS - 1, quickComps, quickSwaps);

  cout << "When sorting numbers that are already in the correct order...." <<  endl;
  cout << "\n\tThe selection sort made " << selectComps << " comparisons";
  cout << " and " << selectSwaps << " swaps.\n";
  cout << "\tThe insertion sort made " << insertComps << " comparisons";
  cout << " and " << insertSwaps << " swaps.\n";
  cout << "\tThe quick sort made " << quickComps << " comparisons";
  cout << " and " << quickSwaps << " swaps.\n\n";

  //Sort array that is in reverse order.
  cout << "Sorting a reversed array\n";

  reverseArray(ints);
  //Display the reversed array
  printArray(ints);

  selectionSort(ints, selectComps, selectSwaps);

  //restore array
  reverseArray(ints);

  insertSort(ints, insertComps, insertSwaps);
  //restore array
  reverseArray(ints);
  // Can't initialize these in the recursive function
  quickComps = 0;
  quickSwaps = 0;

  quickSort(ints, 0, MAXINTS - 1, quickComps, quickSwaps);

  cout << "When sorting numbers that are in reverse order...." << endl;
  cout << "\n\tThe selection sort made " << selectComps << " comparisons";
  cout << " and " << selectSwaps << " swaps.\n";
  cout << "\tThe insertion sort made " << insertComps << " comparisons";
  cout << " and " << insertSwaps << " swaps.\n";
  cout << "\tThe quick sort made " << quickComps << " comparisons";
  cout << " and " << quickSwaps << " swaps.\n\n";

  system("pause");
  return 0;
}

void initRandomArray(IntArray ints)
{
  for (int i = 0; i < MAXINTS; i++)
    ints[i] = 1 + rand() % 40;
}

void selectionSort(IntArray ints, int & comps, int & swaps)
{

  int startScan, minIndex, minValue;

  comps = 0;
  swaps = 0;
  for (startScan = 0; startScan < MAXINTS - 1; startScan++)
  {
    //find smallest in subarray
    minIndex = startScan;
    minValue = ints[minIndex];
    for (int index = startScan + 1; index < MAXINTS; index++)
    {
      comps++;
      if (ints[index] < minValue)
      {
        minValue = ints[index];
        minIndex = index;
      }
    }

    //swap values
    swaps++;
    ints[minIndex] = ints[startScan];
    ints[startScan] = minValue;
  }

}

//Insert sort puts elements in ascending order by repeatedly
//putting 1st element in unsorted subarray into proper position of sorted array
void insertSort(IntArray a, int & comps, int & swaps)
{
  bool found;
  int j;

  comps = 0;
  swaps = 0;

  //put each element in unsorted subarray in proper position
  for (int i = 1; i < MAXINTS; i++)
  {
    //find proper place for a[i] relative to a[0]..a[i]
    found = false;
    j = i;
    while ((j > 0) && !found)
    {
      comps++;
      //swap and decrement j
      if (a[j] < a[j - 1])
      {
        swap(a[j], a[j - 1]);
        swaps++;
        j = j - 1;
      }
      else
        found = true;
    }
  } 
} 


void quickSort(int arr[], int left, int right, int & comps, int & swaps) {
  int i = left, j = right;
  int tmp;
  int pivot = arr[(left + right) / 2];

  /* partition */
  while (i <= j) {
    comps++;
    while (arr[i] < pivot) // if false, found # in wrong half
      i++;
    while (arr[j] > pivot) // Look for # in right half that doesn't belong
      j--;
    if (i <= j) {
      //swap
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
      swaps++;
      i++;
      j--;
    }
  };

  if (left < j)
    quickSort(arr, left, j, comps, swaps);
  if (i < right)
    quickSort(arr, i, right, comps, swaps);
}

void copyArray(IntArray ints, IntArray ints2)
{
  for (int i = 0; i < MAXINTS; i++)
    ints2[i] = ints[i];
}

void reverseArray(IntArray ints)
{
  IntArray ints2;

  for (int i = 0; i < MAXINTS; i++)
    ints2[i] = ints[MAXINTS - i - 1];

  copyArray(ints2, ints);

}

void printArray(IntArray ints)
{
  for (int k = 0; k < MAXINTS; k++)
  {
    cout << ints[k] << "\t";
    if ((k + 1) % 10 == 0)
      cout << endl;
  }
  cout << endl;
}
