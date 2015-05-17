#include "MarriageRecord.hpp"
using namespace std;

bool MarriageRecord::match(string c)
{
	check = c;

	for(int i = 0; i < groom.size(); i++)
	{
		table_gen(groom[i]);		

		if(diff() < matching_threshold)
		{
			return true;
		} 

	}

	for(int i = 0; i < bride.size(); i++)
	{
		table_gen(bride[i]);		

		if(diff() < matching_threshold)
		{
			return true;
		}

	}

	return false;
}

void MarriageRecord::print_table()
{
	for(int x = 0; x < 26; x++)
	{
		cout << x << ": " << matching_table[x] << " ";
	}
	cout << endl;
}

int MarriageRecord::diff()
{
	matching_total = 0;

	for(int x = 0; x < 26; x++)
	{
		matching_total += abs(matching_table[x] - query_table[x]);
	}

	return matching_total;
}

void MarriageRecord::table_gen(string query)
{
	for(int i = 0; i < 26; i++)
	{
		matching_table[i] = 0;	
		query_table[i] = 0;
	}

	for(int i = 0; i < query.length(); i++)
	{
		if(tolower(query[i]) >= 'a' && tolower(query[i]) <= 'z')
		{
			int hash_m = tolower(query[i]) - 'a';

			query_table[hash_m]++;
		}
	}

	for(int i = 0; i < check.length(); i++)
	{
		if(tolower(check[i]) >= 'a' && tolower(check[i]) <= 'z')
		{
			int hash_q = tolower(check[i]) - 'a';

			matching_table[hash_q]++;
		}
	}
}

string MarriageRecord::getGroom()
{

	if(groom.size() > 0)
	{
		string g = groom[0];

		for(int x = 1; x < groom.size(); x++)
		{
			g += " ";
			g += groom[x];
		}

		return g;
	}
	else
	{
		return "";
	}

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

int MarriageRecord::abs(int x)
{
	if(x < 0)
	{
		return -x;
	}
	else
	{
		return x;
	}
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

