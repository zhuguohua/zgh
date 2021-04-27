/**
 * @author   ªØ Æ
 * @email     530894516@qq.com
 * @date       2021-04-25
  *
 *  @detail    hashº∆À„°£
  *
 */

#include "hash-library/md5.h"
#include "hash-library/sha1.h"
#include "hash-library/sha3.h"
#include "hash-library/sha256.h"
#include "hash.h"

namespace api202104
{
	std::string md5(const void *src, unsigned long len) {
		::MD5 tmp;
		return tmp(src, len);     // std::string
	}

	std::string hash(const void *src, unsigned long len) {
		return "";
	}

	std::string sha1(const void *src, unsigned long len) {
		::SHA1 tmp;
		return tmp(src, len);     // std::string
	}

	std::string sha3(const void *src, unsigned long len) {
		::SHA3 tmp;
		return tmp(src, len);     // std::string
	}

	std::string sha256(const void *src, unsigned long len) {
		::SHA256 tmp;
		return tmp(src, len);     // std::string
	}

}






