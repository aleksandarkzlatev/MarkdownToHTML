#include "StrikeNode.h"

StrikeNode::StrikeNode(const StrikeNode& other)
{
	for (const InlineNode* node : other.nodes) {
		nodes.push_back(dynamic_cast<InlineNode*>(node->clone()));
	}
}

StrikeNode& StrikeNode::operator=(const StrikeNode& other)
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

StrikeNode::~StrikeNode()
{
	for (InlineNode* node : nodes) {
		delete node;
	}
}

void StrikeNode::addNode(InlineNode* node)
{
    nodes.push_back(node);
}

string StrikeNode::toHTML() const
{
    string result = "<s>";

    for (const InlineNode* node : nodes) {
        result += node->toHTML();
    }

    result += "</s>";

    return result;
}

void StrikeNode::print(ostream& os, size_t indent) const
{
    printIndent(os, indent);
    os << "StrikeNode\n";

    for (const InlineNode* node : nodes) {
        node->print(os, indent + 1);
    }
}

void StrikeNode::collectStatistics(Statistics& stats) const
{
	stats.strike++;

	for (size_t i = 0; i < nodes.size(); i++) nodes[i]->collectStatistics(stats);
}
