/*
 * bestTimeBuySellStock.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: howard
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string> // int stoi()
using namespace std;

class S
{
  public:
    int maxProfit(vector<int> &prices)
    {
      if (prices.size() == 0) {return 0;}
      typedef std::vector<int>::iterator it;

      int currentMaxProfit = 0;
      int result = 0;

      for (it i = prices.begin() + 1; i != prices.end(); i++)
      {
        currentMaxProfit = currentMaxProfit + *(i) - *(i-1);

        /* negative profit, start anew
         *
         * if positive profit, though maybe decreasing, should KEEP
         */
        if ( currentMaxProfit <= 0 )
        {
          currentMaxProfit = 0;
        }
        result = (currentMaxProfit > result) ? currentMaxProfit : result;
      }
      return result;
    }
};


