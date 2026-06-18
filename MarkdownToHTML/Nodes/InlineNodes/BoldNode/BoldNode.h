#pragma once
#include "../InlineNode.h"

class BoldNode : public InlineNode
{
	vector<InlineNode*> nodes;
public:
	BoldNode() = default;
	BoldNode(const BoldNode& other);
	BoldNode& operator=(const BoldNode& other);
	~BoldNode();

	void addNode(const InlineNode* node);
	string toHTML() const override;
	void print(ostream& os, size_t indent = 0) const override;
	string getType() const override { return "Bold"; }

	virtual Node* clone() const override { return new BoldNode(*this); }
};

