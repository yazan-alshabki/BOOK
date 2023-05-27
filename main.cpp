#include "REGISTER.h"
#include <bits/stdc++.h>
using namespace std;
void Start()
{
    cout << "1- Sign up \n";
    cout << "2- Log in \n";
    cout << "Enter number from [1 - 2] :";
    int number ;
    cin >> number;
    while(cin.fail() || number > 2 || number < 1)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"You have to enter integer number from [1 to 2 ] " <<endl;
        cout<<endl;
        cin >> number;
    }

    if(number == 1)
    {
        cout << "1- admin \n";
        cout << "2- customer \n";
        cout << "Enter number 1 or 2 :";
        Point:
        int number ;
        cin >> number ;
        while(cin.fail() || number > 2 || number < 1)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"You have to enter integer number from [1 to 2 ] " <<endl;
            cout<<endl;
            cin >> number;
        }
        if(number == 1 )
        {
            fstream write("Admin.txt" , ios :: in | ios :: out | ios :: app);
            ifstream read("Admin_id.txt");
            write.clear();

            read.clear();
            int Admin_id;
            read >> Admin_id;
            int new_admin_id=Admin_id + 1;
            read.close();




            cout << "Enter your name :";
            string name ;
            cin >> name ;
            cout << endl;

            cout << "Enter your family :";
            string family ;
            cin >> family ;
            cout << endl;


            cout << "Enter your email :";
            string email ;
            cin >> email ;
            cout << endl;

            cout << "Enter your password :";
            string password ;
            cin >> password ;
            cout << endl;


            ofstream out("Admin_id.txt");
            out.clear();
            out << new_admin_id;
            out.close();


            write << new_admin_id << " ";
            write << name << " ";
            write << family << " ";
            write << email << " ";
            write << password << "\n";
            write.close();
            Start();
            return;

        }
        else
        {
            fstream write("Customer.txt" , ios :: in | ios :: out | ios :: app);
            ifstream read("Customer_id.txt");
            write.clear();

            read.clear();
            int Customer_id;
            read >> Customer_id;
            int new_customer_id=Customer_id + 1;
            read.close();




            cout << "Enter your name :";
            string name ;
            cin >> name ;
            cout << endl;

            cout << "Enter your family :";
            string family ;
            cin >> family ;
            cout << endl;


            cout << "Enter your email :";
            string email ;
            cin >> email ;
            cout << endl;

            cout << "Enter your password :";
            string password ;
            cin >> password ;
            cout << endl;

            ofstream out("Customer_id.txt");
            out.clear();
            out << new_customer_id;
            out.close();

            write << new_customer_id << " ";
            write << name << " ";
            write << family << " ";
            write << email << " ";
            write << password << "\n";
            write.close();
            Start();
            return;

        }

    }
    else
    {
        cout << "1- admin \n";
        cout << "2- customer \n";
        cout << "Enter number 1 or 2 :";
        int number ;
        cin >> number ;
        jump:

        while(cin.fail() || number > 2 || number < 1)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"You have to enter integer number from [1 to 2 ] " <<endl;
            cout<<endl;
            cin>>number;


        }



        if(number == 1)
        {
            cout << "Enter your name :";
            string user_name ;
            cin >> user_name;

            cout << "Enter your family :";
            string user_family ;
            cin >> user_family;

            cout << "Enter your password :";
            string user_password ;
            cin >> user_password;



            fstream read("Admin.txt" , ios :: in | ios :: out | ios :: app);
            read.clear();
            int id;
            while(read >> id)
            {
                string name , family , email , password;
                read >> name >> family >> email >> password;
                if(name == user_name && family == user_family && password == user_password)
                {
                    cout << "Hello "<<user_name << " "<<user_family << " "<<endl;
                    Admin user(id, name ,family , email , password);
                    user.Menu();
                    return;
                }
            }
            read.close();
            cout<< "Not valid ! \n";
            Start();
            return;


        }
        else
        {
            cout << "Enter your name :";
            string user_name ;
            cin >> user_name;

            cout << "Enter your family :";
            string user_family ;
            cin >> user_family;

            cout << "Enter your password :";
            string user_password ;
            cin >> user_password;



            fstream read("Customer.txt" , ios :: in | ios :: out | ios :: app);
            read.clear();
            int id;
            while(read >> id)
            {
                string name , family , email , password;
                read >> name >> family >> email >> password;
                if(name == user_name && family == user_family && password == user_password)
                {
                    cout << "Hello "<<user_name << " "<<user_family << "  !"<<endl;
                    Customer user(id, name ,family , email , password);
                    user.Menu();
                    return;
                }
            }
            read.close();
            cout<< "Not valid !\n";
            Start();
            return;

        }

    }
}

int main()
{
    Start();
}
