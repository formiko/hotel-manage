#include "View.h"
#include <map>
#include "MemberDiscount.h"
#include "Room.h"
#include "Customer.h"
#include <iostream>
#include <fstream>
using namespace std;
map<string, double> MemberDiscount::mpDiscount;
map<string, RoomTypeInfo> RoomTypePrice::mpRoomType;
map<string, RoomInfo> Room::mpRoom;
map<string, CustomerInfo> Customer::mpCustomer;
string Identity::nowUsername = "none";

int main() {
	RoomTypePrice::syncReadRoomTypePrice();
	Room::syncReadRoom();
	Customer::syncReadCustomer();
	MemberDiscount::syncReadDiscount();

//	ofstream file;
//	file.open("Customer.dat", ios::out);
//	file << "formiko �𿨻�Ա �˹� �� 12345678123" << endl;
//	file << "okimrof ������Ա ���� Ů 98765432122" << endl;
//	file << "efemero ��ͨ��Ա �˹��� �� 1234554321" << endl;
//	file << "oremefe �ǻ�Ա ���˹� Ů 5432112345" << endl;

//	ofstream file;
//	file.open("Room.dat", ios::out);
//	file << "101 ��ͨ�ͷ� �շ� ��  0 0" << endl;
//	file << "202 ��׼�ͷ� ��Ԥ�� formiko 0 0" << endl;
//	file << "303 ��ͨ�ͷ� ����ס okimrof 0 0" << endl;

//	ofstream file;
//	file.open("RoomTypePrice.dat", ios::out);
//	file << "�����׷� 4 400" << endl;
//	file << "��׼�ͷ� 2 200" << endl;
//	file << "��ͨ�ͷ� 1 100" << endl;

//	ofstream file;
//	file.open("memberDiscount.dat", ios::out);
//	file << "�𿨻�Ա 0.8" << endl;
//	file << "������Ա 0.9" << endl;
//	file << "��ͨ��Ա 0.95" << endl;
//	file << "�ǻ�Ա 1" << endl;
	(new View)->run();
	return 0;
}