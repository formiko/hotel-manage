#include "View.h"
#include <map>
#include "MemberDiscount.h"
#include "Room.h"
#include "Customer.h"
#include "ContinueDiscount.h"
#include <iostream>
#include <fstream>
using namespace std;
map<string, double> MemberDiscount::mpDiscount;
map<string, RoomTypeInfo> RoomTypePrice::mpRoomType;
map<string, RoomInfo> Room::mpRoom;
map<string, CustomerInfo> Customer::mpCustomer;
map<int, ContinueDiscountInfo>ContinueDiscount::mpContinueDiscount;
string Identity::nowUsername = "none";

int main() {
	RoomTypePrice::syncReadRoomTypePrice();
	Room::syncReadRoom();
	Customer::syncReadCustomer();
	MemberDiscount::syncReadDiscount();
	ContinueDiscount::syncReadDiscount();
//	ofstream file;
//	file.open("continueDiscount.dat", ios::out);
//	file << "0 1" << endl;
//	file << "2 0.9" << endl;
//	file << "5 0.85" << endl;
//	file << "9 0.8" << endl;
	
//	ofstream file;
//	file.open("Customer.dat", ios::out);
//	file << "formiko 金卡会员 菜狗 男 12345678123" << endl;
//	file << "okimrof 银卡会员 狗菜 女 98765432122" << endl;
//	file << "efemero 普通会员 菜狗菜 男 1234554321" << endl;
//	file << "oremefe 非会员 狗菜狗 女 5432112345" << endl;

	ofstream file;
	file.open("Room.dat", ios::out);
	file << "101 豪华套房 空房 无  0 0" << endl;
	file << "102 普通客房 空房 无  0 0" << endl;
	file << "103 标准客房 空房 无  0 0" << endl;
	file << "201 普通客房 空房 无  0 0" << endl;
	file << "202 普通客房 空房 无  0 0" << endl;
	file << "203 标准客房 空房 无  0 0" << endl;
	file << "301 豪华套房 空房 无 0 0" << endl;
	file << "302 豪华套房 空房 无 0 0" << endl;
	file << "303 豪华套房 空房 无 0 0" << endl;

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