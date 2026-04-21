#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string pyramidVolume(double l, double w, double h, string unit)
{

    double V = (l * w * h) / 3;
    double finalV;
    string volumeUnit;

    if (unit == "millimeters")
    {
        finalV = V * 1000000000;
        volumeUnit = "cubic millimeters";
    }
    else if (unit == "centimeters")
    {
        finalV = V * 1000000;
        volumeUnit = "cubic centimeters";
    }
    else if (unit == "kilometers")
    {
        finalV = V / 1000000000;
        volumeUnit = "cubic kilometers";
    }
    else if (unit == "meters")
    {
        finalV = V;
        volumeUnit = "cubic meters";
    }
    else
    {
        return "invalid unit! ";
    }
    string result = to_string(finalV);

    stringstream ss;
    ss << fixed << setprecision(3) << finalV;
    result = ss.str();

    return result + " " + volumeUnit;
}

int main()
{
    double l, w, h;
    string unit;

    cout << "enter lenght, width, height (in meters): ";
    cin >> l >> w >> h;
    cout << "Enter output unit (millimeters, centimeters, meters, kilometers): ";
    cin >> unit;

    string result = pyramidVolume(l, w, h, unit);
    cout << "Volume: " << result << endl;

    return 0;
}