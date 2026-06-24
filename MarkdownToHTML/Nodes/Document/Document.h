#pragma once
#include "../BlockNodes/BlockNode.h"
#include "../Statistics.h"

/**
 * @brief Представя Markdown документ.
 *
 * Document е коренът на синтактичното дърво и съдържа всички блокови
 * елементи на документа. Предоставя функционалност за генериране на HTML,
 * извеждане на дървото и събиране на статистическа информация.
 */
class Document
{
private:
    vector<BlockNode*>blocks;

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
    /**
     * @brief Представя Markdown документ.
     * събира статистиките на всички елементи от дървото
     */
    Statistics getStatistics() const;
};

