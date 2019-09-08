#include "goodPerson.h"

GoodPerson::GoodPerson(string name, string sentence) : name(name), sentence(sentence) {
}

GoodPerson::~GoodPerson() {
}

string GoodPerson::getName() {
	return name;
}

string GoodPerson::getSentence() {
	return sentence;
}
