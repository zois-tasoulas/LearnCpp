#include <algorithm>
#include <array>
#include <iostream>

struct Student
{
    std::string name {};
    int points {};
};

int main()
{
    std::array<Student, 8> arr{
    { { "Albert", 3 },
      { "Ben", 5 },
      { "Christine", 2 },
      { "Dan", 8 }, // Dan has the most points (8).
      { "Enchilada", 4 },
      { "Francis", 1 },
      { "Greg", 3 },
      { "Hagrid", 5 } }
    };

    auto compareStudents { [](const Student &a, const Student &b) -> bool {
        return a.points < b.points ;
    } };

    const auto bestStudent {std::max_element(arr.begin(), arr.end(), compareStudents)};
    if (bestStudent == arr.end()) {
        std::cout << "Error, the students list was empty.\n";
    } else {
        std::cout << bestStudent->name << " is the best student\n";
    }
    return 0;
}
