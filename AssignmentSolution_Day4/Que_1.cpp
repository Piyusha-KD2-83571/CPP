/*
Q1. Stack is a Last-In-First-Out data structure. Write a Stack class. It implements stack using
Dynamically allocated array. Stack size should be passed in parameterized constructor. If size is not
given, allocate stack of size 5.
Provide member functions like push(), pop(), peek(), isEmpty(), isFull(), and print().
*/
#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *ptr;

public:
    Stack(int size = 5)
    {
        this->size = size;
        top = -1;
        ptr = new int[size];
    }

    void push(int element)
    {
        if (!isFull())
        {
           top=top+1;
           ptr[top]=element;
        }
        else
            cout << "Stack Overflow" << endl;
    }
    void pop()
    
    {
        cout<<"After Deleting Value:"<<endl;
        if (!isEmpty())
            top--;
        else
            cout << "Stack underflow" << endl;
    }
    int peek()
    {
        return ptr[top];
    }
    void print()
    {
        if (isEmpty())
        {
            cout<<"Stack is Empty."<<endl;
        }
        else
        {
            for(int i=0;i<=top;++i)
            {
                cout<<ptr[i]<<" ";
            }
            cout<<endl;
        }
        
    }
    bool isFull()
    {
        return top == (size - 1);
    }
    bool isEmpty()
    {
        return top == -1;
    }
    ~Stack()
    {
        delete[] ptr;
        ptr = NULL;
    }
};

int main()
{
    Stack s;
    s.push(2);
    s.push(3);
    s.push(7);
    s.push(9);
    s.push(5);
    s.push(0);  //stack overflow
    s.print();
    s.pop();    //deleting value
    s.print();

    return 0;
}
