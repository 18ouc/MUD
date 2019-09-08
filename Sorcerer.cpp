#include "sorcerer.h"
#include <regex>
#include <sstream>
#include <algorithm> 
Sorcerer::Sorcerer(){
	//cout << "人物创建成功！" << endl;
	skillNum = 0;
	equipmentNum = 0;
	horcruxNum = 0;
	magicitemNum = 0;
	myCheckpoint = 0;
}

Sorcerer::~Sorcerer() {
}

void Sorcerer::setValue(double disguiseValue, double forceValue, double defenceValue, double magicValue, double bloodValue, string name, double money) {
	this->disguiseValue = disguiseValue;
	this->forceValue = forceValue;
	this->defenceValue = defenceValue;
	this->magicValue = magicValue;
	this->bloodValue = bloodValue;
	this->name = name;
	this->money = money;
	cout << "人物" << name << "设置成功！" << endl;
	cout << "你所选择的人物初始属性如下：" << endl;
	cout << "伪装值 = " << disguiseValue << endl;
	cout << "武力值 = " << forceValue << endl;
	cout << "防御值 = " << defenceValue << endl;
	cout << "魔法值 = " << disguiseValue << endl;
	cout << "伪装值 = " << magicValue << endl;
	cout << "血量   = " << bloodValue << endl;
	cout << "金币   = " << money << endl;
}

bool Sorcerer::isSkillEmpty() {
	if (skill.empty())
		return 1;
	else return 0;
}

int Sorcerer::getSkillNum() {
	return skillNum;
}

int Sorcerer::getEquipmentNum() {
	return equipmentNum;
}

int Sorcerer::getHorcruxNum() {
	return horcruxNum;
}

int Sorcerer::getMyCheckpoint() {
	return myCheckpoint;
}

int Sorcerer::getMedicineNum() {
	return medicineNum;
}

void Sorcerer::changeMedicineNum() {
	medicineNum = medicine.size();
}


vector<Skill> Sorcerer::getSkill() {
	return skill;
}

vector<Horcrux> Sorcerer::getHorcrux() {
	return horcrux;
}

vector<Medicine> Sorcerer::getMedicine() {
	return medicine;
}

int Sorcerer::getMagicitemNum() {
	return magicitemNum;
}

int Sorcerer::getBloodValue() {
	return bloodValue;
}

int Sorcerer::getForceValue() {
	return forceValue;
}

int Sorcerer::getDefenceValue() {
	return defenceValue;
}

int Sorcerer::getMagicValue() {
	return magicValue;
}

int Sorcerer::getMoney() {
	return money;
}

void Sorcerer::increaseBlood(int blood) {
	bloodValue += blood;
	cout << "你的血量增加了" << blood << endl;
}

void Sorcerer::decreaseBlood(int blood) {
	bloodValue -= blood;
	cout << "你的血量减少了" << blood << endl;
}

void Sorcerer::setBlood(int blood) {
	this->bloodValue = blood;
}

void Sorcerer::addSkill(Skill mySkill) {
	cout << "恭喜您获得技能：" << mySkill.getName() << endl;
	skill.push_back(mySkill);
	this->increaseSkillNum();
}

void Sorcerer::increaseSkillNum() {
	skillNum++;
}

void Sorcerer::showInformation() {
	cout << "当前您的属性情况如下：" << endl;
	cout << "伪装值 = " << disguiseValue << endl;
	cout << "武力值 = " << forceValue << endl;
	cout << "防御值 = " << defenceValue << endl;
	cout << "魔法值 = " << disguiseValue << endl;
	cout << "伪装值 = " << magicValue << endl;
	cout << "血量   = " << bloodValue << endl;
	cout << "金币   = " << money << endl;
}

bool Sorcerer::battle(Sorcerer * mySorcerer, BadPerson badperson) {
	double otherBloodNum = badperson.getblood();
	int otherDamageNum_Down = badperson.getDown();
	int otherDamageNum_Up = badperson.getUp();
	string otherName = badperson.getName();
	double mySorcererDamage = 0;
	double otherSorcererDamage = 0;
	double mySorcererBlood = mySorcerer->getBloodValue();
	int ii = 1;//代表战斗的轮次数
	srand(time(NULL));
	while (1) {
		system("pause");
		system("cls");
		if (mySorcerer->isSkillEmpty())
			cout << "您目前没有任何技能" << endl;
		else {
			cout << "您目前拥有的技能：" << endl;
			for (int i = 1; i <= mySorcerer->getSkillNum(); i++) {
				cout << i << "." << mySorcerer->getSkill()[i - 1].getName() << endl;
			}
		}
		cout << "第" << ii << "轮战斗" << endl;
		cout << "此时您的血量为" << mySorcererBlood << endl;
		cout << otherName << "的血量为" << otherBloodNum << endl;
		cout << "请输入数字使用技能，输入0代表使用普通攻击" << endl;
		std::regex rx("[0-9]+");
		cout << "请输入你想要使用技能的编号（按0退出）" << endl;
		string op;
		cin >> op;
		bool ifNum = std::regex_match(op.begin(), op.end(), rx);
		if (!ifNum) {
			cout << "你输入的不是数字！请重新输入！" << endl;
			system("pause");
			system("cls");
			continue;
		}
		int op_num = 0;
		stringstream s_temp;//字符和数字转化
		s_temp << op;
		s_temp >> op_num;
		double damage = 0;
		if (!(op_num < mySorcerer->getSkill().size() + 1 && op_num > -1)) {
			cout << "没有该选项！请重新输入！" << endl;
			continue;
		}
		system("cls");
		if (op_num) {
			double skillDamage = mySorcerer->getSkill()[op_num - 1].getDamage();
			cout << "您在第" << ii << "轮战斗中使用了" << mySorcerer->getSkill()[op_num - 1].getName() << ",";
			damage = mySorcerer->getForceValue() + skillDamage - 100 + rand() % 5;
		}
		else if (!op_num) {
			cout << "您在第" << ii << "轮战斗中使用了普通攻击" << ",";
			damage = mySorcerer->getForceValue() - 100 + rand() % 5;
		}
		cout << "对对手造成了" << damage << "伤害。" << endl;
		double damage_other = (rand() % (otherDamageNum_Up - otherDamageNum_Down + 1)) + otherDamageNum_Down;
		cout << otherName << "在第" << ii << "轮战斗中对您造成" << damage_other << "伤害" << endl;
		mySorcererBlood -= damage_other;
		otherBloodNum -= damage;
		if (mySorcererBlood < 0)
			mySorcererBlood = 0;
		if (otherBloodNum < 0)
			otherBloodNum = 0;
		cout << "第" << ii << "轮战斗结束\n" <<
			"您的血量为" << mySorcererBlood << endl;
		cout << otherName << "的血量为" << otherBloodNum << endl;
		ii++;
		if (mySorcererBlood == 0) {
			if (otherBloodNum == 0) {
				cout << "双方同归于尽。" << endl;
			}
			cout << "很遗憾，您的本场战斗失败。。。" << endl;
			return 0;
		}
		else if (otherSorcererDamage >= otherBloodNum) {
			mySorcerer->setBlood(mySorcererBlood);
			cout << "恭喜你，您成功打败了" << otherName << "!!!" << endl;
			return 1;
		}
	}
}

void Sorcerer::inRoom(Room * myroom) {
	this->myroom = myroom;
}

void Sorcerer::increaseMoney(int money) {
	this->money += money;
	cout << "你的金币增加" << money << endl;
}

void Sorcerer::decreaseMoney(int money) {
	this->money -= money;
	cout << "你的金币减少" << money << endl;
}

void Sorcerer::addMedicine(Medicine temp) {
	medicine.push_back(temp);
	cout << "恭喜你获得了：" << temp.getName() << endl;
}

void Sorcerer::showMedicine() {
	if (medicine.empty()) {
		cout << "你目前没有任何药水" << endl;
	}
	else {
		//按照恢复值从小到大排序
		//lambda
		sort(medicine.begin(), medicine.end(), [](Medicine a, Medicine b) -> bool { return a.getRecoverValue() < b.getRecoverValue(); });   // Lambda表达式
		cout << "你目前拥有的药水：" << endl;
		int i = 0;
		for (auto temp : medicine) {
			cout << ++i << ".名称：" << temp.getName() << " 价格：" << temp.getPrice() << " 恢复值：" << temp.getRecoverValue() << endl;
		}
	}
	std::regex rx("[0-9]+");
	cout << "请输入你想要使用药品的编号（按0退出）" << endl;
	string op;
	cin >> op;
	bool ifNum = std::regex_match(op.begin(), op.end(), rx);
	if (!ifNum) {
		cout << "你输入的不是数字！" << endl;
		system("pause");
		system("cls");
	}
	else {
		int op_num = 0;
		stringstream s_temp;//字符和数字转化
		s_temp << op;
		s_temp >> op_num;
		if (op_num == 0) {
			cout << "查看结束" << endl;
		}
		else if (!(op_num < medicine.size() + 1 && op_num > 0)) {
			cout << "没有该选项！请重新输入!" << endl;
		}
		else {
			useMedicine(op_num);
		}
	}


}

void Sorcerer::addMagicitem(Magicitem temp) {
	magicitem.push_back(temp);
	cout << "恭喜你获得了：" << temp.getName() << endl;
	magicitemNum = magicitem.size();
}

void Sorcerer::addHorcrux(Horcrux temp) {
	horcrux.push_back(temp);
	cout << "恭喜你获得了：" << temp.getName() << endl;
	horcruxNum = horcrux.size();
}

void Sorcerer::showMagicItem() {
	if (magicitem.empty()) {
		cout << "你目前没有任何魔法道具" << endl;
	}
	else {
		cout << "你目前拥有的道具：" << endl;
		for (int i = 0; i < magicitem.size(); i++) {
			cout << i + 1 << ".名称:" << magicitem[i].getName() << endl;
		}
	}
}

void Sorcerer::showSkill() {
	if (skill.empty()) {
		cout << "你目前没有任何技能" << endl;
	}
	else {
		cout << "你目前拥有的技能：" << endl;
		for (int i = 0; i < skill.size(); i++) {
			cout << i + 1 << ".名称：" << skill[i].getName() <<" 伤害：" << skill[i].getDamage() << endl;
		}
	}
}

void Sorcerer::showHorcrux() {
	if (horcrux.empty()) {
		cout << "你目前没有任何魂器" << endl;
	}
	else {
		cout << "你目前拥有的魂器：" << endl;
		for (int i = 0; i < horcrux.size(); i++) {
			cout << i + 1 << ".名称：" << horcrux[i].getName() << endl;
		}
	}
}

bool Sorcerer::isHasTheMagicitem(int id) {
	bool temp = 0;
	int low = 0;
	int high = magicitem.size() - 1;
	while (low <= high) {
		int middle = (low + high) / 2;
		if (id == magicitem[middle].getId()){
			temp = 1;
			break;
		}
		else if (id > magicitem[middle].getId()) {
			low = middle + 1;
		}
		else if (id < magicitem[middle].getId()) {
			high = middle - 1;
		}
	}
	//bool temp = 0;
	//for (int i = 0; i < magicitem.size(); ++i) {
	//	if (id == magicitem[i].getId())
	//		temp = 1;
	//}
	return temp;
}

void Sorcerer::useMedicine(int op) {
	vector<Medicine>::iterator it;
	it = medicine.begin() + op - 1;
	cout << "您使用了" << medicine[op - 1].getName() << ",血量增加了" << medicine[op - 1].getRecoverValue() << endl;
	this->increaseBlood(medicine[op - 1].getRecoverValue());
	medicine.erase(it);
	this->changeMedicineNum();
}

void Sorcerer::setMyCheckPoint(int temp) {
	myCheckpoint = temp;
}

void Sorcerer::afterDead() {
	cout << "由于你的游戏中死亡，系统给了你一些关怀，请拿着他们继续战斗吧！" << endl;
	this->setBlood(1);
	cout << "系统给了你一点血量" << endl;
	Medicine temp("关怀药水", 25, 0);
	this->addMedicine(temp);
	this->increaseMoney(1500);
}

int Sorcerer::getDisguiseValue() {
	return disguiseValue;
}

Room * Sorcerer::getRoom() {
	return myroom;
}

string Sorcerer::getName() {
	return name;
}

vector<Magicitem> Sorcerer::getMagicitem() {
	return magicitem;
}