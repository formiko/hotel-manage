#include "Customer.h"
#include <iostream>
#include <fstream>
using namespace std;

ostream &operator << (ostream &out, CustomerInfo &obj) {
	out << obj.username << "\t" << obj.customerStatus << "\t" << obj.realName << "\t" << obj.sex << "\t" << obj.IDCard <<
	    endl;
	return out;
}

istream &operator >> (istream &in, CustomerInfo &obj) {
	in >> obj.username >> obj.customerStatus >> obj.realName >> obj.sex >> obj.IDCard;
	if (!in) {
		obj = CustomerInfo();
	}
	return in;
}

void Customer::showAllCustomer() {
	syncReadCustomer();
	map<string, CustomerInfo>::iterator it;
	for (it = Customer::mpCustomer.begin(); it != Customer::mpCustomer.end(); ++it) {
		cout << it->second;
	}
}

void Customer::syncReadCustomer() {
	ifstream file;
	file.open("Customer.dat", ios::in);
	CustomerInfo line;
	while (file >> line) {
		Customer::mpCustomer[line.username] = line;
	}
	file.close();
}