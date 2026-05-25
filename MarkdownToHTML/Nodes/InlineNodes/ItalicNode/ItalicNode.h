#pragma once
#include "../InlineNode.h"

class ItalicNode : public InlineNode
{
	vector<unique_ptr<InlineNode>> children;

public:
	void addChild(unique_ptr<InlineNode> child);
	string toHTML() const override;
	void print(ostream& os, size_t indent = 0) const override;
	string getType() const override { return "Italic"; }
};

