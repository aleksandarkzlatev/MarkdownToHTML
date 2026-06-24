#pragma once
#include "../Nodes/Document/Document.h"
#include "BlockParser/BlockParser.h"

/**
 * @brief Главен парсер на Markdown файла.
 *
 * Създава синтактично дърво от BlockNode и InlineNode обекти.
 */
class Parser
{
	BlockParser blockParser;
public:
	Document parse(const string& filename);
};

