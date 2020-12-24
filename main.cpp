#include "View.h"
#include <map>
#include "MemberDiscount.h"
using namespace std;
map<string, double> MemberDiscount::mpDiscount;
int main() {
//	ofstream file;
//	file.open("memberDiscount.dat", ios::out);
//	file << "金卡会员 0.8" << endl;
//	file << "银卡会员 0.9" << endl;
//	file << "普通会员 0.95" << endl;
//	file << "非会员 1" << endl;
	(new View)->run();
	return 0;
}