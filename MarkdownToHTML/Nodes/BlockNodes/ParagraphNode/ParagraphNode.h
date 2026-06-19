#pragma once
#include "../BlockNode.h"
#include"../../InlineNodes/InlineNode.h"

class ParagraphNode : public BlockNode
{
	vector<InlineNode*> content;
public:
	ParagraphNode() = default;
	ParagraphNode(const ParagraphNode& other);
	ParagraphNode& operator=(const ParagraphNode& other);
	~ParagraphNode();

	void addInLine(const InlineNode* node);
	string toHTML() const override;
	void print(ostream& os, size_t indent = 0) const override;
	string getType() const override { return "Paragraph"; }

	virtual Node* clone() const override { return new ParagraphNode(*this); }
	void collectStatistics(Statistics& stats) const;
};

