#include <iostream>
using namespace std;

string timeTravel(int hours, int minutes)
{

    minutes += 15;
    if (minutes >= 60)
    {
        minutes -= 60;
        hours += 1;
    }
    if (hours >= 24)
    {
        hours -= 24;
    }
    string result = " ";
    if (hours < 10)
    {
        result = '0' + to_string(hours);
    }
    else
    {
        result = to_string(hours);
    }
    result = result + ":";

    if (minutes < 10)
    {
        result = result + "0" + to_string(minutes);
    }
    else
    {
        result = result + to_string(minutes);
    }

    return result;
}

int main()
{
    int h, min;

    cout << "enter hours: ";
    cin >> h;
    cout << "enter minutes: ";
    cin >> min;

    string futureTime = timeTravel(h,min);
    cout << "Future time: " << futureTime << endl;

    return 0;
}