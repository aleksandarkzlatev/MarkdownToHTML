#include "CodeNode.h"

CodeNode::CodeNode(const string& code)
{
    this->code = code;
}

string CodeNode::toHTML() const
{
    return "<code>" + code + "</code>";
}

void CodeNode::print(ostream& os, size_t indent) const
{
    printIndent(os, indent);
    os << "CodeNode: " << code << "\n";
}
