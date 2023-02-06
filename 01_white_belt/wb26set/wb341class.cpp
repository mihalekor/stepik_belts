/*
Задание по программированию «Отсортированные строки»
Реализуйте класс, поддерживающий набор строк в отсортированном порядке. Класс должен содержать два публичных метода:
*/
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class SortedStrings
{
public:
  void AddString(const string &s)
  {
    v_str.push_back(s);
    sort(begin(v_str), end(v_str));
  }
  vector<string> GetSortedStrings() { return v_str; }

private:
  vector<string> v_str = {};
};

void PrintSortedStrings(SortedStrings &strings)
{
  for (const string &s : strings.GetSortedStrings())
  {
    cout << s << " ";
  }
  cout << endl;
}
