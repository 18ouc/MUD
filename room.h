#ifndef _ROOM_H
#define _ROOM_H
#include <string>
#include "badPerson.h"
#include "goodPerson.h"
#include "badPerson.h"
#include <vector>

using namespace std;

class Room {
public:
	Room(string name = 0) : name(name) {
		ifIn = 0;
	}
	string getName();
	void addGoodPerson(GoodPerson temp);
	void addBadPerson(BadPerson temp);
	void inRoom();
	bool getIfIn();
	void showBadPerson();
	void eraseBadPerson(int id);
	BadPerson getBadPersonSpecial(int id);
	vector<BadPerson> getBadPerson();
	int getBadPersonSize();
	void setIfIn(bool temp);
	~Room();
private:
	string name;
	vector<BadPerson> badperson;
	vector<GoodPerson> goodperson;
	bool ifIn;
	int badPersonNum;
};
#endif

