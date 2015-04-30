#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include "MarriageRecord.hpp"
using namespace std;

bool isDigit(char d)
{
	return d >= '0' && d <= '9';
}

bool isDate(string d)
{
	if(d.length() == 5 && isDigit(d[0]) && isDigit(d[1]) && d[2] == '-' && isDigit(d[3]) && isDigit(d[4]))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isYear(string y)
{
	if(y.length() == 4 && isDigit(y[0]) && isDigit(y[1]) && isDigit(y[2])  && isDigit(y[3]))
	{
		return true;
	}
	else
	{
		return false;
	}
}

vector<MarriageRecord> parseMarriages2(vector<string> strings)
{
	vector<MarriageRecord> marriages;

	string year = "";
	string date = "";
	string bride = "";
	string groom  = "";
	string last = "";
	string expecting = "";
	string current = strings[0];

	for(int x = 1; x < strings.size(); x++)
	{

		if(current == ".")
		{
			if(isYear(last))
			{
				year = last;
				expecting = "date";
			}
		}
		if(expecting == "date")
		{
			if(isDate(current))
			{

			}
		}
		else if(expecting == "husband")
		{

		}

		last = strings[x - 1];
		current = strings[x];
	}

	return marriages;
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

	while(i < list.size())
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
				groom += " ";
				groom += list[i];
			}
		}

		i++;
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

	for(int x = 0; x < marriages.size(); x++)
	{
		marriages[x].print();
	}

	return 0;
}

