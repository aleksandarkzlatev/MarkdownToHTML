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

	void addNode(const InlineNode* node);
	string toHTML() const override;
	void print(ostream& os, size_t indent = 0) const override;
	string getType() const override { return "Italic"; }

	virtual Node* clone() const override { return new ItalicNode(*this); }
};

