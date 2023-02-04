#include "wb260_set_example.cpp"
#include "wb261_uniq_str.cpp"
#include "wb262.cpp"
#include "wb263.cpp"
#include "wb264.cpp"
#include "wb310.cpp"
#include "wb311sort.cpp"
#include "wb312sort.cpp"
#include <iostream>

using namespace std;

int main()
{

  set<string> values = BuildMapValuesSet({{1, "odd"}, {2, "even"}, {3, "odd"}, {4, "even"}, {5, "odd"}});

  for (const string &value : values)
  {
    cout << value << endl;
  }

  cout << "main310:" << endl;
  main312();
  return 0;
}
