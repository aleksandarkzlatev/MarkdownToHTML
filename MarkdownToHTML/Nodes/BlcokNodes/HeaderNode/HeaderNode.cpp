#include "HeaderNode.h"

HeaderNode::HeaderNode(int level)
{
    this->level = level;
}

void HeaderNode::addInLine(unique_ptr<InlineNode> node)
{
	content.push_back(move(node));
}

string HeaderNode::toHTML() const
{
    string result = "<h" + to_string(level) + ">";
    for (const unique_ptr<InlineNode>& node : content) {
		result += node->toHTML();
    }

    result += "</h" + to_string(level) + ">";

    return result;
}

void HeaderNode::print(ostream& os, size_t indent) const
{
	printIndent(os, indent);
	os << "HeaderNode (level " << level << ")\n";
	for (const unique_ptr<InlineNode>& node : content)
	{
		node->print(os, indent + 1);
	}
}
