#include <string>
#include <map>
using namespace std;

class ContinueDiscountInfo {
		friend ostream & operator << (ostream &out, ContinueDiscountInfo &obj);
		friend istream & operator >> (istream &in, ContinueDiscountInfo &obj);
		
	public:
		int leastPeriod;
		double discount;
		ContinueDiscountInfo(int leastPeriod = -1, double discount = -1) {
			this->leastPeriod = leastPeriod;
			this->discount = discount;
		}
		
};

class ContinueDiscount {
		
	public:
		static map<int, ContinueDiscountInfo> mpContinueDiscount;
		static void showDiscount();
		static void syncReadDiscount();
		static double workDiscount(int stayPeriod);
};