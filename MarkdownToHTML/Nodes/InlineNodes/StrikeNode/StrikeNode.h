#pragma once
#include "../InlineNode.h"

class StrikeNode : public InlineNode
{
	vector<InlineNode*> nodes;
public:
	StrikeNode() = default;
	StrikeNode(const StrikeNode& other);
	StrikeNode& operator=(const StrikeNode& other);
	~StrikeNode();

	void addNode(const InlineNode* node);
	string toHTML() const override;
	void print(ostream& os, size_t indent = 0) const override;
	string getType() const override { return "Strike"; }

	virtual Node* clone() const override { return new StrikeNode(*this); }
};

