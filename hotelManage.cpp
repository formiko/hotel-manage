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
			puts("1. ��ѯ���пշ�");
			puts("2. ������Ų�ѯ�շ�");
			puts("3. ��¥���ѯ�շ�");
			int sel;
			cin >> sel;
		}
		void viewCustomerIndex() {
			puts("1. ���ҿͷ�");
			puts("2. Ԥ���ͷ�");
			puts("3. ȡ��Ԥ��");
			puts("4. �˷�������");
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
					puts("��Ч����");
					viewCustomerIndex();
			}
		}
		void viewCustomerRegister() {
			string username;
			bool needReinput = false;
			do {
				puts("�������û�����");
				cin >> username;
				if (Identity::isUsernameExisted(username)) {
					needReinput = true;
					puts("�û����Ѵ���");
				}
			} while (needReinput);
			bool isSamePassword = false;
			string password;
			do {
				puts("���������룺");
				cin >> password;
				puts("���ٴ��������룺");
				string reinputPassword;
				cin >> reinputPassword;
				if (password == reinputPassword) {
					isSamePassword = true;
				}
			} while (!isSamePassword);
			Identity::registerCustomer(username, password);
			puts("ע��ɹ�");
			puts("����û����ǣ�");
			cout << username << endl;
			puts("��������ǣ�");
			cout << password << endl;
			puts("�Զ���¼�ɹ�");
			viewCustomerIndex();
		}

		void viewCustomerLogin() {
			string username, password;
			puts("�������û�����");
			cin >> username;
			puts("���������룺");
			cin >> password;
			if (Identity::customerLogin(username, password)) {
				viewCustomerIndex();
			} else {
				puts("�û��������������");
				viewCustomerLogin();
			}
		}
		void viewCustomer() {
			puts("1. ��¼");
			puts("2. ע��");
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
					puts("��Ч����");
					viewCustomer();
			}
			if (1 == sel) {
				viewCustomerLogin();
			} else if ( 2 == sel) {
				viewCustomerRegister();
			}
		}
		void viewIndex() {
			puts("���ǣ�");
			puts("1. �˿�");
			puts("2. ����Ա");
			puts("3. �Ƶ�ǰ̨");
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
					puts("��Ч����");
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