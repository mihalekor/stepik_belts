/*3.4 Введение в структуры и классы. Часть 2
 * Задача - 2
 * Задание по программированию «Имена и фамилии — 1»
Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.
https://stepik.org/lesson/284812/step/5?auth=login&unit=266156
*/

#include <map>
#include <string>
#include <vector>
using namespace std;

//состояние first_name last_name в конкретном году, и что имено было измененно
struct NameInfo
{
  // int year;
  string first_name = "", last_name = "";
  bool is_first = 0, is_last = 0;
};

string make_brackets(const vector<string> &vectS)
{
  if (vectS.empty())
    return "";
  string res;
  bool isOpen = false;
  int i_last = vectS.size() - 1;

  res += vectS[i_last];
  for (int i = i_last - 1; i > -1; --i)
  {
    if (vectS[i] != vectS[i + 1])
    {
      if (!isOpen)
        res += " (", isOpen = true;
      else
        res += ", ";

      res += vectS[i];

      if (i == 0)
        res += ")";
    }
  }
  return res;
}

string BuildFullName(string first_name, string last_name)
{

  if (first_name.empty() && last_name.empty())
    return "Incognito";
  else if (last_name.empty())
    return first_name + " with unknown last name"; //" with unknown last name"
  else if (first_name.empty())
    return last_name + " with unknown first name"; //" with unknown first name"
  else
    return first_name + " " + last_name;
}
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
    string first_name;
    string last_name;

    for (auto &h : history)
    {
      if (h.first <= year)
      {
        first_name = h.second.first_name;
        last_name = h.second.last_name;
      }
      else
        break;
    }
    if (first_name.empty() && last_name.empty())
      return "Incognito";
    else if (last_name.empty())
      return first_name + " with unknown last name"; //" with unknown last name"
    else if (first_name.empty())
      return last_name + " with unknown first name"; //" with unknown first name"
    else
      return first_name + " " + last_name;
  }

  string GetFullNameWithHistory(int year)
  {
    // получить все имена и фамилии по состоянию на конец года year
    vector<string> all_first;
    vector<string> all_last;

    // перебираем всю историю в хронологическом порядке
    for (auto it = history.begin(); it != history.end(); ++it)
    {
      if (it->first <= year)
      {
        if (it->second.is_first)
          all_first.push_back(it->second.first_name);
        if (it->second.is_last)
          all_last.push_back(it->second.last_name);
      }
    }

    const string first_names = make_brackets(all_first);
    const string last_names = make_brackets(all_last);

    return BuildFullName(first_names, last_names);
  }

private:
  // приватные поля
  map<int, NameInfo> history = {};
};
