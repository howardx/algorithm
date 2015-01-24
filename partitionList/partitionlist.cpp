/*
 *  Created on: Jan 22, 2015
 *      Author: howard
 */

#include "partitionList.h"

class Solution
{
  public:
    ListNode * partition(ListNode *head, int x)
    {
      ListNode * smaller = NULL;
      ListNode * eqORlarger = NULL;
      ListNode * smallHead = NULL;
      ListNode * eqORlargerHead = NULL;

      if (head == NULL || head -> next == NULL) // special case with only 1 or 0 node
      {
        return head;
      }

      while (head)
      {
        if (head->val < x)
        {
          if (smaller) // smaller is NOT NULL
          {
            smaller ->next = head;
            smaller = smaller -> next;
          }
          else // smaller is NULL, first node
          {
            smallHead = head;
            smaller = head;
          }
        }
        else // equal or greater
        {
          if (eqORlarger) // eqORlarger is NOT NULL
          {
            eqORlarger -> next = head;
            eqORlarger = eqORlarger -> next;
          }
          else
          {
            eqORlargerHead = head;
            eqORlarger = head;
          }
        }
        head = head -> next;
      }

      if (smallHead == NULL || eqORlargerHead == NULL) // all lists values are on 1 side of input number
      {
        return (smallHead == NULL) ? eqORlargerHead:smallHead;
      }

      smaller -> next = eqORlargerHead;
      eqORlarger -> next = NULL;
      return smallHead;
    }
};

void printList(ListNode * head)
{
  while (head)
  {
    std::cout << head -> val << std::endl;
    head = head -> next;
  }
}

int main()
{
  Solution s;

  std::cout << "output value is:" << std::endl;

  ListNode * l = new ListNode(2);
  ListNode * l1 = new ListNode(1);
  ListNode * l2 = new ListNode(2);
  l -> next = l1; l1 -> next = l2;

  ListNode * out = s.partition(l, 10);

  std::cout << "output value is:" << std::endl;
  printList(out);

  return 1;
}
