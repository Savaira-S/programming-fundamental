#include <iostream>
using namespace std;

string name(int num)
{
    string result = "";

    if (num == 1)
        return "One";
    if (num == 2)
        return "Two";
    if (num == 3)
        return "Three";
    if (num == 4)
        return "Four";
    if (num == 5)
        return "Five";
    if (num == 6)
        return "Six";
    if (num == 7)
        return "Seven";
    if (num == 8)
        return "Eight";
    if (num == 9)
        return "Nine";
    if (num == 10)
        return "Ten";
    if (num == 11)
        return "Eleven";
    if (num == 12)
        return "Twelve";
    if (num == 13)
        return "Thirteen";
    if (num == 14)
        return "Fourteen";
    if (num == 15)
        return "Fifteen";
    if (num == 16)
        return "Sixteen";
    if (num == 17)
        return "Seventeen";
    if (num == 18)
        return "Eighteen";
    if (num == 19)
        return "Nineteen";

    int tens = num / 10;
    int ones = num % 10;

    if (tens == 2)
        result = "Twenty";
    if (tens == 3)
        result = "Thirty";
    if (tens == 4)
        result = "Forty";
    if (tens == 5)
        result = "Fifty";
    if (tens == 6)
        result = "Sixty";
    if (tens == 7)
        result = "Seventy";
    if (tens == 8)
        result = "Eighty";
    if (tens == 9)
        result = "Ninety";

    if (ones == 1)
        result = result + "One";
    if (ones == 2)
        result = result + "Two";
    if (ones == 3)
        result = result + "Three";
    if (ones == 4)
        result = result + "Four";
    if (ones == 5)
        result = result + "Five";
    if (ones == 6)
        result = result + "Six";
    if (ones == 7)
        result = result + "Seven";
    if (ones == 8)
        result = result + "Eight";
    if (ones == 9)
        result = result + "Nine";

    return result;
}

int main()
{
    int n;
    cout << "enter a number: ";
    cin >> n;

    if (n >= 1 && n <= 99)
    {
        cout << name(n) << endl;
    }
    else
    {
        cout << "number out of range " << endl;
    }

    return 0;
}