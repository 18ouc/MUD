#ifndef _FILE_H
#define _FILE_H
#include "sorcerer.h"
#include <string>
using namespace std;
class File
{
public:
	File(string name = 0);
	void upDate(int id = 0);
	~File();
private:
	string name;
	Sorcerer* mySorcerer;
	//储存每个关卡的数据
};
#endif

