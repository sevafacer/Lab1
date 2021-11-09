#pragma once
#include <iostream>
#include <string>
using namespace std;

class TBitField {
private:
	unsigned int* mem;
	int size;
	int getBit(long long int numb) {
		return(numb - 1) % (8 * sizeof(unsigned int));
	}
	int getNumbMem(long long int numb) {
		return(numb - 1) / (8 * sizeof(unsigned int));
	}
public:
	TBitField(int unisize = 0) {
		size = unisize / (8 * sizeof(int)) + 1;
		mem = new unsigned int[size] {0};
	}
	~TBitField() {
		delete[]mem;
	}
	TBitField(const TBitField& tmp) {
		size = tmp.size;
		mem = new unsigned int[size];
		for (int i = 0; i < size; i++) {
			mem[i] = tmp.mem[i];
		}
	}
	TBitField operator=(const TBitField tmp) {
		if (this == &tmp) {
			return *this;
		}
		delete[]mem;
		size = tmp.size;
		mem = new unsigned int[size];
		for (int i = 0; i < size; i++) {
			mem[i] = tmp.mem[i];
		}
		return *this;
	}
	void add(int numb) {
		int k = getNumbMem(numb);
		int i = getBit(numb);
		if (k < size)
			mem[k] = mem[k] | (1 << i);
	}
	std::string TBToString(int unisize) {
		std::string str = "";
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < sizeof(unsigned int) * 8; j++) {
				if ((mem[i] & (1 << j)) > 0) {
					int k = i * sizeof(unsigned int) * 8 + j + 1;
					if (k <= unisize) {
						str += std::to_string(k) + " ";
					}
				}
			}
		} return str;
	}
	void del(int numb) {
		int k = getNumbMem(numb);
		int i = getBit(numb);
		mem[k] = mem[k] & (~(1 << i));
	}
	TBitField operator~() {
		TBitField res(*this);
		for (int i = 0; i < size; i++) {
			res.mem[i] = ~res.mem[i];
		} return res;
	}
	TBitField operator|(TBitField tmp) {
		TBitField res(*this);
		for (int i = 0; i < size; i++) {
			res.mem[i] = mem[i] | tmp.mem[i];
		}return res;
	}
	TBitField operator&(TBitField tmp) {
		TBitField res(*this);
		for (int i = 0; i < size; i++) {
			res.mem[i] = mem[i] & tmp.mem[i];
		}return res;
	}
};

