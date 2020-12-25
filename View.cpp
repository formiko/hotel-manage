#include <iostream>
#include <fstream>
#include <string>
#include "View.h"
#include "MemberDiscount.h"
#include "Room.h"
#include "ContinueDiscount.h"
using namespace std;

void View::viewCustomerFindAllEmptyRoom() {
	Room::showEmptyRoom();
	puts("1. 预订客房");
	puts("0. 取消（默认）");
	int sel;
	cin >> sel;
	switch (sel) {
		case 1:
			viewCustomerBookRoom();
			break;
		default:
			viewCustomerIndex();
	}
}

void View::viewCustomerFindRoom() {
	system("cls");
	puts("1. 查询所有空房");
//	puts("2. 按房间号查询空房");
//	puts("3. 按楼层查询空房");
	puts("0. 取消（默认）");
	int sel;
	cin >> sel;
	switch (sel) {
		case 1:
			viewCustomerFindAllEmptyRoom();
			break;
		default:
			viewCustomerIndex();
	}
}

void View::viewIndex() {
	system("cls");
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
			viewAdminLogin();
			break;
		case 3:
			viewReceptLogin();
			break;
		default:
			puts("无效输入");
			viewIndex();
	}
}

void View::viewCustomer() {
	system("cls");
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
}

void View::viewCustomerLogin() {
	string username, password;
	puts("请输入用户名：");
	cin >> username;
	puts("请输入密码：");
	cin >> password;
	if (Identity::customerLogin(username, password)) {
		viewCustomerIndex();
	} else {
		puts("1. 重新尝试登录（默认）");
		puts("2. 注册新的顾客账号");
		puts("3. 重新选择身份");
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
	puts("输入任意值按回车到顾客首页");
	string temp;
	cin >> temp;
	viewCustomerIndex();
}

void View::viewCustomerBookRoom() {
	puts("请输入你想要预订的房间的房间号");
	string roomId;
	cin >> roomId;
	puts("请输入入住时长");
	int stayPeriod;
	cin >> stayPeriod;
	cout << "你的username是 " << Identity::nowUsername << endl;
	Room::bookRoom(roomId, Identity::nowUsername, stayPeriod);
	puts("预订成功！");
	Room::showCustomerBookedRoom(Identity::nowUsername);
	puts("1. 取消预订");
	puts("0. 返回顾客首页（默认）");
	int sel;
	cin >> sel;
	switch (sel) {
		case 1:
			viewCustomerCancelBook();
			break;
		default:
			viewCustomerIndex();
	}
}

void View::viewCustomerCancelBook() {
	puts("以下是你的预订");
	Room::showCustomerBookedRoom(Identity::nowUsername);
	puts("1. 取消预订");
	puts("0. 返回（默认）");
	int sel;
	cin >> sel;
	switch (sel) {
		case 1:
			Room::CustomerCancelBook(Identity::nowUsername);
			viewCustomerIndex();
			break;
		default:
			viewCustomerIndex();
	}
}

void View::viewCustomerIndex() {
	system("cls");
	puts("1. 查找客房");
	puts("2. 预订客房");
	puts("3. 取消预订");
	puts("4. 退房后评论");
	puts("0. 重新选择身份（默认）");
	int sel;
	cin >> sel;
	switch (sel) {
		case 1:
			viewCustomerFindRoom();
			break;
		case 2:
			viewCustomerBookRoom();
			break;
		case 3:
			viewCustomerCancelBook();
			break;
		case 4:
			break;
		default:
			viewIndex();
	}
}

void View::viewAdminLogin() {
	string username, password;
	puts("请输入用户名：");
	cin >> username;
	puts("请输入密码：");
	cin >> password;
	if (Identity::adminLogin(username, password)) {
		viewAdminIndex();
	} else {
		puts("1. 重新尝试登录（默认）");
		puts("2. 重新选择身份");
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
	puts("输入需要修改的会员类型序号");
	int index;
	cin >> index;
	puts("输入修改成的折扣比率(0~1)");
	double rate;
	cin >> rate;
	MemberDiscount::setDiscount(index, rate);
	viewSetDiscount();
}

void View::viewShowContinueInDiscount() {
	ContinueDiscount::showDiscount();
	puts("0. 返回上一级（默认）");
	int sel;
	cin >> sel;
	switch (sel) {
		default:
			viewManageContinueInDiscount();

	}
}

void View::viewManageContinueInDiscount() {
	puts("1. 显示当前连续入住优惠政策");
	puts("0. 取消（默认）");
	int sel;
	cin >> sel;
	switch (sel) {
		case 1:
			viewShowContinueInDiscount();
			break;
		default:
			viewSetDiscount();
	}
}

void View::viewSetDiscount() {
	puts("1. 设置会员优惠政策");
	puts("2. 管理连续入住优惠政策");
	puts("0. 取消（默认）");
	int sel;
	cin >> sel;
	switch (sel) {
		case 1:
			viewSetMemberDiscount();
			break;
		case 2:
			viewManageContinueInDiscount();
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
	puts("1. 查看客房");
	puts("2. 增加房间");
	puts("3. 删除房间");
	puts("4. 设置指定客房类型价格");
	puts("5. 设置优惠政策");
	puts("0. 重新选择身份（默认）");
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

void View::viewShowAllRoom(string who) {
	Room::showRoom();
	puts("0. 查看客房信息（默认）");
	int sel;
	cin >> sel;
	switch (sel) {
		case 0:
		default:
			viewLookRoom(who);
	}
}

void View::viewLookRoom(string who) {
	puts("1. 查看全部房间信息");
	puts("2. 查看空房信息");
	puts("3. 查看已预订房间信息");
	puts("4. 查看已入住房间信息");
	puts("5. 按姓名查看");
	puts("6. 按房间号查看");
	puts("0. 取消（默认）");
	int sel;
	cin >> sel;
	switch (sel) {
		case 1:
			viewShowAllRoom(who);
			break;
		default:
			if ("admin" == who) {
				viewAdminIndex();
			} else if ("recept" == who) {
				viewReceptIndex();
			}
	}
}

void View::viewReceptLogin() {
	string username, password;
	puts("请输入用户名：");
	cin >> username;
	puts("请输入密码：");
	cin >> password;
	if (Identity::receptLogin(username, password)) {
		viewReceptIndex();
	} else {
		puts("1. 重新尝试登录（默认）");
		puts("2. 重新选择身份");
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

void View::viewInRoom() {
	puts("请输入顾客预订的房间号");
	string roomId;
	cin >> roomId;
	Room::inRoom(roomId);
	puts("办理入住成功");
	puts("1. 查看客房");
	puts("0. 返回（默认）");
	int sel;
	cin >> sel;
	switch (sel) {
		case 1:
			viewLookRoom("recept");
			break;
		default:
			viewReceptIndex();
	}
}

void View::viewCheckOut() {
	puts("请输入要退房的房间号");
	string roomId;
	cin >> roomId;
	Room::checkOut(roomId);
	puts("退房成功");
	puts("1. 查看客房");
	puts("0. 返回（默认）");
	int sel;
	cin >> sel;
	switch (sel) {
		case 1:
			viewLookRoom("recept");
			break;
		default:
			viewReceptIndex();
	}
}

void View::viewReceptIndex() {
	puts("1. 查看客房");
	puts("2. 办理入住");
	puts("3. 办理退房");
//	puts("4. 办理换房");
	puts("0. 重新选择身份（默认）");
	int sel;
	cin >> sel;
	switch (sel) {
		case 1:
			viewLookRoom("recept");
			break;
		case 2:
			viewInRoom();
			break;
		case 3:
			viewCheckOut();
			break;
		default:
			viewIndex();
	}
}