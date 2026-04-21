#include <iostream>
using namespace std;

bool myFunction(int num)
{
    int original = num;
    int rev = 0;
    while (num > 0)
    {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return original == rev;
}

int main()
{
    int num;
    cout << "enter number ";
    cin >> num;

    if (myFunction(num))
    {
        cout << "symmetrical " << num << endl;
    }
    else
    {

        cout << "not symmetrical " << num << endl;
    }
    return 0;
}