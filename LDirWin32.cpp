#include "LDir.h"

// windows version
#ifdef _WIN32
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
	/*DWORD ftyp = GetFileAttributesA(path.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
	*/	
	if (path.at(path.length() - 1) == '/' ||
		path.at(path.length() - 1) == '\\')
		path.pop_back();

  	DWORD dwAttrib = GetFileAttributes(path.c_str());

	return	(dwAttrib != INVALID_FILE_ATTRIBUTES && 
         	(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
	
}

bool LDir::mkdir(std::string name)
{
	if (!exist(dir_path))
		return false;
	if (dir_path.at(dir_path.length() - 1) == '/' ||
		dir_path.at(dir_path.length() - 1) == '\\')
		dir_path.pop_back();
	if (name.at(0) == '/' || name.at(0) == '\\') {
		name.clear();
		name = dir_path + name;
	}
	else {
		name.clear();
		name = dir_path + '/' + name;

	}

	name.clear();
	name = dir_path + '/' + name;

	if (CreateDirectory(name.c_str(), NULL) ||
		ERROR_ALREADY_EXISTS == GetLastError())
		return true;
	return false;
}

bool LDir::mkpath(std::string name)
{
	std::string temp_path;
	std::string temp_dir;
		temp_path.clear();
		temp_dir.clear();
	int n = name.length();
	int dir = 0;
	bool temp_exist = false;
	//brain hack
	for (int i = 0; i < n; i++) {
		if (temp_exist == true)
			temp_dir.push_back(name.at(i));
		if (name.at(i) == '/' || name.at(i) == '\\') {
			if (temp_exist == false) {
				dir++;
				temp_exist = true;
			}
			else if (temp_exist == true) {
				if (!exist(temp_path)) {
					if (!mkdir(temp_dir))
						return false;
				}
				temp_dir.clear();
				temp_exist = false;
			}
		}
		temp_path.push_back(name.at(i));
	}
	//end brain hack;

	if (exist(temp_path))
		return true;
	return false;
}

#endif