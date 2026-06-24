#pragma once
#include "../Parser/Parser.h"
#include "Validator/Validator.h"

/**
 * @brief Интерпретатор на потребителските команди.
 *
 * CommandInterpreter осигурява интерфейс между потребителя и
 * останалите компоненти на системата. Той обработва въведените
 * команди и извиква съответните операции върху Markdown файловете,
 * като превод към HTML, валидиране, извеждане на синтактичното
 * дърво и извличане на статистика.
 */
class CommnadInterpreter
{
	Parser parser;

	/**
	 * @brief Разделя командата на отделни аргументи.
	 */
	vector<string> split(const string& str);

	/**
	 * @brief Превежда Markdown файл в HTML.
	 */
	void translate(const string& input, const string& output);

	/**
	  * @brief Извежда синтактичното дърво на документа.
	  */
	void print(const string& input);

	/**
	 * @brief Проверява валидността на Markdown файл.
	 */
	void validate(const string& filename);

	/**
	 * @brief Извежда статистическа информация за документа.
	 */
	void info(const string& input);

public:
	/**
	 * @brief Стартира командния интерпретатор.
	 *
	 * Изчаква потребителски команди и ги изпълнява, докато не бъде
	 * подадена командата exit.
	 */
	void run();
};

