#include <string>
#include <map>
#include "RoomTypePrice.h"
using namespace std;

class RoomInfo : public RoomTypeInfo{
		
		friend ostream &operator << (ostream &out, RoomInfo &obj);
		friend istream &operator >> (istream &in, RoomInfo &obj);
	public:
		string roomId;
		string status;
		RoomInfo(string roomId = "wrong init", string typeName = "wrong init", string status = "wrong init") {
			this->roomId = roomId;
			this->typeName = typeName;
			this->status = status;
		}

};

class Room {
		static map<string, RoomInfo> mpRoom;
	public:
		static void showRoom();
		static void syncReadRoom();
		static void syncWriteRoom();
};