#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "Room.h"
using namespace std;

ostream &operator << (ostream &out, RoomInfo &obj) {
	out << obj.roomId << "\t" << obj.typeName	<< "\t" << obj.status;
	return out;
}

istream &operator >> (istream &in, RoomInfo &obj) {
	in >> obj.roomId  >> obj.typeName >> obj.status;
	if (!in) {
		obj = RoomInfo();
	}
	return in;
}

void Room::showRoom() {
	syncReadRoom();
	map<string, RoomInfo>::iterator it;
	for (it = Room::mpRoom.begin(); it != Room::mpRoom.end(); ++it) {
		cout << it->second << endl;
	}
}

void Room::syncReadRoom() {
	ifstream file;
	file.open("Room.dat", ios::in);
	RoomInfo line;
	while (file >> line) {
		Room::mpRoom[line.roomId] = line;
	}
	file.close();
}

void Room::syncWriteRoom() {
}