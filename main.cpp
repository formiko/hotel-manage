#include "View.h"
#include <map>
#include "MemberDiscount.h"
#include "Room.h"
#include <iostream>
#include <fstream>
using namespace std;
map<string, double> MemberDiscount::mpDiscount;
map<string, RoomTypeInfo> RoomTypePrice::mpRoomType;
map<string, RoomInfo> Room::mpRoom;
int main() {
	RoomTypePrice::syncReadRoomTypePrice();
//	ofstream file;
//	file.open("Room.dat", ios::out);
//	file << "101 普通客房 空房" << endl;
//	file << "202 标准客房 已预订" << endl;
//	file << "303 普通客房 已入住" << endl;

//	ofstream file;
//	file.open("RoomTypePrice.dat", ios::out);
//	file << "豪华套房 4 400" << endl;
//	file << "标准客房 2 200" << endl;
//	file << "普通客房 1 100" << endl;

//	ofstream file;
//	file.open("memberDiscount.dat", ios::out);
//	file << "金卡会员 0.8" << endl;
//	file << "银卡会员 0.9" << endl;
//	file << "普通会员 0.95" << endl;
//	file << "非会员 1" << endl;
	(new View)->run();
	return 0;
}