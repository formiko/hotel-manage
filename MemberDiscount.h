#include <map>
#include <string>
using namespace std;

class MemberDiscount {
		
	public:
		static map<string, double>mpDiscount;
		static void setDiscount(int index, double newDiscount);
		static void syncWriteDiscount();
		static void syncReadDiscount();
		static void showDiscount();
};

