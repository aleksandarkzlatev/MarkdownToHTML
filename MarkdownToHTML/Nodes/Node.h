#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Statistics.h"

using namespace std;

/**
 * @brief Базов абстрактен клас за всички възли в синтактичното дърво.
 *
 * Всеки възел в Markdown документа наследява Node и предоставя
 * реализация за преобразуване в HTML, отпечатване на дървото,
 * клониране и събиране на статистика.
 */
class Node
{
public:
	virtual ~Node() = default;

	/**
	 * @brief Превръща възела в HTML.
	 */
	virtual string toHTML() const = 0;

	/**
	 * @brief Отпечатва възела и неговите наследници.
	 *
	 * @param os Изходен поток.
	 * @param indent Брой интервали за отместване.
	 */
	virtual void print(ostream& os, size_t indent = 0) const = 0;

protected:
	/**
	 * @brief Отпечатва отместване с даден брой интервали.
	 */
	void printIndent(ostream& os, size_t indent) const;
public:
	virtual Node* clone() const = 0;
	/**
	* @brief Добавя информация за възела към статистиката.
	*
	* @param stats Обект, в който се натрупва статистиката.
	*/
	virtual void collectStatistics(Statistics& stats) const = 0;
};

