/*
 * reverseLinkedinList.cpp
 *
 *  Created on: Jan 18, 2015
 *      Author: howard
 */

#include <iostream>
#include <stack>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

namespace reverseLinkedList
{
	class Solution
	{
	  public:
		ListNode *reverseBetween(ListNode *head, int m, int n)
		{
		  int counter = 1; // question's start is from 1
          ListNode * newHead = head;
		  stack<ListNode *> s;

		  while (head && counter < m-1) // counter will remain 1 if m = 1 or m = 2
		  {
			head = head -> next;
			counter ++;
		  }

		  // counter == m - 1 if m > 1
          ListNode * start = NULL; // in the case of m = 1, head of list will change to where node n is
		  if (m > 1)
		  {
		    start = head;
		  }
		  else // m == 1, counter = 1
		  {
	        s.push(head);
		  }

		  while (head && counter < n)
		  {
			head = head -> next;
			counter ++;
			s.push(head);
		  }

		  // counter == n
		  if (start == NULL) // special condition where m == 1
		  {
		    start = head;
		    newHead = head;
		  }
		  ListNode * end = head -> next;

		  while (!s.empty())
		  {
			start -> next = s.top();
			s.pop();
			start = start -> next;
		  }
		  start -> next = end;

		  return newHead;
		}
	};

	inline void printLinkedList(ListNode * head)
	{
	  cout << "this list is: ";
	  while (head)
	  {
	    cout << head -> val << " ";
	    head = head -> next;
	  }
	  cout << endl;
	}

	inline void trig()
	{
	  Solution * s = new Solution();

	  ListNode * n1 = new ListNode(1);
	  ListNode * n2 = new ListNode(2);
	  ListNode * n3 = new ListNode(3);
	  ListNode * n4 = new ListNode(4);
	  ListNode * n5 = new ListNode(5);
	  ListNode * n6 = new ListNode(6);

	  n1 -> next = n2; n2 -> next = n3; n3 -> next = n4; n4 ->next = n5; n5 ->next = n6;

	  printLinkedList(n1);

	  ListNode * n = s->reverseBetween(n1, 1, 6);

	  printLinkedList(n);
	  return;
	}
}
