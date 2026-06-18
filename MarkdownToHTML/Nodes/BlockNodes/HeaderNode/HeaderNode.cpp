#include "HeaderNode.h"

HeaderNode::HeaderNode(size_t level)
{
	if (level > 6) throw invalid_argument("Header level must be between 1 and 6");
    this->level = level;
}

HeaderNode::HeaderNode(const HeaderNode& other)
{
	level = other.level;

	for (InlineNode* node : other.content)
	{
		content.push_back(dynamic_cast<InlineNode*>(node->clone()));
	}
}

HeaderNode& HeaderNode::operator=(const HeaderNode& other)
{
	if (this != &other)
	{
		level = other.level;
		for (InlineNode* node : content) delete node;
		content.clear();
		for (InlineNode* node : other.content)
		{
			content.push_back(dynamic_cast<InlineNode*>(node->clone()));
		}
		level = other.level;
	}

	return *this;
}

HeaderNode::~HeaderNode()
{
	for (InlineNode* node : content) delete node;
}

void HeaderNode::addInLine(const InlineNode* node)
{
	content.push_back(dynamic_cast<InlineNode*>(node->clone()));
}

string HeaderNode::toHTML() const
{
    string result = "<h" + to_string(level) + ">";
    for (const InlineNode* node : content) {
		result += node->toHTML();
    }

    result += "</h" + to_string(level) + ">";

    return result;
}

void HeaderNode::print(ostream& os, size_t indent) const
{
	printIndent(os, indent);
	os << "HeaderNode (level " << level << ")\n";
	for (const InlineNode* node : content)
	{
		node->print(os, indent + 1);
	}
}
