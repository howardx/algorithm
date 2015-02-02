/*
 * Given an array with n objects colored red, white or blue,
 * sort them so that objects of the same color are adjacent,
 * with the colors in the order red, white and blue.

 * Here, we will use the integers 0, 1, and 2 to represent
 * the color red, white, and blue respectively. 
 *
 * can you do this with a 1-pass algorithm with constant space?
 * yes
 */
#include <iostream>

void sortColors(int A[], int n)
{
  // allowing dynamic increase the indexs during looping
  int zeroIndex = -1, oneIndex = -1, twoIndex = -1;

  for (int i = 0; i < n; i ++)
  {
    if (A[i] == 0)
    {
      /*
       * ith index should contain 0, while indexs for 1 and 2
       * should all be increased as their possible spaces
       * in the array will be down the road
       *
       * meanwhile, during the iterations the 2 and 1 index
       * will stop at different places hence their values
       * need to be reassigned -- bit equivalent to swapping
       */
      A[++twoIndex] = 2;
      A[++oneIndex] = 1;
      A[++zeroIndex] = 0;
    }
    else if(A[i] == 1)
    {
      A[++twoIndex] = 2;
      A[++oneIndex] = 1;
    }
    else if(A[i] == 2)
    {
      A[++twoIndex] = 2;
    }
  }
}

int main()
{
  int c [5] = {0,2,2,1,0};
  sortColors(c, 5);

  for (int i = 0; i != 5; i++)
  {
    std::cout << c[i] << std::endl;
  }
  return 0;
}
