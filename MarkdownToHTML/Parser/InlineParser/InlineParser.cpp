#include "InlineParser.h"

vector<InlineNode*> InlineParser::parseRange(const string& text, size_t start, size_t end)
{
    vector<InlineNode*> result;
    string plainText;
    size_t i = start;

    while (i < end) {
        if (text[i] == '`') {
            size_t close = findClosing(text, i + 1, "`");
            if (close == string::npos || close >= end) {
                plainText += text[i];
                i++;
                continue;
            }

            if (!plainText.empty()) {
                result.push_back(new TextNode(plainText));
                plainText.clear();
            }

            CodeNode* node = new CodeNode(text.substr(i + 1, close - i - 1));
            result.push_back(node);

            i = close + 1;
            continue;
        }

        if (i + 2 < end && text.substr(i, 3) == "***") {
            size_t close = findClosing(text, i + 3, "***");
            if (close != string::npos && close < end) {
                if (!plainText.empty()) {
                    result.push_back(new TextNode(plainText));
                    plainText.clear();
                }

                ItalicNode* italic = new ItalicNode();
                BoldNode* bold = new BoldNode();

				vector<InlineNode*> nodes = parseRange(text, i + 3, close);

                for (InlineNode* node : nodes) bold->addNode(node);
                
				italic->addNode(bold);


				result.push_back(italic);
				i = close + 3;
                continue;
            }
        }

        if (i + 1 < end && text.substr(i, 2) == "**") {
            size_t close = findClosing(text, i + 2, "**");
            if (close != string::npos && close < end) {
                if(!plainText.empty()) {
                    result.push_back(new TextNode(plainText));
                    plainText.clear();
                }

                ItalicNode* italic = new ItalicNode();

				vector<InlineNode*> nodes = parseRange(text, i + 2, close);

                for (InlineNode* node : nodes) italic->addNode(node);

                result.push_back(italic);

                i = close + 2;
                continue;
            }
        }

        if (text[i] == '*') {
            size_t close = findClosing(text, i + 1, "*");
            if (close != string::npos && close < end) {
                if (!plainText.empty()) {
                    result.push_back(new TextNode(plainText));
                    plainText.clear();
                }

                BoldNode* bold = new BoldNode();

                vector<InlineNode*> nodes = parseRange(text, i + 1, close);

                for (InlineNode* node : nodes) bold->addNode(node);

                result.push_back(bold);

                i = close + 1;
                continue;
            }
        }

        if (text[i] == '~') {
            size_t close = findClosing(text, i + 1, "~");
            if (close != string::npos && close < end) {
                if (!plainText.empty()) {
                    result.push_back(new TextNode(plainText));
                    plainText.clear();
                }

                StrikeNode* strike = new StrikeNode();

                vector<InlineNode*> nodes = parseRange(text, i + 1, close);

                for (InlineNode* node : nodes) strike->addNode(node);

                result.push_back(strike);

                i = close + 1;
                continue;
            }
        }

        plainText += text[i];
        i++;
    }

    if (!plainText.empty())
    {
        result.push_back(
            new TextNode(plainText));
    }

    return result;
}

size_t InlineParser::findClosing(const string& text, size_t start, const string& marker)
{
    return text.find(marker, start);
}

vector<InlineNode*> InlineParser::parse(const string& text)
{
    return parseRange(text, 0, text.size());
}
