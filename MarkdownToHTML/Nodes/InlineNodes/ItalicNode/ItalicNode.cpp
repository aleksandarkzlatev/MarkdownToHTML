#include "ItalicNode.h"

void ItalicNode::addChild(unique_ptr<InlineNode> child)
{
    children.push_back(move(child));
}

string ItalicNode::toHTML() const
{
    string result = "<i>";

    for (const unique_ptr<InlineNode>& child : children) {
        result += child->toHTML();
    }

    result += "</i>";

    return result;
}

void ItalicNode::print(ostream& os, size_t indent) const
{
    printIndent(os, indent);
    os << "ItalicNode\n";
    for (const unique_ptr<InlineNode>& child : children) {
        child->print(os, indent + 1);
    }
}
