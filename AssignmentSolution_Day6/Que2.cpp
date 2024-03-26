/*
A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program
should be menu driven and should not cause memory leakage.
Hint - Create class Product and inherit into Book and Tape. Also create array like Product* arr[3]
*/

#include <iostream>
using namespace std;

class Product
{
    private:
    int id;
    string title;
    double price;
    
    public :
    virtual void accept()
    {
        cout << "Enter id :";
        cin  >> id;
        cout << "Enter Title : ";
        cin >> title;
        cout << "Enter Price : ";
        cin >> price;
    }

    virtual void display()
    {
        cout << "Id Is :"<<id<<endl;
        cout << "Title is : "<<title<<endl;
        cout << "Price is : "<<price<<endl;
    }

   void setPrice(int x)
   {
    if (x == 1)
    {
       price = price*0.90; 
    }
    else
    {
        price = price*0.95;
    }
   } 

 double getPrice()
 {
    return price;
 }

};

class Book : public Product
{
 private :
 string author;

 public :

 void accept()
 {
    cout << "Enter Author : ";
    cin >> author;
    Product::accept();
    Product::setPrice(1);
 }
 void display()
 {
    cout << "Author is :"<< author << endl;
    Product::display();
    cout << "The discount price is:"<<Product::getPrice()<<endl;

   
 }




};

class Tape : public Product
{
    private :
    string artist;
    
    public :
     void accept()
     {
        cout << "Enter the Artist : "<<endl;
        cin >> artist;
        Product::accept();
       Product::setPrice(2);
     }
     void display()
     {
        cout << "Artist is : "<< artist <<endl;
        Product::display();
        cout<<"The discounted Price is :: "<<Product::getPrice()<<endl;
     }


};
int main()
{
   int choice;
   Product*arr[3];
   int index = 0;
   double total;
   do
   {
    cout << "0. Exit"<< endl;
    cout << "1. Enter book details" << endl;
    cout << "2. Enter tape details" << endl;
    cout << "3. Total bill of three products" << endl;
    cout << "4.The product details are " << endl;
    cout << "Enter choice - ";
    cin >> choice;
    switch(choice)
    {
        case 0:
            cout << "Thank You.." << endl;
            break;
        
        case 1:
            if(index<3)
            {
                arr[index] = new Book();
                arr[index]->accept();
                index++;
            }
            else
                cout << "Array is full.." << endl;
            break;

        case 2:
            if (index < 3)
            {
                arr[index] = new Tape();
                arr[index]->accept();
                index++;
            }
            else
                cout << "Array is full.." << endl;
            break;
        case 3:
            for (int i = 0; i < index; i++)
                {

                    total +=arr[i]->getPrice();
                };
        cout << "The total price of all 3 products is " << total << endl;
                break;
                 case 4:
        for (int i = 0; i < index; i++)
                {
                    arr[i]->display();
                };
                break;
                
        default:
            cout << "Wrong choice.." << endl;
            break;
        }
    } while (choice != 0);

    for (int i = 0; i < index; i++)
        delete arr[i];
        
             
      return 0;  

    }


   