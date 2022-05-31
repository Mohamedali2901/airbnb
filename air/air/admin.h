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
class admin
{
public:
	list<pair<string, pair<int, int>>> load_avilable_places();
	list<pair<string, pair<int, int>>> load_reserved_places();
	void modify_user();
	void delete_user();
	void print_available_places();
	void print_reserved_places();
	void show_places();
	void delete_reserved_places();
	void delete_available_places();
	void delete_place();
	void modify_reserved_place();
	void modify_available_place();
	void modify();
	void admin_fun();
	void edit_profile();
	void dashboard();
};


