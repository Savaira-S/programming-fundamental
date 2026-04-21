#include <iostream>
using namespace std;

string calculatePoolState(int V, int P1, int P2, int H)
{
    string result = "";

    int totalWater = (P1 + P2) * H;

    if (totalWater <= V)
    {
        int poolpercentage = (totalWater * 100) / V;
        int Pipe1Percentage = (P1 * H * 100) / totalWater;
        int Pipe2Percentage = (P2 * H * 100) / totalWater;

        result = "the pool is " + to_string(poolpercentage) + "% full";
        result = result + "pipe 1: " + to_string(Pipe1Percentage) + "% ";
        result = result + "pipe 2: " + to_string(Pipe2Percentage) + "% ";
    }
    else
    {
        int overflow = totalWater - V;
        result = "pool is full " + to_string(overflow) + " liters overdflowed ";
    }
    return result;
}

int main()
{
    int V, P1, P2, H;
    cout << "enter volume (liters) ";
    cin >> V;
    cout << "enter flow rate of first pipe ";
    cin >> P1;
    cout << "enter flow rate of second pipe ";
    cin >> P2;
    cout << "enter hours that worker is absent ";
    cin >> H;

    string state = calculatePoolState(V, P1, P2, H);
    cout << state << endl;

    return 0;
}