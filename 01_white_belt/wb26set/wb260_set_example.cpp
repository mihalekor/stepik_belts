#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

template <class T>
void PrintStlOneArg(T stl)
{
  for (auto a = stl.begin(); a != stl.end(); ++a)
  {
    cout << *a << endl;
  }
}
/*template <class T>
void PrintStl(set<T> sett)
{
  for (auto a = sett.begin(); a != sett.end(); ++a)
  {
    cout << *a << endl;
  }
}*/

int wb26set_example()
{
  cout << "Hello World2!" << endl;
  map<int, string> instr = {{1, "aa"}, {2, "bb"}};
  vector<string> str = {"“a”", "“b”"};
  set<string> ss(str.begin(), str.end()); // begin(str), end(str) ? что лучше
  PrintStlOneArg(ss);
  return 0;
}
