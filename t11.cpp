#include <iostream>
using namespace std;

string Oddish_Evenish(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    if (sum = sum % 2)
    {
        return" Oddish ";
    }
    else
    {
        return" Evenish ";
    }
}
int main()
{
    int num;
    cout << "enter 5-digit number: ";
    cin >> num;

    cout << Oddish_Evenish(num) << endl;

    return 0;
}