/*Q1. Write a class to store Account information of Bank customer by using following class diagram.
Use enum to store information of account type.
Create an array of 5 Accounts in main() and accept their details from user.
Write Menu driven program to deposit/withdraw amount from the account.
After each transaction display updated account balance.
Throw exceptions for invalid values.
Also implement an exception class InsufficientFundsException.
In withdraw if sufficient balance is not available in account or while deposit the entered amount is
negative then throw this exception.*/

#include <iostream>
using namespace std;

enum EAccountType
{
    SAVING,
    CURRENT,
    DMAT
};

class InSufficientFundException
{
    int accno;
    double currentBalance;
    double withdrawAmount;

public:
    InSufficientFundException(int accno, double currentBalance, double withdrawAmount)
    {
        this->currentBalance = currentBalance;
        this->accno = accno;
        this->withdrawAmount = withdrawAmount;
    }

    void printException()
    {
        cout << "Insufficient Balance in account no : " << accno << endl;
        cout << "Current Balance is : " << currentBalance << endl;
        cout << "Withdrawal Amount: " << withdrawAmount << endl;
    }
};

class Account
{
    int accno;
    EAccountType type;
    double balance;

public:
    Account()
    {
        cout << "account ctor" << endl;
        accno = 0;
        balance = 0.0;
    }

    Account(int accno, EAccountType type, double balance)
    {
        this->accno = accno;
        this->type = type;
        this->balance = balance;
    }

    void accept()
    {
        int choice;
        cout << "Enter the account details:" << endl;
        cout << "Enter your account number:-";
        cin >> accno;
        cout << "Enter the account type:- ";
        cout << "0.Saving\n1.Current\n2.DMAT \nYour Choice :-";
        cin >> choice;
        type = (EAccountType)choice;
        // switch (choice)
        // {
        //     case 0 : type = SAVING;
        //     break;

        //     case 1 : type = CURRENT;
        //     break;

        //     case 2 : type = DMAT;
        //     break;

        //     default :
        //     cout<<"Invalid Type"<<endl;
        //     break;
        // }
        cout << "Enter the balance :-\n";
        cin >> balance;
    }

    void display()
    {
        cout << "Account Number: " << accno << endl;
        if (type == SAVING)
            cout << "Account Type: Saving" << endl;
        else if (type == CURRENT)
            cout << "Account Type: Current" << endl;
        else if (type == DMAT)
            cout << "Account Type: DMAT" << endl;
        cout << "Balance: Rs." << balance << "/-" << endl;
        cout << "********************************************************" << endl;
    }

    void deposit(double amount)
    {

        // if (amount <= 0)
        // {
        //     cout<<"Deposit amount must be positive"<<endl;
        // }
        // else
        // {
        //     balance += amount;
        //     cout << "Deposited Rs." << amount << " successfully\n";
        //     display();
        // }
        balance = balance + amount;
        cout << "Amount Deposited Successfully";
        cout<<"Total Balance: "<<balance<<endl;
    }

    void withdraw(double amount)
    {
        // if(amount<=0)
        // {
        //     cout<<"Withdrawal amount must be positive"<<endl;
        // }
        // if(amount > balance)
        // {
        //     throw InSufficientFundException(accno, balance,amount);
        // }
        // balance -= amount;
        // cout << "Withdrawn Rs." << amount << " successfully."<<endl;
        // display();
        balance = balance - amount;
        cout << "Amount withdrawn Successfully"<<endl;
        cout<<"Total Balance: "<<balance<<endl
    }

    int getAccountno(int accno)
    {
        return this->accno;
    }
};

int main()
{
    Account *arr[5];
    int choice;
    int index = 0;

    do
    {
        cout << "Press 0: Exit" << endl;
        cout << "Press 1: Create an account" << endl;
        cout << "Press 2: Display Account Details" << endl;
        cout << "Press 3: To Deposit the amount" << endl;
        cout << "Press 4: To Withdraw the amount" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Thank you  for using our services!" << endl;
            break;

        case 1:
        {
            if (index < 5)
            {
                arr[index] = new Account();
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "No more accounts will be created..!!" << endl;
            }
        }
        break;

        case 2:
        {
            for (int i = 0; i < index; i++)
            {
                arr[i]->display();
            }
        }
        break;

        case 3:
        {
            int var;
            double amount;

            cout << "Enter account number where you want to deposit: " << endl;
            cin >> var;
            for (int i = 0; i < index; i++)
            {
                if (var == arr[i]->getAccountno(var))
                {
                    cout << "Enter the amount for deposit: ";
                    cin >> amount;
                    arr[i]->deposit(amount);
                    cout << "Deposited  Successfully." << endl;
                }
            }
        }
        break;

        case 4:
        {
            int var;
            double amt;

            cout << "Enter account number where you want to withdraw: ";
            cin >> var;

            for (int i = 0; i < index; i++)
                if (var == arr[i]->getAccountno(var))
                    try
                    {
                        cout << "Enter the amount for withdraw: " << endl;
                        cin >> amt;
                        arr[i]->withdraw(amt);
                    }
                    catch (InSufficientFundException e)
                    {
                        e.printException();
                    }
        }
        break;
        }

    } while (choice != 0);
    return 0;
}