/*
Тренировка инициализации классво и структур
*/

class Incognizable
{
public:
  int _a = 0, _b = 1, _c = 2;
  Incognizable(){};
  Incognizable(int a) : _a(a){};
  Incognizable(int a, int b) : _a(a), _b(b){};
};

struct Incognizable2
{
  int _a = 0, _b = 1, _c = 2;
  Incognizable2(){};
  Incognizable2(int a) : _a(a){};
  Incognizable2(int a, int b) : _a(a), _b(b){};
};
