/*
 * SolutionParent.cpp
 *
 *  Created on: Jan 18, 2015
 *      Author: howard
 */

#include "SolutionParent.h"

namespace Solution
{

  SolutionParent::SolutionParent(int num)
  {
    (this->m)[1] = num;
    (this->m)[2] = 99;
    std::cout << m[1];
  }

SolutionParent::~SolutionParent() {}

} /* namespace Solution */
