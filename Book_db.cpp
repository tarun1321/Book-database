#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class db
{
public:
    char title[20],auth[20],place[20];
    int cost;
    long isbn;
};
void enter_detail()
{
    ofstream fin;
    db ob;
    fin.open("book_db",ios::app);
    system("cls");
    cout<<"  Book title- ";
    fflush(stdin);
    cin.getline(ob.title,20);
    cout<<"  ISBN- ";
    fflush(stdin);
    cin>>ob.isbn;
    cout<<"  Author- ";
    fflush(stdin);
    cin>>ob.auth;
    cout<<"  Place- ";
    fflush(stdin);
    cin>>ob.place;
    cout<<"  Cost- ";
    fflush(stdin);
    cin>>ob.cost;
    fin.write((char*)&ob,sizeof(db));
    fin.close();
    return;
}
void search()
{
    int ch;
    db ob;
    char str[20];
    long is;
    ifstream fin;
    fin.open("book_db",ios::app);
    system("cls");
    cout<<endl<<endl<<endl;
    cout<<"  1--Search by Book Title\n";
    cout<<"  2--Search by ISBN\n";
    cout<<"  3--Search by Author\n";
    cout<<"  4--Go Back\n";
    cout<<endl<<endl<<endl<<endl<<"       Enter your choice ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        {
            system("cls");
            cout<<endl<<endl<<"   Enter Book Title :";
            fflush(stdin);
            cin>>str;
            while(fin.read((char*)&ob,sizeof(db)))
                {
                    if(!strcmp(str,ob.title))
                    {
                    cout<<endl<<" Match found!!!"<<endl<<endl<<endl;
                    cout<<"  Book title- "<<ob.title<<endl;
                    cout<<"  ISBN- "<<ob.isbn<<endl;
                    cout<<"  Author- "<<ob.auth<<endl;
                    cout<<"  Place- "<<ob.place<<endl;
                    cout<<"  Cost- "<<ob.cost<<endl;
                    break;
                    }
                }
            if((strcmp(str,ob.title))) cout<<"\n Not found";
            getch();
            break;
        }
    case 2:
        {
            system("cls");
            cout<<endl<<endl<<"   Enter ISBN :";
            cin>>is;
            while(fin.read((char*)&ob,sizeof(db)))
                {
                    if(ob.isbn==is)
                   {
                    cout<<endl<<" Match found!!!"<<endl<<endl<<endl;
                    cout<<"  Book title - \t"<<ob.title<<endl<<endl;
                    cout<<"  ISBN       - \t"<<ob.isbn<<endl<<endl;
                    cout<<"  Author     - \t"<<ob.auth<<endl<<endl;
                    cout<<"  Place      - \t"<<ob.place<<endl<<endl;
                    cout<<"  Cost       - \t"<<ob.cost<<endl<<endl;
                    break;
                   }
                }
            if(ob.isbn!=is) cout<<"\n Not found";
            getch();
            break;
        }
    case 3:
        {
            system("cls");
            cout<<endl<<endl<<"   Enter Author :";
            fflush(stdin);
            cin>>str;
            while(fin.read((char*)&ob,sizeof(db)))
                {
                    if(!strcmp(str,ob.auth))
                    {
                    cout<<endl<<" Match found!!!"<<endl<<endl<<endl;
                    cout<<"  Book title- "<<ob.title<<endl;
                    cout<<"  ISBN- "<<ob.isbn<<endl;
                    cout<<"  Author- "<<ob.auth<<endl;
                    cout<<"  Place- "<<ob.place<<endl;
                    cout<<"  Cost- "<<ob.cost<<endl;
                    break;
                    }
                }
            if(strcmp(str,ob.auth)) cout<<"\n Not found";
            getch();
            break;
        }
    case 4: int main();
    default: {
                cout<<" INVALID CHOICE";
                getch();
            }

    }
    fin.close();
}
int main()
{
    int ch;
    while(true)
    {
        system("cls");
        cout<<endl<<endl;
        cout<<"  1--Enter a book details\n";
        cout<<"  2--Search\n";
        cout<<"  3--Exit\n";
        cout<<endl<<endl<<endl<<endl<<"       Enter your choice ";
        cin>>ch;
        switch(ch)
        {
        case 1:{
                    enter_detail();
                    break;
                }
        case 2:{
                    search();
                    break;
                }
        /*case 4: {
                system("cls");
            fflush(stdin);
            while(fin.read((char*)&ob,sizeof(db)))
                {
                    if(!ob))
                    {
                    cout<<endl<<" Match found"<<endl<<endl<<endl;
                    cout<<"  Book title- "<<ob.title<<endl;
                    cout<<"  ISBN- "<<ob.isbn<<endl;
                    cout<<"  Author- "<<ob.auth<<endl;
                    cout<<"  Place- "<<ob.place<<endl;
                    cout<<"  Cost- "<<ob.cost<<endl;
                    break;
                    }
                }
            if(strcmp(str,ob.auth)) cout<<"\n Not found";
            getch();
            break;

            }*/
        case 3: exit(0);
        }
    }
    return 0;
}
