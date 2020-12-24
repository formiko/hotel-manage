#include <map>
#include <string>
using namespace std;

class MemberDiscount {
		static map<string, double>mpDiscount;
	public:
		static void setDiscount(int index, double newDiscount);
		static void syncWriteDiscount();
		static void syncReadDiscount();
		static void showDiscount();
};

