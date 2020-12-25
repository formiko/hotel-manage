#include <iostream>
#include <fstream>
#include <string>
#include "View.h"
#include "MemberDiscount.h"
#include "Room.h"
using namespace std;


void View::viewCustomerFindRoom() {
	system("cls");
	puts("1. ��ѯ���пշ�");
	puts("2. ������Ų�ѯ�շ�");
	puts("3. ��¥���ѯ�շ�");
	int sel;
	cin >> sel;
}

void View::viewIndex() {
	system("cls");
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
			viewAdminLogin();
			break;
		case 3:
			viewReceptLogin();
			break;
		default:
			puts("��Ч����");
			viewIndex();
	}
}

void View::viewCustomer() {
	system("cls");
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
}

void View::viewCustomerLogin() {
	string username, password;
	puts("�������û�����");
	cin >> username;
	puts("���������룺");
	cin >> password;
	if (Identity::customerLogin(username, password)) {
		viewCustomerIndex();
	} else {
		puts("1. ���³��Ե�¼��Ĭ�ϣ�");
		puts("2. ע���µĹ˿��˺�");
		puts("3. ����ѡ�����");
		int sel;
		cin >> sel;
		switch (sel) {
			case 1:
				viewCustomerLogin();
				break;
			case 2:
				viewCustomerRegister();
				break;
			case 3:
				viewIndex();
				break;
			default:
				viewCustomerLogin();
		}

	}
}

void View::viewCustomerRegister() {
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

void View::viewCustomerIndex() {
	system("cls");
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
void View::viewAdminLogin() {
	string username, password;
	puts("�������û�����");
	cin >> username;
	puts("���������룺");
	cin >> password;
	if (Identity::adminLogin(username, password)) {
		viewAdminIndex();
	} else {
		puts("1. ���³��Ե�¼��Ĭ�ϣ�");
		puts("2. ����ѡ�����");
		int sel;
		cin >> sel;
		switch (sel) {
			case 1:
				viewAdminLogin();
				break;
			case 2:
				viewIndex();
				break;
			default:
				viewAdminLogin();
		}

	}
}
void View::viewSetMemberDiscount() {
	MemberDiscount::showDiscount();
	puts("������Ҫ�޸ĵĻ�Ա�������");
	int index;
	cin >> index;
	puts("�����޸ĳɵ��ۿ۱���(0~1)");
	double rate;
	cin >> rate;
	MemberDiscount::setDiscount(index, rate);
	viewSetDiscount();
}
void View::viewManageSteadyInDiscount() {
}
void View::viewSetDiscount() {
	puts("1. ���û�Ա�Ż�����");
	puts("2. ����������ס�Ż�����");
	puts("0. ȡ����Ĭ�ϣ�");
	int sel;
	cin >> sel;
	switch(sel) {
		case 1:
			viewSetMemberDiscount();
			break;
		case 2:
			viewManageSteadyInDiscount();
			break;
		default:
			viewAdminIndex();
	}
}
void View::viewSetRoomTypePrice() {
	RoomTypePrice::showRoomTypePrice();
	
}
void View::viewAdminIndex() {
	system("cls");
	puts("1. �鿴�ͷ�");
	puts("2. ���ӷ���");
	puts("3. ɾ������");
	puts("4. ����ָ���ͷ����ͼ۸�");
	puts("5. �����Ż�����");
	puts("0. ����ѡ����ݣ�Ĭ�ϣ�");
	int sel;
	cin >> sel;
	switch (sel) {
		case 1:
			viewLookRoom("admin");
			break;
		case 2:
			break;
		case 5:
			viewSetDiscount();
			break;
		case 4:
			viewSetRoomTypePrice();
			break;
		default:
			viewIndex();
	}
}
void View::viewLookRoom(string who) {
	puts("1. �鿴ȫ��������Ϣ");
	puts("2. �鿴�շ���Ϣ");
	puts("3. �鿴��Ԥ��������Ϣ");
	puts("4. �鿴����ס������Ϣ");
	puts("5. �������鿴");
	puts("6. ������Ų鿴");
	puts("0. ȡ����Ĭ�ϣ�");
	int sel;
	cin >> sel;
	switch(sel) {
		case 1:
			Room::showRoom();
			break;
		default:
			if("admin" == who) {
				viewAdminIndex();
			} else if("recept" == who) {
				viewReceptIndex();
			}
	}
}
void View::viewReceptLogin() {
	string username, password;
	puts("�������û�����");
	cin >> username;
	puts("���������룺");
	cin >> password;
	if (Identity::receptLogin(username, password)) {
		viewReceptIndex();
	} else {
		puts("1. ���³��Ե�¼��Ĭ�ϣ�");
		puts("2. ����ѡ�����");
		int sel;
		cin >> sel;
		switch (sel) {
			case 1:
				viewReceptLogin();
				break;
			case 2:
				viewIndex();
				break;
			default:
				viewReceptLogin();
		}

	}
}
void View::viewReceptIndex() {
	puts("1. �鿴�ͷ�");
	puts("2. ������ס");
	puts("3. �����˷�");
	puts("4. ������");
	puts("0. ����ѡ����ݣ�Ĭ�ϣ�");
	int sel;
	cin >> sel;
	switch(sel) {
		case 1:
			viewLookRoom("recept");
			break;
		case 2:
			break;
		default:
			viewIndex();
	}
}