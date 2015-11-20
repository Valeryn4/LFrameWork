#include "LObject.h"
#if _DEBUG
void Ldebug(std::string s) {
	std::cout << s << std::endl;
}
#endif


int LObject::global_ID = 0;

LObject::LObject(LObject * par)
{
	global_ID++;
	ID = global_ID;

	if (par == NULL) {
		exist_parent = false;
		LDebug("create process ID = " + std::to_string(ID));
	}
	else {
		exist_parent = true;
		parent = par;
		parent->push_child(this);
		LDebug("create process ID = " + std::to_string(ID) + " parent ID: " + std::to_string(parent->get_ID()));
	}	
}



LObject::~LObject()
{
	size_t size = childs.size();
	for (int i = 0; i < size; i++ )
	{
		childs[i]->set_dead();
		delete childs[i];
	}
	childs.clear();
	if (exist_parent == true)
		parent->del_child(ID);

	LDebug("delete process ID = " + std::to_string(ID));
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
	/*size_t size = childs.size();
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
	}*/
	
	for (int i = 0; i < childs.size(); i++) {
		if (ID == childs[i]->get_ID()) {
			childs.erase(childs.begin() + i);
			break;
		}

	
}

void LObject::push_child(LObject * child)
{
	childs.push_back(child);
}
