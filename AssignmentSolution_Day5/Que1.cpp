/*
Q1. Implement following classes. Test all functionalities in main().
Create a class Date with data memebrs day,month and year.
Cretae a class Person with data members name,address and birthdate. The birthdate should be of
type date.
Create a class Employee with data members id, sal, dept and joining date. The joining date should
be of type date.
*/

#include <iostream>
using namespace std;

class Date
{
    private:

    int day;
    int  month;
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
    Date dob;

    public:

    Person()
    {
        name="";
        address="";
    }

    void acceptPersonDatails()
    {
        cout<<"Name:";
        cin>>name;
        cout<<"Address:";
        cin>>address;
        cout<<"Enter Date of Birth:"<<endl;
        dob.acceptDate();
    }

    void displayPerson()
    {
        cout<<"Name:"<<endl;
        cout<<"Address:"<<address;
        dob.displayDate();
    }
};

class Employee
{
    private:

    int empid;
    double sal;
    string dept;
    Date doj;

    public:

    Employee()
    {
        empid=0;
        sal=0;
        dept="";
    }

    void acceptEmployee()
    {
        cout<<"Enter Employee ID:";
        cin>>empid;
        cout<<"Enter Salary:";
        cin>>sal;
        cout<<"Enter Department:";
        cin>>dept;
        cout<<"Enter Date of Joining:"<<endl;
        doj.acceptDate();
    }

    void displayEmployee()
    {
        cout<<"Employee ID:"<<empid<<endl;
        cout<<"Salary:"<<sal<<endl;
        cout<<"Department:"<<dept<<endl;
        doj.displayDate();
    }
};
 

int main()
{
    // Date d;
    // d.acceptDate();
    // d.displayDate();

    // Person p;
    // p.acceptPersonDatails();
    // p.displayPerson();

    Employee e;
    e.acceptEmployee();
    e.displayEmployee();

    return 0;
}