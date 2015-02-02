#include <iostream>
#include <vector>

void quickSort()
{
}


int main()
{
  int arr[] = {8875,8,9,89,0,44,99,22,787,12,5,1,9,-23,4}; // size 15
  int size = sizeof(arr)/sizeof(int);
  printArray();
  
  quickSort(arr, size);
  printArray(arr, size);
  return 0;
}

void printArray(int * arr, int size)
{
  for ( size i = 0; i != size; i++)
  {
    cout << arr[i] << " ";
  }
}

void swap(int * left, int * right)
{
  int * temp = right;
  right = left;
  left = temp;
}
