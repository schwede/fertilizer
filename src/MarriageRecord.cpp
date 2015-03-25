#include "MarriageRecord.hpp"

MarriageRecord::MarriageRecord(std::string d, std::string y, std::string b, std::string g)
{
	date = d;
	year = y;
	bride = b;
	groom = g;
}

void MarriageRecord::print()
{
	std::cout << groom << " married " << bride << " on " << date << " " << year << std::endl;
}

