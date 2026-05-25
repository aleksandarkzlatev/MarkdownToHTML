#include "StrikeNode.h"

void StrikeNode::addChild(unique_ptr<InlineNode> child)
{
    children.push_back(move(child));
}

string StrikeNode::toHTML() const
{
    string result = "<s>";

    for (const unique_ptr<InlineNode>& child : children) {
        result += child->toHTML();
    }

    result += "</s>";

    return result;
}

void StrikeNode::print(ostream& os, size_t indent)
{
    printIndent(os, indent);
    os << "StrikeNode\n";

    for (const unique_ptr<InlineNode>& child : children) {
        child->print(os, indent + 1);
    }
}
