#include "ListNode.h"

void ListNode::addItem(unique_ptr<ListItemNode> item)
{
    items.push_back(move(item));
}

string ListNode::toHTML() const
{
    string result;
    if (ordered) result += "<ol>";
    else result += "<ul>";
    
    for (const unique_ptr<ListItemNode>& item : items)
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
	for (const unique_ptr<ListItemNode>& item : items)
	{
		item->print(os, indent + 1);
	}
}
