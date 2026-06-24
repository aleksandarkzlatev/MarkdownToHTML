#pragma once
#include "../../Nodes/InlineNodes/BoldNode/BoldNode.h"
#include "../../Nodes/InlineNodes/CodeNode/CodeNode.h"
#include "../../Nodes/InlineNodes/ItalicNode/ItalicNode.h"
#include "../../Nodes/InlineNodes/StrikeNode/StrikeNode.h"
#include "../../Nodes/InlineNodes/TextNode/TextNode.h"

/**
 * @brief Клас за обработка на inline форматирането в Markdown.
 *
 * InlineParser преобразува форматиран текст в съответните възли
 * на синтактичното дърво. Поддържа вложени форматиращи елементи
 * като удебелен текст, курсив, комбинация от двете, зачеркнат текст
 * и кодови блокове.
 */
class InlineParser
{
    enum MarkerType
    {
        NONE,
        BOLD,
        ITALIC,
        BOTH,
        STRIKE
    };
    /**
     * @brief Определя вида на маркера, започващ от дадена позиция.
     */
    string getMarkerAt(const string& text, size_t pos) const;

    /**
     * @brief Проверява дали намереният маркер затваря текущия блок.
     */
    bool markerMatches(const string& marker, MarkerType current) const;

    /**
     * @brief Рекурсивно парсва част от текста.
     *
     * Използва се за обработка на вложени форматиращи блокове.
     */
	vector<InlineNode*> parseRange(const string& text, size_t& pos, MarkerType current);
public:
    /**
     * @brief Парсира форматиран текст.
     */
	vector<InlineNode*> parse(const string& text);
};

