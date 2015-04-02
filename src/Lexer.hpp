
#ifndef LEXER
#define LEXER
#include <fstream>
#include <string>
#include <vector>

enum TOKEN_TYPE {
		FATHER, 
		MOTHER, 
		GODPARENTS, 
		CHILD, 
		HUSBAND, 
		WIFE, 
		COMMA, 
		PERIOD, 
		NEWLINE, 
		WITH,	
		YEAR, 
		DATE, 
		STRING
		};
class Lexer
{
	public:

	Lexer(std::string filename);

	std::string get();

	std::ifstream file;
	int pointer;
	std::vector<std::string> tokens;
};

#endif
