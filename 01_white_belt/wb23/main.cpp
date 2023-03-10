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
int main_is_nervous()
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

/*-------------------------------------------------------------*/
/*
2.3 - 3
Задание по программированию «Ежемесячные дела»

У каждого из нас есть повторяющиеся ежемесячные дела, каждое из которых нужно выполнять в конкретный день каждого
месяца: оплата счетов за электричество, абонентская плата за связь и пр. Вам нужно реализовать работу со списком таких
дел на месяц, а именно, реализовать набор следующих операций:
ADD i s
Назначить дело с названием s на день i текущего
месяца.
DUMP i
Вывести все дела, запланированные на день i текущего месяца.
NEXT
Перейти к списку дел на новый месяц.
При выполнении данной команды вместо текущего (старого) списка дел на текущий месяц создаётся и становится активным
(новый) список дел на следующий месяц: все дела со старого списка дел копируются в новый список. После выполнения данной
команды новый список дел и следующий месяц становятся текущими, а работа со старым списком дел прекращается. При
переходе к новому месяцу необходимо обратить внимание на разное количество дней в месяцах: если следующий месяц имеет
больше дней, чем текущий, «дополнительные» дни необходимо оставить пустыми (не содержащими дел); если следующий месяц
имеет меньше дней, чем текущий, меньше дней, дела со всех «лишних» дней необходимо переместить на последний день
следующего месяца.

Замечания
Историю списков дел хранить не требуется, работа ведется только с текущим списком дел
текущего месяца. Более того, при создании списка дел на следующий месяц, он «перетирает» предыдущий список. Обратите
внимание, что количество команд NEXT в общей последовательности команд при работе со списком дел может превышать 11.
Начальным текущим месяцем считается январь.Количества дней в месяцах соответствуют Григорианскому календарю с той лишь
разницей, что в феврале всегда 28 дней.

Формат ввода
Сначала число операций Q, затем описания операций.
Названия дел s уникальны и состоят только из латинских букв, цифр и символов подчёркивания. Номера дней iявляются целыми
числами и нумеруются от 1 до размера текущего месяца. Формат вывода Для каждой операции типа DUMP в отдельной строке
выведите количество дел в соответствующий день, а затем их названия, разделяя их пробелом. Порядок вывода дел в рамках
каждой операции значения не имеет.
*/

// глобальные (доступные во всей программе) константы
// часто принято называть ЗАГЛАВНЫМИ_БУКВАМИ
const vector<int> MONTH_LENGTHS = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int MONTH_COUNT = MONTH_LENGTHS.size();

int main()
{

  int n; //ввод команды, ввод дела
  cin >> n;

  // номер текущего месяца (от 0 до 11)
  int month = 0;

  vector<vector<string>> deals(MONTH_LENGTHS[month]);
  // int month_now=monthes[current_m];
  for (int i = 0; i < n; ++i)
  {
    string in_cmd;
    cin >> in_cmd;
    if (in_cmd == "NEXT")
    {
      int current_m, next_m;
      current_m = MONTH_LENGTHS[month];
      month = ++month % MONTH_COUNT;
      next_m = MONTH_LENGTHS[month];
      if (current_m > next_m)
      {
        vector<string> &last_day = deals[next_m - 1];
        for (int k = next_m; k < current_m; ++k)
          last_day.insert(end(last_day), begin(deals[k]), end(deals[k]));
      }
      deals.resize(next_m);
    }
    else if (in_cmd == "ADD")
    {
      int in_day;
      string in_deal;
      cin >> in_day;
      cin >> in_deal;
      deals[in_day - 1].push_back(in_deal);
    }
    else if (in_cmd == "DUMP")
    {
      int in_day;
      cin >> in_day;
      cout << deals[in_day - 1].size() << " ";

      for (auto ds : deals[in_day - 1])
        cout << ds << " ";

      cout << endl;
    }
  }

  return 0;
}
