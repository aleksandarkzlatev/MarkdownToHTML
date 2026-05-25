#pragma once
#include "../BlockNode.h"
#include"../../InlineNodes/InlineNode.h"

class HeaderNode : public BlockNode
{
	int level;
	vector<unique_ptr<InlineNode>> content;
public:
	HeaderNode(int level);
	void addInLine(unique_ptr<InlineNode> node);
	string toHTML() const override;
	void print(ostream& os, size_t indent = 0) const override;
	string getType() const override { return "Header"; }
};

