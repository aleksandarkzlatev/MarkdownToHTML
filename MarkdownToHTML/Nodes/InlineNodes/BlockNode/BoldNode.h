#pragma once
#include "../InlineNode.h"

class BoldNode : public InlineNode
{
	// unique_ptr so :
	// 1. the memory of the children gets deleted instantly when the parent gets deleted
	// 2. prevents multiple owners scenario
	vector<unique_ptr<InlineNode>> children;
public:
	void addChild(unique_ptr<InlineNode> child);
	string toHTML() const override;
	void print(ostream& os, size_t indent = 0) const override;
	string getType() const override { return "Bold"; }
};

