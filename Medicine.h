#ifndef _MEDICINE
#define _MEDICINE
#include "Equipment.h"
#include <iostream>
#include <string>
using namespace std;
class Medicine : public Equipment {
public:
	Medicine(string name = 0, int recoverValue = 0, int price = 0);
	string getName();
	int getRecoverValue();
	int getPrice();
	void setInformation(string name = 0, int recoverValue = 0, double price = 0);
private:
	string name;
	int recoverValue;
	int price;
};
#endif
