/*3.6 Конструкторы 5 из 8 шагов пройдено 2 из 17 баллов  получено Задание по программированию «Строка»
 * Реализуйте класс ReversibleString, хранящий строку и поддерживающий методы Reverse для переворота строки и ToString
 * для получения строки
 */
#include <algorithm>
#include <string>

using namespace std;

class ReversibleString
{

public:
  ReversibleString() { myString = ""; }
  ReversibleString(const string &str) { myString = str; }

  void Reverse() { reverse(begin(myString), end(myString)); }
  string ToString() const { return myString; }

private:
  string myString;
};
