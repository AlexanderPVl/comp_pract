#pragma once

#include <math.h>

#include "arithmetics.h"

#define VERSION 1

#define F1(x6, x5, x4, x3, x2, x1, x0) (((x1) & ((x0) ^ (x4))) ^ ((x2) & (x5)) ^ ((x3) & (x6)) ^ (x0))
#define F2(x6, x5, x4, x3, x2, x1, x0) (((x2)& (((x1)& ~(x3)) ^ ((x4)& (x5)) ^ (x6) ^ (x0))) ^ ((x4)& ((x1) ^ (x5))) ^ ((x3 & (x5)) ^ (x0)))
#define F3(x6, x5, x4, x3, x2, x1, x0) (((x3) & (((x1) & (x2)) ^ (x6) ^ (x0))) ^ ((x1) & (x4)) ^ ((x2) & (x5)) ^ (x0))
#define F4(x6, x5, x4, x3, x2, x1, x0) (((x3) & (((x1) & (x2)) ^ ((x4) | (x6)) ^ (x5))) ^ ((x4) & ((~(x2) & (x5)) ^ (x1) ^ (x6) ^ (x0))) ^ ((x2) & (x6)) ^ (x0))
#define F5(x6, x5, x4, x3, x2, x1, x0) (((x0) & ~(((x1) & (x2) & (x3)) ^ (x5)))	^ ((x1) & (x4)) ^ ((x2) & (x5)) ^ ((x3) & (x6)))

/*
word K(int i, int j){
	word arr[4][32] = {
			{
				0x452821E6, 0x38D01377, 0xBE5466CF, 0x34E90C6C, 0xC0AC29B7, 0xC97C50DD, 0x3F84D5B5, 0xB5470917,
				0x9216D5D9, 0x8979FB1B, 0xD1310BA6, 0x98DFB5AC, 0x2FFD72DB, 0xD01ADFB7, 0xB8E1AFED, 0x6A267E96,
				0xBA7C9045, 0xF12C7F99, 0x24A19947, 0xB3916CF7, 0x0801F2E2, 0x858EFC16, 0x636920D8, 0x71574E69,
				0xA458FEA3, 0xF4933D7E, 0x0D95748F, 0x728EB658, 0x718BCD58, 0x82154AEE, 0x7B54A41D, 0xC25A59B5
			},
			{
				0x9C30D539, 0x2AF26013, 0xC5D1B023, 0x286085F0, 0xCA417918, 0xB8DB38EF, 0x8E79DCB0, 0x603A180E,
				0x6C9E0E8B, 0xB01E8A3E, 0xD71577C1, 0xBD314B27, 0x78AF2FDA, 0x55605C60, 0xE65525F3, 0xAA55AB94,
				0x57489862, 0x63E81440, 0x55CA396A, 0x2AAB10B6, 0xB4CC5C34, 0x1141E8CE, 0xA15486AF, 0x7C72E993,
				0xB3EE1411, 0x636FBC2A, 0x2BA9C55D, 0x741831F6, 0xCE5C3E16, 0x9B87931E, 0xAFD6BA33, 0x6C24CF5C
			},
			{
				0x7A325381, 0x28958677, 0x3B8F4898, 0x6B4BB9AF, 0xC4BFE81B, 0x66282193, 0x61D809CC, 0xFB21A991,
				0x487CAC60, 0x5DEC8032, 0xEF845D5D, 0xE98575B1, 0xDC262302, 0xEB651B88, 0x23893E81, 0xD396ACC5,
				0x0F6D6FF3, 0x83F44239, 0x2E0B4482, 0xA4842004, 0x69C8F04A, 0x9E1F9B5E, 0x21C66842, 0xF6E96C9A,
				0x670C9C61, 0xABD388F0, 0x6A51A0D2, 0xD8542F68, 0x960FA728, 0xAB5133A3, 0x6EEF0B6C, 0x137A3BE4
			},
			{
				0xBA3BF050, 0x7EFB2A98, 0xA1F1651D, 0x39AF0176, 0x66CA593E, 0x82430E88, 0x8CEE8619, 0x456F9FB4,
				0x7D84A5C3, 0x3B8B5EBE, 0xE06F75D8, 0x85C12073, 0x401A449F, 0x56C16AA6, 0x4ED3AA62, 0x363F7706,
				0x1BFEDF72, 0x429B023D, 0x37D0D724, 0xD00A1248, 0xDB0FEAD3, 0x49F1C09B, 0x075372C9, 0x80991B7B,
				0x25D479D8, 0xF6E8DEF7, 0xE3FE501A, 0xB6794C3B, 0x976CE0BD, 0x04C006BA, 0xC1A94FB6, 0x409F60C4
			}
	};
	return arr[i - 2][j];
}*/
/*
word F1(word X6, word X5, word X4, word X3, word X2, word X1, word X0){
	word m1 = bit_wise_mod2_mul(X1, X4);
	word m2 = bit_wise_mod2_mul(X2, X5);
	word m3 = bit_wise_mod2_mul(X3, X6);
	word m4 = bit_wise_mod2_mul(X0, X1);
	return bit_wise_mod2_sum(m1, m2, m3, m4);
}

word F2(word X6, word X5, word X4, word X3, word X2, word X1, word X0){
	word m1 = bit_wise_mod2_mul(X1, X2, X3);
	word m2 = bit_wise_mod2_mul(X2, X4, X5);
	word m3 = bit_wise_mod2_mul(X1, X2);
	word m4 = bit_wise_mod2_mul(X1, X4);
	word m5 = bit_wise_mod2_mul(X2, X6);
	word m6 = bit_wise_mod2_mul(X3, X5);
	word m7 = bit_wise_mod2_mul(X4, X5);
	word m8 = bit_wise_mod2_mul(X0, X2);
	return bit_wise_mod2_sum(m1, m2, m3, m4, m5, m6, m7, m8);
}

word F3(word X6, word X5, word X4, word X3, word X2, word X1, word X0){
	word m1 = bit_wise_mod2_mul(X1, X2, X3);
	word m2 = bit_wise_mod2_mul(X1, X4);
	word m3 = bit_wise_mod2_mul(X2, X5);
	word m4 = bit_wise_mod2_mul(X3, X6);
	word m5 = bit_wise_mod2_mul(X0, X3);
	return bit_wise_mod2_sum(m1, m2, m3, m4, m5);
}

word F4(word X6, word X5, word X4, word X3, word X2, word X1, word X0){
	word m1 = bit_wise_mod2_mul(X1, X2, X3);
	word m2 = bit_wise_mod2_mul(X2, X4, X5);
	word m3 = bit_wise_mod2_mul(X3, X4, X6);
	word m4 = bit_wise_mod2_mul(X1, X4);
	word m5 = bit_wise_mod2_mul(X2, X6);
	word m6 = bit_wise_mod2_mul(X3, X4);
	word m7 = bit_wise_mod2_mul(X3, X5);
	word m8 = bit_wise_mod2_mul(X3, X6);
	word m9 = bit_wise_mod2_mul(X4, X5);
	word m10 = bit_wise_mod2_mul(X4, X6);
	word m11 = bit_wise_mod2_mul(X0, X4);
	return bit_wise_mod2_sum(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11);
}

word F5(word X6, word X5, word X4, word X3, word X2, word X1, word X0){
	word m1 = bit_wise_mod2_mul(X1, X4);
	word m2 = bit_wise_mod2_mul(X2, X5);
	word m3 = bit_wise_mod2_mul(X3, X6);
	word m4 = bit_wise_mod2_mul(X0, X1, X2, X3);
	word m5 = bit_wise_mod2_mul(X0, X5);
	return bit_wise_mod2_sum(m1, m2, m3, m4, m5);
}*/

unsigned int ord2(int i){
	int table[32] = { 5, 14, 26, 18, 11, 7, 16, 0, 23, 20, 22, 1, 10, 4, 8, 30, 3, 21, 9, 17, 24, 29, 6, 19, 12, 15, 13, 2, 25, 31, 27 };
	return table[i];
}
unsigned int ord3(int i){
	int table[32] = { 19, 9, 4, 20, 28, 17, 8, 22, 29, 14, 25, 12, 24, 30, 16, 26, 31, 15, 7, 3, 1, 0, 18, 27, 13, 6, 21, 10, 23, 11, 5, 2 };
	return table[i];
}
unsigned int ord4(int i){
	int table[32] = { 24, 4, 0, 14, 2, 7, 28, 23, 26, 6, 30, 20, 18, 25, 19, 3, 22, 11, 31, 21, 8, 27, 12, 9, 1, 29, 5, 15, 17, 10, 16, 13 };
	return table[i];
}
unsigned int ord5(int i){
	int table[32] = { 27, 3, 21, 26, 17, 11, 20, 29, 19, 0, 12, 7, 13, 8, 31, 10, 5, 9, 14, 30, 18, 6, 28, 24, 2, 23, 16, 22, 4, 1, 25, 15 };
	return table[i];
}

block_8 H1(block_8 E0, block_32 B, int PASS){
	word P, r, R;
	word T0 = E0[0], T1 = E0[1], T2 = E0[2], T3 = E0[3], T4 = E0[4], T5 = E0[5], T6 = E0[6], T7 = E0[7];
	for (int i = 0; i < 32; ++i){
		if (PASS == 3){
			P = F1(T2, T3, T0, T4, T1, T6, T5);
		}
		if (PASS == 4){
			P = F1(T5, T2, T3, T1, T6, T4, T0);
		}
		if (PASS == 5){
			P = F1(T0, T2, T5, T6, T1, T4, T3);
		}
		r = (ROT(P, 7) + ROT(T7, 11)) % INT2POW32;
		R = (r + B[i]) % INT2POW32;
		T7 = T6, T6 = T5, T5 = T4, T4 = T3, T3 = T2, T2 = T1, T1 = R;
	}
	return block_8({ T7, T6, T5, T4, T3, T2, T1, T0 });
}

block_8 H2(block_8 E1, block_32 B, int PASS, word K[4][32]){
	word P, r1, r2, R;
	word T0 = E1[0], T1 = E1[1], T2 = E1[2], T3 = E1[3], T4 = E1[4], T5 = E1[5], T6 = E1[6], T7 = E1[7];
	for (int i = 0; i < 32; ++i){
		if (PASS == 3){
			P = F2(T0, T2, T6, T1, T5, T4, T3);
		}
		if (PASS == 4){
			P = F2(T1, T5, T0, T6, T4, T2, T3);
		}
		if (PASS == 5){
			P = F2(T6, T0, T1, T2, T5, T4, T3);
		}
		r1 = (ROT(P, 7) + ROT(T7, 11)) % INT2POW32;
		r2 = (r1 + B[ord2(i)]) % INT2POW32;
		R = (r2 + K[0][i]) % INT2POW32;
		T7 = T6, T6 = T5, T5 = T4, T4 = T3, T3 = T2, T2 = T1, T1 = T0, T0 = R;
	}
	return block_8({ T7, T6, T5, T4, T3, T2, T1, T0 });
}

block_8 H3(block_8 E1, block_32 B, int PASS, word K[4][32]){
	word P, r1, r2, R;
	word T0 = E1[0], T1 = E1[1], T2 = E1[2], T3 = E1[3], T4 = E1[4], T5 = E1[5], T6 = E1[6], T7 = E1[7];
	for (int i = 0; i < 32; ++i){
		if (PASS == 3){
			P = F3(T6, T1, T2, T3, T4, T5, T3);
		}
		if (PASS == 4){
			P = F3(T3, T0, T0, T5, T1, T6, T2);
		}
		if (PASS == 5){
			P = F3(T5, T0, T3, T2, T6, T1, T4);
		}
		r1 = (ROT(P, 7) + ROT(T7, 11)) % INT2POW32;
		r2 = (r1 + B[ord3(i)]) % INT2POW32;
		R = (r2 + K[1][i]) % INT2POW32;
		T7 = T6, T6 = T5, T5 = T4, T4 = T3, T3 = T2, T2 = T1, T1 = T0, T0 = R;
	}
	return block_8({ T7, T6, T5, T4, T3, T2, T1, T0 });
}

block_8 H4(block_8 E1, block_32 B, int PASS, word K[4][32]){
	word P, r1, r2, R;
	word T0 = E1[0], T1 = E1[1], T2 = E1[2], T3 = E1[3], T4 = E1[4], T5 = E1[5], T6 = E1[6], T7 = E1[7];
	for (int i = 0; i < 32; ++i){
		if (PASS == 4){
			P = F4(T6, T3, T5, T0, T2, T1, T4);
		}
		if (PASS == 5){
			P = F4(T0, T5, T1, T4, T3, T6, T2);
		}
		r1 = (ROT(P, 7) + ROT(T7, 11)) % INT2POW32;
		r2 = (r1 + B[ord4(i)]) % INT2POW32;
		R = (r2 + K[2][i]) % INT2POW32;
		T7 = T6, T6 = T5, T5 = T4, T4 = T3, T3 = T2, T2 = T1, T1 = T0, T0 = R;
	}
	return block_8({ T7, T6, T5, T4, T3, T2, T1, T0 });
}

block_8 H5(block_8 E1, block_32 B, int PASS, word K[4][32]){
	word P, r1, r2, R;
	word T0 = E1[0], T1 = E1[1], T2 = E1[2], T3 = E1[3], T4 = E1[4], T5 = E1[5], T6 = E1[6], T7 = E1[7];
	for (int i = 0; i < 32; ++i){
		if (PASS == 5){
			P = F4(T3, T5, T2, T1, T6, T0, T4);
		}
		r1 = (ROT(P, 7) + ROT(T7, 11)) % INT2POW32;
		r2 = (r1 + B[ord5(i)]) % INT2POW32;
		R = (r2 + K[3][i]) % INT2POW32;
		T7 = T6, T6 = T5, T5 = T4, T4 = T3, T3 = T2, T2 = T1, T1 = T0, T0 = R;
	}
	return block_8({ T7, T6, T5, T4, T3, T2, T1, T0 });
}

block_8 H(block_8 D0, block_32 B, int PASS, word K[4][32]){
	block_8 E0, E1, E2, E3, E4, E5, res;
	E0 = D0;
	E1 = H1(E0, B, PASS);
	E2 = H2(E1, B, PASS, K);
	E3 = H3(E2, B, PASS, K);
	if (PASS == 4 || PASS == 5)
		E4 = H4(E3, B, PASS, K);
	if (PASS == 5)
		E5 = H5(E4, B, PASS, K);
	if (PASS == 3){
		return word_wise_2p32_mod_sum(E3, E0);
	}
	if (PASS == 4){
		return word_wise_2p32_mod_sum(E4, E0);
	}
	if (PASS == 5){
		return word_wise_2p32_mod_sum(E5, E0);
	}
}

int blk_offset(int blk_ind, int blk_cnt){
	return (blk_cnt - blk_ind - 1) * 32 * sizeof(word);
}

void haval(const char* message, int PASS, int version, int digest_length){
	unsigned int bytecnt = strlen(message);
	unsigned int extrabit;
	unsigned int offset = ((bytecnt % 1024) * 8) % 1024;
	if (offset > 944) extrabit = 944 + 1024 - offset;
	else extrabit = 944 - offset;

	block_8 D0 = { 0x243F6A88, 0x85A308D3, 0x13198A2E, 0x03707344, 0xA4093822, 0x299F31D0, 0x082EFA98, 0xEC4E6C89 };
	word K[4][32] = {
			{
				0x452821E6, 0x38D01377, 0xBE5466CF, 0x34E90C6C, 0xC0AC29B7, 0xC97C50DD, 0x3F84D5B5, 0xB5470917,
				0x9216D5D9, 0x8979FB1B, 0xD1310BA6, 0x98DFB5AC, 0x2FFD72DB, 0xD01ADFB7, 0xB8E1AFED, 0x6A267E96,
				0xBA7C9045, 0xF12C7F99, 0x24A19947, 0xB3916CF7, 0x0801F2E2, 0x858EFC16, 0x636920D8, 0x71574E69,
				0xA458FEA3, 0xF4933D7E, 0x0D95748F, 0x728EB658, 0x718BCD58, 0x82154AEE, 0x7B54A41D, 0xC25A59B5
			},
			{
				0x9C30D539, 0x2AF26013, 0xC5D1B023, 0x286085F0, 0xCA417918, 0xB8DB38EF, 0x8E79DCB0, 0x603A180E,
				0x6C9E0E8B, 0xB01E8A3E, 0xD71577C1, 0xBD314B27, 0x78AF2FDA, 0x55605C60, 0xE65525F3, 0xAA55AB94,
				0x57489862, 0x63E81440, 0x55CA396A, 0x2AAB10B6, 0xB4CC5C34, 0x1141E8CE, 0xA15486AF, 0x7C72E993,
				0xB3EE1411, 0x636FBC2A, 0x2BA9C55D, 0x741831F6, 0xCE5C3E16, 0x9B87931E, 0xAFD6BA33, 0x6C24CF5C
			},
			{
				0x7A325381, 0x28958677, 0x3B8F4898, 0x6B4BB9AF, 0xC4BFE81B, 0x66282193, 0x61D809CC, 0xFB21A991,
				0x487CAC60, 0x5DEC8032, 0xEF845D5D, 0xE98575B1, 0xDC262302, 0xEB651B88, 0x23893E81, 0xD396ACC5,
				0x0F6D6FF3, 0x83F44239, 0x2E0B4482, 0xA4842004, 0x69C8F04A, 0x9E1F9B5E, 0x21C66842, 0xF6E96C9A,
				0x670C9C61, 0xABD388F0, 0x6A51A0D2, 0xD8542F68, 0x960FA728, 0xAB5133A3, 0x6EEF0B6C, 0x137A3BE4
			},
			{
				0xBA3BF050, 0x7EFB2A98, 0xA1F1651D, 0x39AF0176, 0x66CA593E, 0x82430E88, 0x8CEE8619, 0x456F9FB4,
				0x7D84A5C3, 0x3B8B5EBE, 0xE06F75D8, 0x85C12073, 0x401A449F, 0x56C16AA6, 0x4ED3AA62, 0x363F7706,
				0x1BFEDF72, 0x429B023D, 0x37D0D724, 0xD00A1248, 0xDB0FEAD3, 0x49F1C09B, 0x075372C9, 0x80991B7B,
				0x25D479D8, 0xF6E8DEF7, 0xE3FE501A, 0xB6794C3B, 0x976CE0BD, 0x04C006BA, 0xC1A94FB6, 0x409F60C4
			}
	};

	block_32 Bi;
	word blk[32];

	size_t blk_cnt = bytecnt / 128 + 1;

	for (int i = 0; i < blk_cnt - 1; ++i){
		for (int k = 32; k > 0; --k){
			Bi[k] = bytes_to_word(message[blk_offset(i, blk_cnt) + 4 * k - 4], message[blk_offset(i, blk_cnt) + 4 * k - 3], message[blk_offset(i, blk_cnt) + 4 * k - 2], message[blk_offset(i, blk_cnt) + 4 * k - 1]);
		}
		D0 = H(D0, Bi, PASS, K);
	}
	char Bn[128];
	for (int i = 0; i < offset / 8; ++i) {
		Bn[i] = message[offset / 8 - i - 1];
	}
	if (extrabit != 0)
		Bn[offset / 8] = 1;
	for (int i = 0; i < extrabit / 8 - 1; ++i){
		Bn[offset / 8 + i] = 0;
	}
	Bn[118] = bytecnt % INT2POW8, Bn[119] = bytecnt % INT2POW16 - bytecnt % INT2POW16;;
	Bn[120] = bytecnt % INT2POW24 - bytecnt % INT2POW16, Bn[121] = bytecnt % INT2POW32 - bytecnt % INT2POW24;
	Bn[122] = 0, Bn[123] = 0, Bn[124] = 0, Bn[125] = 0;
	Bn[126] = slise<10, 0, 8>(std::bitset<10>(digest_length)).to_ulong();
	Bn[127] = concatenate(concatenate(std::bitset<3>(version), std::bitset<3>(PASS)), slise<10, 8, 10>(std::bitset<10>(digest_length))).to_ulong();
	Bn[126] = concatenate(concatenate(std::bitset<10>(digest_length), std::bitset<3>(PASS)), std::bitset<3>(version)).to_ulong();
	for (int i = 0; i < 32; ++i)
		Bi[i] = bytes_to_word(Bn[4 * i], Bn[4 * i + 1], Bn[4 * i + 2], Bn[4 * i + 3]);
	D0 = H(D0, Bi, PASS, K);
	prints(D0);
}
