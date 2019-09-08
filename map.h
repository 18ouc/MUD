#ifndef _MAP_H
#define _MAP_H
#include <iostream>
#include <string>
#include <vector>
#include "room.h"
using namespace std;
class Map {
public:
	Map(string shape = 0) : shape(shape) {}
	~Map();
	void showMap();
	void addRoom(Room temp);
private:
	string shape;
	vector<Room> ROOM;
};
#endif

