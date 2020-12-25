#include <string>
#include <map>
#include "RoomTypePrice.h"
using namespace std;

class RoomInfo : public RoomTypeInfo {

		friend ostream &operator << (ostream &out, RoomInfo &obj);
		friend istream &operator >> (istream &in, RoomInfo &obj);
	public:
		string whoInRoom;
		string roomId;
		string roomStatus;
		int stayPeriod;
		double needPay;
		RoomInfo(string roomId = "wrong init", string typeName = "wrong init", string roomStatus = "wrong init",
		         int stayPeriod = -1, double needPay = -1) {
			this->roomId = roomId;
			this->typeName = typeName;
			this->roomStatus = roomStatus;
			this->stayPeriod = stayPeriod;
			this->needPay = needPay;
		}

};

class Room {
		static map<string, RoomInfo> mpRoom;
	public:
		static void bookRoom(string roomId, string username, int stayPeriod);
		static void showCustomerBookedRoom(string username);
		static void CustomerCancelBook(string username);
		static void showEmptyRoom();
		static void showRoom();
		static void syncReadRoom();
		static void syncWriteRoom();
};