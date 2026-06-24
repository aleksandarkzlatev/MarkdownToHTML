#pragma once
#include "../BlockNode.h"
#include"../ListItemNode/ListItemNode.h"

/**
 * @brief Представя Markdown списък.
 *
 * ListNode е блоков възел, който съдържа множество елементи от тип
 * ListItemNode. Списъкът може да бъде нареден (<ol>) или ненареден (<ul>).
 */
class ListNode : public BlockNode
{
	bool ordered;
	vector<ListItemNode*> items;
public:
	ListNode(bool ordered) : ordered(ordered) {}
	ListNode(const ListNode& other);
	ListNode& operator=(const ListNode& other);
	~ListNode();

	void addItem(const ListItemNode* item);
	string toHTML() const override;
	void print(ostream& os, size_t indent = 0) const override;
	bool isOrdered() const { return ordered; }
	const vector<ListItemNode*>& getItems() const { return items; }

	virtual Node* clone() const override { return new ListNode(*this); }
	void collectStatistics(Statistics& stats) const;
};

