#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

struct Student
{
    std::string name {};
    int grade {};
};

bool compareGrades(const Student &studentA, const Student &studentB)
{
    if (studentA.grade > studentB.grade) {
        return true;
    } else {
        return false;
    }
}

void readStudents (std::vector<Student> &students)
{
    std::cout << "Enter the name and age for each student\n";
    for (auto &student: students) {
        std::cin >> student.name;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> student.grade;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void sortStudents (std::vector<Student> &students)
{
    sort(students.begin(), students.end(), compareGrades);
}

void printStudents (std::vector<Student> &students)
{
    for (const auto &student: students) {
        std::cout << student.name << " got a grade of " << student.grade
                  << std::endl;
    }
}

int main()
{
    std::cout << "How many students would you like to enter? ";
    int numOfStudents {};
    std::cin >> numOfStudents;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<Student> students {};
    students.resize(static_cast<size_t>(numOfStudents));

    readStudents(students);
    sortStudents(students);
    printStudents(students);

    return 0;
}
