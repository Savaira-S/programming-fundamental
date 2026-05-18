#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

void mainHeader();
int mainMenu();
void addTransaction(string datearr[], float amntArr[], int &count);
void viewSummary();
void totalBalance(float &totalIncome, float &totalExpenses);
void setBudget(float budgetArray[], int u);
void updateTransaction(int u);
void deleteTransaction(int u);
void saveToFile(float initialbudget[]);
void loadFromFile(float initialbudget[]);
string getField(string record, int field);

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

string passwordArray[2] = {"pss14", "ibo12"};

int main()
{
    loadFromFile(initialBudget);

    while (true)
    {
        int selectedUser = 0;
        string enteredPassword = "";
        bool loginSuccess = false;

        while (!loginSuccess)
        {
            system("cls");
            mainHeader();
            cout << "1. login as User1" << endl;
            cout << "2. login as User2" << endl;
            cout << "3. Exit completely" << endl;
            cout << "select option: ";
            int loginChoice;
            cin >> loginChoice;

            if (loginChoice == 1 || loginChoice == 2)
            {
                selectedUser = loginChoice - 1;

                cout << "Enter password for " << userArray[selectedUser] << ": ";
                cin >> enteredPassword;

                if (enteredPassword == passwordArray[selectedUser])
                {
                    currentUser = selectedUser;
                    loginSuccess = true;
                    cout << "\nLogin Successful! Welcome, " << userArray[currentUser] << "." << endl;
                    getch();
                }
                else
                {
                    cout << "\nIncorrect password! Access Denied." << endl;
                    getch();
                }
            }
            else if (loginChoice == 3)
            {
                cout << "exiting system..." << endl;
                saveToFile(initialBudget);
                return 0;
            }
        }

        while (loginSuccess)
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
                        addTransaction(dateArrayU1, amArrayU1, indexUser[u]);
                    }
                    else
                    {
                        addTransaction(dateArrayU2, amArrayU2, indexUser[u]);
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
                system("cls");
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
                system("cls");
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
                cout << "Saving data and signing out of " << userArray[u] << "..." << endl;
                saveToFile(initialBudget);
                loginSuccess = false;
                getch();
            }
            else
            {
                cout << "Invalid choice! Please select 1-12." << endl;
                getch();
            }
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

int mainMenu()
{
    cout << "1. Add Transaction " << endl;
    cout << "2. View Summary " << endl;
    cout << "3. Calculate Total Balance " << endl;
    cout << "4. Set Initial Budget " << endl;
    cout << "5. Update Transaction (CRUD) " << endl;
    cout << "6. Delete Transaction (CRUD) " << endl;
    cout << "7. View Total Income " << endl;
    cout << "8. View Total Expenses " << endl;
    cout << "9. Clear All Transactions (Danger!) " << endl;
    cout << "10. Change User (User1 / User2) " << endl;
    cout << "11. Reset Budget to Zero " << endl;
    cout << "12. Exit " << endl;
    cout << "choice: ";
    int choice;
    cin >> choice;
    return choice;
}

void addTransaction(string datearr[], float amntArr[], int &count)
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

    datearr[count] = tempDate;
    amntArr[count] = tempAm;

    if (u == 0)
    {
        categoryArrayU1[count] = tempCat;
        isExpenseArrayU1[count] = (type == 1);
    }
    else
    {
        categoryArrayU2[count] = tempCat;
        isExpenseArrayU2[count] = (type == 1);
    }

    count++;

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
            cin >> dateArrayU1[idx];
        else
            cin >> dateArrayU2[idx];

        cout << "Enter new category: ";
        if (u == 0)
            cin >> categoryArrayU1[idx];
        else
            cin >> categoryArrayU2[idx];

        cout << "Enter new amount: ";
        if (u == 0)
            cin >> amArrayU1[idx];
        else
            cin >> amArrayU2[idx];

        cout << "Type (1 for expense, 0 for income): ";
        int type;
        cin >> type;

        if (u == 0)
            isExpenseArrayU1[idx] = (type == 1);
        else
            isExpenseArrayU2[idx] = (type == 1);

        cout << "updated! " << endl;
    }
    else
    {
        cout << "Invalid index!" << endl;
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

        if (u == 0)
        {
            dateArrayU1[indexUser[u]] = "";
            categoryArrayU1[indexUser[u]] = "";
            amArrayU1[indexUser[u]] = 0;
            isExpenseArrayU1[indexUser[u]] = false;
        }
        else
        {
            dateArrayU2[indexUser[u]] = "";
            categoryArrayU2[indexUser[u]] = "";
            amArrayU2[indexUser[u]] = 0;
            isExpenseArrayU2[indexUser[u]] = false;
        }

        cout << "Deleted! ";
    }
    else
    {
        cout << "Invalid index!" << endl;
    }
}

void saveToFile(float initialbudget[])
{
    ofstream outFile;

    outFile.open("financeTrackerUser1.txt");
    if (outFile.is_open())
    {
        outFile << initialbudget[0] << endl;
        for (int i = 0; i < indexUser[0]; i++)
        {
            outFile << dateArrayU1[i] << ","
                    << categoryArrayU1[i] << "," << amArrayU1[i]
                    << "," << isExpenseArrayU1[i] << endl;
        }
        outFile.close();
        cout << "\nData saved successfully\n";
    }
    else
    {
        cout << "error opening user1 file \n";
    }

    outFile.open("financeTrackerUser2.txt");
    if (outFile.is_open())
    {
        outFile << initialbudget[1] << endl;
        for (int i = 0; i < indexUser[1]; i++)
        {
            outFile << dateArrayU2[i] << ","
                    << categoryArrayU2[i] << "," << amArrayU2[i]
                    << "," << isExpenseArrayU2[i] << endl;
        }
        outFile.close();
        cout << "\nData saved successfully\n";
    }
    else
    {
        cout << "error opening user2 file \n";
    }
}

string getField(string record, int field)
{
    int commaCount = 1;
    string word;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount++;
        }
        else if (commaCount == field)
        {
            word = word + record[x];
        }
    }
    return word;
}

void loadFromFile(float initialbudget[])
{
    ifstream inFile;
    inFile.open("financeTrackerUser1.txt");
    if (inFile.is_open())
    {
        inFile >> initialbudget[0];
        inFile.ignore();
        string line = "";
        while (getline(inFile, line))
        {
            dateArrayU1[indexUser[0]] = getField(line, 1);
            categoryArrayU1[indexUser[0]] = getField(line, 2);
            amArrayU1[indexUser[0]] = stof(getField(line, 3));
            isExpenseArrayU1[indexUser[0]] = stoi(getField(line, 4));

            indexUser[0]++;
        }
        inFile.close();
        
    }

    inFile.open("financeTrackerUser2.txt");
    if (inFile.is_open())
    {
        inFile >> initialbudget[1];
        inFile.ignore();

        string line = "";
        while (getline(inFile, line))
        {
            dateArrayU2[indexUser[1]] = getField(line, 1);
            categoryArrayU2[indexUser[1]] = getField(line, 2);
            amArrayU2[indexUser[1]] = stof(getField(line, 3));
            isExpenseArrayU2[indexUser[1]] = stoi(getField(line, 4));

            indexUser[1]++;
        }
        inFile.close();
       
    }
}