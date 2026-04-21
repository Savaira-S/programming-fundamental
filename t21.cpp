#include <iostream>
#include <iomanip>
using namespace std;

float calculateBalance(float balance, int years)
{
    float interestRate = 0.0;

    if (balance < 10000)
    {
        interestRate = 0.05;
    }
    else if (balance <= 50000)
    {
        interestRate = 0.07;
    }
    else
    {
        interestRate = 0.10;
    }

    if (years >= 3)
    {
        interestRate += 0.02;
    }

    return balance * (1 + interestRate);
}

int main()
{
    float balance;
    int years;

    cout << "Enter current balance: $";
    cin >> balance;

    cout << "Enter years with bank: ";
    cin >> years;

    float updatedBalance = calculateBalance(balance, years);

    cout << fixed << setprecision(2);
    cout << "Updated balance: $" << updatedBalance << endl;

    return 0;
}