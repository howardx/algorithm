#include <iostream>
#include <vector>

// making vector size hadware independent
typedef vector<int>::size_type size; 

istream & buildList(istream & in, vector<int> vec)
{
  if(in)
  {
    vec.clear(); // get rid of previous contents -- initialization
    int x;
    while(in >> x)
    {
      vec.push_back(x);
    }
    in.clear(); // clear the stream for potential next call
  }
  return in;
}

void quickSort(vector<int> & vec)
{
  int * left =  vec.get(0);
  int * right = vec.get(vec.size()-1);
  int * median = vec.get((vec.size()-1)/2);
}

int main()
{
  vector<int> vec; // initialization of new empty vector
  buildList(cin, vec)
  quickSort(vec);
  for ( size i = 0; i != vec.size(); i++)
  {
    cout << vec.get(i) << " ";
  }
  return 0;
}
