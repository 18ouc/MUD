#include "map.h"

Map::~Map() {
}

void Map::showMap() {
	cout << shape << endl;
}

void Map::addRoom(Room temp) {
	ROOM.push_back(temp);
}