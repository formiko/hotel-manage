#include "View.h"
#include <map>
#include "MemberDiscount.h"
using namespace std;
map<string, double> MemberDiscount::mpDiscount;
int main() {
//	ofstream file;
//	file.open("memberDiscount.dat", ios::out);
//	file << "�𿨻�Ա 0.8" << endl;
//	file << "������Ա 0.9" << endl;
//	file << "��ͨ��Ա 0.95" << endl;
//	file << "�ǻ�Ա 1" << endl;
	(new View)->run();
	return 0;
}