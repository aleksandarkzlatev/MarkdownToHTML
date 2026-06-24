#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>

using namespace std;

/**
 * @brief Проверява Markdown файл за синтактични грешки.
 *
 * Validator анализира съдържанието на документа без да изгражда
 * синтактично дърво. Проверява коректността на блоковите и inline
 * елементите, валидността на заглавията, списъците и форматиращите
 * маркери, и събира всички открити грешки.
 */
class Validator
{
	/**
	 * @brief Тип на текущо обработвания списък.
	 */
	enum ListType
	{
		NONE,
		ORDERED,
		UNORDERED
	};

	/**
	 * @brief Представя информация за открита грешка.
	 */
	struct ValidationError {
		size_t line;
		string message;
	};

	bool isDigit(char c) const;
	/**
     * @brief Проверява дали върхът на стека съвпада с даден маркер.
     */
	bool endsWithMarker(const vector<string>& stack, const string& marker) const;
	bool isUnorderedListItem(const string& line) const;
	bool isOrderedListItem(const string& line) const;

	void validateHeader(const string& line, size_t lineNumber, vector<ValidationError>& errors);
	/**
	 * @brief Проверява валидността на един ред от документа.
	 */
	void validateLine(const string& line, size_t lineNumber, ListType& currentList, vector<ValidationError>& errors);
	/**
	* @brief Проверява коректността на inline форматирането.
	*
	* Проверяват се незатворени маркери за bold, italic,
	* strike и code.
	*/
	void validateInline(const string& line, size_t lineNumber, vector<ValidationError>& errors);
public:
	/**
	 * @brief Проверява валидността на Markdown файл.
	 *
	 * При откриване на грешки извежда номера на реда и
	 * описание на всяка от тях.
	 */
	void validateFile(const string& filename);
};

