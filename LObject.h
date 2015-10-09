#pragma once
#include <vector>
#include <memory>


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

