#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include "MarriageRecord.hpp"
using namespace std;

bool delimiter(char c)
{
	return c == ' ' || c == '\n';
}

bool isDigit(char d)
{
	switch(d)
	{
		case '0':
			return true;
		case '1':
			return true;
		case '2':
			return true;
		case '3':
			return true;
		case '4':
			return true;
		case '5':
			return true;
		case '6':
			return true;
		case '7':
			return true;
		case '8':
			return true;
		case '9':
			return true;
		case '.':
			return true;
		default:
			return false;
	}
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
	if(y.length() == 5 && isDigit(y[0]) && isDigit(y[1]) && isDigit(y[2])  && isDigit(y[3]) && isDigit(y[4]))
	{
		return true;
	}
	else
	{
		return false;
	}
}

vector<MarriageRecord> parseMarriages(vector<string> list)
{
	vector<MarriageRecord> marriages;

	string year = "";
	string date = "";
	string bride = "";
	string groom = "";
	int i = 0;

	while(i < list.size())
	{
		if(isYear(list[i]))
		{
			year = list[i];

			while(i < list.size() - 1 && !isYear(list[i + 1]))
			{
				if(isDate(list[i]))
				{
					if(list[i] != "..-..")
					{
						date = list[i];
					}
					cout << date << endl;
				}
				

				i++;
			}
		}

		i++;
	}

	return marriages;
}


vector<string> loadStrings()
{
	ifstream in;
	in.open("marriages.txt");

	if(in.fail())
	{
		cout << "Couldn't open file" << endl;
		exit(0);
	}

	char c = ' ';
	int count = 0;
	string  input = "";
	vector<string> list;

	while(!in.eof())
	{
		char c = in.get();

		if(delimiter(c))
		{
			if(!delimiter(in.peek()))
			{
				list.push_back(input);
				input = "";
			}
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
	vector<string> list = loadStrings();
	vector<MarriageRecord> marriages = parseMarriages(list);
	int i = 0;


	for(int i = 0; i < marriages.size(); i++)
	{
		marriages[i].print();
	}

	return 0;
}

