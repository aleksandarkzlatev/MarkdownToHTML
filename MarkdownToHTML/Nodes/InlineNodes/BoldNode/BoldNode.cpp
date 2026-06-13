#include "BoldNode.h"

BoldNode::BoldNode(const BoldNode& other)
{
	for (const InlineNode* child : other.children) {
		children.push_back(dynamic_cast<InlineNode*>(child->clone()));
	}
}

BoldNode& BoldNode::operator=(const BoldNode& other)
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

BoldNode::~BoldNode()
{
	for (InlineNode* child : children) {
		delete child;
	}
}

void BoldNode::addChild(const InlineNode* child)
{
    // making sure that we dont copy the data but "move" it
    children.push_back(dynamic_cast<InlineNode*>(child->clone()));
}

string BoldNode::toHTML() const
{
    string result = "<b>";
    
    for (const InlineNode* child : children) {
        result += child->toHTML();
    }
    result += "</b>";

    return result;
}

void BoldNode::print(ostream& os, size_t indent) const
{
    printIndent(os, indent);
    os << "BoldNode\n";

    for (const InlineNode* child : children) {
        child->print(os, indent + 1);
    }
}
