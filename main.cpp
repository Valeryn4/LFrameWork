
#include "LObject.h"
#include "LDir.h"
#include <iostream>
int main() {

	LObject * o1 = new LObject;
	LDir * dir = new LDir(o1);
	
	dir->set_path("C:/SQL");
	std::cout << dir->get_path() << std::endl;

	dir->cd("..");
	std::cout << dir->get_path() << std::endl;

	dir->cd("Users");
	std::cout << dir->get_path() << std::endl;

	dir->cd("..");
	std::cout << dir->get_path() << std::endl;

	dir->cd("SQL");
	std::cout << dir->get_path() << std::endl;

	dir->mkdir("testdir");
	std::cout << dir->get_path() << std::endl;

	dir->mkpath("C:/SQL/Test1/test2/test3");
	std::cout << dir->get_path() << std::endl;

	dir->exist("C:/Windows");
	
	delete o1;

	return 0;
}