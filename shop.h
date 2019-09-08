#ifndef _SHOP_
#define _SHOP_
#include <iostream>
#include <string>
#include "sorcerer.h"
#include "Medicine.h"
#include "Skill.h"
using namespace std;
class Shop {
public:
	//构造函数初始化店铺
	Shop(vector<Medicine> medicine, vector<Skill>skill, string name = 0, int medicineNumber = 0, int skillNumber = 0);
	//用户如果要购买东西会发生的事情
	void buy(Sorcerer * mysorcerer = NULL, int choice = 0);
	void showShop(Sorcerer *mysorcerer);
	vector<Medicine> getMedicine();
	vector<Skill> getSkill();
	int getMedicineNum();
	int getSkillNum();
	void setValue(vector<Medicine> medicine, vector<Skill>skill, string name = 0, int medicineNumber = 0, int skillNumber = 0);
private:
	string name;
	vector<Medicine> medicine;
	vector<Skill> skill;
	int medicineNumber;
	int skillNumber;
};

#endif