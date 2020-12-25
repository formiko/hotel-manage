#include "View.h"
#include <map>
#include "MemberDiscount.h"
#include "RoomTypePrice.h"

#include <iostream>
#include <fstream>
using namespace std;
map<string, double> MemberDiscount::mpDiscount;
map<int, RoomTypeInfo> RoomTypePrice::mpRoomType;
int main() {
	ofstream file;
	file.open("RoomTypePrice.dat", ios::out);
	file << "豪华套房 4 400" << endl;
	file << "标准客房 2 200" << endl;
	file << "普通客房 1 100" << endl;

//	ofstream file;
//	file.open("memberDiscount.dat", ios::out);
//	file << "金卡会员 0.8" << endl;
//	file << "银卡会员 0.9" << endl;
//	file << "普通会员 0.95" << endl;
//	file << "非会员 1" << endl;
	(new View)->run();
	return 0;
}