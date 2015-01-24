#include <iostream>
#include "peakValue.cpp"
#include "reverseLinkedinList.cpp"
#include "SolutionParent.h"


int main()
{
  peakValue::trig();

  reverseLinkedList::trig();

  Solution::SolutionParent sp(333);
  std::cout << sp.m[1] << std::endl;


  return 0;
}

