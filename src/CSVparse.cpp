#include "CSVparse.hpp"
#include <string>
#include <fstream>

std::string& prepareToWrite(std::string &str, const char &sym) {
	size_t iter = 0;
	while (iter < str.size()) {
		if (str[iter] == '\"') {
			str = str.substr(0, iter) + "\"" + str.substr(iter, str.size() - 1);
			iter++;
		}
		iter++;
	}
	size_t poz = str.find(sym);
	if (poz < str.size()) {
		str = "\"" + str + "\"";
	}
	return str;
}

std::string CSVparse::translate_error(int err) {
	if (err == 0)
		return "Parsing completed successfully";
	if (err == 1)
		return "Can not open file";
	return "Parse error in line " + std::to_string(err-1);
}

void CSVparse::readLine(std::ifstream& f, std::vector<std::string>* in) {
	in->clear();
	std::string ele = "";
	char temp;
	bool comment = false;
	while (f.get(temp)) {
		if (temp == '"') {
			f.get(temp);
			if (temp == '"') {
				ele += "\"";
				continue;
			}
			comment = !comment;
		}
		if (comment) {
			ele += temp;
		}
		else {
			if (temp == separator) {
				in->emplace_back(ele);
				ele = "";
				continue;
			}
			if (temp == '\n') {
				in->emplace_back(ele);
				return;
			}
			ele += temp;
		}
	}
	if (ele.size() > 0)
		in->emplace_back(ele);
}

int CSVparseKey::parse(std::ifstream& f) {
	std::vector<std::string> in;
	size_t line = 1;
	readLine(f, &in);
	addKeys(in);
	size_t line_size = in.size();
	while (!f.eof()) {
		line++;
		readLine(f, &in);
		if (line_size != in.size() && in.size()>0) {
			return (int)(line_size + 1);
		}
		insertRow(in);
	}
	return 0;
}

void CSVparseKey::addKeys(std::vector<std::string>& keys) {
	for (std::string t : keys) {
		data.emplace_back(std::pair<std::string, std::vector<std::string>>(t, {}));
		data[data.size()-1].second.reserve(keys.size());
	}
}

void CSVparseKey::insertRow(std::vector<std::string>& t_data) {
	if (t_data.size() != data.size())
		return;
	for (size_t i = 0; i < data.size(); i++) {
		data[i].second.emplace_back(t_data[i]);
	}
}

void CSVparseKey::insertColumn(std::vector<std::string>& t_data){
	//TODO:
}

int CSVparseKey::readFile(char* file, parseSeparator t_separator) {
	separator = t_separator;
	data.clear();
	std::ifstream f;
	f.open(file);
	if (!f.is_open())
		return 1;
	int temp = parse(f);
	f.close();
	return temp;
}

bool CSVparseKey::writeFile(char* file, parseSeparator t_separator) {
	if (data.size() == 0)
		return false;
	size_t t = data[0].second.size();
	size_t i;
	for (i = 1; i < data.size(); i++) {
		if (data[i].second.size() != t)
			return false;
	}
	std::ofstream f;
	f.open(file, std::ofstream::out);
	if (!f.is_open())
		return false;
	for (i = 0; i < data.size()-1; i++) {
		f << prepareToWrite(data[i].first, t_separator) << (char)separator;
	}
	f << prepareToWrite(data[i].first, t_separator) << std::endl;
	size_t j;
	for (i = 0; i < data[0].second.size(); i++) {
		for (j = 0; j < data.size()-1; j++) {
			f << prepareToWrite(data[j].second[i], t_separator) << (char)separator;
		}
		f << prepareToWrite(data[j].second[i], t_separator) << std::endl;
	}
	f.close();
	return true;
}

void CSVparseKey::clear() {
	data.clear();
}

int CSVparseLin::parse(std::ifstream& f) {
	std::vector<std::string> in;
	size_t line = 1;
	readLine(f, &in);
	data.reserve(in.size());
	for (size_t i = 0; i < in.size(); i++) {
		data.emplace_back(std::vector<std::string>());
	}
	insertRow(in);
	size_t line_size = in.size();
	while (!f.eof()) {
		line++;
		readLine(f, &in);
		if (line_size != in.size() && in.size()>0) {
			return (int)(line_size + 1);
		}
		insertRow(in);
	}
	return 0;
}

void CSVparseLin::insertRow(std::vector<std::string>& t_data) {
	if (t_data.size() != data.capacity())
		return;
	for (size_t i = 0; i < t_data.size(); i++) {
		data[i].push_back(t_data[i]);
	}
}

void CSVparseLin::insertColumn(std::vector<std::string>& t_data) {
	//TODO:
}

int CSVparseLin::readFile(char* file, parseSeparator t_separator) {
	separator = t_separator;
	data.clear();
	std::ifstream f;
	f.open(file, std::ofstream::out);
	if (!f.is_open())
		return 1;
	int temp = parse(f);
	f.close();
	return temp;
}

bool CSVparseLin::writeFile(char* file, parseSeparator t_separator) {
	if (data.size() == 0)
		return false;
	size_t t = data[0].size();
	for (size_t i = 1; i < data.size(); i++) {
		if (data[i].size() != t)
			return false;
	}
	std::ofstream f;
	f.open(file);
	if (!f.is_open())
		return false;
	size_t j;
	for (size_t i = 0; i < data[0].size(); i++) {
		for (j = 0; j < data.size()-1; j++) {
			f << prepareToWrite(data[j][i], t_separator) << (char)separator;
		}
		f << prepareToWrite(data[j][i], t_separator) << std::endl;
	}
	f.close();
	return true;
}

void CSVparseLin::clear() {
	data.clear();
}