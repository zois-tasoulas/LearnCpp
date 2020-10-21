#include <algorithm>
#include <array>
#include <iostream>
#include <string>

struct Season
{
  std::string name{};
  double averageTemperature{};
};

int main()
{
  std::array<Season, 4> seasons{
    { { "Spring", 285.0 },
      { "Summer", 296.0 },
      { "Fall", 288.0 },
      { "Winter", 263.0 } }
  };

    auto compareTemperature {
        [](const Season &a, const Season &b) -> bool {
            return a.averageTemperature < b.averageTemperature;
    } };

    std::sort(seasons.begin(), seasons.end(), compareTemperature);

  for (const auto& season : seasons)
  {
    std::cout << season.name << '\n';
  }

  return 0;
}
