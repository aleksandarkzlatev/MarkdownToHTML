#include "BoldNode.h"

void BoldNode::addChild(unique_ptr<InlineNode> child)
{
    // making sure that we dont copy the data but "move" it
    children.push_back(move(child));
}

string BoldNode::toHTML() const
{
    string result = "<b>";
    
    for (const unique_ptr<InlineNode>& child : children) {
        result += child->toHTML();
    }
    result += "</b>";

    return result;
}

void BoldNode::print(ostream& os, size_t indent) const
{
    printIndent(os, indent);
    os << "BoldNode\n";

    for (const unique_ptr<InlineNode>& child : children) {
        child->print(os, indent + 1);
    }
}
