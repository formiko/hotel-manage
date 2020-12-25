#include <iostream>
#include <string>
#include <fstream>
#include "ContinueDiscount.h"
using namespace std;

ostream &operator << (ostream &out, ContinueDiscountInfo &obj) {
	out << obj.leastPeriod << "\t" << obj.discount;
	return out;
}

istream &operator >> (istream &in, ContinueDiscountInfo &obj) {
	in >> obj.leastPeriod >> obj.discount;
	if (!in) {
		obj = ContinueDiscountInfo();
	}
	return in;
}

void ContinueDiscount::syncReadDiscount() {
	ifstream file;
	file.open("continueDiscount.dat", ios::in);
	ContinueDiscountInfo line;
	while (file >> line) {
		ContinueDiscount::mpContinueDiscount[line.leastPeriod] = line;
	}
	file.close();
}

void ContinueDiscount::showDiscount() {
	syncReadDiscount();
	map<int, ContinueDiscountInfo>::iterator it;
	cout << "至少入住天数\t折扣比率" << endl;
	for (it = ContinueDiscount::mpContinueDiscount.begin(); it != ContinueDiscount::mpContinueDiscount.end(); ++it) {
		cout << it->second << endl;
	}
}

double ContinueDiscount::workDiscount(int stayPeriod) {
	double re = 1.0;
	map<int, ContinueDiscountInfo>::iterator it;
	for (it = ContinueDiscount::mpContinueDiscount.begin(); it != ContinueDiscount::mpContinueDiscount.end(); ++it) {
		if(stayPeriod >= it->second.leastPeriod && re > it->second.discount) {
			re = it->second.discount;
		}
	}
	return re;
}