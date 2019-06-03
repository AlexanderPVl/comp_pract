#pragma once

#define VERSION 1

#define INT2POW32 4294967296
#define INT2POW24 16777216
#define INT2POW16 65536
#define INT2POW8  256

#define blk_offset(blk_ind, blk_cnt) (blk_cnt - blk_ind - 1) * 32 * sizeof(word)
#define ROT(wd, s) ((wd >> s) | (wd << (32 - s)))

#define copy_tf(to, from, n) for (size_t i = 0; i < n; ++i) to[i] = from[i]

#define F1(x6, x5, x4, x3, x2, x1, x0) (((x1) & ((x0) ^ (x4))) ^ ((x2) & (x5)) ^ ((x3) & (x6)) ^ (x0))
#define F2(x6, x5, x4, x3, x2, x1, x0) (((x2)& (((x1)& ~(x3)) ^ ((x4)& (x5)) ^ (x6) ^ (x0))) ^ ((x4)& ((x1) ^ (x5))) ^ ((x3 & (x5)) ^ (x0)))
#define F3(x6, x5, x4, x3, x2, x1, x0) (((x3) & (((x1) & (x2)) ^ (x6) ^ (x0))) ^ ((x1) & (x4)) ^ ((x2) & (x5)) ^ (x0))
#define F4(x6, x5, x4, x3, x2, x1, x0) (((x3) & (((x1) & (x2)) ^ ((x4) | (x6)) ^ (x5))) ^ ((x4) & ((~(x2) & (x5)) ^ (x1) ^ (x6) ^ (x0))) ^ ((x2) & (x6)) ^ (x0))
#define F5(x6, x5, x4, x3, x2, x1, x0) (((x0) & ~(((x1) & (x2) & (x3)) ^ (x5)))	^ ((x1) & (x4)) ^ ((x2) & (x5)) ^ ((x3) & (x6)))

#define F_31(x6, x5, x4, x3, x2, x1, x0) F1(x1, x0, x3, x5, x6, x2, x4)
#define F_32(x6, x5, x4, x3, x2, x1, x0) F2(x4, x2, x1, x0, x5, x3, x6)
#define F_33(x6, x5, x4, x3, x2, x1, x0) F3(x6, x1, x2, x3, x4, x5, x0)

#define F_41(x6, x5, x4, x3, x2, x1, x0) F1(x2, x6, x1, x4, x5, x3, x0)
#define F_42(x6, x5, x4, x3, x2, x1, x0) F2(x3, x5, x2, x0, x1, x6, x4)
#define F_43(x6, x5, x4, x3, x2, x1, x0) F3(x1, x4, x3, x6, x0, x2, x5)
#define F_44(x6, x5, x4, x3, x2, x1, x0) F4(x6, x4, x0, x5, x2, x1, x3)

#define F_51(x6, x5, x4, x3, x2, x1, x0) F1(x3, x4, x1, x0, x5, x2, x6)
#define F_52(x6, x5, x4, x3, x2, x1, x0) F2(x6, x2, x1, x0, x3, x4, x5)
#define F_53(x6, x5, x4, x3, x2, x1, x0) F3(x2, x6, x0, x4, x3, x1, x5)
#define F_54(x6, x5, x4, x3, x2, x1, x0) F4(x1, x5, x3, x2, x0, x4, x6)
#define F_55(x6, x5, x4, x3, x2, x1, x0) F5(x2, x5, x0, x6, x4, x3, x1)

typedef unsigned long int word;

word bytes_to_word(int b1, int b2, int b3, int b4){
	return (b1 << 24 | b2 << 16 | b3 << 8 | b4);
}

static int ord2[] = {
	5, 14, 26, 18, 11, 28, 7, 16,
	0, 23, 20, 22, 1, 10, 4, 8,
	30, 3, 21, 9, 17, 24, 29, 6,
	19, 12, 15, 13, 2, 25, 31, 27
};

static int ord3[] = {
	19, 9, 4, 20, 28, 17, 8, 22,
	29, 14, 25, 12, 24, 30, 16, 26,
	31, 15, 7, 3, 1, 0, 18, 27,
	13, 6, 21, 10, 23, 11, 5, 2
};
static int ord4[] = {
	24, 4, 0, 14, 2, 7, 28, 23,
	26, 6, 30, 20, 18, 25, 19, 3,
	22, 11, 31, 21, 8, 27, 12, 9,
	1, 29, 5, 15, 17, 10, 16, 13
};
static int ord5[] = {
	27, 3, 21, 26, 17, 11, 20, 29,
	19, 0, 12, 7, 13, 8, 31, 10,
	5, 9, 14, 30, 18, 6, 28, 24,
	2, 23, 16, 22, 4, 1, 25, 15
};

static word K[4][32] = {
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