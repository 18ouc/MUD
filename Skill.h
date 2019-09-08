#ifndef _SKILL_H
#define _SKILL_H
#include <iostream>
#include <string>
using namespace std;
class Skill {
public:
	Skill(string name = 0, int damage = 0, int price = 0);	//构造函数初始化技能
	~Skill();
	//Get方法
	string getName();
	int getDamage();
	int getPrice();
	//Set方法
	void setValue(string name = 0, int damage = 0, int price = 0);
private:
	string name;
	int damage;
	int price;
};

#endif