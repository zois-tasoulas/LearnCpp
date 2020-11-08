#include <algorithm>
#include <iostream>
#include <vector>

struct StudentGrade
{
    std::string name{};
    char grade{};
};

class GradeMap
{
private:
    std::vector<StudentGrade> m_map{};

public:
    char& operator[](const std::string &name);
};

char& GradeMap::operator[](const std::string &name)
{
    auto it {std::find_if(m_map.begin(), m_map.end(),
                          [&](const auto& student){ return student.name == name;})};

    if (it != m_map.end()) {
        return it->grade;
    } else {
        m_map.push_back({name, '\0'});
        return m_map.back().grade;
    }
}

int main()
{
    GradeMap grades{};

    grades["Joe"] = 'A';
    grades["Frank"] = 'B';

    std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
    std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

    return 0;
}
