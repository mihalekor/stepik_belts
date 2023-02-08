/*3.4 - 3 задача
 * Задание по программированию «Имена и фамилии — 1»
Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.
https://stepik.org/lesson/284812/step/5?auth=login&unit=266156
*/

#include <map>
#include <string>
using namespace std;

//состояние first_name last_name в конкретном году, и что имено было измененно
struct NameInfo
{
  // int year;
  string first_name = "", last_name = "";
  bool is_first = 0, is_last = 0;
};

class Person
{
public:
  void ChangeFirstName(int year, const string &first_name)
  {
    // добавить факт изменения имени на first_name в год year
    history[year].first_name = first_name;
    history[year].is_first = true;
    auto it = history.find(year);

    //подгружаем предыдущий last_name
    if (it != history.begin() && !it->second.is_last)
      it->second.last_name = prev(it)->second.last_name;

    // проставляем first_name в будущем, если он еще не был ни разу изменён
    for (++it; it != history.end(); ++it)
      if (!it->second.is_first)
        it->second.first_name = first_name;
      else
        break;
  }
  void ChangeLastName(int year, const string &last_name)
  {
    // добавить факт изменения фамилии на last_name в год year
    history[year].last_name = last_name;
    history[year].is_last = true;
    auto it = history.find(year);

    //подгружаем предыдущий first_name если не первый и не меняется first_name в этом year
    if (it != history.begin() && !it->second.is_first)
      it->second.first_name = prev(it)->second.first_name;

    // проставляем last_name в будущем, если он еще не был ни разу изменён
    for (++it; it != history.end(); ++it)
      if (!it->second.is_last)
        it->second.last_name = last_name;
      else
        break;
  }
  string GetFullName(int year)
  {
    if (history.empty())
      return "Incognito";

    int _year = 0;
    // cout << year << ": ";
    //  получить имя и фамилию по состоянию на конец года year

    //попытка подветси введёный год к ближайшему в истории
    for (auto it = history.begin(); it != history.end(); ++it)
    {
      if (year == it->first)
      {
        _year = year;
        break;
      }
      if (year > prev(history.end())->first)
      {
        _year = prev(history.end())->first;
        break;
      }
      if (year > it->first)
        continue;
      else if (year < it->first)
      {
        if (it == history.begin())
          return "Incognito";
        else
        {
          _year = prev(it)->first;
          break;
        }
      }
    }

    string first_name = history[_year].first_name;
    string last_name = history[_year].last_name;

    if (!first_name.empty() && last_name.empty())
      return first_name + " with unknown last name"; //" with unknown last name"

    else if (first_name.empty() && !last_name.empty())
      return last_name + " with unknown first name"; //" with unknown first name"

    else
      return first_name + " " + last_name;
  }

private:
  // приватные поля
  map<int, NameInfo> history = {};
};
