#pragma once
#include "LObject.h"
#include <string>
#include <list>
#include <algorithm>
#include <iostream>


#ifdef _WIN32
#define CORE_DIR_ "C:/"

#include <Windows.h>
#include <ShlObj.h>
#include <cstdio>  //reame

#elif __linux 
#define CORE_DIR_ "/"

#else
#define CORE_DIR_ "/"

#endif


class LDir :
	public LObject
{
private:
	std::string dir_path;
public:
	explicit LDir(LObject * par = NULL);
	explicit LDir(char * path_dir, LObject * par = NULL);
	explicit LDir(std::string path_dir, LObject * par = NULL);

	std::string get_path();
	bool set_path(std::string path);
	bool cd(std::string path);

	std::string get_dir_name();
	std::string get_dir_name(std::string path);
	std::string get_currect_path();
	std::string get_home_path();
	bool rename_dir(std::string old_name, std::string new_name);

	bool exist(std::string path);
	bool mkdir(std::string name);
	bool mkpath(std::string name);

	std::list<std::string> get_ls(std::string path = "-1");

};

