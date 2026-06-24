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

	void addNode(InlineNode* node);
	string toHTML() const override;
	void print(ostream& os, size_t indent = 0) const override;

	virtual Node* clone() const override { return new StrikeNode(*this); }
	void collectStatistics(Statistics& stats) const;
};

