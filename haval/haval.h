#pragma once

#include <math.h>

#include "arithmetics.h"

block_8 H1(block_8 E0, block_32 B, int PASS){
	word P, r, R;
	word T0 = E0[0], T1 = E0[1], T2 = E0[2], T3 = E0[3], T4 = E0[4], T5 = E0[5], T6 = E0[6], T7 = E0[7];
	for (int i = 0; i < 32; ++i){
		if (PASS == 3){
			//P = F1(T2, T3, T0, T4, T1, T6, T5);
			P = F_31(T6, T5, T4, T3, T2, T1, T0);
		}
		if (PASS == 4){
			//P = F1(T5, T2, T3, T1, T6, T4, T0);
			P = F_41(T6, T5, T4, T3, T2, T1, T0);
		}
		if (PASS == 5){
			//P = F1(T0, T2, T5, T6, T1, T4, T3);
			P = F_51(T6, T5, T4, T3, T2, T1, T0);
		}
		r = (ROT(P, 7) + ROT(T7, 11)) & 0xffff;
		R = (r + B[i]) & 0xffff;
		T7 = T6, T6 = T5, T5 = T4, T4 = T3, T3 = T2, T2 = T1, T1 = R;
	}
	return block_8({ T7, T6, T5, T4, T3, T2, T1, T0 });
}

block_8 H2(block_8 E1, block_32 B, int PASS){
	word P, r1, r2, R;
	word T0 = E1[0], T1 = E1[1], T2 = E1[2], T3 = E1[3], T4 = E1[4], T5 = E1[5], T6 = E1[6], T7 = E1[7];
	for (int i = 0; i < 32; ++i){
		if (PASS == 3){
			//P = F2(T0, T2, T6, T1, T5, T4, T3);
			P = F_32(T6, T5, T4, T3, T2, T1, T0);
		}
		if (PASS == 4){
			//P = F2(T1, T5, T0, T6, T4, T2, T3);
			P = F_42(T6, T5, T4, T3, T2, T1, T0);
		}
		if (PASS == 5){
			//P = F2(T6, T0, T1, T2, T5, T4, T3);
			P = F_52(T6, T5, T4, T3, T2, T1, T0);
		}
		r1 = (ROT(P, 7) + ROT(T7, 11)) & 0xffff;
		r2 = (r1 + B[ord2[i]]) & 0xffff;
		R = (r2 + K[0][i]) & 0xffff;
		T7 = T6, T6 = T5, T5 = T4, T4 = T3, T3 = T2, T2 = T1, T1 = T0, T0 = R;
	}
	return block_8({ T7, T6, T5, T4, T3, T2, T1, T0 });
}

block_8 H3(block_8 E1, block_32 B, int PASS){
	word P, r1, r2, R;
	word T0 = E1[0], T1 = E1[1], T2 = E1[2], T3 = E1[3], T4 = E1[4], T5 = E1[5], T6 = E1[6], T7 = E1[7];
	for (int i = 0; i < 32; ++i){
		if (PASS == 3){
			//P = F3(T6, T1, T2, T3, T4, T5, T3);
			P = F_33(T6, T5, T4, T3, T2, T1, T0);
		}
		if (PASS == 4){
			//P = F3(T3, T0, T0, T5, T1, T6, T2);
			P = F_43(T6, T5, T4, T3, T2, T1, T0);
		}
		if (PASS == 5){
			//P = F3(T5, T0, T3, T2, T6, T1, T4);
			P = F_53(T6, T5, T4, T3, T2, T1, T0);
		}
		r1 = (ROT(P, 7) + ROT(T7, 11)) & 0xffff;
		r2 = (r1 + B[ord3[i]]) & 0xffff;
		R = (r2 + K[1][i]) & 0xffff;
		T7 = T6, T6 = T5, T5 = T4, T4 = T3, T3 = T2, T2 = T1, T1 = T0, T0 = R;
	}
	return block_8({ T7, T6, T5, T4, T3, T2, T1, T0 });
}

block_8 H4(block_8 E1, block_32 B, int PASS){
	word P, r1, r2, R;
	word T0 = E1[0], T1 = E1[1], T2 = E1[2], T3 = E1[3], T4 = E1[4], T5 = E1[5], T6 = E1[6], T7 = E1[7];
	for (int i = 0; i < 32; ++i){
		if (PASS == 4){
			//P = F4(T6, T3, T5, T0, T2, T1, T4);
			P = F_44(T6, T5, T4, T3, T2, T1, T0);
		}
		if (PASS == 5){
			//P = F4(T0, T5, T1, T4, T3, T6, T2);
			P = F_54(T6, T5, T4, T3, T2, T1, T0);
		}
		r1 = (ROT(P, 7) + ROT(T7, 11)) & 0xffff;
		r2 = (r1 + B[ord4[i]]) & 0xffff;
		R = (r2 + K[2][i]) & 0xffff;
		T7 = T6, T6 = T5, T5 = T4, T4 = T3, T3 = T2, T2 = T1, T1 = T0, T0 = R;
	}
	return block_8({ T7, T6, T5, T4, T3, T2, T1, T0 });
}

block_8 H5(block_8 E1, block_32 B, int PASS){
	word P, r1, r2, R;
	word T0 = E1[0], T1 = E1[1], T2 = E1[2], T3 = E1[3], T4 = E1[4], T5 = E1[5], T6 = E1[6], T7 = E1[7];
	for (int i = 0; i < 32; ++i){
		if (PASS == 5){
			//P = F4(T3, T5, T2, T1, T6, T0, T4);
			P = F_55(T6, T5, T4, T3, T2, T1, T0);
		}
		r1 = (ROT(P, 7) + ROT(T7, 11)) & 0xffff;
		r2 = (r1 + B[ord5[i]]) & 0xffff;
		R = (r2 + K[3][i]) & 0xffff;
		T7 = T6, T6 = T5, T5 = T4, T4 = T3, T3 = T2, T2 = T1, T1 = T0, T0 = R;
	}
	return block_8({ T7, T6, T5, T4, T3, T2, T1, T0 });
}

block_8 H(block_8 D0, block_32 B, int PASS){
	block_8 E0, E1, E2, E3, E4, E5, res;
	E0 = D0;
	E1 = H1(E0, B, PASS);
	E2 = H2(E1, B, PASS);
	E3 = H3(E2, B, PASS);
	if (PASS == 4 || PASS == 5)
		E4 = H4(E3, B, PASS);
	if (PASS == 5)
		E5 = H5(E4, B, PASS);
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

void haval(const char* message, int PASS, int version, int digest_length){
	unsigned int bytecnt = strlen(message);
	unsigned int extrabit;
	unsigned int offset = ((bytecnt % 1024) * 8) % 1024;
	if (offset > 944) extrabit = 944 + 1024 - offset;
	else extrabit = 944 - offset;

	block_8 D0 = { 0x243F6A88, 0x85A308D3, 0x13198A2E, 0x03707344, 0xA4093822, 0x299F31D0, 0x082EFA98, 0xEC4E6C89 };

	block_32 Bi;
	word blk[32];

	//size_t blk_cnt = bytecnt / 128 + 1;
	size_t blk_cnt = (bytecnt * 8 + extrabit + 80) / 1024;

	for (int i = 0; i < blk_cnt - 1; ++i){
		for (int k = 32; k > 0; --k){
			Bi[k] = bytes_to_word(message[blk_offset(i, blk_cnt) + 4 * k - 4], message[blk_offset(i, blk_cnt) + 4 * k - 3], message[blk_offset(i, blk_cnt) + 4 * k - 2], message[blk_offset(i, blk_cnt) + 4 * k - 1]);
		}
		D0 = H(D0, Bi, PASS);
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
	Bn[118] = bytecnt & 0xf, Bn[119] = bytecnt & 0xff - bytecnt & 0xf;
	Bn[120] = bytecnt & 0xfff - bytecnt & 0xff, Bn[121] = bytecnt & 0xffff - bytecnt & 0xfff;
	Bn[122] = 0, Bn[123] = 0, Bn[124] = 0, Bn[125] = 0;
	Bn[126] = slise<10, 0, 8>(std::bitset<10>(digest_length)).to_ulong();
	Bn[127] = concatenate<8>(std::bitset<3>(version), std::bitset<3>(PASS), slise<10, 8, 10>(std::bitset<10>(digest_length))).to_ulong();
	for (int i = 0; i < 32; ++i)
		Bi[i] = bytes_to_word(Bn[4 * i], Bn[4 * i + 1], Bn[4 * i + 2], Bn[4 * i + 3]);
	D0 = H(D0, Bi, PASS);
	//char* s = new char[1];
	char* s = (char*)malloc(256);
	size_t l = 0;
	s[0] = '\0';


	for (int i = 0; i < 7; ++i){
		l += sprintf(s + l, "%x", D0[i]);
	}

	std::cout << s << std::endl;
	//prints(D0);
}
