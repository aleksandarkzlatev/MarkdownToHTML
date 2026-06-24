#include "ItalicNode.h"

ItalicNode::ItalicNode(const ItalicNode& other)
{
	for (const InlineNode* node : other.nodes) {
		nodes.push_back(dynamic_cast<InlineNode*>(node->clone()));
	}
}

ItalicNode& ItalicNode::operator=(const ItalicNode& other)
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

ItalicNode::~ItalicNode()
{
	for (InlineNode* node : nodes) {
		delete node;
	}
}

void ItalicNode::addNode(InlineNode* node)
{
	nodes.push_back(node);
}

string ItalicNode::toHTML() const
{
    string result = "<i>";

    for (const InlineNode* node : nodes) {
        result += node->toHTML();
    }

    result += "</i>";

    return result;
}

void ItalicNode::print(ostream& os, size_t indent) const
{
    printIndent(os, indent);
    os << "ItalicNode\n";
    for (const InlineNode* node : nodes) {
        node->print(os, indent + 1);
    }
}

void ItalicNode::collectStatistics(Statistics& stats) const
{
	stats.italic++;

	for (size_t i = 0; i < nodes.size(); i++) nodes[i]->collectStatistics(stats);
}
