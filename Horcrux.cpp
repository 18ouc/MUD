#include "Horcrux.h"

Horcrux::Horcrux(string name, int id) : name(name), id(id) {
}

Horcrux::~Horcrux() {
}

string Horcrux::getName() {
	return name;
}

int Horcrux::getId() {
	return id;
}

void Horcrux::setValue(string name, int id) {
	this->name = name;
	this-> id = id;
}