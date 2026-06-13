#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Node
{
public:
	virtual ~Node() = default;

	virtual string toHTML() const = 0;

	virtual void print(ostream& os, size_t indent = 0) const = 0;

	virtual string getType() const = 0;
protected:
	void printIndent(ostream& os, size_t indent) const;
public:
	virtual Node* clone() const = 0;
};

