#pragma once
#include "../Nodes/Document/Document.h"
#include "BlockParser/BlockParser.h"

class Parser
{
	BlockParser blockParser;
public:

	Document parse(const string& filename);
};

