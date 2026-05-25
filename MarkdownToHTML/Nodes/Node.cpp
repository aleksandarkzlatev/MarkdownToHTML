#include "Node.h"

void Node::printIndent(ostream& os, size_t indent) const
{
	for (size_t i = 0; i < indent; i++) {
		os << " ";
	}
}
