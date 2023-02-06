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
