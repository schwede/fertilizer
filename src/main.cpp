#include <cstdlib>
#include <iostream>
#include <fstream>
#include "MarriageNode.hpp"
#include "Node.hpp"
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

MarriageNode* loadRecords(Node* h)
{
	MarriageNode* head = new MarriageNode();

	string date = "";
	string year = "";
	string bride = "";
	string groom = "";
	bool valid = false;
	bool toggle = true;

	
	MarriageNode* i = head;
	Node* s = h;

	while(s != NULL)
	{
		if(isYear(s->item))
		{
			year = s->item;
		}
		else if(isDate(s->item))
		{
			if(valid)
			{	
				i = new MarriageNode(year, date, bride, groom, i);
			}


			if(s->item != "..-..")
			{
				date = s->item;
			}

			valid = !valid;
		}
		else if(valid)
		{
			if(s->item == "mit")
			{
				toggle = !toggle;
			}
			else if(toggle) // groom
			{
				groom += " ";
				groom += s->item;
			}
			else // bride
			{
				bride += " ";
				bride += s->item;
			}
		
		}
		

		s = s->next;
	}

	return head;
}

Node* loadStrings()
{
	ifstream in;
	in.open("marriages.txt");

	if(in.fail())
	{
		cout << "Couldn't open file" << endl;
		exit(0);
	}

	char c;
	string  input = "";
	Node* head = new Node();
	Node* i = head;

	while(!in.eof())
	{
		char c = in.get();

		if(delimiter(c))
		{
			if(!delimiter(in.peek()))
			{
				i->next = new Node(input);
				i = i->next;
				input = "";
			}
		}
		else
		{
			input += c;		
		}
	}

	return head;
}

int main()
{
	Node* list = loadStrings();
	MarriageNode* marriages = loadRecords(list);


	MarriageNode* i = marriages;

	while(i != NULL)
	{
		i->item.print();
		i = i->next;
	}

	return 0;
}

