//0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2
// given a target value to search.
//If found in the array return its index, otherwise return -1
// no duplicates
#include <iostream>

class Solution
{
public:
  int search(int A[], int n, int target)
  {
    int start = 0; n--;
    while (start <= n)
    {
      // CORRECT way to calculate mid in binary search
      // n or end equal to size - 1 !!!
      // recursive/loop condition: start <= end !!!
      int mid = (n-start)/2 + start;
      //std::cout << "mid is: " << mid << std::endl;

      if (A[mid] == target)
      {
        return mid;
      }
      else
      {
        if (A[start] < A[mid]) // left hand side is sorted
        {
          if (A[start] <= target && target <= A[mid-1])
          {
            // target is in sorted left half
        	n = mid - 1;
          }
          else
          {
            // target is in unsorted (or could be sorted) right half
        	start = mid + 1;
          }
        }

        else // right hand side is sorted
        {
          if (A[mid+1] <= target && target <= A[n])
          {
        	// target in sorted right hand side
            start = mid + 1;
          }
          else
          {
            // target in left hand side, not sure whether it's sorted or not
        	n = mid - 1;
          }
        }
      }
    }
    return -1;
  }
};
