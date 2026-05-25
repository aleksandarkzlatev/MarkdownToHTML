#include "TextNode.h"

TextNode::TextNode(const string& text)
{
	this->text = text;
}

void TextNode::print(ostream& os, size_t indent) const
{
	printIndent(os, indent);
	os << "TextNode: " << text << '\n';
}
