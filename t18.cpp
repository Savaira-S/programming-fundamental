#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string projectTimeCalculation(int neededHours, int days, int workers)
{

    int workingDays = floor(days * 0.9);
    int hoursPerWorkerPerDay = 10;
    int totalAvailableHours = workingDays * workers * hoursPerWorkerPerDay;
    int difference = totalAvailableHours - neededHours;

    if (difference >= 0)
    {
        return "Yes!" + to_string(difference) + " hours left.";
    }
    else
    {
        return "Not enough time!" + to_string(abs(difference)) + " hours needed.";
    }
}
int main()
{
    int neededHours, days, workers;

    cout << "Enter needed hours: ";
    cin >> neededHours;

    cout << "Enter number of days: ";
    cin >> days;

    cout << "Enter number of workers: ";
    cin >> workers;

    string result = projectTimeCalculation(neededHours, days, workers);
    cout << result << endl;

    return 0;
}
