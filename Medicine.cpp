#include "Medicine.h"

Medicine::Medicine(string name, int recoverValue, int price) : name(name), recoverValue(recoverValue), price(price) {
}

string Medicine::getName() {
	return name;
}

int Medicine::getRecoverValue() {
	return recoverValue;
}

int Medicine::getPrice() {
	return price;
}

void Medicine::setInformation(string name, int recoverValue, double price) {
	this->name = name;
	this->recoverValue = recoverValue;
	this->price = price;
}