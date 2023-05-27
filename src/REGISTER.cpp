#include "REGISTER.h"

// ADMIN CLASS

Admin :: Admin(){};
Admin :: Admin(int id , string name , string family , string email ,string password)
{
    this -> id=id;
    this -> name=name;
    this -> family=family;
    this -> email=email;
    this -> password=password;
}

void Admin :: View_my_Profile()
{
    cout<<"Your id is :"<< id << endl;
    cout<<"Your name is :" << name << endl;
    cout<<"Your family is :" << family << endl;
    cout<<"Your email is :" << email << endl;
    cout<<"Your password is :"<< password << endl;
    Menu();
    return;
}
void Admin :: Add_book()
{
    fstream add_book("Books.txt" , ios :: in | ios :: out | ios :: app);
    ifstream read_id("Books_id.txt");
    add_book.clear();

    read_id.clear();
    int id ;
    read_id >> id;
    int new_id = id;
    new_id++;
    read_id.close();

    ofstream write_id("Books_id.txt");
    write_id.clear();
    write_id << new_id;
    write_id.close();


    cout << "Enter book name :"<<endl;
    string book_name;
    cin >> book_name;
    cout << endl;

    cout << "Enter number of sessions in book :"<<endl;
    int number;
    cin >> number;
    cout << endl;

    add_book << new_id <<" " ;
    add_book << this->id <<" ";
    add_book << book_name <<" " ;
    add_book << number <<" " ;

    for(int i=1 ; i<=number ; i++)
    {
        cout << "Enter number of pages in session "<<i<<" :";
        int number ;
        cin >> number ;
        add_book << number <<" " ;
    }
    add_book << "\n";
    add_book.close();
    Menu();
    return;
}
void Admin :: Delete_book()
{
    cout << "Enter id of book you want to delete :";
    int number;
    cin >> number;

    vector<Books>books;
    fstream read_book("Books.txt" , ios :: in | ios :: out | ios :: app);
    read_book.clear();

    bool you_can=false;
    int id;
    while(read_book >> id)
    {
        vector<int>sessions;
        int owner;
        string name;
        int number_of_session;
        read_book >> owner >> name >> number_of_session;
        for(int i=1;i<=number_of_session;i++)
        {
            int number_of_page;
            read_book >> number_of_page;
            sessions.push_back( number_of_page);
        }
        if(id == number && this->id == owner){you_can=true;continue;}
        else if(id == number && this->id != owner){cout << "You cant do that !"<<endl;break;}
        books.push_back(Books(id , owner , name , number_of_session , sessions));
    }
    read_book.close();
    if(!you_can){Menu();return;}

    ofstream write("Books.txt");
    write.clear();
    for(int i=0;i<books.size();i++)
    {
        write << books[i].id << " ";
        write << books[i].owner << " ";
        write << books[i].name << " ";
        write << books[i].session << " ";
        for(int j=0;j<books[i].sessions.size();j++)
        {
            write << books[i].sessions[j];
            if(j != books[i].sessions.size()-1)
            {
                write<<" ";
            }
            else write<<"\n";
        }

    }
    write.close();



    vector<read_list>reads;
    fstream read("Read_list.txt" , ios :: in | ios :: out | ios :: app);
    read.clear();
    int customer_id;
    while(read >> customer_id)
    {
        int book_id ,session_id, page_;
        read >> book_id >> session_id >> page_;
        if(book_id == number)
        {
            continue;
        }
        else reads.push_back(read_list(customer_id , book_id,session_id , page_));
    }
    read.close();

    ofstream wrtie_list("Read_list.txt");
    wrtie_list.clear();
    for(int i=0;i<reads.size();i++)
    {
        wrtie_list << reads[i].customer_id<<" ";
        wrtie_list << reads[i].book_id<<" ";
        wrtie_list << reads[i].session_id<<" ";
        wrtie_list << reads[i].page<<"\n";
    }
    wrtie_list.close();
    cout <<"You delete book : "<<number << endl;
    Menu();
    return;



}
void Admin :: List_books()
{
    fstream read_book("Books.txt" , ios :: in | ios :: out | ios :: app);
    read_book.clear();
    int id;
    bool i_have=false;;
    while(read_book >> id)
    {
        int owner;
        string name ;
        int number_of_session;
        read_book >> owner >> name >> number_of_session;
        if(owner == this->id)
        {
            cout << "Book "<<id <<" :"<<name<<" number of session :"<<number_of_session<<endl;
            i_have=true;
        }
        for(int i=1;i<=number_of_session;i++)
        {
            int number_of_page;
            read_book >> number_of_page;
        }
    }
    read_book.close();
    if(!i_have)
    {
        cout << "You do not have any book !"<<endl;
    }
    Menu();
    return;

};
void Admin :: Menu()
{
    cout << "1- View my profile \n";
    cout << "2- Add book \n";
    cout << "3- Delete book \n";
    cout << "4- List books \n";
    cout << "5- Log out \n";
    cout <<"Enter number 1 to 5:";
    int number ;
    cin >> number;
    while(cin.fail() || number > 5 || number < 1)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"You have to enter integer number from [1 to 5 ] " <<endl;
        cout<<endl;
        cin>>number;

    }
    if(number == 1)
    {
        View_my_Profile();
        return;
    }
    if(number == 2)
    {
        Add_book();
        return;
    }
    if(number == 3)
    {
        Delete_book();
        return;
    }
    if(number == 4)
    {
        List_books();
        return;
    }
    if(number == 5)
    {
        Start();
        return;
    }
    return;
}

// CUSTOMER CLASS

Customer :: Customer(){};
Customer :: Customer(int id ,string name ,string family ,string email , string password)
{
    this -> id=id;
    this -> name=name;
    this -> family=family;
    this -> email=email;
    this -> password=password;
};
void Customer :: View_my_Profile()
{
    cout<<"Your id is :"<< this->id << endl;
    cout<<"Your name is :" << this->name << endl;
    cout<<"Your family is :" << this->family << endl;
    cout<<"Your email is :" << this->email << endl;
    cout<<"Your password is :"<< this->password << endl;
    Menu();
    return;
};
void Customer :: List_books()
{
    fstream read_book("Books.txt" , ios :: in | ios :: out | ios :: app);
    read_book.clear();
    int id;
    bool found=false;
    while(read_book >> id)
    {
        int owner;
        string name ;
        int number_of_session;
        read_book >> owner >> name >> number_of_session;

        cout << "Book "<<id <<" :"<<name<<" number of session :"<<number_of_session<<endl;

        for(int i=1;i<=number_of_session;i++)
        {
            int number_of_page;
            read_book >> number_of_page;
        }
        found=true;
    }
    if(!found){cout << "there is not book in system !"<<endl;}
    read_book.close();


    Menu();
    return;

};
void Customer :: My_current_reading_session()
{
    fstream read("Read_list.txt" , ios :: in | ios :: out | ios :: app);
    read.clear();
    int customer_id;
    bool i_read=false;
    bool you_read_at_least_one_book=false;
    while(read >> customer_id)
    {
        int book_id ,session_id, page_;
        read >> book_id >> session_id >> page_;
        if(customer_id == this->id)
        {
            you_read_at_least_one_book=true;
            string book_name="-1";

            fstream read_book("Books.txt" , ios :: in | ios :: out | ios :: app);
            read_book.clear();
            int id;
            while(read_book >> id)
            {
                int owner;
                string name ;
                int number_of_session;
                read_book >>owner>> name >> number_of_session;
                for(int i=1;i<=number_of_session;i++)
                {
                    int number_of_page;
                    read_book >> number_of_page;
                }
                if(id == book_id){book_name=name;break;}
            }
            read_book.close();
            if(book_name != "-1")cout <<"Book :"<< book_name  <<" sessoin :"<<session_id<<" Page :"<<page_<<endl;
        }
    }
    read.close();
    if(!you_read_at_least_one_book)
    {
        cout << "You have not read any book yet !"<<endl;
    }
    Menu();
    return;
};
void Customer :: Read()
{
    cout <<"Enter book id :";
    int number;
    cin >> number;

    bool valid=false;
    int valid_session=0;
    fstream read_book("Books.txt" , ios :: in | ios :: out | ios :: app);
    read_book.clear();
    int id;
    while(read_book >> id)
    {
        int owner;
        string name ;
        int number_of_session;
        read_book >>owner>> name >> number_of_session;
        for(int i=1;i<=number_of_session;i++)
        {
            int number_of_page;
            read_book >> number_of_page;
        }
        if(id == number){valid=true;valid_session=number_of_session;break;}
    }
    read_book.close();
    if(!valid)
    {
        cout << "This book is not valid !"<<endl;
        Menu();
    }

    else
    {
        cout << "Enter session id :" << endl;
        int number_session;
        cin >> number_session;
        if(number_session > valid_session || number_session < 1)
        {
            cout << "This book is not valid !"<<endl;
            Menu();
            return ;
        }


        map<int,int>pages_;

        fstream read_book("Books.txt" , ios :: in | ios :: out | ios :: app);
        read_book.clear();
        int id;
        while(read_book >> id)
        {
            int owner;
            string name ;
            int number_of_session;
            read_book >>owner>> name >> number_of_session;
            for( int i=1 ; i<=number_of_session ; i++ )
            {
                int number_of_page;
                read_book >> number_of_page;
                if(id == number){pages_[i]=number_of_page + 1;}
            }
        }
        read_book.close();

        map<int,int>where_i_am;
        fstream read("Read_list.txt" , ios :: in | ios :: out | ios :: app);
        read.clear();
        int customer_id;
        while(read >> customer_id)
        {
            int book_id , session_id , page;
            read >> book_id >> session_id >> page;
            if(book_id == number)
            {
                where_i_am[session_id]=page;
            }
        }
        read.close();

        int pages =where_i_am[number_session];
        cout <<"session id:"<<number<< " page:" <<pages<<endl;

        while(true)
        {
            cout <<"1 next page \n";
            cout <<"2 previous page \n";
            cout <<"3 stop read \n";
            cout << "Enter number [1 - 3] :";

            int choice;
            cin >> choice;
            if(choice == 1)
            {
                pages++;
                if(pages == pages_[number_session])
                {
                    number_session++;
                    if(number_session > (int)pages_.size()){number_session=pages_.size();pages--;cout << "You can not" << endl;continue;}
                    else
                    {
                        pages = 1 ;
                    }
                }
                where_i_am[number_session]=pages;
                cout << "session id: "<<number_session<<" "<<"page :"<<pages<<endl;
            }
            else if(choice == 2)
            {
                pages--;
                if(pages == 0)
                {
                    number_session--;
                    if(number_session < 1 ){number_session = 1;pages++;cout << "You can not" << endl;continue;}
                    else
                    {
                        pages = pages_[number_session] - 1;
                    }
                }
                where_i_am[number_session]=pages;
                cout << "session id: "<<number_session<<" "<<"page :"<<pages<<endl;
            }
            else if(choice == 3)
            {
                vector<read_list>reads;
                fstream read("Read_list.txt" , ios :: in | ios :: out | ios :: app);
                read.clear();
                int customer_id;
                bool valid=false;
                while(read >> customer_id)
                {
                    int book_id ,session_id, page_;
                    read >> book_id >> session_id >> page_;
                    if(customer_id == this->id && book_id == number)
                    {
                        valid=true;
                        reads.push_back(read_list(customer_id , book_id ,session_id, where_i_am[page_]));;
                    }
                    else reads.push_back(read_list(customer_id , book_id,session_id , page_));
                }
                read.close();

                ofstream write("Read_list.txt");
                write.clear();
                for(int i=0;i<reads.size();i++)
                {
                    write << reads[i].customer_id<<" ";
                    write << reads[i].book_id<<" ";
                    write << reads[i].session_id<<" ";
                    write << reads[i].page<<"\n";
                }

                if(!valid)
                {
                    for(auto p : where_i_am)
                    {
                        write << this->id << " ";
                        write << number <<" ";
                        write << p.first << " ";
                        write << p.second << "\n";
                    }
                }
                write.close();
                break;
            }
        }
        Menu();
        return;
    }
};
//void Customer :: Log_out();
void Customer :: Menu()
{
    cout << "1- View my profile \n";
    cout << "2- List books \n";
    cout << "3- My_current_reading_session \n";
    cout << "4- Read book \n";
    cout << "5- Log out \n";
    cout <<"Enter number 1 to 5:";
    int number ;
    cin >> number;
    while(cin.fail() || number > 5 || number < 1)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"You have to enter integer number from [1 to 5 ] " <<endl;
        cout<<endl;
        cin>>number;
    }

    if(number == 1)
    {
        View_my_Profile();
        return;
    }
    if(number == 2)
    {
        List_books();
        return;
    }
    if(number == 3)
    {
        My_current_reading_session();
        return;
    }
    if(number == 4)
    {
        Read();
        return;
    }
    if(number == 5)
    {
        Start();
        return;
    }


};







