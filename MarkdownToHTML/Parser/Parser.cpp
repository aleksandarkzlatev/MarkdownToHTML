#include "Parser.h"


Document Parser::parse(const string& filename)
{
	ifstream file(filename);
	if (!file.is_open()) throw runtime_error("Cannot open input file! Check if the name is wrong or if the exists!");

	Document document;
	string line;
	
	while (getline(file, line)) {
		BlockNode* node = nullptr;

		if (line.empty()) continue;

		if (blockParser.isHorizontalRule(line)) node = blockParser.parseHorizontalRule();

		else if (blockParser.isHeader(line)) node = blockParser.parseHeader(line);

		else if (blockParser.isOrderedListItem(line) || blockParser.isUnorderedListItem(line)) node = blockParser.parseList(file, line);

		else node = blockParser.parseParagraph(line);

		if (node) document.addBlock(node);
	}

	if (file.bad()) throw runtime_error("Read error while reading file");

	return document;
}
