#include "Parser.h"

Document Parser::parse(const string& filename)
{
	ifstream file(filename);
	if (!file.is_open()) throw runtime_error("Could not open file!");

	Document document;
	string line;
	
	while (getline(file, line)) {
		BlockNode* node = nullptr;

		if (blockParser.isHorizontalRule(line)) node = blockParser.parseHorizontalRule();

		else if (blockParser.isHeader(line)) node = blockParser.parseHeader(line);

		else if (blockParser.isOrderedListItem(line) || blockParser.isUnorderedListItem(line)) node = blockParser.parseList(file, line);

		else node = blockParser.parseParagraph(line);

		if (node) document.addBlock(node);
	}

	return document;
}
