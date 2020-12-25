#include <iostream>
#include <string>
#include <fstream>
#include <strstream>
#include "RoomTypePrice.h"
using namespace std;

ostream & operator << (ostream &out, RoomTypeInfo &obj) {
	out << obj.typeName << "\t" << obj.bedNum << "\t" << obj.pricePerNight;
	return out;
}
istream & operator >> (istream &in, RoomTypeInfo &obj) {
	in >> obj.typeName >> obj.bedNum >> obj.pricePerNight;
	if(!in) {
		obj = RoomTypeInfo();
	}
	return in;
}
void RoomTypePrice::showRoomTypePrice() {
	syncReadRoomTypePrice();
	map<int, RoomTypeInfo>::iterator it;
	cout << "序号\t房间类型\t床位数\t每晚价格" << endl;
	for (it = RoomTypePrice::mpRoomType.begin(); it != RoomTypePrice::mpRoomType.end(); ++it) {
		cout << it->first << "\t" << it->second << endl;
	}
}

void RoomTypePrice::setRoomTypePrice(int index, RoomTypeInfo rti) {
}

void RoomTypePrice::syncReadRoomTypePrice() {
	ifstream file;
	file.open("RoomTypePrice.dat", ios::in);
//	string line;
//	int index = 1;
//	while (getline(file, line)) {
//		istrstream strin(line.c_str());
//		RoomTypeInfo t;
//		strin >> t;
//		RoomTypePrice::mpRoomType[index] = t;
//		string typeName;
//		int bedNum;
//		double pricePerNight;
//		strin >>  typeName >> bedNum >> pricePerNight;
//		RoomTypePrice::mpRoomType[index] = RoomTypeInfo{typeName, bedNum, pricePerNight};
//		++index;
//	}
	RoomTypeInfo line;
	int index = 1;
	while(file >> line) {
		RoomTypePrice::mpRoomType[index] = line;
		++index;
	}
	file.close();
}

void RoomTypePrice::syncWriteRoomTypePrice() {

}