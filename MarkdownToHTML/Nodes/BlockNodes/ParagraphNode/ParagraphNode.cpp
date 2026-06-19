#include "ParagraphNode.h"

ParagraphNode::ParagraphNode(const ParagraphNode& other)
{
	for (InlineNode* node : other.content) 
	{
		content.push_back(dynamic_cast<InlineNode*>(node->clone()));
	}
}

ParagraphNode& ParagraphNode::operator=(const ParagraphNode& other)
{
	if (this != &other) 
	{
		for (InlineNode* node : content)  delete node;
		content.clear();
		for (InlineNode* node : other.content)
		{
			content.push_back(dynamic_cast<InlineNode*>(node->clone()));
		}
	}
	return *this;
}

ParagraphNode::~ParagraphNode()
{
	for (InlineNode* node : content) {
		delete node;
	}
}

void ParagraphNode::addInLine(const InlineNode* node)
{
    content.push_back(dynamic_cast<InlineNode*>(node->clone()));
}

string ParagraphNode::toHTML() const
{
	string result = "<p>";
	for (const InlineNode* node : content)
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
	for (const InlineNode* node : content)
	{
		node->print(os, indent + 1);
	}
}

void ParagraphNode::collectStatistics(Statistics& stats) const
{
	stats.totalLines++;
	stats.paragraphs++;

	for (size_t i = 0; i < content.size(); i++) content[i]->collectStatistics(stats);
}
