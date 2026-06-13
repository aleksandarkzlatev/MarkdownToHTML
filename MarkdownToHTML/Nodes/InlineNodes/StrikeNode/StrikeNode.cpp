#include "StrikeNode.h"

StrikeNode::StrikeNode(const StrikeNode& other)
{
	for (const InlineNode* child : other.children) {
		children.push_back(dynamic_cast<InlineNode*>(child->clone()));
	}
}

StrikeNode& StrikeNode::operator=(const StrikeNode& other)
{
	if (this != &other)
	{
		for (InlineNode* child : children) delete child;
		children.clear();
		for (const InlineNode* child : other.children) {
			children.push_back(dynamic_cast<InlineNode*>(child->clone()));
		}
	}
	return *this;

}

StrikeNode::~StrikeNode()
{
	for (InlineNode* child : children) {
		delete child;
	}
}

void StrikeNode::addChild(const InlineNode* child)
{
    children.push_back(dynamic_cast<InlineNode*>(child->clone()));
}

string StrikeNode::toHTML() const
{
    string result = "<s>";

    for (const InlineNode* child : children) {
        result += child->toHTML();
    }

    result += "</s>";

    return result;
}

void StrikeNode::print(ostream& os, size_t indent) const
{
    printIndent(os, indent);
    os << "StrikeNode\n";

    for (const InlineNode* child : children) {
        child->print(os, indent + 1);
    }
}
