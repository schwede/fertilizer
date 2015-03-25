#ifndef MARRIAGE_RECORD
#define MARRIAGE_RECORD
#include <string>
#include <iostream>

class MarriageRecord
{
	public:

	MarriageRecord(std::string d = "", std::string y = "", std::string b ="", std::string g = "");

	void print();

	std::string date;
	std::string year;
	std::string bride;
	std::string groom;

};

#endif
