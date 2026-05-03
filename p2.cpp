#include <iostream>
#include <conio.h>

using namespace std;

void showMenu(){ 
    system("cls");
    cout << "============================================" << endl;
    cout << "        PERSONAL FINANCE TRACKER" << endl;
    cout << "  Designed & Implemented by: [Savaira Eman-40]" << endl;
    cout << "============================================" << endl;

    cout << "1. Add Transaction " << endl;
    cout << "2. View Summary " << endl;
    cout << "3. Calculate Total Balance " << endl;
    cout << "4. Set Initial Budget " << endl;
    cout << "5.  Update Transaction (CRUD) " << endl;
    cout << "6.  Delete Transaction (CRUD) " << endl;
    cout << "7.  View Total Income " << endl;
    cout << "8.  View Total Expenses " << endl;
    cout << "9.  Clear All Transactions (Danger!) " << endl;
    cout << "10. Change User (User1 / User2) " << endl;
    cout << "11. Reset Budget to Zero " << endl;
    cout << "12. Exit " << endl;
    cout << "choice: ";
}

void printAllTransactions(int u, string dateArrayU1[], string categoryArrayU1[], float amArrayU1[], bool isExpenseArrayU1[], string dateArrayU2[], string categoryArrayU2[], float amArrayU2[], bool isExpenseArrayU2[], int indexUser[]){
    cout << "Date\tCategory\tAmount\tType" << endl;
    for (int i = 0; i < indexUser[u]; i++)
    {
        if (u == 0)
        {
            cout << dateArrayU1[i] << "\t" << categoryArrayU1[i] << "\t" << amArrayU1[i] << "\t";
            if (isExpenseArrayU1[i] == true)
                cout << "Expense ";
            else
                cout << "Income ";
        }
        else
        {
            cout << dateArrayU2[i] << "\t" << categoryArrayU2[i] << "\t" << amArrayU2[i] << "\t";
            if (isExpenseArrayU2[i] == true)
                cout << "Expense ";
            else
                cout << "Income ";
        }
        cout << endl;
    }
}

void calculateBalanceLoop(int u, string dateArrayU1[], float amArrayU1[], bool isExpenseArrayU1[], string dateArrayU2[], float amArrayU2[], bool isExpenseArrayU2[], int indexUser[], float &totalExpenses, float &totalIncome){
    totalExpenses = 0;
    totalIncome = 0;
    for (int i = 0; i < indexUser[u]; i++)
    {
        if (u == 0)
        {
            if (isExpenseArrayU1[i] == true)
                totalExpenses += amArrayU1[i];
            else
                totalIncome += amArrayU1[i];
        }
        else
        {
            if (isExpenseArrayU2[i] == true)
                totalExpenses += amArrayU2[i];
            else
                totalIncome += amArrayU2[i];
        }
    }
}

void incomeLoop(int u, string dateArrayU1[], float amArrayU1[], bool isExpenseArrayU1[], string dateArrayU2[], float amArrayU2[], bool isExpenseArrayU2[], int indexUser[], float &totalIncome){
    totalIncome = 0;
    for (int i = 0; i < indexUser[u]; i++)
    {
        if (u == 0)
        {
            if (!isExpenseArrayU1[i])
                totalIncome += amArrayU1[i];
        }
        else
        {
            if (!isExpenseArrayU2[i])
                totalIncome += amArrayU2[i];
        }
    }
}

void expenseLoop(int u, string dateArrayU1[], float amArrayU1[], bool isExpenseArrayU1[], string dateArrayU2[], float amArrayU2[], bool isExpenseArrayU2[], int indexUser[], float &totalExpense){
    totalExpense = 0;
    for (int i = 0; i < indexUser[u]; i++)
    {
        if (u == 0)
        {
            if (isExpenseArrayU1[i])
                totalExpense += amArrayU1[i];
        }
        else
        {
            if (isExpenseArrayU2[i])
                totalExpense += amArrayU2[i];
        }
    }
}

void updateListLoop(int u, string dateArrayU1[], string categoryArrayU1[], float amArrayU1[], string dateArrayU2[], string categoryArrayU2[], float amArrayU2[], int indexUser[]){
    for (int i = 0; i < indexUser[u]; i++)
    {
        if (u == 0)
            cout << i << ". " << dateArrayU1[i] << " - " << categoryArrayU1[i] << " - " << amArrayU1[i] << endl;
        else
            cout << i << ". " << dateArrayU2[i] << " - " << categoryArrayU2[i] << " - " << amArrayU2[i] << endl;
    }
}

void deleteListLoop(int u, string dateArrayU1[], string categoryArrayU1[], float amArrayU1[], bool isExpenseArrayU1[], string dateArrayU2[], string categoryArrayU2[], float amArrayU2[], bool isExpenseArrayU2[], int indexUser[]){
    for (int i = 0; i < indexUser[u]; i++)
    {
        if (u == 0)
        {
            cout << i << ". " << dateArrayU1[i] << " - " << categoryArrayU1[i] << " - " << amArrayU1[i] << " (";
            if (isExpenseArrayU1[i] == true)
                cout << "Expense ";
            else
                cout << "Income ";
        }
        else
        {
            cout << i << ". " << dateArrayU2[i] << " - " << categoryArrayU2[i] << " - " << amArrayU2[i] << " (";
            if (isExpenseArrayU2[i] == true)
                cout << "Expense ";
            else
                cout << "Income ";
        }
        cout << ")" << endl;
    }
}

void shiftDeleteLoop(int u, string dateArrayU1[], string categoryArrayU1[], float amArrayU1[], bool isExpenseArrayU1[], string dateArrayU2[], string categoryArrayU2[], float amArrayU2[], bool isExpenseArrayU2[], int delIndex, int indexUser[]){
    for (int i = delIndex; i < indexUser[u] - 1; i++)
    {
        if (u == 0)
        {
            dateArrayU1[i] = dateArrayU1[i + 1];
            categoryArrayU1[i] = categoryArrayU1[i + 1];
            amArrayU1[i] = amArrayU1[i + 1];
            isExpenseArrayU1[i] = isExpenseArrayU1[i + 1];
        }
        else
        {
            dateArrayU2[i] = dateArrayU2[i + 1];
            categoryArrayU2[i] = categoryArrayU2[i + 1];
            amArrayU2[i] = amArrayU2[i + 1];
            isExpenseArrayU2[i] = isExpenseArrayU2[i + 1];
        }
    }
}

void userListLoop(string userArray[], int totalUsers){
    for (int i = 0; i < totalUsers; i++)
    {
        cout << i + 1 << ". " << userArray[i] << endl;
    }
}

int main()
{
    const int MAX = 100;

    int totalUsers = 2;
    int currentUser = 0;
    string userArray[2] = {"User1", "User2"};

    string dateArrayU1[MAX], categoryArrayU1[MAX];
    float amArrayU1[MAX];
    bool isExpenseArrayU1[MAX];

    string dateArrayU2[MAX], categoryArrayU2[MAX];
    float amArrayU2[MAX];
    bool isExpenseArrayU2[MAX];

    float initialBudget[2] = {0, 0};
    int indexUser[2] = {0, 0};

    while (true)
    {
         showMenu();
        int choice;
        cin >> choice;

        int u = currentUser;

        if (choice == 1)
        {
            system("cls");
            if (indexUser[u] >= MAX)
            {
                cout << "Transaction limit reached! Cannot add more." << endl;
                getch();
                continue;
            }

            string tempDate, tempCat;
            float tempAm;
            int type;

            cout << "Enter date (DD/MM/YYYY): ";
            cin >> tempDate;
            cout << "Enter category: ";
            cin >> tempCat;
            cout << "Enter amount: ";
            cin >> tempAm;
            cout << "Type (1 for expense, 0 for income): ";
            cin >> type;

            if (u == 0)
            {
                dateArrayU1[indexUser[u]] = tempDate;
                categoryArrayU1[indexUser[u]] = tempCat;
                amArrayU1[indexUser[u]] = tempAm;
                isExpenseArrayU1[indexUser[u]] = (type == 1);
            }
            else
            {
                dateArrayU2[indexUser[u]] = tempDate;
                categoryArrayU2[indexUser[u]] = tempCat;
                amArrayU2[indexUser[u]] = tempAm;
                isExpenseArrayU2[indexUser[u]] = (type == 1);
            }
            indexUser[u]++;

            cout << "Data Saved Successfully! " << endl;
            getch();
        }
        else if (choice == 2)
        {
            system("cls");
            printAllTransactions(u, dateArrayU1, categoryArrayU1, amArrayU1, isExpenseArrayU1, dateArrayU2, categoryArrayU2, amArrayU2, isExpenseArrayU2, indexUser);
            getch();
        }
        else if (choice == 3)
        {
            float totalExpenses = 0;
            float totalIncome = 0;
            calculateBalanceLoop(u, dateArrayU1, amArrayU1, isExpenseArrayU1, dateArrayU2, amArrayU2, isExpenseArrayU2, indexUser, totalExpenses, totalIncome);

            float remaining = initialBudget[u] + totalIncome - totalExpenses;
            cout << "Initial Budget: " << initialBudget[u] << endl;
            cout << "Total Income:   " << totalIncome << endl;
            cout << "Total Expenses: " << totalExpenses << endl;
            cout << "Remaining Budget: " << remaining << endl;

            if (remaining < 0)
            {
                cout << "Warning: you are over Budget! " << endl;
            }

            getch();
        }
        else if (choice == 4)
        {
            cout << "Enter your total initial budget: ";
            cin >> initialBudget[u];
            cout << "Budget set successfully! " << userArray[u] << "!" << endl;
            getch();
        }
        else if (choice == 5)
        {
            system("cls");
            if (indexUser[u] == 0)
            {
                cout << "No transactions to update!" << endl;
            }
            else
            {
                cout << "Current Transactions:" << endl;
                updateListLoop(u, dateArrayU1, categoryArrayU1, amArrayU1, dateArrayU2,