#pragma once
#include "../BlockNode.h"
#include"../../InlineNodes/InlineNode.h"

/**
 * @brief Представя един елемент от списък.
 *
 * ListItemNode съдържа поредица от inline елементи, които образуват
 * съдържанието на съответния <li> елемент.
 */
class ListItemNode : public BlockNode
{
	vector<InlineNode*> content;
public:
	ListItemNode() = default;
	ListItemNode(const ListItemNode& other);
	ListItemNode& operator=(const ListItemNode& other);
	~ListItemNode();

	void addInLine(const InlineNode* node);
	string toHTML() const override;
	void print(ostream& os, size_t indent = 0) const override;

	virtual Node* clone() const override { return new ListItemNode(*this); }
	void collectStatistics(Statistics& stats) const;
};

