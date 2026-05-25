#pragma once
#include "../BlockNode.h"
#include"../../InlineNodes/InlineNode.h"

class HorizontalRuleNode : public BlockNode
{
public:
	string toHTML() const { return "<hr></hr>"; }
	void print(ostream& os, size_t indent = 0) const;
	string getType() const { return "HorizontalRule"; }
};

