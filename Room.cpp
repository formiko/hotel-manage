#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "Room.h"
#include "MemberDiscount.h"
#include "Customer.h"
#include "ContinueDiscount.h"
using namespace std;

ostream &operator << (ostream &out, RoomInfo &obj) {
	out << obj.roomId << "\t" << obj.typeName << "\t" << obj.roomStatus << "\t" << obj.whoInRoom << "\t" << obj.stayPeriod
	    << "\t" << obj.needPay;
	return out;
}

istream &operator >> (istream &in, RoomInfo &obj) {
	in >> obj.roomId  >> obj.typeName >> obj.roomStatus >> obj.whoInRoom >> obj.stayPeriod >> obj.needPay;
	if (!in) {
		obj = RoomInfo();
	}
	return in;
}

void Room::checkOut(string roomId) {
	cout << "需要收费金额为 " << Room::mpRoom[roomId].needPay << endl;
	Room::mpRoom[roomId].roomStatus = "空房";
	Room::mpRoom[roomId].whoInRoom = "无";
	Room::mpRoom[roomId].stayPeriod = 0;
	Room::mpRoom[roomId].needPay = 0;
	syncWriteRoom();
}

void Room::inRoom(string roomId) {
	Room::mpRoom[roomId].roomStatus = "已入住";
	syncWriteRoom();
}

void Room::bookRoom(string roomId, string username, int stayPeriod) {
	Room::mpRoom[roomId].roomStatus = "已预订";
	Room::mpRoom[roomId].whoInRoom = username;
	Room::mpRoom[roomId].stayPeriod = stayPeriod;
	puts("********************");
	cout << RoomTypePrice::mpRoomType[Room::mpRoom[roomId].typeName].pricePerNight << endl;
	cout <<	MemberDiscount::mpDiscount[Customer::mpCustomer[username].customerStatus] << endl;
	cout <<	ContinueDiscount::workDiscount(stayPeriod) << endl;
	puts("********************");

	Room::mpRoom[roomId].needPay = (double)stayPeriod
	                               * RoomTypePrice::mpRoomType[Room::mpRoom[roomId].typeName].pricePerNight
	                               * MemberDiscount::mpDiscount[Customer::mpCustomer[username].customerStatus]
	                               * ContinueDiscount::workDiscount(stayPeriod);
	syncWriteRoom();
}

void Room::CustomerCancelBook(string username) {
	syncReadRoom();
	map<string, RoomInfo>::iterator it;
	cout << "房间号\t房间状态\t房间类型\t床位数\t每晚价格" << endl;
	for (it = Room::mpRoom.begin(); it != Room::mpRoom.end(); ++it) {
		if (username != it->second.whoInRoom) {
			continue;
		}
		it->second.roomStatus = "空房";
		it->second.whoInRoom = "无";
		it->second.stayPeriod = 0;
		it->second.needPay = 0;
	}
	syncWriteRoom();
}

void Room::showCustomerBookedRoom(string username) {
	syncReadRoom();
	map<string, RoomInfo>::iterator it;
	cout << "房间号\t房间状态\t顾客\t入住时长\t待支付\t房间类型\t床位数\t每晚价格" << endl;
	for (it = Room::mpRoom.begin(); it != Room::mpRoom.end(); ++it) {
		if (username != it->second.whoInRoom) {
			continue;
		}
		cout << it->second.roomId << "\t" << it->second.roomStatus << "\t" << it->second.whoInRoom << "\t" <<
		     it->second.stayPeriod << "\t"
		     << it->second.needPay << "\t" <<
		     RoomTypePrice::mpRoomType[it->second.typeName] <<
		     endl;
	}
}

void Room::showEmptyRoom() {
	syncReadRoom();
	map<string, RoomInfo>::iterator it;
	cout << "房间号\t房间状态\t房间类型\t床位数\t每晚价格" << endl;
	for (it = Room::mpRoom.begin(); it != Room::mpRoom.end(); ++it) {
		if ("空房" != it->second.roomStatus) {
			continue;

		}
		cout << it->second.roomId << "\t" << it->second.roomStatus << "\t" << RoomTypePrice::mpRoomType[it->second.typeName] <<
		     endl;
	}
}

void Room::showRoom() {
	syncReadRoom();
	map<string, RoomInfo>::iterator it;
	cout << "房间号\t房间状态\t用户名\t房间类型\t床位数\t每晚价格" << endl;
	for (it = Room::mpRoom.begin(); it != Room::mpRoom.end(); ++it) {
		cout << it->second.roomId << "\t" << it->second.roomStatus << "\t" << it->second.whoInRoom << "\t" <<
		     RoomTypePrice::mpRoomType[it->second.typeName] <<
		     endl;
	}
}








//void Room::showRoomAndType() {
//	syncReadRoom();
//	map<string, RoomInfo>::iterator it;
//	for (it = Room::mpRoom.begin(); it != Room::mpRoom.end(); ++it) {
//		cout << it->second << endl;
//	}
//}
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
	ofstream file;
	file.open("Room.dat", ios::out);
	map<string, RoomInfo>::iterator it;
	for (it = Room::mpRoom.begin(); it != Room::mpRoom.end(); ++it) {
		file << it->second << endl;
	}
	file.close();
}