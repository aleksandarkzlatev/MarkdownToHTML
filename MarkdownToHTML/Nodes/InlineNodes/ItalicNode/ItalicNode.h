#pragma once
#include "../InlineNode.h"

class ItalicNode : public InlineNode
{
	vector<InlineNode*> nodes;

public:
	ItalicNode() = default;
	ItalicNode(const ItalicNode& other);
	ItalicNode& operator=(const ItalicNode& other);
	~ItalicNode();

	void addNode(InlineNode* node);
	string toHTML() const override;
	void print(ostream& os, size_t indent = 0) const override;

	virtual Node* clone() const override { return new ItalicNode(*this); }
	void collectStatistics(Statistics& stats) const;
};

