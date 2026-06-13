#include "ListItemNode.h"

ListItemNode::ListItemNode(const ListItemNode& other)
{
	for (InlineNode* node : other.content)
	{
		content.push_back(dynamic_cast<InlineNode*>(node->clone()));
	}
}

ListItemNode& ListItemNode::operator=(const ListItemNode& other)
{
	if (this != &other)
	{
		for (InlineNode* node : content) delete node;
		content.clear();
		for (InlineNode* node : other.content)
		{
			content.push_back(dynamic_cast<InlineNode*>(node->clone()));
		}
	}
	return *this;

}

ListItemNode::~ListItemNode()
{
	for (InlineNode* node : content) delete node;
}

void ListItemNode::addInLine(const InlineNode* node)
{
    content.push_back(dynamic_cast<InlineNode*>(node->clone()));
}

string ListItemNode::toHTML() const
{
	string result = "<li>";
	for (const InlineNode* node : content) {
		result += node->toHTML();
	}

    result += "</li>";

    return result;
}

void ListItemNode::print(ostream& os, size_t indent) const
{
	printIndent(os, indent);
	os << "ListItemNode\n";
	for (const InlineNode* node : content)
	{
		node->print(os, indent + 1);
	}
}
