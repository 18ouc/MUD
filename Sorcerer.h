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
	Sorcerer();	//���캯�����ó�ʼֵ
	~Sorcerer();
	//�ж��ຯ��
	bool isSkillEmpty();
	bool isHasTheMagicitem(int id);
	//��Ϸ����֮�жԸ���ֵ���иı��ʹ��
	//�޸�ֵ�ຯ��
	void setValue(double disguiseValue = 0, double forceValue = 0, double defenceValue = 0, double magicValue = 0, double bloodValue = 0, string name = 0, double money = 0);
		//�޸�Ѫ��
	void increaseBlood(int blood);
	void decreaseBlood(int blood);
	void setBlood(int blood);
		//�޸ļ���
	void addSkill(Skill s);
	void increaseSkillNum();
		//�޸Ľ��
	void increaseMoney(int money);
	void decreaseMoney(int money);
		//�޸�ҩƷ
	void addMedicine(Medicine temp);
	void useMedicine(int op = 0);	//ʹ��ҩƷ
	void changeMedicineNum();
		//�޸�ħ����Ʒ
	void addMagicitem(Magicitem temp);
		//�޸Ļ���
	void addHorcrux(Horcrux temp);
		//�޸�Ŀǰ���ڹؿ�
	void setMyCheckPoint(int temp = 0);
	//չʾ��Ϣ�ຯ��
	void showInformation();
	void showMedicine();
	void showMagicItem();
	void showSkill();
	void showHorcrux();
	//ս��ϵͳ����
	bool battle(Sorcerer *mySorcerer, BadPerson badperson);
	//���뷿�亯��
	void inRoom(Room *myroom);
	//����������
	void afterDead();	//������Ϸ������֮��ϵͳ������İ���
	//Get��������
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
	//��������ֵ
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
	//һЩ����ֵ
	int skillNum;
	int equipmentNum;
	int horcruxNum;
	int magicitemNum;
	int medicineNum;
};
#endif