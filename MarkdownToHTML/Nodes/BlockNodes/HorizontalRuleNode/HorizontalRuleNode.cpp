#include "HorizontalRuleNode.h"

void HorizontalRuleNode::print(ostream& os, size_t indent) const
{
	printIndent(os, indent);
	os << "HorizontalRuleNode\n";
}

void HorizontalRuleNode::collectStatistics(Statistics& stats) const
{
	stats.totalLines++;
	stats.horizontalRules++;
}
