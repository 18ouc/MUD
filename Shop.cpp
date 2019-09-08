#include "Shop.h"
#include <regex>
#include <sstream>
Shop::Shop(vector<Medicine> medicine, vector<Skill> skill, string name, int medicineNumber, int skillNumber) : name(name), medicine(medicine), medicineNumber(medicineNumber), skill(skill), skillNumber(skillNumber) {
}

void Shop::buy(Sorcerer * mysorcerer, int choice) {
	if (choice == 1) {
		std::regex rx("[0-9]+");
		cout << "��������Ҫ�����ҩƿ��ţ�(��0�˳���" << endl;
		string op;
		cin >> op;
		bool ifNum = std::regex_match(op.begin(), op.end(), rx);
		if (!ifNum) {
			cout << "������Ĳ������֣�" << endl;
			system("pause");
			system("cls");
		}
		else {
			int op_num = 0;
			stringstream s_temp;//�ַ�������ת��
			s_temp << op;
			s_temp >> op_num;
			if (op_num == 0) {
				cout << "��ӭ���Ĺ��٣�" << endl;
			}
			else if (!(op_num < medicine.size() + 1 && op_num > 0)) {
				cout << "û�и�ѡ�" << endl;
			}
			else if (mysorcerer->getMoney() < medicine[op_num - 1].getPrice()) {
				cout << "��Ľ�Ҳ��㣡�޷�����" << endl;
			}
			else {
				vector<Medicine>::iterator it;
				it = medicine.begin() + op_num - 1;
				cout << "��������" << medicine[op_num - 1].getName() << ",������" << medicine[op_num - 1].getPrice() << endl;
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
		cout << "��������Ҫ����ļ��ܱ�ţ�(��0�˳���" << endl;
		string op;
		cin >> op;
		bool ifNum = std::regex_match(op.begin(), op.end(), rx);
		if (!ifNum) {
			cout << "������Ĳ������֣�" << endl;
			system("pause");
			system("cls");
		}
		else {
			int op_num = 0;
			stringstream s_temp;//�ַ�������ת��
			s_temp << op;
			s_temp >> op_num;
			if (op_num == 0) {
				cout << "��ӭ���Ĺ��٣�" << endl;
			}
			else if (!(op_num < skill.size() + 1 && op_num > 0)) {
				cout << "û�и�ѡ�" << endl;
			}
			else if (mysorcerer->getMoney() < skill[op_num - 1].getPrice()) {
				cout << "��Ľ�Ҳ��㣡�޷�����" << endl;
			}
			else {
				vector<Skill>::iterator it;
				it = skill.begin() + op_num - 1;
				cout << "��������" << skill[op_num - 1].getName() << ",������" << skill[op_num - 1].getPrice() << endl;
				mysorcerer->decreaseMoney(skill[op_num - 1].getPrice());
				mysorcerer->addSkill(skill[op_num - 1]);
				skill.erase(it);
				skillNumber--;
			}
		}

	}
	else if(choice == 0){
		cout << "��ӭ���Ĺ��٣�" << endl;
	}
	else {
		cout << "�������" << endl;
	}
}

void Shop::showShop(Sorcerer * mysorcerer) {
	cout << "������" << name << "��" << endl;
	cout << "��Ŀǰ�Ľ�ң�" << mysorcerer->getMoney() << "��" << endl;
	cout << "��ӭħ��ʦ" << mysorcerer->getName() << "�����̵꣡����" << endl;
	cout << "Ŀǰ�̵�Ĵ�����:" << endl;
	cout << "ҩˮ��" << endl;
	if (medicine.size() == 0) {
		cout << "�̵�Ŀǰû���κ�ҩˮ......" << endl;
	}
	int i = 0;
	for (auto temp : medicine) {
		cout << ++i << ".���ƣ�" << temp.getName() << " �۸�" << temp.getPrice() << " �ָ�ֵ��" << temp.getRecoverValue() << endl;
	}
	i = 0;
	cout << "���ܣ�" << endl;
	for (auto temp : skill) {
		cout << ++i << ".���ƣ�" << temp.getName() << " �۸�" << temp.getPrice() << " �˺���" << temp.getDamage() << endl;
	}
	if (skill.size() == 0) {
		cout << "�̵�Ŀǰû���κμ���....." << endl;
	}
	int op = 0;
	cout << "���������ѡ��" << endl;
	cout << "1.����ҩˮ		2.������		0.�˳�����" << endl;
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
