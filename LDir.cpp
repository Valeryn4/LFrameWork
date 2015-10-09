#include "LDir.h"
#include <iostream>
LDir::LDir(LObject * par) : LObject(par)
{

}

LDir::LDir(char * path_dir, LObject * par)
{
	set_path(path_dir);
}

LDir::LDir(std::string path_dir, LObject * par)
{
	set_path(path_dir);
}

std::string LDir::get_path()
{
	if (dir_path.empty())
		return CORE_DIR_;
	return dir_path;
}

bool LDir::set_path(std::string path)
{
	dir_path.clear();
	dir_path.shrink_to_fit();
	dir_path = path;
	if (exist(dir_path))
		return true;
	return false;
}

bool LDir::cd(std::string path)
{
	std::cout << "cd " << path << std::endl;
	if (!exist(dir_path))
		return false;
	if (path == "..") {
		std::string temp = dir_path;
		std::cout << "string '" << temp << "' leght: " << temp.length() << "size:  " << temp.size() << std::endl;
		if (temp.at(temp.length()-1) == '/' || temp.at(temp.length()-1) == '\\')
			temp.pop_back();
		for (int i = temp.length()-1; i > 0; i--) {
			if (temp.at(i) == '/' || temp.at(i) == '\\') {
				temp.pop_back();
				dir_path.clear();
				dir_path = temp;
				dir_path.shrink_to_fit();
				return true;
			}
			temp.pop_back();
		}
		return false;
	}
	if (exist(dir_path + path)) {
		dir_path += path;
		return true;
	}
	else if (exist(dir_path + "/" + path)) {
		dir_path = dir_path + "/" + path;
		return true;
	}
	return false;
}

std::string LDir::get_dir_name()
{
	std::string temp = dir_path;
	if (temp.at(temp.length()-1) == '/' || temp.at(temp.length()-1) == '\\')
		temp.pop_back();
	for (int i = temp.length()-1; i > 0; i--) {
		if (temp.at(i) == '\\' || temp.at(i) == '/') {
			temp.clear();
			temp.shrink_to_fit();
			int length = dir_path.length()-1;
			for (int n = i; n > length; n++) {
				temp.push_back(dir_path.at(n));
			}
			return temp;
		}
		temp.pop_back();
	}
	return "ERROR ERROR ERROR";
}

std::string LDir::get_dir_name(std::string path)
{
	std::string temp = path;
	if (temp.at(temp.length()-1) == '/' || temp.at(temp.length()-1) == '\\')
		temp.pop_back();
	for (int i = temp.length()-1; i > 0; i--) {
		if (temp.at(i) == '\\' || temp.at(i) == '/') {
			temp.clear();
			temp.shrink_to_fit();
			int length = path.length()-1;
			for (int n = i; n > length; n++) {
				temp.push_back(path.at(n));
			}
			return temp;
		}
		temp.pop_back();
	}
	return "ERROR ERROR ERROR";
}

bool LDir::rename_dir(std::string old_name, std::string new_name)
{
	return false;
}

bool LDir::exist(std::string path)
{
	//copy-paste http://stackoverflow.com/questions/8233842/how-to-check-if-directory-exist-using-c-and-winapi
	DWORD ftyp = GetFileAttributesA(path.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
}

bool LDir::mkdir(std::string name)
{
	return false;
}

bool LDir::mkpath(std::string name)
{
	return false;
}
