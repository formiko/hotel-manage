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
	file << "�����׷� 4 400" << endl;
	file << "��׼�ͷ� 2 200" << endl;
	file << "��ͨ�ͷ� 1 100" << endl;

//	ofstream file;
//	file.open("memberDiscount.dat", ios::out);
//	file << "�𿨻�Ա 0.8" << endl;
//	file << "������Ա 0.9" << endl;
//	file << "��ͨ��Ա 0.95" << endl;
//	file << "�ǻ�Ա 1" << endl;
	(new View)->run();
	return 0;
}