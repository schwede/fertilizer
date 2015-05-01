#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include "MarriageRecord.hpp"
using namespace std;

const double threshold = 0.8;

bool isDigit(char d)
{
	return d >= '0' && d <= '9';
}

bool isDate(string d)
{
	return d.length() == 5 && isDigit(d[0]) && isDigit(d[1]) && d[2] == '-' && isDigit(d[3]) && isDigit(d[4]);
}

bool isYear(string y)
{
	return y.length() == 4 && isDigit(y[0]) && isDigit(y[1]) && isDigit(y[2])  && isDigit(y[3]);
}

vector<MarriageRecord> parseMarriages2(vector<string> strings)
{
	vector<MarriageRecord> marriages;

	return marriages;
}

bool match(string check, string query)
{
//	cout << "Checking " << query << " against: " << check << endl;
	double max = query.length(); 
	
	double matched = 0;
	for(int i = 0; i < check.length(); i++)
	{
		for(int j = 0; j < query.length(); j++)
		{
			if(tolower(check[i]) == tolower(query[j]))
			{
				//cout << query << " -- " << check[i] << " --> ";
				query = query.substr(0, j) + query.substr(j + 1);
				//cout << query << endl;
				matched += 1;
				break;
			}
		}
	}

	cout << matched << " / " << query.length() << endl;
	return matched / query.length() > threshold;
}

void search(vector<MarriageRecord> marriages)
{
	string use = "Kreyen";
	for(int i = 0; i < marriages.size(); i++)
	{
		for(int j = 0; j < marriages[i].groom.size(); j++)
		{
			if(match(marriages[i].groom[j], use))
			{
				break;
			}
		}
	}

	for(int i = 0; i < marriages.size(); i++)
	{
		for(int j = 0; j < marriages[i].bride.size(); j++)
		{
			if(match(marriages[i].bride[j], use))
			{
				break;
			}
		}
	}
}

vector<MarriageRecord> parseMarriages(vector<string> list)
{
	vector<MarriageRecord> marriages;

	string year = "";
	string date = "";
	string bride = "";
	string groom  = "";
	string expecting = "year";
	int i = 0;

	for(int i = 0; i < list.size(); i++)
	{
		if(expecting == "year")
		{
			if(isYear(list[i]))
			{
				year = list[i];
			}

			expecting = "date";
		}
		else if(expecting == "date")
		{
			if(isDate(list[i]))
			{
				if(list[i] != "..-..")
				{
					date = list[i];
				}
			}
		
			expecting = "groom";
		}
		else if(expecting == "bride")
		{
			if(isYear(list[i]))
			{
				expecting = "year";

				marriages.push_back(MarriageRecord(year, date, bride, groom));
				bride = "";
				groom = "";

				continue;
			}
			else if(isDate(list[i]))
			{
				expecting = "date";	

				marriages.push_back(MarriageRecord(year, date, bride, groom));
				bride = "";
				groom = "";

				continue;
			}
			else
			{
				if(bride != "")
				bride += " ";
				bride += list[i];
			}
		}
		else if(expecting == "groom")
		{
			if(list[i] == "mit" || list[i] == "an")
			{
				expecting = "bride";
			}
			else
			{
				if(groom != "")
				groom += " ";
				groom += list[i];
			}
		}
	}

	return marriages;
}

vector<string> loadStrings() // produces a list of strings seperated by spaces, newlines, commas, and periods
{
	ifstream in;
	in.open("marriages.txt");

	if(in.fail())
	{
		cout << "Couldn't open file" << endl;
		exit(0);
	}

	char c = ' ';
	string  input = "";
	vector<string> list;

	while(!in.eof())
	{
		c = in.get();

		if(c == ' ' || c == '\n')
		{
			if(input != "")
			{
				list.push_back(input);
				input = "";
			}

		}
		else if(c == '.')
		{
			list.push_back(input);
			list.push_back(".");
			input = "";
		}
		else if(c == ',')
		{
			list.push_back(input);
			list.push_back(",");
			input = "";
		}
		else
		{
			input += c;		
		}
	}

	return list;
}

int main()
{
	vector<string> strings = loadStrings();
	vector<MarriageRecord> marriages = parseMarriages(strings);
	search(marriages);

	/*for(int x = 0; x < marriages.size(); x++)
	{
		marriages[x].print();
	}*/

	return 0;
}

