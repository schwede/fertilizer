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

	string date;
	string year;
	vector<string> bride;
	vector<string> groom;
	vector<string> brideExtra;
	vector<string> groomExtra;

};

#endif

