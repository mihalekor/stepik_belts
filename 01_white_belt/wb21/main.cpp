#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

/*
Задание по программированию «Факториал»
Напишите функцию, которая:
называется Factorial возвращает int принимает int и возвращает факториал своего аргумента. Гарантируется, что аргумент
функции по модулю не превышает 10. Для отрицательных аргументов функция должна возвращать 1.
https://stepik.org/lesson/283169/step/3?auth=login&unit=264473
*/
int Factorial(int f)
{
  if (f < 2)
    return 1;
  return f * Factorial(f - 1);
}

/*
Задание по программированию «Палиндром»
Напишите функцию, которая называется IsPalindrom
возвращает bool принимает параметр типа string и возвращает, является ли переданная строка палиндромом
Палиндром - это слово или фраза, которые одинаково читаются слева направо и справа налево. Пустая строка является
палиндромом.
*/

bool IsPalindrom(string str)
{
  int size = str.size() - 1;
  for (int beg = 0, end = size; beg <= size / 2; ++beg, --end)
    if (str[beg] != str[end])
      return false;
  return true;
}

/*
Задание по программированию «Отбор палиндромов»
Напишите функцию, которая называется PalindromFilter возвращает vector<string> принимает vector<string> words и int
minLength и возвращает все строки из вектора words, которые являются палиндромами и имеют длину не меньше minLength
Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.
*/
vector<string> PalindromFilter(vector<string> words, int minLength)
{
  auto start = steady_clock::now();
  vector<string> result;
  for (auto w : words)
  {
    if (IsPalindrom(w) && w.size() >= minLength)
      result.push_back(w);
  }
  auto finish = steady_clock::now();
  cout << duration_cast<microseconds>(finish - start).count() << " ms" << endl;
  return result;
}

int main()
{
  vector<string> result{"abacaba",  "aba",      "weeew",    "jj",       ";;;oijij", ";;;oijij",
                        ";;;oijij", ";;;oijij", ";;;oijij", ";;;oijij", ";;;oijij", ";;;oijij"};

  for (auto w : PalindromFilter(result, 1))
    cout << w << endl;
  return 0;
}
