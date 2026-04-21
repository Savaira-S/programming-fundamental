#include <iostream>
#include <iomanip>
using namespace std;

float calculateSalary(float base, int score, int experience)
{
    float bonus = 0.0;

    if (score >= 90)
    {
        bonus = 0.20 * base;
    }
    else if (score >= 75)
    {
        bonus = 0.10 * base;
    }
    else
    {
        bonus = 0.05 * base;
    }

    if (experience >= 5)
    {
        bonus += 0.05 * base;
    }

    return base + bonus;
}

int main()
{
    float baseSalary;
    int score, experience;

    cout << "Enter base salary: ";
    cin >> baseSalary;

    cout << "Enter performance score: ";
    cin >> score;

    cout << "Enter years of experience: ";
    cin >> experience;

    float finalSalary = calculateSalary(baseSalary, score, experience);

    cout << fixed << setprecision(2);
    cout << "Final salary: $" << finalSalary << endl;

    return 0;
}