#include "Document.h"

Document::Document(const Document& other)
{
	for (BlockNode* block : other.blocks)
	{
		blocks.push_back(dynamic_cast<BlockNode*>(block->clone()));
	}
}

Document& Document::operator=(const Document& other)
{
	if (this != &other)
	{
		for (BlockNode* block : blocks) delete block;
		blocks.clear();
		for (BlockNode* block : other.blocks)
		{
			blocks.push_back(dynamic_cast<BlockNode*>(block->clone()));
		}
	}
	return *this;
}

Document::~Document()
{
	for (BlockNode* block : blocks) delete block;
}

void Document::addBlock(BlockNode* block)
{
	blocks.push_back(block);
}

string Document::toHTML() const
{
	string result;

	for (const BlockNode* block : blocks)
	{
		result += block->toHTML();
		result += '\n';
	}
	return result;
}

void Document::print(ostream& os) const
{
	os << "Document\n";
	for (const BlockNode* block : blocks)
	{
		block->print(os, 1);
	}
}

Statistics Document::getStatistics() const
{
	Statistics stats;

	for (size_t i = 0; i < blocks.size(); i++) blocks[i]->collectStatistics(stats);

	return stats;
}
