#include "LObject.h"
#include <iostream>

int LObject::global_ID = 0;

LObject::LObject(LObject * par)
{
	global_ID++;
	ID = global_ID;

	if (par == NULL) {
		exist_parent = false;
		//std::cout << "create process ID = " << ID << std::endl;
	}
	else {
		exist_parent = true;
		parent = par;
		parent->push_child(this);
		//std::cout << "create process ID = " << ID << "; parrent ID = " << parent->get_ID() << std::endl;
	}	
}



LObject::~LObject()
{
	int size = childs.size();
	for (int i = 0; i < size; i++ )
	{
		childs[i]->set_dead();
		delete childs[i];
	}
	childs.clear();
	if (exist_parent == true)
		parent->del_child(ID);

	std::cout << "delete ID = " << ID << " \n";
}

void LObject::set_dead()
{
	exist_parent = false;
}

int LObject::get_ID()
{
	return ID;
}

void LObject::del_child(int ID)
{
	int size = childs.size();
	for (int i = 0; i < childs.size(); i++) {
		if (ID == childs[i]->get_ID()) {
			if (i == 0) {
				childs.erase(childs.begin());
				i--;
			}
			else {
				childs.erase(childs.begin() + i);
			}
		}
	}

	
}

void LObject::push_child(LObject * child)
{
	childs.push_back(child);
}
