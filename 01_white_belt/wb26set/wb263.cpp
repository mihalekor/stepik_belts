/*2.6-3 Контейнер set
 * Задание по программированию «Синонимы»

Два слова называются синонимами друг друга, если они имеют похожие значения. Реализуйте следующие операции над словарём
синонимов:

ADD word1word2 — добавить в словарь пару синонимов (word1, word2).

COUNT word — узнать количество синонимов слова word.

CHECK word1word2 — проверить, являются ли слова word1 и word2 синонимами. Слова word1 и word2считаются синонимами, если
среди запросов ADD был хотя бы один запрос ADD word1word2 или ADD word2word1.

Замечание
Для упрощения, будем считать, что синонимы не обладают транзитивностью, то есть, если A - синоним B, а B - синоним C, то
из этого НЕ следует, что A - синоним C.

Формат ввода
Сначала вводится количество запросов Q, затем Q строк с описаниями запросов. Гарантируется, что в каждом запросе CHECK и
ADD слова word1 и word2 различны. Все слова состоят лишь из латинских букв, цифр и символов подчёркивания.

Формат вывода
Для каждого запроса в соответствующей строке выведите ответ на него:

В ответ на запрос COUNT word выведите единственное целое число — количество синонимов слова word.

В ответ на запрос CHECK word1word2 выведите строку YES, если word1 и word2 являются синонимами, и NO в противном
случае.

https://stepik.org/lesson/283172/step/9?auth=login&unit=264476
*/

#include <iostream>
#include <map>
#include <set>
using namespace std;
/*
 *
 *
8
ADD program code
COUNT cipher
ADD code cipher
COUNT code
COUNT program
CHECK code program
CHECK program cipher
CHECK cpp java

0
2
1
YES
NO
NO
--------------------
8
CHECK code program
ADD program code
ADD code cipher
CHECK program cipher
CHECK cpp java
COUNT cipher
COUNT code
COUNT program

NO
NO
NO
1
2
1
-----------------
8
ADD cipher code
ADD code program
ADD program code
CHECK code program
CHECK program code
CHECK cpp java
CHECK cipher program
CHECK program cipher

YES
YES
NO
NO
NO

*/
int main263() //_263
{
  int n;
  cin >> n;
  map<string, set<string>> map_str;
  for (int t = 0; t < n; ++t)
  {
    string cmd_str;
    cin >> cmd_str;
    if (cmd_str == "ADD")
    {
      string word1, word2;
      cin >> word1 >> word2;
      map_str[word1].insert(word2);
      map_str[word2].insert(word1);
    }
    else if (cmd_str == "COUNT")
    {
      string word;
      cin >> word;
      cout << map_str[word].size() << endl;
    }
    else if (cmd_str == "CHECK")
    {
      string word1, word2;
      cin >> word1 >> word2;
      if (map_str[word1].count(word2))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  // cout << set_str.size() << endl;
  return 0;
}
