#pragma once
#include "../InlineNode.h"

class CodeNode : public InlineNode
{
	string code;
public:
	CodeNode(const string& code);
	string toHTML() const override;
	void print(ostream& os, size_t indent = 0) const override;

	virtual Node* clone() const override { return new CodeNode(*this); }
	void collectStatistics(Statistics& stats) const;
};

