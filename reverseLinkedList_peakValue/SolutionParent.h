/*
 * SolutionParent.h
 *
 *  Created on: Jan 18, 2015
 *      Author: howard
 */

#include <iostream>
#include <unordered_map>

#ifndef SOLUTIONPARENT_H_
#define SOLUTIONPARENT_H_

namespace Solution {

class SolutionParent
{
  public:
	std::unordered_map<int, int> m;
	SolutionParent(int);
	virtual ~SolutionParent();
};

} /* namespace Solution */
#endif /* SOLUTIONPARENT_H_ */
