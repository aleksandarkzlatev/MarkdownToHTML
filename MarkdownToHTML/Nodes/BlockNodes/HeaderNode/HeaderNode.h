#pragma once
#include "../BlockNode.h"
#include"../../InlineNodes/InlineNode.h"

class HeaderNode : public BlockNode
{
	int level;
	vector<InlineNode*> content;
public:
	HeaderNode(int level);

	HeaderNode(const HeaderNode& other);
	HeaderNode& operator=(const HeaderNode& other);
	~HeaderNode();

	void addInLine(const InlineNode* node);
	string toHTML() const override;
	void print(ostream& os, size_t indent = 0) const override;
	string getType() const override { return "Header"; }

	virtual Node* clone() const override { return new HeaderNode(*this); }
};

