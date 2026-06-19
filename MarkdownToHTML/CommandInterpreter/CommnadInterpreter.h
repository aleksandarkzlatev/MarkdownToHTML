#pragma once
#include "../Parser/Parser.h"
#include "Validator/Validator.h"

class CommnadInterpreter
{
	Parser parser;

	vector<string> split(const string& str);

	void translate(const string& input, const string& output);

	void print(const string& input);

	void validate(const string& filename);

	void info(const string& input);

public:
	void run();
};

