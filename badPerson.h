#ifndef _BADPERSON_H
#define _BADPERSON_H
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;
class BadPerson : public Person {
public:
	BadPerson(double blood = 0, double down = 0, double up = 0, string name = 0);
	~BadPerson();
	double getblood();
	double getDown();
	double getUp();
	string getName();
	void setValue(double blood = 0, double down = 0, double up = 0, string name = 0);
private:
	double blood;
	double down;	//	对主角造成伤害的下限
	double up;	//	对主角造成伤害的上限
	string name;
};
#endif