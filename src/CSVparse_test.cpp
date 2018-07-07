#include "CSVparse.hpp"
#include <string>
#include <iostream>
#include <chrono>

int main() {
	CSVparseKey file1;
	auto start = std::chrono::system_clock::now();
	file1.readFile("example/test1.csv", CSVparse::comma);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "read test1 time : " << elapsed_seconds.count() << std::endl;

	start = std::chrono::system_clock::now();
	file1.writeFile("test1_out.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "write test1 time : " << elapsed_seconds.count() << std::endl;
	
	file1.clear();

	CSVparseLin file2;
	start = std::chrono::system_clock::now();
	file2.readFile("example/test2.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "read test2 time : " << elapsed_seconds.count() << std::endl;

	start = std::chrono::system_clock::now();
	file2.writeFile("test2_out.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "write test2 time : " << elapsed_seconds.count() << std::endl;

	file2.clear();

	CSVparseKey file3;
	start = std::chrono::system_clock::now();
	file3.readFile("example/test3.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "read test3 time : " << elapsed_seconds.count() << std::endl;

	start = std::chrono::system_clock::now();
	file3.writeFile("test3_out.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "write test3 time : " << elapsed_seconds.count() << std::endl;

	file3.clear();

	CSVparseLin file4;
	start = std::chrono::system_clock::now();
	file4.readFile("example/test4.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "read test4 time : " << elapsed_seconds.count() << std::endl;

	start = std::chrono::system_clock::now();
	file4.writeFile("test4_out.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "write test4 time : " << elapsed_seconds.count() << std::endl;

	file4.clear();

	CSVparseLin file5;
	start = std::chrono::system_clock::now();
	file5.readFile("example/test5.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "read test5 time : " << elapsed_seconds.count() << std::endl;

	start = std::chrono::system_clock::now();
	file5.writeFile("test5_out.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "write test5 time : " << elapsed_seconds.count() << std::endl;

	file5.clear();

	CSVparseLin file6;
	start = std::chrono::system_clock::now();
	file6.readFile("example/test6.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "read test6 time : " << elapsed_seconds.count() << std::endl;

	start = std::chrono::system_clock::now();
	file6.writeFile("test6_out.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "write test6 time : " << elapsed_seconds.count() << std::endl;

	file6.clear();

	CSVparseLin file_10_10000;
	start = std::chrono::system_clock::now();
	file_10_10000.readFile("example/test_10x10000.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "read test_10x10000 time : " << elapsed_seconds.count() << std::endl;

	start = std::chrono::system_clock::now();
	file_10_10000.writeFile("test_10x10000_out.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "write test_10x10000 time : " << elapsed_seconds.count() << std::endl;

	file_10_10000.clear();

	CSVparseLin file_100_10000;
	start = std::chrono::system_clock::now();
	file_100_10000.readFile("example/test_100x10000.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "read test_100x10000 time : " << elapsed_seconds.count() << std::endl;

	start = std::chrono::system_clock::now();
	file_100_10000.writeFile("test_100x10000_out.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "write test_100x10000 time : " << elapsed_seconds.count() << std::endl;

	file_100_10000.clear();

	CSVparseLin file_1000_10000;
	start = std::chrono::system_clock::now();
	file_1000_10000.readFile("example/test_1000x10000.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "read test_1000x10000 time : " << elapsed_seconds.count() << std::endl;

	start = std::chrono::system_clock::now();
	file_1000_10000.writeFile("test_1000x10000_out.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "write test_1000x10000 time : " << elapsed_seconds.count() << std::endl;

	file_1000_10000.clear();

	CSVparseLin file_10_1000000;
	start = std::chrono::system_clock::now();
	file_10_1000000.readFile("example/test_10x1000000.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "read test_10x1000000 time : " << elapsed_seconds.count() << std::endl;

	start = std::chrono::system_clock::now();
	file_10_1000000.writeFile("test_10x1000000_out.csv", CSVparse::comma);
	end = std::chrono::system_clock::now();
	elapsed_seconds = end - start;
	std::cout << "write test_10x1000000 time : " << elapsed_seconds.count() << std::endl;

	file_10_1000000.clear();

	std::cin.get();
	return 0;
}