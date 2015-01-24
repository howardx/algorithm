


#include "bestTimeBuySellStock.cpp"


class Solution
{
  public:
    int evalRPN(vector<string> &tokens)
    {
      stack<int> s;
      vector<string>::iterator iter = tokens.begin();

      for (; iter != tokens.end(); iter++)
      {
        if (*iter == "+" || *iter == "-" || *iter == "*" || *iter == "/")
        {
          // all these operations take 2 operators and 2 operators ONLY
          int secondOp = s.top();
          s.pop();
          int firstOp = s.top();
          s.pop();

          // c++ switch case can ONLY be used with integer values
          if (*iter == "+")
          {
            s.push(firstOp + secondOp);
          }
          else if (*iter == "-")
          {
            s.push(firstOp - secondOp);
          }
          else if (*iter == "*")
          {
            s.push(firstOp * secondOp);
          }
          else if (*iter == "/")
          {
            s.push(firstOp/secondOp);
          }
        }
        else
        {
          s.push(stoi(*iter));
        }
      }
      return s.top();
    }
};

int main()
{
  Solution s;

  string arr1[] = {"2", "1", "+", "3", "*"};
  vector<string> in1(arr1, arr1+5);

  cout << s.evalRPN(in1) << endl;

  S so;
  vector<int> v {6,1,3,2,4,7};
  cout << so.maxProfit(v) << endl;

  return 1;
}
