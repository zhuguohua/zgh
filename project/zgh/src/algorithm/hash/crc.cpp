/**
 * @author   ªØ Æ
 * @email     530894516@qq.com
 * @date       2021-04-25
  *
 *  @detail    crcº∆À„°£crc16 crc32
  *
 */

#include "hash-library/crc32.h"
#include "libcrc/include/checksum.h"
#include "crc.h"

namespace api202104
{
	unsigned long crc8(const void *src, unsigned long size) {
		uint8_t tmp = ::crc_8((const unsigned char *)src, (size_t)size);
		return tmp;
	}

	unsigned long crc16(const void *src, unsigned long size) {
		uint16_t tmp = ::crc_16((const unsigned char *)src, (size_t)size);
		return tmp;
	}

	unsigned long crc32(const void *src, unsigned long size) {
		unsigned char buff[4] = { 0 };
		CRC32 tmp;
		tmp(src, size);
		tmp.getHash(buff);
		unsigned long ul = 0;
		ul |= buff[0] << 24;
		ul |= buff[1] << 16;
		ul |= buff[2] << 8;
		ul |= buff[3];
		return ul;
	}
}
