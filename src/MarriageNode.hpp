#ifndef MARRIAGE_NODE
#define MARRIAGE_NODE
#include "MarriageRecord.hpp"
#include "MarriageNode.hpp"


class MarriageNode
{
	public:

	MarriageNode(std::string = "", std::string = "", std::string = "", std::string = "", MarriageNode* = NULL);

	MarriageRecord item;
	MarriageNode* next;

};


#endif 
