#pragma once
#include "../InlineNode.h"

class TextNode : public InlineNode
{
	string text;

public:
	TextNode(const string& text);
	string toHTML() const override { return text;}
	void print(ostream& os, size_t indent = 0) const override;
	string getType() const override { return "Text"; }
};

