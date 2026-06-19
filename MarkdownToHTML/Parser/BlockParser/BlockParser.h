#pragma once
#include "../../Nodes/BlockNodes/HorizontalRuleNode/HorizontalRuleNode.h"
#include "../../Nodes/BlockNodes/HeaderNode/HeaderNode.h"
#include "../../Nodes/BlockNodes/ListItemNode/ListItemNode.h"
#include "../../Nodes/BlockNodes/ListNode/ListNode.h"
#include "../../Nodes/BlockNodes/ParagraphNode/ParagraphNode.h"
#include "../InlineParser/InlineParser.h"
#include <fstream>

class BlockParser
{
	InlineParser inlineParser;
	
public:
	bool isDigit(char c) const;
	bool isHeader(const string& line) const;
	bool isHorizontalRule(const string& line) const;
	bool isUnorderedListItem(const string& line) const;
	bool isOrderedListItem(const string& line) const;

	BlockNode* parseHeader(const string& line);
	BlockNode* parseParagraph(const string& line);
	BlockNode* parseHorizontalRule();
	ListNode* parseList(ifstream& file, const string& firstLine);
};

