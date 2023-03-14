/*
4.1 Структуры и классы: примеры
Задача 2
Задание по программированию «Обратимая функция»

Реализуйте рассказанный на лекции класс Function, позволяющий создавать, вычислять и инвертировать функцию, состоящую из
следующих элементарных операций: прибавить вещественное число x; вычесть вещественное число x. При этом необходимо
объявить константными все методы, которые по сути такими являются.

Пример
Код
----------------------------------------------------------
struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('-', image.freshness * params.a + params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 46) << endl;
  return 0;
}
----------------------------------------------------------
Вывод

36
20
*/

#include <vector>
using namespace std;

class FuctionPart
{
public:
  char _operation;
  double _operand;

  FuctionPart(char operation, double operand) : _operation(operation), _operand(operand) {}
  double Apply(double source_value) const
  {
    if (_operation == '+')
      return source_value + _operand;
    else
      return source_value - _operand;
  }

  void Invert()
  {
    if (_operation == '+')
      _operation = '-';
    else
      _operation = '+';
  }
};
class Function
{
public:
  void AddPart(char operation, double operand) { parts.push_back({operation, operand}); }
  double Apply(double source_value) const
  {

    for (auto i : parts)
      source_value = i.Apply(source_value);
    return source_value;
  };
  void Invert()
  {
    for (auto &i : parts)
      i.Invert();

    reverse(begin(parts), end(parts));
  }

private:
  vector<FuctionPart> parts;
};

namespace wb412
{

struct Image
{
  double quality;
  double freshness;
  double rating;
};

struct Params
{
  double a;
  double b;
  double c;
};

Function MakeWeightFunction(const Params &params, const Image &image)
{
  Function function;
  function.AddPart('-', image.freshness * params.a + params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params &params, const Image &image)
{
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params &params, const Image &image, double weight)
{
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}
} // namespace wb412
