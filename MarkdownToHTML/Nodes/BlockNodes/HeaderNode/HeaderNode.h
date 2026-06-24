#pragma once
#include "../BlockNode.h"
#include"../../InlineNodes/InlineNode.h"
#include <exception>

class HeaderNode : public BlockNode
{
	size_t level;
	vector<InlineNode*> content;
public:
	HeaderNode(size_t level);

	HeaderNode(const HeaderNode& other);
	HeaderNode& operator=(const HeaderNode& other);
	~HeaderNode();

	void addInLine(const InlineNode* node);
	string toHTML() const override;
	void print(ostream& os, size_t indent = 0) const override;

	virtual Node* clone() const override { return new HeaderNode(*this); }
	void collectStatistics(Statistics& stats) const;
};

