#pragma once
#include "../InlineNode.h"

class StrikeNode : public InlineNode
{
	vector<InlineNode*> children;
public:
	StrikeNode() = default;
	StrikeNode(const StrikeNode& other);
	StrikeNode& operator=(const StrikeNode& other);
	~StrikeNode();

	void addChild(const InlineNode* child);
	string toHTML() const override;
	void print(ostream& os, size_t indent = 0) const override;
	string getType() const override { return "Strike"; }

	virtual Node* clone() const override { return new StrikeNode(*this); }
};

