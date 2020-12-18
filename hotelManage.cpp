#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Identity {

	public:
		static bool isUsernameExisted(string username) {
			return false;
		}
		static void registerCustomer(string username, string password) {
			ofstream passFile;
			passFile.open("password.txt", ios::app);
			passFile << username << " " << password << " " << "customer" << endl;
			passFile.close();
		}
		static bool customerLogin(string username, string password) {
			ifstream passFile;
			passFile.open("password.txt", ios::in);
			string line;

		}

};

class mainLine {
	private:
		void viewCustomerFindRoom() {
			puts("1. 查询所有空房");
			puts("2. 按房间号查询空房");
			puts("3. 按楼层查询空房");
			int sel;
			cin >> sel;
		}
		void viewCustomerIndex() {
			puts("1. 查找客房");
			puts("2. 预订客房");
			puts("3. 取消预订");
			puts("4. 退房后评论");
			int sel;
			cin >> sel;
			switch (sel) {
				case 1:
					viewCustomerFindRoom();
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				default:
					puts("无效输入");
					viewCustomerIndex();
			}
		}
		void viewCustomerRegister() {
			string username;
			bool needReinput = false;
			do {
				puts("请输入用户名：");
				cin >> username;
				if (Identity::isUsernameExisted(username)) {
					needReinput = true;
					puts("用户名已存在");
				}
			} while (needReinput);
			bool isSamePassword = false;
			string password;
			do {
				puts("请输入密码：");
				cin >> password;
				puts("请再次输入密码：");
				string reinputPassword;
				cin >> reinputPassword;
				if (password == reinputPassword) {
					isSamePassword = true;
				}
			} while (!isSamePassword);
			Identity::registerCustomer(username, password);
			puts("注册成功");
			puts("你的用户名是：");
			cout << username << endl;
			puts("你的密码是：");
			cout << password << endl;
			puts("自动登录成功");
			viewCustomerIndex();
		}

		void viewCustomerLogin() {
			string username, password;
			puts("请输入用户名：");
			cin >> username;
			puts("请输入密码：");
			cin >> password;
			if (Identity::customerLogin(username, password)) {
				viewCustomerIndex();
			} else {
				puts("用户名或者密码错误");
				viewCustomerLogin();
			}
		}
		void viewCustomer() {
			puts("1. 登录");
			puts("2. 注册");
			int sel;
			cin >> sel;
			switch (sel) {
				case 1:
					viewCustomerLogin();
					break;
				case 2:
					viewCustomerRegister();
					break;
				default:
					puts("无效输入");
					viewCustomer();
			}
			if (1 == sel) {
				viewCustomerLogin();
			} else if ( 2 == sel) {
				viewCustomerRegister();
			}
		}
		void viewIndex() {
			puts("你是？");
			puts("1. 顾客");
			puts("2. 管理员");
			puts("3. 酒店前台");
			int sel;
			cin >> sel;
			switch (sel) {
				case 1:
					viewCustomer();
					break;
				case 2:
					break;
				case 3:
					break;
				default:
					puts("无效输入");
					viewIndex();
			}
		}
	public:
		void run() {
			viewIndex();
		}
};

int main() {
	(new mainLine)->run();
	return 0;
}