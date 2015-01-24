#include <iostream>
#include <vector>
using namespace std;

namespace peakValue
{
	class Solution
	{
	  public:
	  int findPeakElement(const vector<int> &num)
	  {
		// we know that num[i] != num[i+1]

		int end = num.size() - 1;
		//cout << "size of vector passing in is : " << end << endl; // std::vector.size() will return the number of elements in vector
		int start = 0;

		while (start <= end)
		{
		/* have special conditions handled   (start = end or start + 1 = end )
		 *
		 * within binary search loop in order to reduce risk
		 */
		  if (start == end)
		  {
			return start;
		  }
		  if (start + 1 == end)
		  {
			return num[start] > num[end] ? start:end;
		  }

		  int mid = (end - start)/2 + 1 + start;
		  if (num[mid] > num[mid+1] && num[mid] > num[mid-1])
		  {
			return mid;
		  }
		  else if(num[mid - 1] < num[mid] && num[mid] < num[mid + 1])
		  {
			start = mid + 1;
		  }
		  else
		  {
			end = mid - 1;
		  }
		}

		return -9;
	  }
	};

	inline void trig()
	{
	  Solution * s = new Solution();

	  static const int arr[] = {1,2,3};
	  const vector<int> v (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	  cout << "the first call " << s -> findPeakElement(v) << endl;

	  static const int arr1[] = {1,2,3,4,5,2,1};
	  const vector<int> v1 (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
	  cout << "the second call " << s -> findPeakElement(v1) << endl;
	  return;
	}
}
