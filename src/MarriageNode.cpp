#include "MarriageNode.hpp"

MarriageNode::MarriageNode(std::string d, std::string y, std::string b, std::string g, MarriageNode* n)
{
	item = MarriageRecord(d, y, b, g);
	next = n;
}

