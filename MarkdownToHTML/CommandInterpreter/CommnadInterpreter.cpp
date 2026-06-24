#include "CommnadInterpreter.h"

vector<string> CommnadInterpreter::split(const string& str)
{
	vector<string> result;
	size_t start = 0;

	while (start < str.length()) {
		while (start < str.length() && str[start] == ' ') start++;
		if (start >= str.length()) break;
		size_t end = start;

		while (end < str.length() && str[end] != ' ') end++;

		result.push_back(str.substr(start, end - start));

		start = end;
	}

	return result;
}

void CommnadInterpreter::translate(const string& input, const string& output)
{
	ifstream checkFile(output);
	if (checkFile.is_open()) {
		checkFile.close();

		cout << "File \"" << output << "\" already exists. Overwrite? (y/n): ";
		string response;
		getline(cin, response);

		if (response != "y") {
			cout << "Translation cancelled.\n";
			return;
		}
	}

	ofstream out(output);
	if (!out) throw runtime_error("Cannot open output file");
	
	Document doc = parser.parse(input);

	out << doc.toHTML();
	out.close();

	cout << "Translation successful.\n";
}

void CommnadInterpreter::print(const string& input)
{
	Document doc = parser.parse(input);
	doc.print(cout);
}

void CommnadInterpreter::validate(const string& filename)
{
	Validator validator;
	validator.validateFile(filename);
}

void CommnadInterpreter::info(const string& input)
{
	Document doc = parser.parse(input);
	Statistics stats = doc.getStatistics();

	cout << "Total lines: " << stats.totalLines << '\n';

	cout << "H1: " << stats.h1 << '\n';

	cout << "H2: " << stats.h2 << '\n';

	cout << "H3: " << stats.h3 << '\n';

	cout << "H4: " << stats.h4 << '\n';

	cout << "H5: " << stats.h5 << '\n';

	cout << "H6: " << stats.h6 << '\n';

	cout << "Paragraphs: " << stats.paragraphs << '\n';

	cout << "Horizontal Rules: " << stats.horizontalRules << '\n';

	cout << "Ordered Lists: " << stats.orderedLists << '\n';

	cout << "Unordered Lists: " << stats.unorderedLists << '\n';

	cout << "Bold: " << stats.bold << '\n';

	cout << "Italic: " << stats.italic << '\n';

	cout << "Strike: " << stats.strike << '\n';

	cout << "Code: " << stats.code << '\n';
}

void CommnadInterpreter::run()
{
	string command;

	while (true) {
		cout << "> ";
		getline(cin, command);

		vector<string> args = split(command);

		try {
			if (args[0] == "translate") {
				if (args.size() != 3) throw logic_error("Invalid arguments given for translate");
				translate(args[1], args[2]);
			} 
			else if (args[0] == "print") {
				if (args.size() != 2) throw logic_error("Invalid arguments given for print");
				print(args[1]);
			} 
			else if (args[0] == "validate") {
				if (args.size() != 2) throw logic_error("Invalid arguments given for validate");
				validate(args[1]);
			} 
			else if (args[0] == "info") {
				if (args.size() != 2) throw logic_error("Invalid arguments given for info");
				info(args[1]);
			} 
			else if (args[0] == "exit") break;

			else {
				cout << "Unknown command, valid commands:\n";
				cout << "translate (input file) (output file); \n"<< 
					"print (input file);\n" <<
					"validate (input file);\n" <<
					"info (input file);\n" <<
				    "exit\n";
			} 
		}
		catch (const exception& e) {
			cout << e.what() << '\n';
		}
	}
}
