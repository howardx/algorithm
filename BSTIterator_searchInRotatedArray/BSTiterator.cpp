#include <iostream>
#include <unordered_map>
#include <stack>
#include "SolutionParent.h"
#include "TreeNode.h"
using namespace std;

class BSTIterator
{
  public:
	stack<TreeNode *> s;

	BSTIterator(TreeNode * root) // constructor
    {
	  while (root)
	  {
		s.push(root);
	    root = root -> left;
	  }
    }

	/** @return whether we have a next smallest number */
	bool hasNext()
	{
      return !s.empty();
	}

   /** @return the next smallest number */
	int next()
	{
      if (hasNext())
      {
    	TreeNode * nextSmallest = s.top();
    	processStack(nextSmallest);
        return nextSmallest -> val;
      }
      return -1;
	}

	void processStack(TreeNode * current)
	{
	  s.pop(); // remove current/nextSmallest, just returned

      if (current -> right)
      {
        current = current -> right;

        while(current)
        {
          s.push(current);
          current = current -> left;
        }
      }
	}

	/* only after a destructor is implemented, a vtable
	 * would be generated by compiler (if inherenting)
	 */
    ~BSTIterator() {}
};
