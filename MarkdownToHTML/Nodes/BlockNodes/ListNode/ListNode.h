#pragma once
#include "../BlockNode.h"
#include"../ListItemNode/ListItemNode.h"

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
	string getType() const override { return "List"; }

	virtual Node* clone() const override { return new ListNode(*this); }
};

