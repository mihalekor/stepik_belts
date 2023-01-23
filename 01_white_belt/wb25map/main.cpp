#include <iostream>
#include <map>
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
int main()
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
