#include <iostream>
#include "SLinkedListClass.h"
#include <fstream>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("names.txt");

	SLinkedList Names;

	while(!fin.eof())
	{
		string line;
		getline(fin, line);
		Names.insert(line);
	}

	Names.display();

	fin.close();
	return 0;

}
