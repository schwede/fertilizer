
#include <iostream>
#include "Lexer.hpp"
using namespace std;

Lexer::Lexer(string filename)
{
	pointer = 0;
	file.open(filename.c_str());	

	if(file.fail())
	{
		cout << "Couldn't open " << filename << endl;
	}
	else
	{
		while(!file.eof())
		{
			string in;
			file >> in;	
			tokens.push_back(in);
		}

		file.close();

	}

}

string Lexer::get()
{
	pointer++;

	return tokens[pointer - 1];
			
	
}
