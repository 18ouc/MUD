#ifndef _PLOT_H
#define _PLOT_H
#include <iostream>
#include <string>
#include "sorcerer.h"
#include "map.h"
#include "Skill.h"
#include "badPerson.h"
#include "room.h"
#include "goodPerson.h"
#include "Medicine.h"
#include "Shop.h"
#include "Magicitem.h"
using namespace std;
class Plot {
public:
	Plot();
	int init1(Sorcerer *mySorcerer, int myCheckPoint = 0, bool ifNew = 0);	//代表剧情1即第一关
	int init2(Sorcerer *mySorcerer, int myCheckPoint = 0, bool ifNew = 0);
	int init3(Sorcerer *mySorcerer, int myCheckPoint = 0, bool ifNew = 0);
	int init4(Sorcerer *mySorcerer, int myCheckPoint = 0, bool ifNew = 0);
	int init5(Sorcerer *mySorcerer, int myCheckPoint = 0, bool ifNew = 0);
	int init6(Sorcerer *mySorcerer, int myCheckPoint = 0, bool ifNew = 0);
	int initFinal(Sorcerer *mySorcerer, int myCheckPoint = 0, bool ifNew = 0);
	void init_new(Sorcerer *mySorcerer);
	~Plot();
private:
	int id;
};
#endif

