#include "ParagraphNode.h"

void ParagraphNode::addInLine(unique_ptr<InlineNode> node)
{
    content.push_back(move(node));
}

string ParagraphNode::toHTML() const
{
	string result = "<p>";
	for (const unique_ptr<InlineNode>& node : content)
	{
		result += node->toHTML();
	}

	result += "</p>";

    return result;
}

void ParagraphNode::print(ostream& os, size_t indent) const
{
	printIndent(os, indent);
	os << "ParagraphNode\n";
	for (const unique_ptr<InlineNode>& node : content)
	{
		node->print(os, indent + 1);
	}
}
