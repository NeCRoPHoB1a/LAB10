// 7
#include <iostream>
#include "fstream"
#include "string"
#include <vector>
#include <map>
#include <functional>


using namespace std;


ifstream in_users("users.txt");
ifstream in_1("1.txt");
ifstream in_2("2.txt");
ifstream in_3("3.txt");
ofstream out_users("users.txt");
ofstream out_1("1.txt");
ofstream out_2("2.txt");
ofstream out_3("3.txt");


struct users
{
    string pass, log, permision;
    void getdata();
    void printdata();
    void setdata();
};
void users::getdata()
{
    getline(in_users, log);
    getline(in_users, pass);
    getline(in_users, permision);
}
void users::setdata()
{
    out_users << log;
    out_users << pass;
    out_users << permision;
    out_users << "\n";
}


void users::printdata()
{
    cout << "\t Логин:" << log<<endl;
    cout << "\t Пароль:" << pass;
    cout << "\t Разрешение:" << permision;
    cout << endl;
}

int check_data(string log, string pass, vector<users>& mass)
{
    for (int i = 0; i < mass.size(); i++)
    {
        if (log == mass[i].log && pass==mass[i].pass)
        {
            return i;
        }
    }
    return -1;
}



class Admin{ 
private:
    string cm;
public:
    Admin() { cout << "\t1. Добавить пользывателей\n0. Выйти"; }
    void enter_user() 
    {   
        users u;
        cout << "Логин:";
        getline(cin, u.log);
        cout << "Пароль:";
        getline(cin, u.pass);

        u.permision = "adm";
        while (u.permision == "adm")
        {
            cout << "Права:";
            getline(cin, u.permision);
        }
        u.setdata();
    }
    void cmd() {cin >> cm;if (cm == "1"){enter_user();}}

};

class Read  {
private:
    string cm,s;
    void print() { while (in_3.peek() != EOF) { in_3 >> s; cout << s << endl; } }
public:
    Read() { cout << "\t1. Просмотреть файлй\t\n0. Выйти"; }
    void cmd() { cin >> cm; if (cm == "1") { print(); }}
};

class Write : protected Read {
private:
    string cm, s;
    void print() { while (in_3.peek() != EOF) { in_3 >> s; cout << s << endl; } }
    void qwest()
    {
        int a, b;
        while (in_1.peek() != EOF)
        { 
            in_1 >> a; 
            in_2 >> b;
            if (a == pow(2, b)) { out_3 << a; }
        }
    }
public:
    Write() { cout << "\t1. Просмотреть файлй\t\n2.Запись\t\n0. Выйти"; }
    void cmd() { cin >> cm; if (cm == "1") { print(); }if (cm == "2") { qwest(); }}
};





int main()
{
    setlocale(LC_ALL, "Russian");
    vector<users> list;
    users tip;
    int i = 0;
    string l;
    while (in_users.peek() != EOF)//считывание из файла
    {
        list.push_back(tip);
        list[i].getdata();
        i++;
        getline(in_users, l);
    }

    
    int flag_data= -1;
    string enter_pass, enter_log;

    while (flag_data<0)//ввод с клавы
    {
        cout << "Введите логин" << endl;
        getline(cin, enter_log);
        cout << "Введите пароль" << endl;
        getline(cin, enter_pass);

        flag_data = check_data(enter_log,enter_pass, list);
       
    }

    
    cout << "Меню:" << endl;
   
    if (list[flag_data].permision == "wr") { Write current_user; current_user.cmd();}
    if (list[flag_data].permision == "r") { Read current_user; current_user.cmd();}
    if (list[flag_data].permision == "adm") { Admin current_user; current_user.cmd();}


    in_1.close();
    in_2.close();
    in_users.close();

    system("Pause");
}
//User setup_user(string log, string pass) { User a(log, pass); return a; }
    //current_user->setDATA(list[flag_data].log, list[flag_data].pass);
   /* map<string, Admin(*)(string, string)> permitons;
    permitons["adm"] = &setup_adm;
    permitons["wr"] = &setup_adm;
    permitons["r"] = &setup_adm;

    int j = 0;
    Admin act_user = permitons[list[j].permision](list[j].log, list[j].pass);*/
    // Display all of the mapped functions
    //map<string, Admin(*)(string, string)>::const_iterator it = m.begin();
/*for (i = 0; i < list.size(); i++)
    {
        cout << i + 1 << ":" << endl;
        list[i].printdata();
    }*/
    // User current_user(list[flag_data].log, list[flag_data].pass);