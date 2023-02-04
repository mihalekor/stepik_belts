/*
Задание по программированию
«Сортировка целых чисел по модулю»


Условие
В стандартном потоке дана одна строка, состоящая из N + 1 целых чисел. Первым числом идёт само число N. Далее следуют
ещё N чисел, обозначим их за массив A. Между собой числа разделены пробелом.

Отсортируйте массив А по модулю и выведите его в стандартный поток.

Ограничения
0 <= N <= 1000

-1000000 <= A[i] <= 1000000
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//первая рабочая версия, проверку прошла
int main311()
{
  int n;
  vector<pair<int, bool>> vector_n;

  cin >> n;

  for (int var = 0; var < n; ++var)
  {
    int t, isMore = true;
    cin >> t;
    if (t < 0)
    {
      isMore = false;
      t *= -1;
    }
    vector_n.push_back(make_pair(t, isMore));
  }

  sort(begin(vector_n), end(vector_n));

  for (const auto &v : vector_n)
  {
    if (!v.second)
      cout << "-";
    cout << v.first << " ";
  }

  cout << endl;

  return 0;
}

//вторая версия через лямбду
int main311sort()
{
  int n;
  vector<int> vector_n;

  cin >> n;

  for (int var = 0; var < n; ++var)
  {
    int t;
    cin >> t;
    vector_n.push_back(t);
  }

  sort(begin(vector_n), end(vector_n),
       [](int a, int b)
       {
         if (a < 0) //#include <algorithm> : abs(a);
           a *= -1;
         if (b < 0)
           b *= -1;

         return a < b;
       });

  for (const auto &v : vector_n)
    cout << v << " ";

  return 0;
}
