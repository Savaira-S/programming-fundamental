#include <iostream>
#include <string>
using namespace std;

float taxCalculator(char chr, float p)
{

    float taxRate;

    if (chr == 'M')
    {
        taxRate = 6;
    }
    else if (chr == 'E')
    {
        taxRate = 8;
    }
    else if (chr == 'S')
    {
        taxRate = 10;
    }
    else if (chr == 'V')
    {
        taxRate = 12;
    }
    else if (chr == 'T')
    {
        taxRate = 15;
    }
    else
    {
        return -1; // for invalid type
    }

    float taxam = (p * taxRate) / 100;
    float finalP = p + taxam;

    return finalP;
}

string Name(char type)
{
    if (type == 'M')
        return "Motorcycle";
    else if (type == 'E')
        return "Electric";
    else if (type == 'S')
        return "Sedan";
    else if (type == 'V')
        return "Van";
    else if (type == 'T')
        return "Truck";
    else
        return "Unknown";
}

int main()
{

    char chr;
    float p;

    cout << "enter vehicle type code(M/E/S/V/T): ";
    cin >> chr;
    cout << "enter vehicle price: ";
    cin >> p;

    if (chr != 'M' && chr != 'E' && chr != 'S' && chr != 'V' && chr != 'T')
    {
        cout << "Invalid vehicle type!" << endl;
        return 1;
    }

    float finalP = taxCalculator(chr, p);
    string vehcileName = Name(chr);

    cout << "final price after tax: " << vehcileName << endl;
    cout << " after adding the tax is $" << finalP << endl;

    return 0;
}