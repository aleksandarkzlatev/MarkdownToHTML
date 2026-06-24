#include "InlineParser.h"

string InlineParser::getMarkerAt(const string& text, size_t pos) const
{
    if (pos + 2 < text.size() && text.substr(pos, 3) == "***")
        return "***";

    if (pos + 1 < text.size() && text.substr(pos, 2) == "**")
        return "**";

    if (text[pos] == '*')
        return "*";

    if (text[pos] == '~')
        return "~";

    if (text[pos] == '`')
        return "`";

    return "";
}

bool InlineParser::markerMatches(const string& marker, MarkerType current) const
{
    switch (current)
    {
    case BOLD:
        return marker == "*" || marker == "***";

    case ITALIC:
        return marker == "**" || marker == "***";

    case BOTH:
        return marker == "***";

    case STRIKE:
        return marker == "~";

    default:
        return false;
    }
}

vector<InlineNode*> InlineParser::parseRange(const string& text, size_t& pos, MarkerType current)
{
    vector<InlineNode*> result;
    string plain;

    while (pos < text.size())
    {
        string marker = getMarkerAt(text, pos);

        if (current != NONE && markerMatches(marker, current))
        {
            if (!plain.empty())
            {
                result.push_back(new TextNode(plain));
                plain.clear();
            }

            pos += marker.size();
            return result;
        }

        if (marker == "`")
        {
            if (!plain.empty())
            {
                result.push_back(new TextNode(plain));
                plain.clear();
            }

            pos++;

            size_t start = pos;

            while (pos < text.size() && text[pos] != '`')
                pos++;

            result.push_back(
                new CodeNode(text.substr(start, pos - start)));

            if (pos < text.size())
                pos++;

            continue;
        }

        if (marker == "***")
        {
            if (!plain.empty())
            {
                result.push_back(new TextNode(plain));
                plain.clear();
            }

            if (current == BOLD)
                pos += 1;
            else if (current == ITALIC)
                pos += 2;
            else
                pos += marker.size();

            vector<InlineNode*> children =
                parseRange(text, pos, BOTH);

            BoldNode* bold = new BoldNode();

            for (InlineNode* child : children)
                bold->addNode(child);

            ItalicNode* italic = new ItalicNode();
            italic->addNode(bold);

            result.push_back(italic);

            continue;
        }

        if (marker == "**")
        {
            if (!plain.empty())
            {
                result.push_back(new TextNode(plain));
                plain.clear();
            }

            pos += 2;

            vector<InlineNode*> children =
                parseRange(text, pos, ITALIC);

            ItalicNode* italic = new ItalicNode();

            for (InlineNode* child : children)
                italic->addNode(child);

            result.push_back(italic);

            continue;
        }

        if (marker == "*")
        {
            if (!plain.empty())
            {
                result.push_back(new TextNode(plain));
                plain.clear();
            }

            pos++;

            vector<InlineNode*> children =
                parseRange(text, pos, BOLD);

            BoldNode* bold = new BoldNode();

            for (InlineNode* child : children)
                bold->addNode(child);

            result.push_back(bold);

            continue;
        }

        if (marker == "~")
        {
            if (!plain.empty())
            {
                result.push_back(new TextNode(plain));
                plain.clear();
            }

            pos++;

            vector<InlineNode*> children =
                parseRange(text, pos, STRIKE);

            StrikeNode* strike = new StrikeNode();

            for (InlineNode* child : children)
                strike->addNode(child);

            result.push_back(strike);

            continue;
        }

        plain += text[pos];
        pos++;
    }

    if (!plain.empty())
        result.push_back(new TextNode(plain));

    return result;
}

vector<InlineNode*> InlineParser::parse(const string& text)
{
    size_t pos = 0;
    return parseRange(text, pos, NONE);
}
