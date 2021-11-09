#include<iostream>
#include"TBitField.h"
#include"TSet.h"
using namespace std;

int main() {
	TSet A(100);
	TSet B;
	TSet C(A);
	B = A;
	cout << A.TSetToString() << endl;
	cout << B.TSetToString() << endl;
	cout << C.TSetToString() << endl;
	A.add(32);
	cout << A.TSetToString() << endl;
	A.add(49);
	cout << A.TSetToString() << endl;
	A.add(78);
	cout << A.TSetToString() << endl;
	A.add(100);
	cout << A.TSetToString() << endl;
	B.add(78);
	B.add(32);
	B.add(62);
	B.add(51);
	B.add(1);
	A.add(115);
	A.del(49);
	B.add(50);
	A.add(43);
	B.del(21);
	B.add(43);
	B.del(43);
	
	TSet D;
	cout << A.TSetToString() << endl;
	cout << B.TSetToString() << endl;
	cout << D.TSetToString() << endl;
	D = A | B;
	TSet G = A & B;
	cout << "ITS FINALY A " << endl;
	cout << A.TSetToString() << endl;
	cout << "ITS FINALY B " << endl;
	cout << B.TSetToString() << endl;
	cout << "ITS G " << endl;
	cout << G.TSetToString() << endl;
	cout << "ITS D " << endl;
	cout << D.TSetToString() << endl;
	TSet F;
	F = ~D;
	cout << "ITS F " << endl;
	cout << F.TSetToString() << endl;
	return 0;
}