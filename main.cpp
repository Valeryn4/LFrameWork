
#include "LObject.h"
#include "LDir.h"
#include <iostream>
int main() {

	LObject * o1 = new LObject;
	LDir * dir = new LDir(o1);
	
	dir->set_path("C:/Qt");
	std::cout << dir->get_path() << std::endl;

	dir->cd("..");
	std::cout << dir->get_path() << std::endl;

	dir->cd("Users");
	std::cout << dir->get_path() << std::endl;

	dir->exist("C:/Windows");
	
	delete o1;

	return 0;
}