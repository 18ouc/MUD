#ifndef _SKILL_H
#define _SKILL_H
#include <iostream>
#include <string>
using namespace std;
class Skill {
public:
	Skill(string name = 0, int damage = 0, int price = 0);	//���캯����ʼ������
	~Skill();
	//Get����
	string getName();
	int getDamage();
	int getPrice();
	//Set����
	void setValue(string name = 0, int damage = 0, int price = 0);
private:
	string name;
	int damage;
	int price;
};

#endif