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

int main_PalindromFilter()
{
  vector<string> result{"abacaba",  "aba",      "weeew",    "jj",       ";;;oijij", ";;;oijij",
                        ";;;oijij", ";;;oijij", ";;;oijij", ";;;oijij", ";;;oijij", ";;;oijij"};

  for (auto w : PalindromFilter(result, 1))
    cout << w << endl;
  return 0;
}

/*Задание по программированию «Максимизатор». Напишите функцию UpdateIfGreater, которая принимает два целочисленных
   аргумента: first и second. Если first оказался больше second, Ваша функция должна записывать в second значение
   параметра first. При этом указанная функция не должна ничего возвращать, а изменение параметра second должно быть
   видно на вызывающей стороне.
*/
void UpdateIfGreater(int first, int &second)
{
  if (first > second)
    second = first;
}

/*Задание по программированию «Перемещение строк»
Напишите функцию MoveStrings, которая принимает два вектора строк, source и destination, и дописывает все строки из
первого вектора в конец второго. После выполнения функции вектор source должен оказаться пустым. Чтобы очистить
содержимое вектора, надо вызвать у него метод clear:*/
void MoveStrings(vector<string> &source, vector<string> &destination)
{
  for (auto s : source)
    destination.push_back(s);
  source.clear();
}

int main_MoveStrings()
{
  vector<string> source = {"123", "345"};
  vector<string> destination = {""};

  MoveStrings(source, destination);

  for (auto d : destination)
  {
    cout << d << " " << endl;
  }

  return 0;
}

/*Задание по программированию «Разворот последовательности» Реализуйте функцию void Reverse(vector<int>& v), которая
 * переставляет элементы вектора в обратном порядке.*/

void Reverse(vector<int> &v)
{
  for (size_t beg = 0, end = v.size() - 1; beg < v.size() / 2; ++beg, --end)
  {
    int temp = v[beg];
    v[beg] = v[end];
    v[end] = temp;
  }
}

/*Задание по программированию «Разворот последовательности 2»
 * Реализуйте функцию vector<int> Reversed(const vector<int>& * v), возвращающую копию вектора v, в которой числа
 * переставлены в обратном порядке.*/
vector<int> Reversed(const vector<int> &v)
{
  vector<int> result = v;
  for (size_t beg = 0, end = result.size() - 1; beg < result.size() / 2; ++beg, --end)
  {
    int temp = result[beg];
    result[beg] = result[end];
    result[end] = temp;
  }
  return result;
}

int main()
{
  vector<int> vvv = {1, 2};
  Reversed(vvv);
  for (auto d : vvv)
  {
    cout << d << " ";
  }
}
