#pragma once
#include "../BlockNode.h"
#include"../ListItemNode/ListItemNode.h"

class ListNode : public BlockNode
{
	bool ordered;
	vector<unique_ptr<ListItemNode>> items;
public:
	ListNode(bool ordered) : ordered(ordered) {}
	void addItem(unique_ptr<ListItemNode> item);
	string toHTML() const override;
	void print(ostream& os, size_t indent = 0) const override;
	string getType() const override { return "List"; }
};

