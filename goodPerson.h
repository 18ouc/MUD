#ifndef _GOODPERSON_H
#define _GOODPERSON_H
#include <string>
#include "Person.h"
using namespace std;
class GoodPerson :
	public Person
{
public:
	GoodPerson(string name = 0, string sentence = 0);
	~GoodPerson();
	string getName();
	string getSentence();
private:
	string sentence;
	string name;
};
#endif

