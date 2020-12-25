#include <string>
#include <map>
using namespace std;

struct CustomerInfo{
		friend ostream &operator << (ostream &out, CustomerInfo &obj);
		friend istream &operator >> (istream &out, CustomerInfo &obj);
	public:
		CustomerInfo(string username = "wrong init", string customerStatus = "wrong init", string realName = "wrong init", 
		string sex = "wrong init", string IDCard = "wrong init") {
			this->username = username;
			this->customerStatus = customerStatus;
			this->realName = realName;
			this->sex = sex;
			this->IDCard = IDCard;
		}
		string username;
		string customerStatus;
		string realName;
		string sex;
		string IDCard;
};

class Customer {
	public:
		static map<string, CustomerInfo>mpCustomer;
		string username;
		CustomerInfo customerInfo;
		static void showAllCustomer();
		static void syncReadCustomer();
};