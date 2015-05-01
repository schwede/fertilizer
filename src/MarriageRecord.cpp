#include "MarriageRecord.hpp"
using namespace std;

string MarriageRecord::getGroom()
{
	string g = groom[0];

	for(int x = 1; x < groom.size(); x++)
	{
		g += " ";
		g += groom[x];
	}

	return g;
}

string MarriageRecord::getBride()
{
	string b = bride[0];

	for(int x = 1; x < bride.size(); x++)
	{
		b += " ";
		b += bride[x];
	}

	return b;
}

MarriageRecord::MarriageRecord(string d, string y, string b, string g)
{
	date = d;
	year = y;

	string acc = "";
	bool comma = false;
	for(int x = 0; x < b.length(); x++)
	{
		if(b[x] == ',')
		{
			comma = true;
			x++;
		}

		if(b[x] == ' ' && acc != "")
		{
			if(comma)
			{
				brideExtra.push_back(acc);	
				acc = "";
			}
			else
			{
				bride.push_back(acc);
				acc = "";
			}	
		}
		else
		{
			acc += b[x];
		}
	}
	
	acc = "";
	comma = false;
	for(int x = 0; x < g.length(); x++)
	{
		if(g[x] == ',')
		{
			comma = true;
			x++;
		}

		if(g[x] == ' ' && acc != "")
		{
			if(comma)
			{
				groomExtra.push_back(acc);	
				acc = "";
			}
			else
			{
				groom.push_back(acc);
				acc = "";
			}	
		}
		else
		{
			acc += g[x];
		}
	}
}

void MarriageRecord::print()
{
		cout << getGroom() << " " << "married " << getBride() << " " << "on " << date << " " << year << endl;
}

