#pragma once
#include <vector>
#include <map>
#include <fstream>

class CSVparse{
public:
	enum parseSeparator {
		tabulator = 9,
		comma = 44,
		colon = 58,
		semicolon = 59
	} separator;
protected:
	void readLine(std::ifstream& f, std::vector<std::string>* in);
	virtual int parse(std::ifstream& f) = 0;
public:
	virtual void insertRow(std::vector<std::string>& t_data) = 0;
	virtual void insertColumn(std::vector<std::string>& t_data) = 0;

	virtual int readFile(char* file, parseSeparator t_separator) = 0;
	virtual bool writeFile(char* file, parseSeparator t_separator) = 0;

	virtual void clear() = 0;

	static std::string translate_error(int err);
};

class CSVparseKey : public CSVparse {
private:
	std::vector<std::pair<std::string, std::vector<std::string>>> data;

	int parse(std::ifstream& f);
	void addKeys(std::vector<std::string>& keys);
public:
	void insertRow(std::vector<std::string>& t_data);
	void insertColumn(std::vector<std::string>& t_data);
	int readFile(char* file, parseSeparator t_separator);
	bool writeFile(char* file, parseSeparator t_separator);
	void clear();
};

class CSVparseLin : public CSVparse {
private:
	std::vector<std::vector<std::string>> data;

	int parse(std::ifstream& f);
public:
	void insertRow(std::vector<std::string>& t_data);
	void insertColumn(std::vector<std::string>& t_data);
	int readFile(char* file, parseSeparator t_separator);
	bool writeFile(char* file, parseSeparator t_separator);
	void clear();
};