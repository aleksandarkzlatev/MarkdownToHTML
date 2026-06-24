#pragma once

/**
 * @brief Съдържа статистическа информация за Markdown документ.
 *
 * Използва се за съхраняване на броя на различните блокови и inline
 * елементи, открити в синтактичното дърво.
 */
struct Statistics {
	size_t totalLines = 0;

    size_t h1 = 0;
    size_t h2 = 0;
    size_t h3 = 0;
    size_t h4 = 0;
    size_t h5 = 0;
    size_t h6 = 0;

    size_t paragraphs = 0;
    size_t horizontalRules = 0;

    size_t orderedLists = 0;
    size_t unorderedLists = 0;

    size_t bold = 0;
    size_t italic = 0;
    size_t strike = 0;
    size_t code = 0;
};