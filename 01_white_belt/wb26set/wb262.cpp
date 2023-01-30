/*
Задание по программированию «Множество значений словаря»


Напишите функцию BuildMapValuesSet, принимающую на вход словарь map<int, string> и возвращающую множество значений этого
словаря:

set<string> BuildMapValuesSet(const map<int, string>& m) {
  // ...
}


Пример
Код

set<string> values = BuildMapValuesSet({
    {1, "odd"},
    {2, "even"},
    {3, "odd"},
    {4, "even"},
    {5, "odd"}
});

for (const string& value : values) {
  cout << value << endl;
}


Вывод

even
odd
*/

#include <iostream>
#include <set>

set<string> BuildMapValuesSet(const map<int, string> &m)
{
  set<string> set_out;
  for (const auto &s : m)
    set_out.insert(s.second);
  return set_out;
}
