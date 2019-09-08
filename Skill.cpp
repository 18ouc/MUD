#include "Skill.h"

Skill::Skill(string name, int damage, int price) : name(name), damage(damage), price(price) {
}

Skill::~Skill() {
}

string Skill::getName() {
	return name;
}

int Skill::getDamage() {
	return damage;
}

void Skill::setValue(string name, int damage, int price) {
	this->name = name;
	this->damage = damage;
	this->price = price;
}

int Skill::getPrice() {
	return price;
}

