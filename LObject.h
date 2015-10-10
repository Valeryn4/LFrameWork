#pragma once
#include <vector>
#include <memory>

#if _DEBUG
#include <iostream>
#include <string>
#define LDebug(str) Ldebug(str)
void Ldebug(std::string str);
#else
#define LDebug(str) /*#str*/
#endif


class LObject
{
private:	
	static int global_ID;
	int ID;							
	LObject *parent;	
	bool exist_parent;			//used in ~LObhect(); Используется в диструкторе, при уничтожении наследников, что бы наследник не обращался к родителю, который к этому времени может уже само уничтожиться.
	std::vector<LObject *> childs;	
	
public:
	explicit LObject(LObject * par = NULL);
	~LObject();
	void set_dead();			//used in ~LObject(); Вызывается в диструкторе у наследников, во избежания обращения к родителю.
	int get_ID();
	void del_child(int ID);
	void push_child(LObject * child);
	
};

