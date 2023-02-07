#include "wb260_set_example.cpp"
#include "wb261_uniq_str.cpp"
#include "wb262.cpp"
#include "wb263.cpp"
#include "wb264.cpp"
#include "wb310.cpp"
#include "wb311sort.cpp"
#include "wb312sort.cpp"
#include "wb341class.cpp"
#include "wb342.cpp"

#include <iostream>

using namespace std;

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89

int fib(int n)
{
  if (n < 1)
    return 0;
  int a = 1, b = 0, t;
  for (int var = 0; var < n; ++var)
  {
    t = a;
    a = a + b;
    b = t;
  }
  return a;
};

/*
1	1
2	2
3	6
4	24
5	120
6	720
7	5040
8	40320
9	362880
10	3628800
*/

int fact(int n)
{
  int res = 1;
  for (int i = 1; i < n + 1; ++i)
  {
    res = res * i;
  }
  return res;
}

int main_f()
{
  for (int var = 0; var < 10; ++var)
  {
    cout << fib(var) << " ";
  }
  cout << endl;
  for (int var = 0; var < 10; ++var)
  {
    cout << fact(var) << " ";
  }

  return 0;
}

template <class T>
void printStlOne(T forPrint)
{
  for (const auto &p : forPrint)
    cout << p << " ";
  cout << endl;
}

int main_wb341class()
{
  SortedStrings strings;

  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);

  strings.AddString("second");
  PrintSortedStrings(strings);

  strings.AddString("Second");
  strings.AddString("123");
  strings.AddString("3");
  strings.AddString("S");
  PrintSortedStrings(strings);

  return 0;
}

int main()
{
  Person person;
  cout << "1111111111111111111111111111" << endl;
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970, 1971})
  {
    cout << person.GetFullName(year) << endl;
  }

  cout << "2222222222222222222222222222" << endl;
  person.ChangeFirstName(1965, "Polina");
  for (int year : {1900, 1965, 1966, 1967, 1990})
  {
    cout << person.GetFullName(year) << endl;
  }

  cout << "3333333333333333333333333333" << endl;
  person.ChangeLastName(1964, "Volkova");
  for (int year : {1965, 1967, 1968, 1969, 1970, 1971})
  {
    cout << person.GetFullName(year) << endl;
  }
  /*cout << "4444444444444444444444444444" << endl;
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1966, 1967, 1968, 1970, 1990})
  {
    cout << person.GetFullName(year) << endl;
  }*/

  return 0;
}

int main_()
{
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990})
  {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970})
  {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970})
  {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}
