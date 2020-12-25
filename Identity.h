#include <string>
using namespace std;

class Identity {
	public:
		static string nowUsername;
		static bool isUsernameExisted(string username);
		static void registerCustomer(string username, string password);
		static bool customerLogin(string username, string password);
		static bool adminLogin(string username, string password);
		static bool receptLogin(string username, string password);
};