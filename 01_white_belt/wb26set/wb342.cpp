/*Задание по программированию «Имена и фамилии — 1»
Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.
https://stepik.org/lesson/284812/step/5?auth=login&unit=266156
*/

#include <map>
#include <string>
using namespace std;
class Person
{
public:
  void ChangeFirstName(int year, const string &first_name)
  {
    // добавить факт изменения имени на first_name в год year
    history[year].first = first_name;
    auto it = history.find(year);
    for (++it; it != history.end(); ++it)
      if (it->second.first.empty())
        it->second.first = first_name;
      else
        break;
  }
  void ChangeLastName(int year, const string &last_name)
  {
    // добавить факт изменения фамилии на last_name в год year
    history[year].second = last_name;
    auto it = history.find(year);
    for (++it; it != history.end(); ++it)
      if (it->second.second.empty())
        it->second.second = last_name;
      else
        break;
  }
  string GetFullName(int year)
  {
    // получить имя и фамилию по состоянию на конец года year
    if (history.count(year))
    {
      string first_name = history[year].first;
      string last_name = history[year].second;

      if (!first_name.empty() && last_name.empty())
        return first_name + " with unknown last name";

      else if (first_name.empty() && !last_name.empty())
        return last_name + " with unknown first name";

      else
        return first_name + last_name;
    }
    else
      return "Incognito";
  }

private:
  // приватные поля
  map<int, pair<string, string>> history = {};
};
