#pragma once
#include "../InlineNode.h"

class ItalicNode : public InlineNode
{
	vector<InlineNode*> children;

public:
	ItalicNode() = default;
	ItalicNode(const ItalicNode& other);
	ItalicNode& operator=(const ItalicNode& other);
	~ItalicNode();

	void addChild(const InlineNode* child);
	string toHTML() const override;
	void print(ostream& os, size_t indent = 0) const override;
	string getType() const override { return "Italic"; }

	virtual Node* clone() const override { return new ItalicNode(*this); }
};

