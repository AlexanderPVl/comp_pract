#include <iostream>

#include <fstream>

#include "haval.h"

using namespace std;

int main(){
	unsigned int PASS = 5;
	unsigned int digest_leng = 256;

	const char* sample_message1 = "sample message sample message sample message sample message sample message sample message sample message sample message999933333 58650thero0ighgifjeriuj erjhg s9drughs e9ru 90er7uh w0e489hf 0q9uwerhg 09urh 0e9urgh 0weai9rugh w0e9urgh a0s9urgh a0gh soidrugh soirudgh ae90rugh s90ruh ";
	const char* sample_message2 = "sayple message sample message sample message sample message sample message sample message samle mesyage sample message999933333 58650thero0ighgifjeriuj erjhg s9drughs e9ru 90er7uh w0e48yhf 0q9uwerhg 09urh 0e9urgh 0weai9rugh w0e9urgh a0s9urgh a0gh soidrugh soirudgh ae90rugh s90ruh ";
	const char* sample_message3 = "123io 8943";
	const char* sample_message4 = "123io 8843";
	const char* sample_message5 = "123io 899943";


	haval(sample_message1, PASS, VERSION, digest_leng);
	haval(sample_message2, PASS, VERSION, digest_leng);
	haval(sample_message3, PASS, VERSION, digest_leng);
	haval(sample_message4, PASS, VERSION, digest_leng);
	haval(sample_message5, PASS, VERSION, digest_leng);

	return 0;
}
