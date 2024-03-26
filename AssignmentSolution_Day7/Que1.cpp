#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    double salary;

public:
    Employee()
    {
        cout << "Inside Employee()" << endl;
    }
    Employee(int id, double salary)
    {
        cout << "Inside Employee(int,double)" << endl;
    }
    virtual void accept()
    {
        cout << "Enter the empid - ";
        cin >> id;
        cout << "Enter the salary - ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "Id - " << id << endl;
        cout << "Salary - " << salary << endl;
    }
    virtual ~Employee()
    {
        cout << "~Employee()" << endl;
    }
};

class Manager : virtual public Employee
{
private:
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter the bonus - ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Bonus - " << bonus << endl;
    }

public:
    Manager()
    {
        cout << "Inside Manager()" << endl;
    }
    Manager(int id, double salary, double bonus)
    {
        cout << "Inside Manager(int,double,double)" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }
    ~Manager()
    {
        cout << "~Manager()" << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    double commission;
    int count=0;

protected:
    void acceptSalesman()
    {
        cout << "Enter the Commission - ";
        cin >> commission;
    }
    void displaySalesman()
    {
        cout << "Commission - " << commission << endl;
    }

public:
    Salesman()
    {
        cout << "Inside Salesman()" << endl;
    }
    Salesman(int id, double salary, double commission)
    {
        cout << "Inside Salesman(int,double,double)" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptSalesman();
    
    }

    void display()
    {
        Employee::display();
        displaySalesman();
    }
    ~Salesman()
    {
        cout << "~Salesman()" << endl;
    }
};
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
        cout << "Inside Salesmanager()" << endl;
    }
    SalesManager(int id, double salary, double bonus, double commission)
    {
        cout << "Inside SalesManager(int,double,double,double)" << endl;
    }
    ~SalesManager()
    {
        cout << "~Salesmanager()" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};

int main()
{
    Employee *arr[10];
    int index=0;
    int choice;
    int managerCount=0;
    int salesmanCount=0;
    int salesManagerCount=0;
   

    do{
        cout<<"0. Exit"<<endl;
        cout<<"1. Accept Employee"<<endl;
        cout<<"2. Display the count of all employees with respect to designation"<<endl;
        cout<<"3. Display All Managers"<<endl;
        cout<<"4. Display All Salesman"<<endl;
        cout<<"5. Display All SalesManagers"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 0:  cout<<"Thank you for using our App!"<<endl;
            break;

        case 1:    if(index<10)
                    {   int x;
                        cout<<"Enter the choice of Designation-"<<endl;
                        cout<<"Press 1 for Manager"<<endl;
                        cout<<"Press 2 for Salesman"<<endl;
                        cout<<"Press 3 for SalesManager"<<endl;
                        cin>>x;

                        if(x==1){
                            arr[index] = new Manager;
                            arr[index]->accept();
                            index++;
                            managerCount++;
                        }else if(x==2){
                            arr[index] = new Salesman;
                            arr[index]->accept();
                            index++;
                            salesmanCount++;
                        }else if(x==3){
                            arr[index] = new SalesManager;
                            arr[index]->accept();
                            index++;
                            salesManagerCount++;
                        }
                    }    
            break;

        case 2:    cout<<"The Manager Count is :"<<managerCount<<endl;
                   cout<<"The Salesman Count is :"<<salesmanCount<<endl;
                   cout<<"The SalesManager Count is :"<<salesManagerCount<<endl;
                
            break;

        case 3:    for(int i=0;i<index;i++){
                        if(typeid(*arr[i])== typeid(Manager)){
                            arr[i]->display();
                            cout<<"*************************************************************************************";
                        }
                    }
            break;

        case 4:    for(int i=0;i<index;i++){
                        if(typeid(*arr[i])== typeid(Salesman)){
                            arr[i]->display();
                        }
                    }
            break;

        case 5:    for(int i=0;i<index;i++){
                        if(typeid(*arr[i])== typeid(SalesManager)){
                            arr[i]->display();
                        }
                    }
            break;

        case 6:    for(int i=0;i<index;i++){
                        
                            arr[i]->display();
                        
                    }
            break;

        default:  cout<<"Invalid Choice"<<endl;
            break;
        }
    } while(choice!=0);

    for(int i=0; i<index;i++){
           delete arr[i];
           arr[i] = NULL;
        }

    return 0;
}