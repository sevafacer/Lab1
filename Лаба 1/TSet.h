#pragma once
#include<iostream>
#include "TBitField.h"
#include<string>
using namespace std;

class TSet {
private:
	int unisize;
	TBitField tb;
public:
	TSet(int _unisize = 0) {
		unisize = _unisize;
		tb = TBitField(unisize);
	}
	TSet(const TSet& tmp) {
		unisize = tmp.unisize;
		tb = tmp.tb;
	}
	~TSet() {};
	TSet operator=(TSet tmp) {

		tb = tmp.tb;
		unisize = tmp.unisize;
		return *this;
	}
	void add(int numb) {
		if (numb > 0 && numb <= unisize) {
			tb.add(numb);
		}
	}
	void del(int numb) {
		tb.del(numb);
	}

	TSet operator|(TSet tmp) {
		TSet res(*this);
		if (unisize == tmp.unisize) {
			res.tb = res.tb | tmp.tb;
		}
		return res;
	}

	TSet operator&(TSet tmp) {
		TSet res(*this);
		if (unisize == tmp.unisize) {
			res.tb = res.tb & tmp.tb;
		}
		return res;
	}

	TSet operator~() {
		TSet res(*this);
		res.tb = ~res.tb;
		return res;
	}

	std::string TSetToString() {
		return tb.TBToString(unisize);
	}
};
