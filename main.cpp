
#include "LObject.h"
#include "LDir.h"
#include <iostream>
int main() {

	
	LObject * o1 = new LObject;
	LObject * z1 = new LObject(o1);

	LObject * a1 = new LObject(z1);
	LObject * a2 = new LObject(z1);
	LObject * a3 = new LObject(z1);

	LDir * dir = new LDir(a2);

	LObject * c1 = new LObject(a1);
	LObject * c2 = new LObject(a1);
	LObject * c3 = new LObject(a3);

	LObject * d1 = new LObject(c1);
	LObject * d2 = new LObject(c3);
	LObject * d3 = new LObject(dir);

	dir->get_ls();
	dir->get_ls("C:/SQL");
	dir->get_currect_path();
	dir->get_home_path();
	dir->get_dir_name(dir->get_home_path());
	
	
	std::cout << "\n a1 " << a1->get_ID()
		<< "\n a2 " << a2->get_ID()
		<< "\n a3 " << a3->get_ID()
		<< "\n dir " << dir->get_ID()
		<< "\n c1 " << c1->get_ID()
		<< "\n c2 " << c2->get_ID()
		<< "\n c3 " << c3->get_ID()
		<< "\n d1 " << d1->get_ID()
		<< "\n d2 " << d2->get_ID()
		<< "\n d3 " << d3->get_ID() << std::endl;

	delete a3;	//delete 5 -> 9 -> 11

	delete a1;	//delete 3 -> 7 - > 10
				//        \-> 8

	delete o1;	//delete 1 -> 2 -> 4
				//             \-> 6 -> 12

	return 0;
}