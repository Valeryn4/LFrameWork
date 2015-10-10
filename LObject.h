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
	bool exist_parent;			//used in ~LObhect(); ������������ � �����������, ��� ����������� �����������, ��� �� ��������� �� ��������� � ��������, ������� � ����� ������� ����� ��� ���� ������������.
	std::vector<LObject *> childs;	
	
public:
	explicit LObject(LObject * par = NULL);
	~LObject();
	void set_dead();			//used in ~LObject(); ���������� � ����������� � �����������, �� ��������� ��������� � ��������.
	int get_ID();
	void del_child(int ID);
	void push_child(LObject * child);
	
};

