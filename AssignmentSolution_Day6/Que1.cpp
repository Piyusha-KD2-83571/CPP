/*Q1. Create a class Date with data memebrs day,month and year.
Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of
type Date.
Cretae a class Employee with data members id, sal, dept and joining date. The joining date should
be of type date.
Employee class should be inherited from Person.
Implement following classes. Test all functionalities in main().*/

#include <iostream>
using namespace std;

class Date
{
    private:

    int day;
    int month;
    int year;

    public:

    Date()
    {
        day=1;
        month=1;
        year=2000;
    }

    void acceptDate()
    {
        cout<<"Enter Day:"<<endl;
        cin>>day;
        cout<<"Enter month:"<<endl;
        cin>>month;
        cout<<"Enter year:"<<endl;
        cin>>year;
    }

    void displayDate()
    {
        cout<<"Date is:"<<day<<"/"<<month<<"/"<<year<<endl;
    }
};

class Person
{
    private:
    
    string name;
    string address;
    Date *birthDate;

    public:

    Person()
    {
        name="";
        address="";
        birthDate = new Date;
    }

    void acceptData()
    {
        cout<<"Name:";
        cin>>name;
        cout<<"Address:";
        cin>>address;
        cout<<"Enter Date of Birth:"<<endl;
        birthDate->acceptDate();
    }

    void displayData()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Address:"<<address<<endl;
        cout << "BirthDate :"<<endl;
        birthDate->displayDate();
    }

    ~Person()
    {
        delete birthDate;
        birthDate = NULL;
    }
};

class Employee : public Person
{
    private:

    int empid;
    double sal;
    string dept;
    Date *doj;

    public:

    Employee()
    {
        empid=0;
        sal=0;
        dept="";
        doj = new Date;
    }

    void acceptData()
    {
        cout<<"Enter Employee ID:";
        cin>>empid;
        cout<<"Enter Salary:";
        cin>>sal;
        cout<<"Enter Department:";
        cin>>dept;
        cout<<"Enter Date of Joining:"<<endl;
        doj->acceptDate();
    }

    void displayData()
    {   Person :: displayData();
        cout<<"Employee ID:"<<empid<<endl;
        cout<<"Salary:"<<sal<<endl;
        cout<<"Department:"<<dept<<endl;
        doj->displayDate();
    } 
    
    ~Employee()
    {
        delete doj;
        doj = NULL;
    }

    
};
 

int main()
{
    
    Person *ptr = new Employee;
    ptr->acceptData();
    ptr->displayData();

    // Person P1;
    // P1.acceptData();
    // P1.displayData();

    // Employee e;
    // e.acceptData();
    // e.displayData();
    






   

    return 0;
}