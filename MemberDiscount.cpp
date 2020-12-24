#include <iostream>
#include <fstream>
#include <strstream>
#include "MemberDiscount.h"
using namespace std;

void MemberDiscount::setDiscount(int index, double newDiscount) {
	map<string, double>::iterator it;
	int curIndex = 1;
	bool setSuccess = false;
	for(it = MemberDiscount::mpDiscount.begin(); it != MemberDiscount::mpDiscount.end(); ++it, ++curIndex) {
		if(index == curIndex) {
			setSuccess = true;
			it->second = newDiscount;
			syncWriteDiscount();
			cout << it->first << "类型的折扣比率成功设置为" << newDiscount << endl;
			break;
		}
	}
	if(!setSuccess) {
		cout << "序号为" << index << "的会员类型折扣比率设置失败" << endl;
	}
}
void MemberDiscount::syncWriteDiscount() {
	ofstream file;
	file.open("memberDiscount.dat", ios::out);
	map<string, double>::iterator it;
	for(it = MemberDiscount::mpDiscount.begin(); it != MemberDiscount::mpDiscount.end(); ++it) {
		file << it->first << " " << it->second << endl;
	}
	file.close();
}
void MemberDiscount::syncReadDiscount() {
	ifstream file;
	file.open("memberDiscount.dat", ios::in);
	string line;
	
	while(getline(file, line)) {
		
		istrstream strin(line.c_str());
		string status;
		double curDiscount;
		strin >> status >> curDiscount;
		MemberDiscount::mpDiscount[status] = curDiscount;
//		cout << status << " + " << curDiscount << endl;
	}
	file.close();
}
void MemberDiscount::showDiscount() {
	
	syncReadDiscount();
	map<string, double>::iterator it;
	cout << "会员类型\t折扣比率" << endl;
	int index = 1;
	for(it = MemberDiscount::mpDiscount.begin(); it != MemberDiscount::mpDiscount.end(); ++it, ++index) {
		cout << index << "\t" << it->first << "\t" << it->second << endl;
	}
}