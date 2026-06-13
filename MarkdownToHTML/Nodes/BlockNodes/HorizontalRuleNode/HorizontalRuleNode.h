#pragma once
#include "../BlockNode.h"
#include"../../InlineNodes/InlineNode.h"

class HorizontalRuleNode : public BlockNode
{
public:
	HorizontalRuleNode() = default;
	string toHTML() const { return "<hr></hr>"; }
	void print(ostream& os, size_t indent = 0) const;
	string getType() const { return "HorizontalRule"; }

	virtual Node* clone() const override { return new HorizontalRuleNode(*this); }
};

