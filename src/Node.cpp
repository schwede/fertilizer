#include "Node.hpp"

Node::Node(std::string i, Node* n)
{
	item = i;
	next = n;
}

