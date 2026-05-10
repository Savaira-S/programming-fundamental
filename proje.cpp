#include <iostream>
#include <conio.h>

using namespace std;

void mainHeader();
char mainMenu();
void addTransaction(string datearr[], float amntArr[],
                    int &count);
void viewSummary();
void totalBalance(float &totalIncome, float &totalExpenses);
void setBudget(float budgetArray[], int u);
void updateTransaction(int u);
void deleteTransaction(int u);

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

int main()
{
    while (true)
    {
        system("cls");

        mainHeader();

        int u = currentUser;
        int choice = mainMenu();

        if (choice == 1)
        {
            system("cls");
            if (indexUser[u] >= MAX)
            {
                cout << "Transaction limit reached! Cannot add more." << endl;
            }
            else
            {
                if (u == 0)
                {
                    addTransaction(dateArrayU1,
                                   amArrayU1, indexUser[u]);
                }
                else
                {
                    addTransaction(dateArrayU2,
                                   amArrayU2, indexUser[u]);
                }
                getch();
            }
        }
        else if (choice == 2)
        {
            system("cls");
            cout << "Date\tCategory\tAmount\tType" << endl;

            viewSummary();

            getch();
        }
        else if (choice == 3)
        {
            float totalExpenses = 0;
            float totalIncome = 0;
            totalBalance(totalIncome, totalExpenses);

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
            setBudget(initialBudget, u);

            getch();
        }
        else if (choice == 5)
        {
            system("cls");

            updateTransaction(u);

            getch();
        }
        else if (choice == 6)
        {
            system("cls");

            deleteTransaction(u);

            getch();
        }
        else if (choice == 7)
        {
            system("cls");
            float totalIncome = 0;
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
            cout << "Total Income for " << userArray[u] << ": " << totalIncome << endl;
            getch();
        }
        else if (choice == 8)
        {
            system("cls");
            float totalExpense = 0;
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
            cout << "Total Expenses for " << userArray[u] << ": " << totalExpense << endl;
            getch();
        }
        else if (choice == 9)
        {
            system("cls");
            cout << "Are you sure you want to delete ALL transactions for "
                 << userArray[u] << "? (1 for YES, 0 to cancel): ";
            int confirm;
            cin >> confirm;

            if (confirm == 1)
            {
                indexUser[u] = 0;
                cout << "All transactions cleared for " << userArray[u] << "!" << endl;
            }
            else
            {
                cout << "Operation cancelled." << endl;
            }
            getch();
        }
        else if (choice == 10)
        {
            system("cls");
            cout << "Available users:" << endl;
            for (int i = 0; i < totalUsers; i++)
            {
                cout << i + 1 << ". " << userArray[i] << endl;
            }
            cout << "Select user (1 or 2): ";
            int userChoice;
            cin >> userChoice;

            if (userChoice == 1 || userChoice == 2)
            {
                currentUser = userChoice - 1;
                cout << "Now using: " << userArray[currentUser] << endl;
            }
            else
            {
                cout << "Invalid user choice!" << endl;
            }
            getch();
        }
        else if (choice == 11)
        {
            system("cls");
            initialBudget[u] = 0;
            cout << "Budget for " << userArray[u] << " has been reset to 0." << endl;
            getch();
        }
        else if (choice == 12)
        {
            cout << "Exiting Personal Finance Tracker. Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice! Please select 1-12." << endl;
            getch();
        }
    }

    return 0;
}

void mainHeader()
{
    cout << "============================================" << endl;
    cout << "        PERSONAL FINANCE TRACKER" << endl;
    cout << "      Designed & Implemented by: [Savaira Eman-40]" << endl;
    cout << "============================================" << endl;
}
char mainMenu()
{
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
    int choice;
    cin >> choice;
    return choice;
}

void addTransaction(string datearr[], float amntArr[],
                    int &count)
{
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

    int u = currentUser;
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
}

void viewSummary()
{
    int u = currentUser;
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

void totalBalance(float &totalIncome, float &totalExpenses)
{
    int u = currentUser;

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
void setBudget(float budgetArray[], int u)
{
    cout << "Enter your total initial budget: ";
    cin >> budgetArray[u];
    cout << "Budget set successfully! " << endl;
}
void updateTransaction(int u)
{
    if (indexUser[u] == 0)
    {
        cout << "No transactions to update! " << endl;
        return;
    }
    int idx;
    cout << "Enter index to update: ";
    cin >> idx;
    if (idx >= 0 && idx < indexUser[u])
    {
        cout << "Enter new date: ";
        if (u == 0)
        {
            cin >> dateArrayU1[idx];
        }
        else
        {
            cin >> dateArrayU2[idx];
        }

        cout << "updated! " << endl;
    }
}

void deleteTransaction(int u)
{
    if (indexUser[u] == 0)
    {
        cout << "No data! ";
        return;
    }
    int del;
    cout << "Enter index to delete: ";
    cin >> del;
    if (del >= 0 && del < indexUser[u])
    {
        for (int i = del; i < indexUser[u] - 1; i++)
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
        indexUser[u]--;
        cout << "Deleted! ";
    }
}