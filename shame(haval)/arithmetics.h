#pragma once

#include <bitset>

typedef unsigned long int word;

#define INT2POW32 4294967296
#define INT2POW24 16777216
#define INT2POW16 65536
#define INT2POW8  256

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
}

template<size_t N, size_t n1, size_t n2>
std::bitset<n2 + n1> slise(std::bitset<N> b){
	std::bitset<n2 + n1> b12;
	for (int i = n1; i < n2; ++i)
		b12[i] = b[i];
	return b12;
}

word bytes_to_word(char b1, char b2, char b3, char b4){
	return b4 + b3 * INT2POW8 + b2 * INT2POW16 + b3 * INT2POW24;
}

template<size_t N>
struct block{
	word* blk = new word[N];
	word& operator[](int i){ return blk[i]; }
	block() = default;
	block(std::initializer_list<word> list){
		int i = 0;
		for (auto it = list.begin(); it < list.end(); ++it, ++i){ blk[i] = *it; }
	}
	block(word w[N]){
		for (int i = 0; i < N; ++i){
			blk[i] = w[i];
		}
	}
	void operator = (word w[N]){
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
	cout << endl;
}

typedef block<8> block_8;
typedef block<32> block_32;
/*
template<size_t N>
block<N> operator + (block<N> &b1, block<N> &b2){
	block<N> ret;
	for (int i = 0; i < N; ++i){
		ret.blk[i] = (b1.blk[i] + b2.blk[i]) % 2;
	}
	return ret;
}*/

template<class T>
void copy_tf(T* to, T* from, int n){
	for (int i = 0; i < n; ++i){
		to[i] = from[i];
	}
}

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

word ROT(word wd, int s){
	std::bitset<4> b(wd), lpart, rpart;
	lpart = b >> s;
	rpart = b << 4 - s;
	return (lpart | rpart).to_ulong();
}

word bit_wise_mod2_sum(){
	return 0;
}

word bit_wise_mod2_sum(word w){
	return w;
}

word bit_wise_mod2_sum(word w1, word w2){
	std::bitset<8 * sizeof(word)> b1(w1);
	std::bitset<8 * sizeof(word)> b2(w2);
	return (b1 ^ b2).to_ulong();
}

template<class ... Args>
word bit_wise_mod2_sum(word w1, Args ... args){
	std::bitset<8 * sizeof(word)> b1(w1);
	std::bitset<8 * sizeof(word)> b2(bit_wise_mod2_sum(args ...));
	return (b1 ^ b2).to_ulong();
}

word bit_wise_mod2_mul(word w1, word w2){
	std::bitset<8 * sizeof(word)> b1(w1);
	std::bitset<8 * sizeof(word)> b2(w2);
	return (b1 & b2).to_ulong();
}

template<class ... Args>
word bit_wise_mod2_mul(word w1, Args ... args){
	std::bitset<8 * sizeof(word)> b1(w1);
	std::bitset<8 * sizeof(word)> b2(bit_wise_mod2_mul(args ...));
	return (b1 & b2).to_ulong();
}