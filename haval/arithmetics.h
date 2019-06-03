#pragma once

#include <bitset>

#include "defines_tables.h"

template<class ... sizes> size_t sum() { return 0; }
template<class ... sizes> size_t sum(size_t t) { return t; }
template<class ... sizes> size_t sum(size_t t, sizes ... sz) { return t + sum(sz ...); }
/*
template<size_t N1, size_t N2>
std::bitset<N1 + N2> concatenate(std::bitset<N1> b1, std::bitset<N2> b2){
	std::bitset<N1 + N2> b;
	for (int i = 0; i < N1; ++i){
		b[i] = b1[i];
	}
	for (int i = 0; i < N2; ++i){
		b[i + N1] = b2[i];
	}
	return b;
}*/

template<size_t N, size_t Next>
void concatenate(size_t ind, std::bitset<N>& base, std::bitset<Next> next){
	for (size_t i = 0; i < Next; ++i){
		base[N - ind - Next + i] = next[i];
	}
}

template<size_t N, size_t Next, class ... Bitsets>
void concatenate(size_t ind, std::bitset<N>& base, std::bitset<Next> next, Bitsets ... bitsets){
	for (size_t i = 0; i < Next; ++i){
		base[N - ind - Next + i] = next[i];
	}
	concatenate(ind + Next, base, bitsets ...);
}

template<size_t N, class ... Bitsets>
std::bitset<N> concatenate(Bitsets ... bitsets){
	std::bitset<N> res;
	concatenate(0, res, bitsets ...);
	return res;
}

template<size_t N, size_t n1, size_t n2>
std::bitset<n2 - n1> slise(std::bitset<N> b){
	std::bitset<n2 - n1> b12;
	for (int i = n1; i < n2; ++i)
		b12[i - n1] = b[i];
	return b12;
}

template<size_t N, class T = word>
struct block{
	T* blk;// = new T[N];
	T& operator[](int i){ return blk[i]; }
	block() { blk = new T[N]; };
	block(std::initializer_list<T> list){
		int i = 0;
		blk = new T[N];
		for (auto it = list.begin(); it < list.end(); ++it, ++i){ blk[i] = *it; }
	}
	block(T w[N]){
		blk = new T[N];
		for (int i = 0; i < N; ++i){
			blk[i] = w[i];
		}
	}
	void operator = (T w[N]){
		for (int i = 0; i < N; ++i){
			blk[i] = w[i];
		}
	}
	void operator = (block<N> b){
		for (int i = 0; i < N; ++i){
			blk[i] = b.blk[i];
		}
	}
};

template<size_t N>
void prints(block<N> b){
	for (int i = 0; i < N; ++i){
		printf("%x%c", b.blk[i], ' ');
	}
	std::cout << std::endl;
}

typedef block<8> block_8;
typedef block<32> block_32;

template<class T>
struct list_s{
	list_s() : data(nullptr), size(0), alloc_(0) {}
	/*list_s(initializer_list<T> list) {
		int size_ = list.size();
		data = new T[size_];
		int i = 0;
		for (auto it = list.begin(); it != list.end(); ++it, ++i) data[i] = *it;
		size = size_;
		alloc_ = size_;
	}*/
	~list_s(){ delete[] data; }
	void push_back(T t){
		if (data == nullptr) {
			data = new T[1];
			alloc_ = 1;
			size = 1;
			return;
		}
		if (alloc_ > size){
			data[size] = t;
			++size;
		}
		else{
			T* buf = new T[size];
			copy_tf(buf, data, size);
			alloc_ *= 2;
			delete[] data;
			data = new T[alloc_];
			copy_tf(data, buf, size);
			data[size] = t;
			++size;
			delete[] buf;
		}
	}
	T operator [](int i){ return data[i]; }
	T* data;
	size_t size;
	size_t alloc_;
};

struct big_integer{
	big_integer(std::string);
	static const int base;
	list_s<char> digits;
};

big_integer::big_integer(std::string str){
	size_t len = str.length();
	
}
/*
word ROT(word wd, int s){
	return (wd >> s | wd << (32 - s));
}*/

template<class ... Args>
word bit_wise_mod2_mul(word w1, Args ... args){
	std::bitset<8 * sizeof(word)> b1(w1);
	std::bitset<8 * sizeof(word)> b2(bit_wise_mod2_mul(args ...));
	return (b1 & b2).to_ulong();
}

template<size_t N>
block<N> word_wise_2p32_mod_sum(block<N> b1, block<N> b2){
	block<N> res;
	for (int i = 0; i < N; ++i){
		res[i] = (b1[i] + b2[i]) & 0xffff;
	}
	return res;
}

block<4, char> word_to_bytes(word w){
	block<4, char> b;
	b[0] = (w >> 24) & 0xff;
	b[1] = (w >> 16) & 0xff;
	b[2] = (w >> 8) & 0xff;
	b[3] = w & 0xff;

	return b;
}

const char* constc(char* s){
	char* ss = new char[strlen(s) + 1];
	for (int i = 0; i < strlen(s); ++i) ss[i] = s[i];
	ss[strlen(s)] = '\0';
	return ss;
}
