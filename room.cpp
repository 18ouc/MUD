#include "room.h"

string Room::getName() {
	return name;
}

void Room::addGoodPerson(GoodPerson temp) {
	goodperson.push_back(temp);
}

void Room::addBadPerson(BadPerson temp) {
	badperson.push_back(temp);
	badPersonNum++;
}

void Room::inRoom() {
	ifIn = 1;
}

bool Room::getIfIn() {
	return ifIn;
}

void Room::showBadPerson() {
	cout << "该房间中坏人的情况为：" << endl;
	if (badperson.size() == 0) {
		cout << "该房间的无坏人" << endl;
	}
	else {
		for (int i = 0; i < badperson.size(); i++) {
			cout << i + 1 << ".名称:" << badperson[i].getName() << " 难度值:" << badperson[i].getDown() + badperson[i].getUp() << " 生命值：" << badperson[i].getblood() << endl;
		}
	}
}

void Room::eraseBadPerson(int id)
{
	vector<BadPerson>::iterator it;
	it = badperson.begin() + id - 1;
	cout << "您击败了" << badperson[id - 1].getName()  << endl;
	badperson.erase(it);
}

BadPerson Room::getBadPersonSpecial(int id) {
	return badperson[id - 1];
}

vector<BadPerson> Room::getBadPerson() {
	return badperson;
}

int Room::getBadPersonSize() {
	return badperson.size();
}

void Room::setIfIn(bool temp) {
	ifIn = temp;
}



Room::~Room() {
}