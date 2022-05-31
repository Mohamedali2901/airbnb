#include "admin.h"
list<pair<string, pair<int, int>>> admin::load_avilable_places()
{
    list<pair<string, pair<int, int>>> places_list;
    ifstream infile;
    infile.open("available_places.txt");
    string place_location;
    int price;
    int availability;
    while (infile >> place_location >> price >> availability)
    {
        places_list.push_back(make_pair(place_location, make_pair(price, availability)));
    }
    infile.close();
    return places_list;
}

list<pair<string, pair<int, int>>> admin::load_reserved_places()
{

    list<pair<string, pair<int, int>>> places_list;
    ifstream infile;
    infile.open("reserved_places.txt");
    string place_location;
    int price;
    int availability;
    while (infile >> place_location >> price >> availability)
    {
        places_list.push_back(make_pair(place_location, make_pair(price, availability)));
    }
    infile.close();
    return places_list;

}

void admin::modify_user()
{
    string username;
    cout << "Enter the username you want to modify: ";
    cin >> username;
    ifstream fin;
    fin.open("user.txt");
    string line;
    string user[100];
    int i = 0;
    while (getline(fin, line))
    {
        user[i] = line;
        i++;
    }
    fin.close();
    ofstream fout;
    fout.open("user.txt");
    for (int j = 0; j < i; j++)
    {
        if (user[j].find(username) != string::npos)
        {
            cout << "Enter the new information for the user: " << endl;
            string new_firstName, new_lastName, new_userName, new_password;
            cout << "Enter the new first name: ";
            cin >> new_firstName;
            cout << "Enter the new last name: ";
            cin >> new_lastName;
            cout << "Enter the new user name: ";
            cin >> new_userName;
            cout << "Enter the new password: ";
            cin >> new_password;
            user[j] = new_firstName + " " + new_lastName + " " + new_userName + " " + new_password;
        }
        fout << user[j] << endl;
    }
    fout.close();
    system("cls");
}
void admin::delete_user()
{
    string username;
    cout << "Enter the username you want to delete: ";
    cin >> username;
    ifstream fin;
    fin.open("user.txt");
    string line;
    string user[100];
    int i = 0;
    while (getline(fin, line))
    {
        user[i] = line;
        i++;
    }
    fin.close();
    ofstream fout;
    fout.open("user.txt");
    for (int j = 0; j < i; j++)
    {
        if (user[j].find(username) != string::npos)
        {
            user[j] = "";
        }
        fout << user[j] << endl;
    }
    fout.close();
    system("cls");
}

void admin::print_available_places()
{
    cout << "the available places are:" << endl << endl;
    list<pair<string, pair<int, int>>> places_list = load_avilable_places();
    for (auto it = places_list.begin(); it != places_list.end(); it++) {
        cout << it->first << " " << it->second.first << " " << it->second.second << endl  << "-----------------------------" << endl;
    }
}

void admin::print_reserved_places()
{
    cout << "the reserved places are:" << endl << endl;
    list<pair<string, pair<int, int>>> reserved_places = load_reserved_places();
    for (auto it = reserved_places.begin(); it != reserved_places.end(); it++) {
        cout << it->first << " " << it->second.first << " " << it->second.second << endl << "-----------------------------" << endl;
    }
}

void admin::show_places()
{
    while (true) {
        int choice;
        cout << "1. Print available places" << endl;
        cout << "2. Print reserved places" << endl;
        cout << "3. exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Please enter a number" << endl;
            continue;
        }
        switch (choice) {
        case 1:
            system("cls");
            print_available_places();
            break;
        case 2:
            system("cls");
            print_reserved_places();
            break;
        case 3:
            system("cls");
            return;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}

void admin::delete_reserved_places()
{
    print_reserved_places();
    string place_name;
    cout << "Enter the place name you want to delete: ";
    cin >> place_name;
    ifstream fin;
    fin.open("reserved_places.txt");
    string line;
    string reserved_places[100];
    int i = 0;
    while (getline(fin, line))
    {
        reserved_places[i] = line;
        i++;
    }
    fin.close();
    ofstream fout;
    fout.open("reserved_places.txt");
    for (int j = 0; j < i; j++)
    {
        if (reserved_places[j].find(place_name) != string::npos)
        {
            reserved_places[j] = "";
        }
        fout << reserved_places[j] << endl;
    }
    fout.close();
    system("cls");
}

void admin::delete_available_places()
{
    print_available_places();
    string place_name;
    cout << "Enter the place name you want to delete: ";
    cin >> place_name;
    ifstream fin;
    fin.open("available_places.txt");
    string line;
    string available_places[100];
    int i = 0;
    while (getline(fin, line))
    {
        available_places[i] = line;
        i++;
    }
    fin.close();
    ofstream fout;
    fout.open("available_places.txt");
    for (int j = 0; j < i; j++)
    {
        if (available_places[j].find(place_name) != string::npos)
        {
            available_places[j] = "";
        }
        fout << available_places[j] << endl;
    }
    fout.close();
    system("cls");
}

void admin::delete_place()
{
    while (true) {
        int choice;
        cout << "1. Delete from the reserved places" << endl;
        cout << "2. Delete form the available places" << endl;
        cout << "3. exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Please enter a number" << endl;
            continue;
        }
        switch (choice)
        {
        case 1:
            system("cls");
            delete_reserved_places();
            break;
        case 2:
            system("cls");
            delete_available_places();
            break;
        case 3:
            system("cls");
            return;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}

void admin::modify_reserved_place()
{
    cout << "the reserved places are:" << endl;
    list<pair<string, pair<int, int>>> places_list = load_reserved_places();
    for (auto it = places_list.begin(); it != places_list.end(); it++) {
        cout << it->first << " " << it->second.first << " " << it->second.second << endl << "-----------------------------" << endl;
    }
    string place_name;
    cout << "Enter the place name you want to modify: ";
    cin >> place_name;
    string new_place_name;
    cout << "Enter the new place name: ";
    cin >> new_place_name;
    int price;
    cout << "Enter the price: ";
    cin >> price;
    int availablity_time;
    cout << "Enter the new availablity time: ";
    cin >> availablity_time;
    ifstream fin;
    fin.open("reserved_places.txt");
    string line;
    string reserved_places[100];
    int i = 0;
    while (getline(fin, line))
    {
        reserved_places[i] = line;
        i++;
    }
    fin.close();
    ofstream fout;
    fout.open("reserved_places.txt");
    for (int j = 0; j < i; j++)
    {
        if (reserved_places[j].find(place_name) != string::npos)
        {
            reserved_places[j] = new_place_name + " " + to_string(price) + " " + to_string(availablity_time);
        }
        fout << reserved_places[j] << endl;
    }
    fout.close();
    system("cls");
}

void admin::modify_available_place()
{
    cout << "the available places are:" << endl;
    list<pair<string, pair<int, int>>> places_list = load_avilable_places();
    for (auto it = places_list.begin(); it != places_list.end(); it++) {
        cout << it->first << " " << it->second.first << " " << it->second.second << endl << "-----------------------------" << endl;
    }
    string place_name;
    cout << "Enter the place name you want to modify: ";
    cin >> place_name;
    string new_place_name;
    cout << "Enter the new place name: ";
    cin >> new_place_name;
    int price;
    cout << "Enter the price: ";
    cin >> price;
    int availablity_time;
    cout << "Enter the new availablity time: ";
    cin >> availablity_time;
    ifstream fin;
    fin.open("available_places.txt");
    string line;
    string available_places[100];
    int i = 0;
    while (getline(fin, line))
    {
        available_places[i] = line;
        i++;
    }
    fin.close();
    ofstream fout;
    fout.open("available_places.txt");
    for (int j = 0; j < i; j++)
    {
        if (available_places[j].find(place_name) != string::npos)
        {
            available_places[j] = new_place_name + " " + to_string(price) + " " + to_string(availablity_time);
        }
        fout << available_places[j] << endl;
    }
    fout.close();
    system("cls");
}

void admin::modify()
{
    while (true) {
        int choice;
        cout << "1. Modify the reserved places" << endl;
        cout << "2. Modify the available places" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Please enter a number" << endl;
            continue;
        }
        switch (choice) {
        case 1:
            system("cls");
            modify_reserved_place();
            break;
        case 2:
            system("cls");
            modify_available_place();
            break;
        case 3:
            system("cls");
            return;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}

void admin::admin_fun()
{
    while (true)
    {
        int choice;
        cout << "1. edit user's profile" << endl;
        cout << "2. modify_places" << endl;
        cout << "3. delete_places" << endl;
        cout << "4. show places" << endl;
        cout << "5. dashboard" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Please enter a number" << endl;
            continue;
        }
        switch (choice)
        {
        case 1:
            system("cls");
            edit_profile();
            break;
        case 2:
            system("cls");
            modify();
            break;
        case 3:
            system("cls");
            delete_place();
            break;
        case 4:
            system("cls");
            show_places();
            break;
        case 5:
            system("cls");
            dashboard();
            break;
        case 6:
            system("cls");
            return;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}

void admin::edit_profile()
{
    while (true) {
        int choice;
        cout << "1. Modify" << endl;
        cout << "2. Delete" << endl;
        cout << "3. exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Please enter a number" << endl;
            continue;
        }
        switch (choice)
        {
        case 1:
            system("cls");
            modify_user();
            break;
        case 2:
            system("cls");
            delete_user();
            break;
        case 3:
            system("cls");
            return;
        default:
            cout << "Please enter a valid choice" << endl;
            break;
        }
    }
}

void admin::dashboard()
{
    system("cls");
    int counter = 1;
    cout << " the active user  is \n ";
    ifstream f;
    f.open("user.txt");

    string user;
    getline(f, user);

    while (getline(f, user))
    {
        cout << counter << "  ";
        counter++;
        cout << user << endl;
        cout << "------------------------------- \n";


    }
    cout << " the number of user  is : " << counter - 1 << endl;
    cout << "****************** \n ";
    print_available_places();
    cout << "****************** \n ";
    print_reserved_places();
    int choice;
    cout << " to exit press  1 " << endl;
    cin >> choice;
    if (choice == 1) {
        system("cls");
        return;
    }
    else
        cout << "invaid input \n";
    dashboard();
}
