#ifndef _SORCERER_H
#define _SORCERER_H
#include <vector>
#include <string>
#include "Equipment.h"
#include "Horcrux.h"
#include <iostream>
#include "Skill.h"
#include "Person.h"
#include "badPerson.h"
#include <cstdlib>
#include <ctime>
#include "room.h"
#include "Medicine.h"
#include "Magicitem.h"
using namespace std;

class Sorcerer : public Person {
public:
	Sorcerer();	//构造函数设置初始值
	~Sorcerer();
	//判断类函数
	bool isSkillEmpty();
	bool isHasTheMagicitem(int id);
	//游戏过程之中对各种值进行改变后使用
	//修改值类函数
	void setValue(double disguiseValue = 0, double forceValue = 0, double defenceValue = 0, double magicValue = 0, double bloodValue = 0, string name = 0, double money = 0);
		//修改血量
	void increaseBlood(int blood);
	void decreaseBlood(int blood);
	void setBlood(int blood);
		//修改技能
	void addSkill(Skill s);
	void increaseSkillNum();
		//修改金币
	void increaseMoney(int money);
	void decreaseMoney(int money);
		//修改药品
	void addMedicine(Medicine temp);
	void useMedicine(int op = 0);	//使用药品
	void changeMedicineNum();
		//修改魔法用品
	void addMagicitem(Magicitem temp);
		//修改魂器
	void addHorcrux(Horcrux temp);
		//修改目前所在关卡
	void setMyCheckPoint(int temp = 0);
	//展示信息类函数
	void showInformation();
	void showMedicine();
	void showMagicItem();
	void showSkill();
	void showHorcrux();
	//战斗系统函数
	bool battle(Sorcerer *mySorcerer, BadPerson badperson);
	//进入房间函数
	void inRoom(Room *myroom);
	//死亡后处理函数
	void afterDead();	//你在游戏中死亡之后，系统给与你的帮助
	//Get方法函数
	int getDisguiseValue();
	int getBloodValue();
	int getForceValue();
	int getDefenceValue();
	int getMagicValue();
	int getMoney();
	Room *getRoom();
	string getName();
	vector<Magicitem> getMagicitem();
	vector<Skill> getSkill();
	vector<Horcrux> getHorcrux();
	vector<Medicine> getMedicine();
	int getMagicitemNum();
	int getSkillNum();
	int getEquipmentNum();
	int getHorcruxNum();
	int getMyCheckpoint();
	int getMedicineNum();
private:
	//基本属性值
	int disguiseValue;	
	int forceValue;
	int defenceValue;
	int magicValue;
	int bloodValue;
	int money;
	string name;
	vector<Magicitem>magicitem;
	vector<Horcrux>horcrux;
	vector<Skill>skill;
	vector<Medicine>medicine;
	Room *myroom;
	int myCheckpoint;
	//一些数量值
	int skillNum;
	int equipmentNum;
	int horcruxNum;
	int magicitemNum;
	int medicineNum;
};
#endif