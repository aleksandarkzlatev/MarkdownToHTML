#include "ListNode.h"

ListNode::ListNode(const ListNode& other)
{
	ordered = other.ordered;
	for (const ListItemNode* item : other.items)
	{
		items.push_back(dynamic_cast<ListItemNode*>(item->clone()));
	}
}

ListNode& ListNode::operator=(const ListNode& other)
{
	if (this != &other)
	{
		ordered = other.ordered;
		for (ListItemNode* item : items) delete item;
		items.clear();
		for (const ListItemNode* item : other.items)
		{
			items.push_back(dynamic_cast<ListItemNode*>(item->clone()));
		}
	}
	return *this;

}

ListNode::~ListNode()
{
	for (ListItemNode* item : items) delete item;
}

void ListNode::addItem(const ListItemNode* item)
{
    items.push_back(dynamic_cast<ListItemNode*>(item->clone()));
}

string ListNode::toHTML() const
{
    string result;
    if (ordered) result += "<ol>";
    else result += "<ul>";
    
    for (const ListItemNode* item : items)
    {
        result += item->toHTML();
    }

    if (ordered) result += "</ol>";
    else result += "</ul>";

    return result;
}

void ListNode::print(ostream& os, size_t indent) const
{
	printIndent(os, indent);
    os << "ListNode(" << (ordered ? "ordered" : "unordered") << ")\n";
	for (const ListItemNode* item : items)
	{
		item->print(os, indent + 1);
	}
}

void ListNode::collectStatistics(Statistics& stats) const
{
	if (ordered) stats.orderedLists++;
	else stats.unorderedLists++;

	stats.totalLines += items.size();

	for (size_t i = 0; i < items.size(); i++) items[i]->collectStatistics(stats);
}
