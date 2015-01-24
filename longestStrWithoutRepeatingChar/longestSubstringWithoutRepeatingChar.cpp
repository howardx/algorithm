/*
 * longestSubstringWithoutRepeatingChar.cpp
 *
 *  Created on: Jan 23, 2015
 *      Author: howard
 */

// for testing c++0x only
#include <unordered_map>

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DON'T INTRODUCE MORE UNKONW/UNCERTAINTIES BEFORE SOLVING EXISTING PROBLEMS !!

void printHashTable(unordered_map<char, bool> map)
{
  unordered_map<char, bool>::iterator iter = map.begin();
  while (iter != map.end())
  {
    /*  cout << (*iter) << endl; WON'T WORK
     *
     * operator << is designed to work with standard data types
     * and not custom data type like class or unordered_map
     *
     */
    cout << iter -> first;
    iter++;
  }
  cout << endl;
}

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
      if (s.length() > 1)
      {
        unordered_map<char, bool> uniqueChar;

        // initialization steps for DP
        int maxUpTo = 1;
        uniqueChar[s[0]] = true;
        int maxl = 1;

        for (int i = 1; i < s.length(); i++)
        {
          printHashTable(uniqueChar);
          if (uniqueChar.find(s[i]) == uniqueChar.end() && s[i] != s[i+1] && s[i] != s[i-1])
          {
        	if (uniqueChar.empty()) // new substring, just started
        	{
              maxUpTo = 1;
        	}
        	else
        	{
              maxUpTo++;
        	}
            uniqueChar[s[i]] = true;
          }
          else
          {
            maxUpTo = 1;
            uniqueChar.clear();
            i--; // next time should still start from i
          }
          maxl = std::max(maxUpTo, maxl);
        }
        return maxl;
      }
      return (s.length() == 0)?0:1;
    }
};

int main()
{
  string s("tthiihhsos"); // 2
  string s1("hchzvfrkmlnozjk"); // 11
  string s2("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");

  // for calling default constructor or constructor who takes no input argument
  Solution so;
  std::cout << so.lengthOfLongestSubstring(s) << std::endl;
  std::cout << so.lengthOfLongestSubstring(s1) << std::endl;
  //std::cout << so.lengthOfLongestSubstring(s2) << std::endl;
  return 1;
}
