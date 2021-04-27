#include "../src/zgh.h"
#include "testzgh.h"

void testbase64 () {
	std::string raw = "12345678";
	std::string enc = zgh::base64::encodeStr(raw);
	std::string dec = zgh::base64::decodeStr(enc);
	
	// ∂œµ„”√
	int a = 0;
	a = 1;
}

void testzgh() {
	testbase64();
}