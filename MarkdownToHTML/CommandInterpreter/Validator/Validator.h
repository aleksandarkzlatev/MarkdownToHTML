#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>

using namespace std;

class Validator
{
	enum ListType
	{
		NONE,
		ORDERED,
		UNORDERED
	};

	struct ValidationError {
		size_t line;
		string message;
	};

	bool isDigit(char c) const;
	bool endsWithMarker(const vector<string>& stack, const string& marker) const;
	bool isUnorderedListItem(const string& line) const;
	bool isOrderedListItem(const string& line) const;

	void validateHeader(const string& line, size_t lineNumber, vector<ValidationError>& errors);
	void validateLine(const string& line, size_t lineNumber, ListType& currentList, vector<ValidationError>& errors);
	void validateInline(const string& line, size_t lineNumber, vector<ValidationError>& errors);
public:
	void valdateFile(const string& filename);
};

