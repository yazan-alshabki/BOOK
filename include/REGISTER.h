#ifndef REGISTER_H
#define REGISTER_H
#include <bits/stdc++.h>
using namespace std;
void Start();
struct read_list
{
    int customer_id;
    int book_id;
    int session_id;
    int page;

    read_list(int customer_id2,int session_id2 , int book_id2 , int page2)
    {
        customer_id = customer_id2;
        book_id = book_id2;
        session_id = session_id2;
        page=page2;
    }
};
struct Books
{
    int id;
    int owner;
    string name ;
    int session;
    vector<int>sessions;

    Books(int id2 ,int owner2, string name2 , int session2 ,vector<int>sessions2)
    {
        id = id2;
        owner=owner2;
        name = name2;
        session = session2;
        sessions = sessions2;
    }

};
class Admin{
private :
    int id ;
    string name ;
    string family ;
    string email ;
    string password ;
public:
    Admin();
    Admin(int id , string name , string family , string email ,string password);
    void View_my_Profile();
    void Add_book();
    void Delete_book();
    void List_books();
    void Log_out();
    void Menu();
};



class Customer {
private:
    int id ;
    string name ;
    string family ;
    string email ;
    string password ;
public:
    Customer();
    Customer(int id ,string name ,string family ,string email , string password);
    void View_my_Profile();
    void List_books();
    void My_current_reading_session();
    void Read();
    void Log_out();
    void Menu();

};


#endif // REGISTER_H
