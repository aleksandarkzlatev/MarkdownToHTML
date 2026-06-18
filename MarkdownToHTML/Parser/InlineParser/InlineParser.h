#pragma once
#include "../../Nodes/InlineNodes/BoldNode/BoldNode.h"
#include "../../Nodes/InlineNodes/CodeNode/CodeNode.h"
#include "../../Nodes/InlineNodes/ItalicNode/ItalicNode.h"
#include "../../Nodes/InlineNodes/StrikeNode/StrikeNode.h"
#include "../../Nodes/InlineNodes/TextNode/TextNode.h"

class InlineParser
{
	vector<InlineNode*> parseRange(const string& text, size_t start, size_t end);
	size_t findClosing(const string& text, size_t start, const string& marker);
public:
	vector<InlineNode*> parse(const string& text);
};

