#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include "Lexer.hpp"
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

void parseBaptims(vector<string> list)
{
	string year = "";
	string date = "";
	string infant = "";
	string mother = "";
	string father = "";
	vector<string> godparents;
	string expecting = "year";
	int i = 0;

	/*
	02-07P. Johan Herbordt Droege, M. Anna Maria Ollenhagens
	Inf. Claus Henrich, bapt. den 2 Jul.
	Patr. Johan Henrich Ubbing, Claus Henrich Droege, Anna Maria Dunckers
	*/


	while(i < list.size());
	{
		if(expecting == "year")
		{

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

	while(i < list.size())
	{
		if(expecting == "year")
		{
			if(isYear(list[i]))
			{
				year = list[i].substr(0, list[i].length() - 1);
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

// Todo: switch it up to do some parsing and type finding here instead of the parse marriages
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

void test()
{
	vector<string> list = loadStrings();
	vector<MarriageRecord> marriages = parseMarriages(list);
	int i = 0;


	for(int i = 0; i < marriages.size(); i++)
	{
		marriages[i].print();
	}
}

int main()
{
	Lexer lexer("marriages.txt");

	for(int x = 0; x < 10; x++)
	{
		cout << lexer.get() << endl;
	}

	return 0;
}

