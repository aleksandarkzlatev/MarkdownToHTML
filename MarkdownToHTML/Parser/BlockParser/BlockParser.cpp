#include "BlockParser.h"


bool BlockParser::isHeader(const string& line) const
{
    return !line.empty() && line[0] == '#';
}

bool BlockParser::isHorizontalRule(const string& line) const
{
    return line == "- - -";
}

bool BlockParser::isUnorderedListItem(const string& line) const
{
    return line.size() > 2 && (
            (line[0] == '-' && line[1] == ' ') ||
            (line[0] == '*' && line[1] == ' ')
            );
}

bool BlockParser::isOrderedListItem(const std::string& line) const
{
    size_t i = 0;

    while (i < line.size() && isdigit(line[i])) i++;

    return i > 0 && i + 1 < line.size() && line[i] == '.' && line[i + 1] == ' ';
}

BlockNode* BlockParser::parseHeader(const string& line)
{
    int level = 0;
    while (level < line.size() && line[level] == '#') level++;

    HeaderNode* header = new HeaderNode(level);
    string content = line.substr(level + 1);
    vector<InlineNode*> inlines = inlineParser.parse(content);

    for (const InlineNode* node : inlines) {
        header->addInLine(node);
    }

    return header;
}

BlockNode* BlockParser::parseParagraph(const string& line)
{
    ParagraphNode* paragraph = new ParagraphNode();

    vector<InlineNode*> inlines = inlineParser.parse(line);

    for (const InlineNode* node : inlines) {
        paragraph->addInLine(node);
    }

    return paragraph;
}

BlockNode* BlockParser::parseHorizontalRule()
{
    return new HorizontalRuleNode();
}

ListNode* BlockParser::parseList(ifstream& file, const string& firstLine)
{
    bool ordered = isOrderedListItem(firstLine);
    ListNode* list = new ListNode(ordered);
    string current = firstLine;

    while (true) {
        ListItemNode* item = new ListItemNode();
        string content;

        if (ordered) {
            size_t pos = current.find('.');
            content = current.substr(pos + 2);
        }
        else content = current.substr(2);

        vector<InlineNode*> inlines = inlineParser.parse(content);

        for (const InlineNode* inlineNode : inlines) item->addInLine(inlineNode);

        list->addItem(item);

        streampos pos = file.tellg();
        if (!getline(file, current)) break;

        bool sameType = ordered ? isOrderedListItem(current) : isUnorderedListItem(current);

        if (!sameType) {
            file.seekg(pos);
            break;
        }
    }

    return list;
}