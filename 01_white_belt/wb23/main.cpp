#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
void PrintVector(vector<T> v)
{
  int i = 0;
  for (auto s : v)
  {
    cout << i << " : " << s << endl;
    ++i;
  }
}

int main_exempl()
{
  int n;
  cin >> n;
  vector<string> v(n);
  for (auto &s : v)
    cin >> s;

  PrintVector(v);
  return 0;
}

/*
2.3 - 1
Задание по программированию «Средняя температура»
Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней. Найдите номера дней (в нумерации с нуля) со
значением температуры выше среднего арифметического за все N дней. Гарантируется, что среднее арифметическое значений
температуры является целым числом.
Формат ввода
Вводится число N, затем N неотрицательных целых чисел — значения
температуры в 0-й, 1-й, ... (N−1)-й день.
Формат вывода
Первое число K — количество дней, значение температуры в которых
выше среднего арифметического. Затем Kцелых чисел — номера этих дней.
https://stepik.org/lesson/283763/step/5?auth=login&unit=265062
*/
int main_average()
{
  int n, sum = 0, avrg = 0; //кол-во элем, сумма все элем, среднее знач
  cin >> n;

  vector<int> vect(n);
  vector<int> result;
  for (auto &v : vect)
  {
    cin >> v;
    sum += v;
  }
  if (n)
    avrg = sum / n;

  for (int i = 0; i < vect.size(); ++i)
  {
    if (vect[i] > avrg)
      result.push_back(vect[i]); // cout << i << " ";
  }

  cout << result.size() << endl;

  for (int i = 0; i < vect.size(); ++i)
  {
    if (vect[i] > avrg)
      cout << i << " ";
  }

  return 0;
}

/*
2.3 - 2
Задание по программированию «Очередь»
Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить в конец и уходить оттуда. Более того,
иногда некоторые люди могут прекращать и начинать беспокоиться из-за того, что очередь не продвигается. Реализуйте
обработку следующих операций над очередью:
WORRY i: пометить i-го человека с начала очереди (в нумерации с 0) как
беспокоящегося;
QUIET i: пометить i-го человека как успокоившегося;
COME k: добавить k спокойных человек в конец
очереди;
COME -k: убрать k человек из конца очереди;
WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
Изначально очередь пуста.
*/
int main()
{
  int n, sum = 0, num = 0; //кол-во элем, сумма все элем, среднее знач
  cin >> n;
  vector<bool> is_nervous;
  string cmd_s;

  for (int i = 0; i < n; ++i)
  {
    cin >> cmd_s;
    if (cmd_s == "WORRY_COUNT")
    {
      // подсчитываем количество элементов в векторе is_nervous, равных true
      cout << count(begin(is_nervous), end(is_nervous), true) << endl;
    }
    else
      cin >> num;

    if (cmd_s == "WORRY" || cmd_s == "QUIET")
      is_nervous[num] = cmd_s == "WORRY";
    else if (cmd_s == "COME")
      is_nervous.resize(is_nervous.size() + num, false);
  }

  return 0;
}
