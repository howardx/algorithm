#include <iostream>
using namespace std;

void swap(int & a, int & b);

void insertionSort(int arr[], int size)
{
  for (int i = 1; i != size; i ++)
  {
    if (arr[i-1] >= arr[i]) // need to swap and insert
    {
      for (int j = 0; j != i; j ++)
      {
        if (arr[j] > arr[i])
        {
          swap(arr[i], arr[j]);
        } 
      }
    }
  }
}

int main()
{
  int arr[12] = {9,6,10,4,654,3,-1,2,33,0,0,1};
  
  insertionSort(arr, 12);
  
  for (int i = 0; i != 12; i++)
  {
    cout << arr[i] << " " ;
  }
  return 0;
}

void swap(int & a, int & b)
{
  int temp = a;
  a = b;
  b = temp;
}
