#include "ListItemNode.h"

void ListItemNode::addInLine(unique_ptr<InlineNode> node)
{
    content.push_back(move(node));
}

string ListItemNode::toHTML() const
{
	string result = "<li>";
	for (const unique_ptr<InlineNode>& node : content) {
		result += node->toHTML();
	}

    result += "</li>";

    return result;
}

void ListItemNode::print(ostream& os, size_t indent) const
{
	printIndent(os, indent);
	os << "ListItemNode\n";
	for (const unique_ptr<InlineNode>& node : content)
	{
		node->print(os, indent + 1);
	}
}
