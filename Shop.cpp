#include "Shop.h"
#include <regex>
#include <sstream>
Shop::Shop(vector<Medicine> medicine, vector<Skill> skill, string name, int medicineNumber, int skillNumber) : name(name), medicine(medicine), medicineNumber(medicineNumber), skill(skill), skillNumber(skillNumber) {
}

void Shop::buy(Sorcerer * mysorcerer, int choice) {
	if (choice == 1) {
		std::regex rx("[0-9]+");
		cout << "请输入您要购买的药瓶编号：(按0退出）" << endl;
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
				cout << "欢迎您的光临！" << endl;
			}
			else if (!(op_num < medicine.size() + 1 && op_num > 0)) {
				cout << "没有该选项！" << endl;
			}
			else if (mysorcerer->getMoney() < medicine[op_num - 1].getPrice()) {
				cout << "你的金币不足！无法购买！" << endl;
			}
			else {
				vector<Medicine>::iterator it;
				it = medicine.begin() + op_num - 1;
				cout << "您购买了" << medicine[op_num - 1].getName() << ",花费了" << medicine[op_num - 1].getPrice() << endl;
				mysorcerer->decreaseMoney(medicine[op_num - 1].getPrice());
				mysorcerer->addMedicine(medicine[op_num - 1]);
				mysorcerer->changeMedicineNum();
				medicine.erase(it);
				medicineNumber--;
			}
		}	
	}
	else if (choice == 2) {
		std::regex rx("[0-9]+");
		cout << "请输入您要购买的技能编号：(按0退出）" << endl;
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
				cout << "欢迎您的光临！" << endl;
			}
			else if (!(op_num < skill.size() + 1 && op_num > 0)) {
				cout << "没有该选项！" << endl;
			}
			else if (mysorcerer->getMoney() < skill[op_num - 1].getPrice()) {
				cout << "你的金币不足！无法购买！" << endl;
			}
			else {
				vector<Skill>::iterator it;
				it = skill.begin() + op_num - 1;
				cout << "您购买了" << skill[op_num - 1].getName() << ",花费了" << skill[op_num - 1].getPrice() << endl;
				mysorcerer->decreaseMoney(skill[op_num - 1].getPrice());
				mysorcerer->addSkill(skill[op_num - 1]);
				skill.erase(it);
				skillNumber--;
			}
		}

	}
	else if(choice == 0){
		cout << "欢迎您的光临！" << endl;
	}
	else {
		cout << "输入错误！" << endl;
	}
}

void Shop::showShop(Sorcerer * mysorcerer) {
	cout << "这里是" << name << "。" << endl;
	cout << "你目前的金币：" << mysorcerer->getMoney() << "。" << endl;
	cout << "欢迎魔法师" << mysorcerer->getName() << "进入商店！！！" << endl;
	cout << "目前商店的存货情况:" << endl;
	cout << "药水：" << endl;
	if (medicine.size() == 0) {
		cout << "商店目前没有任何药水......" << endl;
	}
	int i = 0;
	for (auto temp : medicine) {
		cout << ++i << ".名称：" << temp.getName() << " 价格：" << temp.getPrice() << " 恢复值：" << temp.getRecoverValue() << endl;
	}
	i = 0;
	cout << "技能：" << endl;
	for (auto temp : skill) {
		cout << ++i << ".名称：" << temp.getName() << " 价格：" << temp.getPrice() << " 伤害：" << temp.getDamage() << endl;
	}
	if (skill.size() == 0) {
		cout << "商店目前没有任何技能....." << endl;
	}
	int op = 0;
	cout << "请输入你的选择：" << endl;
	cout << "1.购买药水		2.购买技能		0.退出店铺" << endl;
	cin >> op;
	buy(mysorcerer, op);
}

vector<Medicine> Shop::getMedicine() {
	return medicine;
}

vector<Skill> Shop::getSkill()
{
	return skill;
}

int Shop::getMedicineNum() {
	return medicineNumber;
}

int Shop::getSkillNum() {
	return skillNumber;
}

void Shop::setValue(vector<Medicine> medicine, vector<Skill> skill, string name, int medicineNumber, int skillNumber) {
	this->medicine = medicine;
	this->skill = skill;
	this->name = name;
	this->medicineNumber = medicineNumber;
	this->skillNumber = skillNumber;
}
