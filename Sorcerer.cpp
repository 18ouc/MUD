#include "sorcerer.h"
#include <regex>
#include <sstream>
#include <algorithm> 
Sorcerer::Sorcerer(){
	//cout << "���ﴴ���ɹ���" << endl;
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
	cout << "����" << name << "���óɹ���" << endl;
	cout << "����ѡ��������ʼ�������£�" << endl;
	cout << "αװֵ = " << disguiseValue << endl;
	cout << "����ֵ = " << forceValue << endl;
	cout << "����ֵ = " << defenceValue << endl;
	cout << "ħ��ֵ = " << disguiseValue << endl;
	cout << "αװֵ = " << magicValue << endl;
	cout << "Ѫ��   = " << bloodValue << endl;
	cout << "���   = " << money << endl;
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
	cout << "���Ѫ��������" << blood << endl;
}

void Sorcerer::decreaseBlood(int blood) {
	bloodValue -= blood;
	cout << "���Ѫ��������" << blood << endl;
}

void Sorcerer::setBlood(int blood) {
	this->bloodValue = blood;
}

void Sorcerer::addSkill(Skill mySkill) {
	cout << "��ϲ����ü��ܣ�" << mySkill.getName() << endl;
	skill.push_back(mySkill);
	this->increaseSkillNum();
}

void Sorcerer::increaseSkillNum() {
	skillNum++;
}

void Sorcerer::showInformation() {
	cout << "��ǰ��������������£�" << endl;
	cout << "αװֵ = " << disguiseValue << endl;
	cout << "����ֵ = " << forceValue << endl;
	cout << "����ֵ = " << defenceValue << endl;
	cout << "ħ��ֵ = " << disguiseValue << endl;
	cout << "αװֵ = " << magicValue << endl;
	cout << "Ѫ��   = " << bloodValue << endl;
	cout << "���   = " << money << endl;
}

bool Sorcerer::battle(Sorcerer * mySorcerer, BadPerson badperson) {
	double otherBloodNum = badperson.getblood();
	int otherDamageNum_Down = badperson.getDown();
	int otherDamageNum_Up = badperson.getUp();
	string otherName = badperson.getName();
	double mySorcererDamage = 0;
	double otherSorcererDamage = 0;
	double mySorcererBlood = mySorcerer->getBloodValue();
	int ii = 1;//����ս�����ִ���
	srand(time(NULL));
	while (1) {
		system("pause");
		system("cls");
		if (mySorcerer->isSkillEmpty())
			cout << "��Ŀǰû���κμ���" << endl;
		else {
			cout << "��Ŀǰӵ�еļ��ܣ�" << endl;
			for (int i = 1; i <= mySorcerer->getSkillNum(); i++) {
				cout << i << "." << mySorcerer->getSkill()[i - 1].getName() << endl;
			}
		}
		cout << "��" << ii << "��ս��" << endl;
		cout << "��ʱ����Ѫ��Ϊ" << mySorcererBlood << endl;
		cout << otherName << "��Ѫ��Ϊ" << otherBloodNum << endl;
		cout << "����������ʹ�ü��ܣ�����0����ʹ����ͨ����" << endl;
		std::regex rx("[0-9]+");
		cout << "����������Ҫʹ�ü��ܵı�ţ���0�˳���" << endl;
		string op;
		cin >> op;
		bool ifNum = std::regex_match(op.begin(), op.end(), rx);
		if (!ifNum) {
			cout << "������Ĳ������֣����������룡" << endl;
			system("pause");
			system("cls");
			continue;
		}
		int op_num = 0;
		stringstream s_temp;//�ַ�������ת��
		s_temp << op;
		s_temp >> op_num;
		double damage = 0;
		if (!(op_num < mySorcerer->getSkill().size() + 1 && op_num > -1)) {
			cout << "û�и�ѡ����������룡" << endl;
			continue;
		}
		system("cls");
		if (op_num) {
			double skillDamage = mySorcerer->getSkill()[op_num - 1].getDamage();
			cout << "���ڵ�" << ii << "��ս����ʹ����" << mySorcerer->getSkill()[op_num - 1].getName() << ",";
			damage = mySorcerer->getForceValue() + skillDamage - 100 + rand() % 5;
		}
		else if (!op_num) {
			cout << "���ڵ�" << ii << "��ս����ʹ������ͨ����" << ",";
			damage = mySorcerer->getForceValue() - 100 + rand() % 5;
		}
		cout << "�Զ��������" << damage << "�˺���" << endl;
		double damage_other = (rand() % (otherDamageNum_Up - otherDamageNum_Down + 1)) + otherDamageNum_Down;
		cout << otherName << "�ڵ�" << ii << "��ս���ж������" << damage_other << "�˺�" << endl;
		mySorcererBlood -= damage_other;
		otherBloodNum -= damage;
		if (mySorcererBlood < 0)
			mySorcererBlood = 0;
		if (otherBloodNum < 0)
			otherBloodNum = 0;
		cout << "��" << ii << "��ս������\n" <<
			"����Ѫ��Ϊ" << mySorcererBlood << endl;
		cout << otherName << "��Ѫ��Ϊ" << otherBloodNum << endl;
		ii++;
		if (mySorcererBlood == 0) {
			if (otherBloodNum == 0) {
				cout << "˫��ͬ���ھ���" << endl;
			}
			cout << "���ź������ı���ս��ʧ�ܡ�����" << endl;
			return 0;
		}
		else if (otherSorcererDamage >= otherBloodNum) {
			mySorcerer->setBlood(mySorcererBlood);
			cout << "��ϲ�㣬���ɹ������" << otherName << "!!!" << endl;
			return 1;
		}
	}
}

void Sorcerer::inRoom(Room * myroom) {
	this->myroom = myroom;
}

void Sorcerer::increaseMoney(int money) {
	this->money += money;
	cout << "��Ľ������" << money << endl;
}

void Sorcerer::decreaseMoney(int money) {
	this->money -= money;
	cout << "��Ľ�Ҽ���" << money << endl;
}

void Sorcerer::addMedicine(Medicine temp) {
	medicine.push_back(temp);
	cout << "��ϲ�����ˣ�" << temp.getName() << endl;
}

void Sorcerer::showMedicine() {
	if (medicine.empty()) {
		cout << "��Ŀǰû���κ�ҩˮ" << endl;
	}
	else {
		//���ջָ�ֵ��С��������
		//lambda
		sort(medicine.begin(), medicine.end(), [](Medicine a, Medicine b) -> bool { return a.getRecoverValue() < b.getRecoverValue(); });   // Lambda���ʽ
		cout << "��Ŀǰӵ�е�ҩˮ��" << endl;
		int i = 0;
		for (auto temp : medicine) {
			cout << ++i << ".���ƣ�" << temp.getName() << " �۸�" << temp.getPrice() << " �ָ�ֵ��" << temp.getRecoverValue() << endl;
		}
	}
	std::regex rx("[0-9]+");
	cout << "����������Ҫʹ��ҩƷ�ı�ţ���0�˳���" << endl;
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
			cout << "�鿴����" << endl;
		}
		else if (!(op_num < medicine.size() + 1 && op_num > 0)) {
			cout << "û�и�ѡ�����������!" << endl;
		}
		else {
			useMedicine(op_num);
		}
	}


}

void Sorcerer::addMagicitem(Magicitem temp) {
	magicitem.push_back(temp);
	cout << "��ϲ�����ˣ�" << temp.getName() << endl;
	magicitemNum = magicitem.size();
}

void Sorcerer::addHorcrux(Horcrux temp) {
	horcrux.push_back(temp);
	cout << "��ϲ�����ˣ�" << temp.getName() << endl;
	horcruxNum = horcrux.size();
}

void Sorcerer::showMagicItem() {
	if (magicitem.empty()) {
		cout << "��Ŀǰû���κ�ħ������" << endl;
	}
	else {
		cout << "��Ŀǰӵ�еĵ��ߣ�" << endl;
		for (int i = 0; i < magicitem.size(); i++) {
			cout << i + 1 << ".����:" << magicitem[i].getName() << endl;
		}
	}
}

void Sorcerer::showSkill() {
	if (skill.empty()) {
		cout << "��Ŀǰû���κμ���" << endl;
	}
	else {
		cout << "��Ŀǰӵ�еļ��ܣ�" << endl;
		for (int i = 0; i < skill.size(); i++) {
			cout << i + 1 << ".���ƣ�" << skill[i].getName() <<" �˺���" << skill[i].getDamage() << endl;
		}
	}
}

void Sorcerer::showHorcrux() {
	if (horcrux.empty()) {
		cout << "��Ŀǰû���κλ���" << endl;
	}
	else {
		cout << "��Ŀǰӵ�еĻ�����" << endl;
		for (int i = 0; i < horcrux.size(); i++) {
			cout << i + 1 << ".���ƣ�" << horcrux[i].getName() << endl;
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
	cout << "��ʹ����" << medicine[op - 1].getName() << ",Ѫ��������" << medicine[op - 1].getRecoverValue() << endl;
	this->increaseBlood(medicine[op - 1].getRecoverValue());
	medicine.erase(it);
	this->changeMedicineNum();
}

void Sorcerer::setMyCheckPoint(int temp) {
	myCheckpoint = temp;
}

void Sorcerer::afterDead() {
	cout << "���������Ϸ��������ϵͳ������һЩ�ػ������������Ǽ���ս���ɣ�" << endl;
	this->setBlood(1);
	cout << "ϵͳ������һ��Ѫ��" << endl;
	Medicine temp("�ػ�ҩˮ", 25, 0);
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