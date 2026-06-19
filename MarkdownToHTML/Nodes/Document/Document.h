#pragma once
#include "../BlockNodes/BlockNode.h"
#include "../Statistics.h"

class Document
{
private:
    std::vector<BlockNode*>blocks;

public:
	Document() = default;
    Document(const Document& other);
    Document& operator=(const Document& other);
    ~Document();

    void addBlock(BlockNode* block);
    const vector<BlockNode*> getBlocks() const { return blocks; }
    string toHTML() const;
    void print(ostream& os) const;

	Document* clone() const { return new Document(*this); }
    Statistics getStatistics() const;
};

