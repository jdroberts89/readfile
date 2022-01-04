#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>
#include <streambuf>

using namespace std;

#define FILE "C:\\Users\\jrobe\\Downloads\\Files\\TransactionSummary.txt"
#define DFILE "C:\\Users\\jrobe\\Downloads\\Files\\TransactionSummaryJason.txt"



string readFile(string file) {
	std::ifstream t(file);
	std::string str;

	t.seekg(0, std::ios::end);
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());
	return str;
};

string readFileBuffer(string file) {
	std::ifstream t(file);
	std::stringstream buffer;

	buffer << t.rdbuf();

	return buffer.str();

};



void writeFile(string contents, string file) { 
	std::ofstream o(file);
	o << contents;
};

string findAndInsert(string contents, string find, string insert) {
	size_t loc = contents.find(find);
	contents.insert(loc + find.length(), insert);
	contents.erase(loc, find.length());
	return contents;
};

void findAndInsertptr(const string& contents, string find, string insert) {
	string& content = const_cast<string&>(contents);
	size_t loc = content.find(find);
	content.insert(loc + find.length(), insert);
	content.erase(loc, find.length());
	
};





int main() {
	auto begin = chrono::system_clock::now();
	//string tran = readFile(FILE);
	string tran = readFileBuffer(FILE);
	auto end = chrono::system_clock::now();
	chrono::duration<double> timetoread = end - begin;




	auto writeBegin = chrono::system_clock::now();
	writeFile(tran, DFILE);
	auto writeEnd = chrono::system_clock::now();
	chrono::duration<double> timetowrite = writeEnd - writeBegin;

	cout << "Time to read: " << timetoread.count() << endl;



	return 0;
};