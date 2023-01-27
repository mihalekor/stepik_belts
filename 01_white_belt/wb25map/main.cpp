#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

template <class T1, class T2>
void PrintMap(map<T1, T2> myMap)
{
  for (const auto &m : myMap)
    cout << "first " << m.first << " second " << m.second << endl;
}

template <class T1>
void PrintVector(vector<T1> myVector)
{
  for (const auto &m : myVector)
    cout << m << endl;
}

/*Функция BuildReversedMap возвращает «перевёрнутый» словарь, в котором ключами являются значения переданного словаря, а
 * значениями — соответствующие ключи*/
map<string, bool> BuildReversedMap(const map<bool, string> &m)
{
  map<string, bool> result;
  for (const auto &item : m)
  {
    result[item.second] = item.first;
  }
  return result;
}

int main_exemple()
{
  vector<int> myVector{1, 2, 3, 4};
  myVector[0]++;
  PrintVector(myVector);

  map<int, string> events;
  events[1950] = "Bjarne Stroudtrup`s birth";
  events[1941] = "Dennis Retchie`s birth";

  cout << events[1950] << endl;
  PrintMap(events);
  return 0;
}

/*2.5 - 1:Задание по программированию «Анаграммы»

Слова называются анаграммами друг друга, если одно из них можно получить перестановкой букв в другом. Например, слово
«eat» можно получить перестановкой букв слова «tea», поэтому эти слова являются анаграммами друг друга. Даны пары слов,
проверьте для каждой из них, являются ли слова этой пары анаграммами друг друга.
Указание
Один из способов проверки того, являются ли слова анаграммами друг друга, заключается в следующем. Для каждого слова с
помощью словаря подсчитаем, сколько раз в нём встречается каждая буква. Если для обоих слов эти словари равны (а это
проверяется с помощью обычного оператора ==), то слова являются анаграммами друг друга, в противном случае не являются.
При этом построение такого словаря по слову удобно вынести в отдельную функцию BuildCharCounters.
Формат ввода
Сначала дано число пар слов N, затем в N строках содержатся пары слов, которые необходимо проверить. Гарантируется, что
все слова состоят лишь из строчных латинских букв.
Формат вывода
Выведите N строк: для каждой введённой пары слов YES, если эти слова являются анаграммами, и NO в противном случае.
https://stepik.org/lesson/283171/step/8?auth=login&unit=264475
*/
int main_anagrama()
{
  int n;
  cin >> n;
  for (int t = 0; t < n; ++t)
  {
    map<char, int> map1, map2;
    string s1, s2;
    cin >> s1 >> s2;

    for (auto s : s1)
      ++map1[s];
    for (auto s : s2)
      ++map2[s];

    if (map1 == map2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

/*2.5 - 2:Задание по программированию «Справочник столиц»
Реализуйте справочник столиц стран.

На вход программе поступают следующие запросы:

CHANGE_CAPITAL country new_capital — изменение столицы страны country на new_capital, либо добавление такой страны с
такой столицей, если раньше её не было.

RENAME old_country_name new_country_name — переименование страны из old_country_name в new_country_name.

ABOUT country — вывод столицы страны country.

DUMP — вывод столиц всех стран.

Формат ввода
В первой строке содержится количество запросов Q, в следующих Q строках — описания запросов. Все названия стран и столиц
состоят лишь из латинских букв, цифр и символов подчёркивания.

Формат вывода
Выведите результат обработки каждого запроса:

В ответ на запрос CHANGE_CAPITAL country new_capital выведите
Introduce new country country with capital new_capital, если страны country раньше не существовало;

Country country hasn't changed its capital, если страна country до текущего момента имела столицу new_capital;

Country country has changed its capital from old_capital to new_capital, если страна country до текущего момента имела
столицу old_capital, название которой не совпадает с названием new_capital.

В ответ на запрос RENAME old_country_name new_country_name выведите
Incorrect rename, skip, если новое название страны совпадает со старым, страна old_country_name не существует или страна
new_country_name уже существует;

Country old_country_name with capital capital has been renamed to new_country_name, если запрос корректен и страна имеет
столицу capital.

В ответ на запрос ABOUT country выведите
Country country doesn't exist, если страны с названием country не существует;

Country country has capital capital, если страна country существует и имеет столицу capital.

В ответ на запрос DUMP выведите
There are no countries in the world, если пока не было добавлено ни одной страны;

последовательность пар вида country/capital, описывающую столицы всех стран, если в мире уже есть хотя бы одна страна.
При выводе последовательности пары указанного вида необходимо упорядочить по названию страны и разделять между собой
пробелом.*/

int main_country_capital()
{
  int n, sum = 0, num = 0; //кол-во элем, сумма все элем, среднее знач
  cin >> n;
  map<string, string> map1;

  for (int i = 0; i < n; ++i)
  {
    string cmd_s;
    cin >> cmd_s;

    if (cmd_s == "CHANGE_CAPITAL")
    {
      string country, new_capital;
      cin >> country >> new_capital;

      if (map1.count(country) == 0)
      {
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
        map1[country] = new_capital;
      }
      else
      {
        if (map1[country] == new_capital)
          cout << "Country " << country << " hasn't changed its capital" << endl;
        else
        {
          cout << "Country " << country << " has changed its capital from " << map1[country] << " to " << new_capital
               << endl;
          map1[country] = new_capital;
        }
      }

      map1[country] = new_capital;
    }
    else if (cmd_s == "RENAME")
    {
      string old_country_name, new_country_name;
      cin >> old_country_name >> new_country_name;
      if (new_country_name == old_country_name || map1.count(old_country_name) == 0 ||
          map1.count(new_country_name) == 1)
        cout << "Incorrect rename, skip" << endl;
      else
      {
        string temp_capital = map1[old_country_name];
        if (!temp_capital.empty())
        {
          map1.erase(old_country_name);
          map1[new_country_name] = temp_capital;
          cout << "Country " << old_country_name << " with capital " << temp_capital << " has been renamed to "
               << new_country_name << endl;
        }
      }
    }
    else if (cmd_s == "ABOUT")
    {
      string country;
      cin >> country;
      if (map1.count(country) == 0)
        cout << "Country " << country << " doesn't exist" << endl;
      else
        cout << "Country " << country << " has capital " << map1[country] << endl;
    }
    else if (cmd_s == "DUMP")
    {
      if (!map1.empty())
      {
        // country/capital
        for (const auto &m : map1)
          cout << m.first << "/" << m.second << " ";
      }
      else
      {
        cout << "There are no countries in the world";
      }
      cout << endl;
    }
  }
  return 0;
}

/*
2.5 Контейнер map - Задача 3:
Задание по программированию «Автобусные остановки — 1»


Реализуйте систему хранения автобусных маршрутов. Вам нужно обрабатывать следующие запросы:

NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и stop_countостановками с названиями
stop1, stop2, ...

BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.

STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов, на которые можно пересесть на
каждой из остановок.

ALL_BUSES — вывести список всех маршрутов с остановками.

Формат ввода
В первой строке ввода содержится количество запросов Q, затем в Q строках следуют описания запросов.

Гарантируется, что все названия маршрутов и остановок состоят лишь из латинских букв, цифр и знаков подчёркивания.

Для каждого запроса NEW_BUS bus stop_count stop1 stop2 ... гарантируется, что маршрут bus отсутствует, количество
остановок больше 0, а после числа stop_count следует именно такое количество названий остановок, причём все названия в
каждом списке различны.

Формат вывода
Для каждого запроса, кроме NEW_BUS, выведите соответствующий ответ на него:

На запрос BUSES_FOR_STOP stop выведите через пробел список автобусов, проезжающих через эту остановку, в том порядке, в
котором они создавались командами NEW_BUS. Если остановка stop не существует, выведите No stop.

На запрос STOPS_FOR_BUS bus выведите описания остановок маршрута bus в отдельных строках в том порядке, в котором они
были заданы в соответствующей команде NEW_BUS. Описание каждой остановки stop должно иметь вид Stop stop: bus1 bus2 ...,
где bus1 bus2 ... — список автобусов, проезжающих через остановку stop, в порядке, в котором они создавались командами
NEW_BUS, за исключением исходного маршрута bus. Если через остановку stop не проезжает ни один автобус, кроме bus,
вместо списка автобусов для неё выведите no interchange. Если маршрут bus не существует, выведите No bus.

На запрос ALL_BUSES выведите описания всех автобусов в алфавитном порядке. Описание каждого маршрута bus должно иметь
вид Bus bus: stop1 stop2 ..., где stop1 stop2 ... — список остановок автобуса bus в порядке, в котором они были заданы в
соответствующей команде NEW_BUS. Если автобусы отсутствуют, выведите No buses.

Предупреждение
Условие задачи выше содержит много важных деталей. Если вы не уверены в том, что не упустили ни одной, перечитайте
условие ещё раз.*/

int main_bus_stop()
{
  int n; //кол-во команд
  cin >> n;
  map<string, vector<string>> bus_stop,
      stop_bus; //словари маршрут/остановки, остановка/какие маршруты через неё проходят

  for (int i = 0; i < n; ++i)
  {
    string cmd_s;
    cin >> cmd_s;

    if (cmd_s == "NEW_BUS") //заполняем словари
    {
      string bus, stop;
      cin >> bus;
      int count;
      cin >> count;
      for (int var = 0; var < count; ++var)
      {
        cin >> stop;
        bus_stop[bus].push_back(stop);
        stop_bus[stop].push_back(bus);
      }
    }
    else if (cmd_s == "BUSES_FOR_STOP") //выводим маршруты для остановки stop
    {
      string stop;
      cin >> stop;
      if (stop_bus.count(stop))
        for (auto b : stop_bus[stop])
          cout << b << " ";
      else
        cout << "No stop";
      cout << endl;
    }
    else if (cmd_s == "STOPS_FOR_BUS") //для маршрутв выводим остановки и куда можно пересесть на каждой
    {
      string bus;
      cin >> bus;

      if (bus_stop.count(bus))
      {
        for (auto s : bus_stop[bus])
        {
          cout << "Stop " << s << ": ";
          if (stop_bus[s].size() > 1)
          {
            for (auto b : stop_bus[s])
            {
              if (b == bus)
                continue;
              cout << b << " ";
            }
            cout << endl;
          }
          else
            cout << "no interchange" << endl;
        }
      }
      else
        cout << "No bus" << endl;
    }
    else if (cmd_s == "ALL_BUSES") // выводим все маршруты с остановками
    {
      if (!bus_stop.empty())
        for (auto b : bus_stop)
        {
          cout << "Bus " << b.first << ": ";
          for (auto s : b.second)
            cout << s << " ";
          cout << endl;
        }
      else
        cout << "No buses" << endl;
    }
  }
  return 0;
}

/*
2.5 Контейнер map - Задача 4
Задание по программированию «Автобусные остановки — 2»


В этой задаче вам нужно присваивать номера автобусным маршрутам.

А именно, для каждого маршрута, заданного набором названий остановок, нужно либо выдать новый номер (первому маршруту —
1, второму — 2 и т. д.), либо вернуть номер существующего маршрута, которому соответствует такой набор остановок.

Наборы остановок, полученные друг из друга перестановкой остановок, считаются различными (см. пример).

Указание
В C++ ключом словаря может быть не только число или строка, но и другой контейнер, например, vector.

Формат ввода
Сначала вводится количество запросов Q, затем Q описаний запросов.

Каждый запрос представляет собой положительное количество остановок N, за которым следуют разделённые пробелом N
различных названий остановок соответствующего маршрута. Названия остановок состоят лишь из латинских букв и символов
подчёркивания.

Формат вывода
Выведите ответ на каждый запрос в отдельной строке.

Если маршрут с данным набором остановок уже существует, в ответ на соответствующий запрос выведите Already exists for i,
где i — номер маршрута с таким набором остановок. В противном случае нужно выделить введённому набору остановок новый
номер i и вывести его в формате New bus i.
*/

int main()
{
  int count_bus = 0, cmd_n; //счётчик маршрутов, кол-во команд
  cin >> cmd_n;
  map<vector<string>, int> Bus_num; //словарь маршрут/его порядковый номер

  for (int i = 0; i < cmd_n; ++i)
  {
    int cmd_stop;
    cin >> cmd_stop;
    vector<string> bus_cmd; //остановки маршрута
    for (int var = 0; var < cmd_stop; ++var)
    {
      string str;
      cin >> str;
      bus_cmd.push_back(str);
    }
    if (Bus_num.count(bus_cmd))
      cout << "Already exists for " << Bus_num[bus_cmd] << endl;
    else
    {
      Bus_num[bus_cmd] = ++count_bus;
      cout << "New bus " << count_bus << endl;
    }
  }
  return 0;
}
