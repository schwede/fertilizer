#ifndef NODE
#define NODE
#include <string>


class Node
{
	public:

	Node(std::string = "", Node* = NULL);

	std::string item;
	Node* next;

};


#endif 
