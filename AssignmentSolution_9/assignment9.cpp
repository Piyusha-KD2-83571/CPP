#include<iostream>
#include<vector>
using namespace std;

enum Eaccounttype {
    SAVING = 1,
    CURRENT,
    DMAT
};

class InsufficientFundsException {
private:
    int accno;
    double currentBalance;
    double withdrawAmount;
public:
    void display() {
        if (currentBalance < withdrawAmount) {
            cout << "Insufficient Balance" << endl;
        }
        else if (withdrawAmount < 0) {
            cout << "cannot withdraw value less than 0 " << endl;
        }
    }
    InsufficientFundsException() {

    }
    InsufficientFundsException(int accno, double currentBalance, double withdrawAmount) {
        this->accno = accno;
        this->currentBalance = currentBalance;
        this->withdrawAmount = withdrawAmount;

    }

};

class Account {
private:
    const int accno;
    Eaccounttype type;
    double balance;
    static int generateno;

public:
    Account() : accno(++generateno) {

    }

    Account(Eaccounttype type, double balance) : accno(++generateno) {
        this->type = type;
        this->balance = balance;
    }

    int getAccNo() const {
        return accno;
    }

    void accept() {
        int ch;
        cout << "Enter Balance:" << endl;
        cin >> balance;

        cout << "Enter Account Type:\n1.Saving\n2.Current\n3.Dmat" << endl;
        cin >> ch;
        type = Eaccounttype(ch);
    }

    void display() {
        cout << "-----Account Details-----" << endl;
        cout << "Acc No:" << accno << endl;
        cout << "AccountType:" << type << endl;
        cout << "Balance:" << balance << endl;
    }

    void deposit(double amount) {
        if (amount < 0)
            throw 1;
        else {
            balance = amount + balance;
        }
    }

    void withdraw(double amount) {
        if (balance < amount) {
            throw InsufficientFundsException(accno, balance, amount);
        }
        else if (amount < 0) {
            throw InsufficientFundsException(accno, balance, amount);
        }
        else {
            balance = balance - amount;
        }
    }
};

int Account::generateno = 100000;

int main() {
    int choice;
    int index = 0;
    vector<Account*> Acclist;
    Account *a;
    do {
        cout << "-------Welcome to Banking System-----------" << endl;
        cout << "0.Exit" << endl;
        cout << "1.Add Account details" << endl;
        cout << "2.Display Account details" << endl;
        cout << "3.Deposit money" << endl;
        cout << "4.Withdraw money" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "---------Thank you for using Bank--------------------" << endl;
                break;

            case 1:
                if (index < 5) {
                    a = new Account();
                    a->accept();
                    Acclist.push_back(a);
                }
                else {
                    cout << "Array is full" << endl;
                }
                break;

            case 2:
                for (int i = 0; i < Acclist.size(); i++) {
                    Acclist[i]->display();
                }
                break;

            case 3:
                int depositAccNo;
                double depositAmount;
                cout << "Enter Account Number to deposit into:" << endl;
                cin >> depositAccNo;
                cout << "Enter Amount to deposit:" << endl;
                cin >> depositAmount;
                
                for (int i = 0; i < Acclist.size(); i++) {
                    if (Acclist[i]->getAccNo() == depositAccNo) {
                        try {
                            Acclist[i]->deposit(depositAmount);
                        }
                        catch (int) {
                            cout << "Invalid Amount to deposit" << endl;
                        }
                        break;
                    }
                }
                break;

            case 4:
                int withdrawAccNo;
                double withdrawAmount;
                cout << "Enter Account Number to withdraw from:" << endl;
                cin >> withdrawAccNo;
                cout << "Enter Amount to withdraw:" << endl;
                cin >> withdrawAmount;
                
                for (int i = 0; i < Acclist.size(); i++) {
                    if (Acclist[i]->getAccNo() == withdrawAccNo) {
                        try {
                            Acclist[i]->withdraw(withdrawAmount);
                        }
                        catch (InsufficientFundsException e) {
                            e.display();
                        }
                        break;
                    }
                }
                break;

            default:
                cout << "Invalid Choice!!!!!!!!!!" << endl;
                break;
        }
    } while (choice != 0);

    for(int i=0;i<sizeof(a);i++)
    {
        delete a;
    }

    for (int i = 0; i < Acclist.size(); i++)
        delete Acclist[i];

        
    return 0;
}