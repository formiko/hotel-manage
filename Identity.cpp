#include <iostream>
//#include <string>
#include <fstream>
#include <strstream>
#include "Identity.h"
using namespace std;

bool Identity::isUsernameExisted(string username) {
	return false;
}

void Identity::registerCustomer(string username, string password) {
	ofstream passFile;
	passFile.open("password.dat", ios::app);
	passFile << username << " " << password << " " << "customer" << endl;
	passFile.close();
}

bool Identity::customerLogin(string username, string password) {
	ifstream passFile;
	passFile.open("password.dat", ios::in);
	string line;
	bool have_user = false;
	bool wrong_password;
	bool is_customer = true;
	while (getline(passFile, line)) {
		istrstream strin(line.c_str());
		string curUsername, curPassword, curUserType;
		strin >> curUsername >> curPassword >> curUserType;
		if (username == curUsername) {
			have_user = true;
			if (password != curPassword) {
				cout << "�������" << endl;
				wrong_password = true;
			} else {
				cout << "������ȷ��" << endl;
				wrong_password = false;
				if ("customer" != curUserType) {
					is_customer = false;
					cout << "���ǹ˿��˺ţ�" << endl;
				}
			}
			break;
		}
	}
	passFile.close();
	if (!have_user) {
		cout << "�û��������ڣ�" << endl;
		return false;
	} else {
		if (wrong_password) {
			return false;
		} else {
			if (!is_customer) {
				return false;
			} else {
				return true;
			}
		}
	}
}
bool Identity::adminLogin(string username, string password) {
	ifstream passFile;
	passFile.open("password.dat", ios::in);
	string line;
	bool have_user = false;
	bool wrong_password;
	bool is_admin = true;
	while (getline(passFile, line)) {
		istrstream strin(line.c_str());
		string curUsername, curPassword, curUserType;
		strin >> curUsername >> curPassword >> curUserType;
		if (username == curUsername) {
			have_user = true;
			if (password != curPassword) {
				cout << "�������" << endl;
				wrong_password = true;
			} else {
				cout << "������ȷ��" << endl;
				wrong_password = false;
				if ("admin" != curUserType) {
					is_admin = false;
					cout << "���ǹ���Ա�˺ţ�" << endl;
				}
			}
			break;
		}
	}
	passFile.close();
	if (!have_user) {
		cout << "�û��������ڣ�" << endl;
		return false;
	} else {
		if (wrong_password) {
			return false;
		} else {
			if (!is_admin) {
				return false;
			} else {
				return true;
			}
		}
	}
}

bool Identity::receptLogin(string username, string password) {
	ifstream passFile;
	passFile.open("password.dat", ios::in);
	string line;
	bool have_user = false;
	bool wrong_password;
	bool is_recept = true;
	while (getline(passFile, line)) {
		istrstream strin(line.c_str());
		string curUsername, curPassword, curUserType;
		strin >> curUsername >> curPassword >> curUserType;
		if (username == curUsername) {
			have_user = true;
			if (password != curPassword) {
				cout << "�������" << endl;
				wrong_password = true;
			} else {
				cout << "������ȷ��" << endl;
				wrong_password = false;
				if ("recept" != curUserType) {
					is_recept = false;
					cout << "����ǰ̨�˺ţ�" << endl;
				}
			}
			break;
		}
	}
	passFile.close();
	if (!have_user) {
		cout << "�û��������ڣ�" << endl;
		return false;
	} else {
		if (wrong_password) {
			return false;
		} else {
			if (!is_recept) {
				return false;
			} else {
				return true;
			}
		}
	}
}