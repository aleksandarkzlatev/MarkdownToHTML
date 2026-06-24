#include "Validator.h"

bool Validator::isDigit(char c) const
{
	return c >= '0' && c <= '9';
}

bool Validator::endsWithMarker(const vector<string>& stack, const string& marker) const
{
	if (stack.empty()) return false;
	return stack.back() == marker;
}

bool Validator::isUnorderedListItem(const string& line) const
{
	return line.size() > 2 &&
		((line[0] == '-' || line[0] == '*') && line[1] == ' ');
}

bool Validator::isOrderedListItem(const string& line) const
{
	size_t i = 0;

	while (i < line.size() && isDigit(line[i])) i++;
	if (i == 0) return false;
	
	if (i + 1 >= line.size()) return false;

	if (line[i] != '.') return false;

	if (line[i + 1] != ' ') return false;

	int number = atoi(line.substr(0, i).c_str());

	return number > 0;
}

void Validator::validateHeader(const string& line, size_t lineNumber, vector<ValidationError>& errors)
{
	int hashes = 0;
	while (hashes < line.length() && line[hashes] == '#') hashes++;

	if (hashes > 6) errors.push_back({ lineNumber , "invalid header level" });

	if (hashes < line.length() && line[hashes] != ' ') errors.push_back({ lineNumber , "missing space after #" });
}

void Validator::validateLine(const string& line, size_t lineNumber, ListType& currentList, vector<ValidationError>& errors)
{
	if (line.empty()) {
		currentList = NONE;
		return;
	}

	if (line == "- - -") return;
	
	if (line[0] == '#') validateHeader(line, lineNumber, errors);

	bool ordered = isOrderedListItem(line);
	bool unordered = isUnorderedListItem(line);

	if (ordered || unordered) {
		if (line.back() == ' ') errors.push_back({ lineNumber , "empty list item" });

		if (currentList == NONE) currentList = ordered ? ORDERED : UNORDERED;
		else {
			if (currentList == ORDERED && unordered) errors.push_back({ lineNumber , "mixed list types" });
			if (currentList == UNORDERED && ordered) errors.push_back({ lineNumber , "mixed list types" });
		}
	}
	else currentList = NONE;
	
	validateInline(line, lineNumber, errors);
}

void Validator::validateInline(const string& line, size_t lineNumber, vector<ValidationError>& errors)
{
	vector<string> stack;
	size_t i = 0;

	while (i < line.size()) {
		if (i + 2 < line.size() &&
			line.substr(i, 3) == "***")
		{
			if (stack.size() >= 2 &&
				stack.back() == "**" &&
				stack[stack.size() - 2] == "*")
			{
				stack.pop_back();
				stack.pop_back();
			}
			else if (stack.size() >= 2 &&
				stack.back() == "*" &&
				stack[stack.size() - 2] == "**")
			{
				stack.pop_back();
				stack.pop_back();
			}
			else if (endsWithMarker(stack, "***"))
			{
				stack.pop_back();
			}
			else
			{
				stack.push_back("***");
			}

			i += 3;
			continue;
		}

		if (i + 1 < line.size() && line[i] == '*' && line[i + 1] == '*') {
			if (endsWithMarker(stack, "**")) stack.pop_back();
			else stack.push_back("**");

			i += 2;
			continue;
		}

		if (line[i] == '*') {
			if (endsWithMarker(stack, "*")) stack.pop_back();
			else stack.push_back("*");

			i++;
			continue;
		}

		if (line[i] == '~') {
			if (endsWithMarker(stack, "~")) stack.pop_back();
			else stack.push_back("~");

			i++;
			continue;
		}

		if (line[i] == '`') {
			i++;
			while (i < line.size() && line[i] != '`') i++;
			if (i < line.size()) i++; 
			continue;
		}


		i++;
	}

	while (!stack.empty()) {
		errors.push_back( { lineNumber, "unclosed formatting block: " + stack.back() });
		stack.pop_back();
	}
}

void Validator::validateFile(const string& filename)
{
	vector<ValidationError> errors;
	ifstream file(filename);
	if (!file.is_open()) throw runtime_error("Cannot open input file! Check if the name is wrong or if the exists!");
	if (file.peek() == EOF) throw logic_error("File is empty");
	string line;
	size_t lineNumber = 1;
	ListType currentList = NONE;

	while (getline(file, line)) {
		validateLine(line, lineNumber, currentList, errors);
		lineNumber++;
	}

	if (file.bad()) throw runtime_error("Read error while reading file");

	if (errors.empty()) cout << "Markdown is valid.\n";
	else {
		for (const ValidationError& err : errors)
			cout << "Line " << err.line << ": " << err.message << "\n";
	}
}
