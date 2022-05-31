#include "user.h"
void user::signup()
{
    string first_name;
    string last_name;
    string username;
    string password;
    cout << "Enter your first name: ";
    cin >> first_name;
    cout << "Enter your last name: ";
    cin >> last_name;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    vector<string> users;
    ifstream fin;
    fin.open("user.txt");
    string line;
    while (getline(fin, line))
    {
        users.push_back(line);
    }
    fin.close();
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].find(username) != string::npos)
        {
            system("cls");
            cout << "The username is already taken please try again" << endl;
            return;
        }
    }
    ofstream fout;
    fout.open("user.txt", ios::app);
    fout << first_name + " " + last_name + " " + username + " " + password + "\n";
    fout.close();
    system("cls");
}

void user::store_places()
{
    string place_location;
    int price;
    int availability;
    ofstream outfile;
    outfile.open("available_places.txt", ios::app);
    cout << "enter the place location" << endl;
    cin >> place_location;
    cout << "enter the price" << endl;
    cin >> price;
    cout << "enter the month that the place will be available" << endl;
    cin >> availability;
    outfile << place_location << " " << price << " " << availability << endl;
    outfile.close();
    system("cls");

}

list<pair<string, pair<int, int>>> user::load_avilable_places()
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

list<pair<string, pair<int, int>>> user::load_reserved_places()
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

void user::search_places()
{
    unordered_map<string, pair<int, int>> places_map;
    ifstream infile;
    infile.open("available_places.txt");
    string place_location;
    int price;
    int availability;
    while (infile >> place_location >> price >> availability)
    {
        places_map.insert(make_pair(place_location, make_pair(price, availability)));
    }
    infile.close();
    string place_location_search;
    int price_search;
    int availability_search;
    cout << "enter the place location" << endl;
    cin >> place_location_search;
    cout << "enter the price" << endl;
    cin >> price_search;
    cout << "enter the month that you want to reserve the place" << endl;
    cin >> availability_search;
    if (places_map.find(place_location_search) != places_map.end() && places_map[place_location_search].first == price_search && places_map[place_location_search].second == availability_search)
    {
        system("cls");
        cout << "the place is available" << endl;
        cout << "place location: " << place_location_search << endl;
        cout << "price: " << price_search << endl;
        cout << "availability: " << availability_search << endl;
        cout << "do you want to reserve the place? (y/n)" << endl;
        char choice;
        cin >> choice;
        if (choice == 'y')
        {
            ofstream outfile;
            outfile.open("reserved_places.txt", ios::app);
            outfile << place_location_search << " " << price_search << " " << availability_search << endl;
            outfile.close();
            places_map.erase(place_location_search);
            ofstream outfile2;
            outfile2.open("available_places.txt");
            for (auto it = places_map.begin(); it != places_map.end(); it++)
            {
                outfile2 << it->first << " " << it->second.first << " " << it->second.second << endl;
            }
            outfile2.close();
            cout << "the place has been reserved" << endl;
            system("cls");
        }
        else
        {
            system("cls");
            return;
        }
    }
    else
    {
        system("cls");
        cout << "place location: " << place_location_search << " is not available" << endl;
        cout << "do you want to another place? (y/n)" << endl;
        char choice;
        cin >> choice;
        if (choice == 'y')
        {
            search_places();
        }
        else
        {
            return;
        }
    }
}

void user::modify_user()
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
}

void user::delete_user()
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
}

void user::edit_profile()
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

void user::host()
{
    while (true)
    {
        int choice;
        cout << "1. add available places" << endl;
        cout << "2. exit" << endl;
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
            store_places();
            break;
        case 2:
            system("cls");
            return;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}

void user::traveler()
{
    while (true)
    {
        int choice;
        cout << "1. search place" << endl;
        cout << "2. exit" << endl;
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
            search_places();
            break;
        case 2:
            system("cls");
            return;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}

void user::user_fun()
{
    while (true)
    {
        int choice;
        cout << "1. traveler" << endl;
        cout << "2. host" << endl;
        cout << "3. edit profile" << endl;
        cout << "4. Exit" << endl;
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
            traveler();
            break;
        case 2:
            system("cls");
            host();
            break;
        case 3:
            system("cls");
            edit_profile();
            break;
        case 4:
            system("cls");
            return;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}


