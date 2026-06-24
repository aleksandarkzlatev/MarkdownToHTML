#include "BoldNode.h"

BoldNode::BoldNode(const BoldNode& other)
{
	for (const InlineNode* node : other.nodes) {
		nodes.push_back(dynamic_cast<InlineNode*>(node->clone()));
	}
}

BoldNode& BoldNode::operator=(const BoldNode& other)
{
	if (this != &other)
	{
		for (InlineNode* node : nodes) delete node;
		nodes.clear();
		for (const InlineNode* node : other.nodes) {
			nodes.push_back(dynamic_cast<InlineNode*>(node->clone()));
		}
	}
	return *this;
}

BoldNode::~BoldNode()
{
	for (InlineNode* node : nodes) {
		delete node;
	}
}

void BoldNode::addNode(InlineNode* node)
{
	nodes.push_back(node);
}

string BoldNode::toHTML() const
{
    string result = "<b>";
    
    for (const InlineNode* node : nodes) {
        result += node->toHTML();
    }
    result += "</b>";

    return result;
}

void BoldNode::print(ostream& os, size_t indent) const
{
    printIndent(os, indent);
    os << "BoldNode\n";

    for (const InlineNode* node : nodes) {
		node->print(os, indent + 1);
    }
}

void BoldNode::collectStatistics(Statistics& stats) const
{
	stats.bold++;

	for (size_t i = 0; i < nodes.size(); i++) nodes[i]->collectStatistics(stats);
}
