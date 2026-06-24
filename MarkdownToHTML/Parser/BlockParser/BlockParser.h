#pragma once
#include "../../Nodes/BlockNodes/HorizontalRuleNode/HorizontalRuleNode.h"
#include "../../Nodes/BlockNodes/HeaderNode/HeaderNode.h"
#include "../../Nodes/BlockNodes/ListItemNode/ListItemNode.h"
#include "../../Nodes/BlockNodes/ListNode/ListNode.h"
#include "../../Nodes/BlockNodes/ParagraphNode/ParagraphNode.h"
#include "../InlineParser/InlineParser.h"
#include <fstream>

/**
 * @brief Клас за обработка на блоковите елементи в Markdown.
 *
 * BlockParser преобразува отделните редове на документа в
 * съответните блокови възли от синтактичното дърво, като
 * заглавия, параграфи, списъци и хоризонтални линии.
 */
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
	/**
	 * @brief Парсва последователни елементи на списък.
	 *
	 * В зависимост от типа на първия елемент създава нареден
	 * или ненареден списък и добавя всички последователни
	 * елементи към него.
	 */
	ListNode* parseList(ifstream& file, const string& firstLine);
};

