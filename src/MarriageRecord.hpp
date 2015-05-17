#ifndef MARRIAGE_RECORD
#define MARRIAGE_RECORD
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class MarriageRecord
{
	public:

	MarriageRecord(string d = "", string y = "", string b = "", string g = "");

	void print();

	string getGroom();

	string getBride();

	void print_table();

	int abs(int x);

	bool match(string c);

	int diff();

	void table_gen(string query);

	static const int matching_threshold = 3;

	string check;
	int matching_table[26];
	int query_table[26];
	int matching_total;

	string date;
	string year;
	vector<string> bride;
	vector<string> groom;
	vector<string> brideExtra;
	vector<string> groomExtra;

};

#endif

