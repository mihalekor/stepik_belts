/*
3.1 Алгоритмы - 2
Задание по программированию
«Сортировка без учёта регистра»

Условие
В стандартном потоке дана одна строка, состоящая из числа N и следующих за ним N строк S. Между собой число и строки
разделены пробелом.

Отсортируйте строки S в лексикографическом порядке по возрастанию, игнорируя регистр букв, и выведите их в стандартный
поток вывода.

Ограничения
0 <= N <= 1000

1 <= |S| <= 15

Каждая строка S[i] может состоять из следующих символов: [0-9,a-z,A-Z]*/

#include <algorithm>
#include <iostream>
#include <locale>
#include <string>
#include <vector>
// tolower
using namespace std;

/*

2 q A
A q

3 a C b
a b C

4 AaBbcCdd ab a BB
a ab AaBbcCdd BB

11 ABcd abCD abc abcd s a abs A AA Bb BBB
a A AA abc ABcd abCD abcd abs Bb BBB s
*/

int main312()
{
  int n;
  vector<string> vector_n;

  cin >> n;

  for (int var = 0; var < n; ++var)
  {
    string str;
    cin >> str;
    vector_n.push_back(str);
  }

  sort(begin(vector_n), end(vector_n),
       [](string a, string b)
       {
         int m_size = min(a.size(), b.size());
         for (int var = 0; var < m_size; ++var)
         {
           if (tolower(a[var]) == tolower(b[var]))
             continue;
           else if (tolower(a[var]) < tolower(b[var]))
             return true;
           else
             return false;
         }

         return a.size() < b.size();
       });

  for (const auto &v : vector_n)
    cout << v << " ";

  return 0;
}
