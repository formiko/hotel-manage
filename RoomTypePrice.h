#include <string>
#include <map>
using namespace std;

class RoomTypeInfo {
		friend ostream & operator << (ostream &out, RoomTypeInfo &obj);
		friend istream & operator >> (istream &in, RoomTypeInfo &obj);
		
	public:
		string typeName;
		int bedNum;
		double pricePerNight;
		RoomTypeInfo(string typeName = "wrong in", int bedNum = -1, double pricePerNight = -1) {
			this->typeName = typeName;
			this->bedNum = bedNum;
			this->pricePerNight = pricePerNight;
		}
		
};

class RoomTypePrice {
		static map<string, RoomTypeInfo> mpRoomType;
	public:
		static void showRoomTypePrice();
		static void setRoomTypePrice(int index, RoomTypeInfo);
		static void syncReadRoomTypePrice();
		static void syncWriteRoomTypePrice();
};