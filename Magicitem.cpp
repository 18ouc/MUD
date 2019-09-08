#include "Magicitem.h"

Magicitem::Magicitem(string name,int id) : name(name), id(id) {
}


Magicitem::~Magicitem() {
}

string Magicitem::getName() {
	return name;
}

int Magicitem::getId() {
	return id;
}

void Magicitem::setValue(string name, int id) {
	this->name = name;
	this->id = id;
}