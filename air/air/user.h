#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include<vector>
#include<unordered_map>
#include<iterator>
#include<algorithm>
using namespace std;
class user
{
public:
	void store_places();
	list<pair<string, pair<int, int>>> load_avilable_places();
	list<pair<string, pair<int, int>>> load_reserved_places();
	void search_places();
	void modify_user();
	void delete_user();
	void edit_profile();
	void host();
	void traveler();
	void user_fun();
	void signup();
};


