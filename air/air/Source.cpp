#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include<vector>
#include<unordered_map>
#include<iterator>
#include<algorithm>
#include"admin.h"
#include"user.h"
using namespace std;
void signIn();
admin a;
user u;
int main()
{
    int choice;
    while (true)
    {
        cout << "1. Sign up" << endl;
        cout << "2. Sign in" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Please enter a number" << endl;
            continue;
        }
        if (choice == 1)
        {
            system("cls");
            u.signup();
        }
        else if (choice == 2)
        {
            system("cls");
            signIn();
        }
        else if (choice == 3)
        {
            return 0;
        }
        else
        {
            cout << "Please enter a number between 1 and 3" << endl;
        }
    }
}
void signIn()
{
    int choice;
    string username, password;
    cout << "Choose one of the following options: " << endl;
    cout << "1. Sign in as admin" << endl;
    cout << "2. Sign in as a user" << endl;
    cout << "3. exit" << endl;
    cin >> choice;
    if (choice == 1) {
        system("cls");
        cout << "Sign in as admin" << endl;
        cout << "Enter your username: " << endl;
        cin >> username;
        cout << "Enter your password: " << endl;
        cin >> password;
        if (username == "admin" && password == "1234") {
            cout << "Hello admin" << endl;
            system("cls");
            a.admin_fun();
        }
        else {
            system("cls");
            cout << "Invalid username or password" << endl;
        }
    }
    else if (choice == 2) {
        system("cls");
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;
        ifstream myfile;
        myfile.open("user.txt");
        string line;
        while (getline(myfile, line)) {
            string firstName, lastName, user, pass;
            int i = 0;
            while (line[i] != ' ') {
                firstName += line[i];
                i++;
            }
            i++;
            while (line[i] != ' ') {
                lastName += line[i];
                i++;
            }
            i++;
            while (line[i] != ' ') {
                user += line[i];
                i++;
            }
            i++;
            while (i < line.length()) {
                pass += line[i];
                i++;
            }
            if (user == username && pass == password) {
                cout << "Hello " << firstName << " " << lastName << endl;
                system("cls");
                u.user_fun();
                myfile.close();
                return;
            }
        }
        system("cls");
        cout << "Wrong username or password" << endl;
        myfile.close();
    }
    else if (choice == 3) {
        system("cls");
        return;
    }
    else {
        cout << "Invalid choice" << endl;
    }
}