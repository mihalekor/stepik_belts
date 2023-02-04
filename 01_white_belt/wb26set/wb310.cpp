#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

void PrintV(const vector<int> &v, const string &title)
{
  cout << title << ": ";
  for (auto i : v)
  {
    cout << i << ' ';
  }
}

int main310()
{
  cout << min(2, 3) << endl;
  cout << max(2, 3) << endl;

  string s1 = "abc";
  string s2 = "bca";
  cout << min(s1, s2) << endl;
  cout << max(s1, s2) << endl;

  vector<int> v = {1, 3, 2, 5, 4};
  PrintV(v, "init");
  sort(begin(v), end(v));
  cout << endl;
  PrintV(v, "sort");

  vector<int> v2 = {1, 3, 2, 5, 4};
  cout << count(begin(v2), end(v2), 2);

  return 0;
}
