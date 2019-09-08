#include "badPerson.h"

BadPerson::BadPerson(double blood, double down, double up, string name) : blood(blood), down(down), up(up), name(name) {
}

BadPerson::~BadPerson() {
}

double BadPerson::getblood() {
	return blood;
}

double BadPerson::getDown() {
	return down;
}

double BadPerson::getUp() {
	return up;
}

string BadPerson::getName() {
	return name;
}

void BadPerson::setValue(double blood, double down, double up, string name) {
	this->blood = blood;
	this->down = down;
	this->up = up;
	this->name = name;
}
