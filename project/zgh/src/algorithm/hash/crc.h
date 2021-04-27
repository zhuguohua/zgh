/**
 * @author   ��ʮ
 * @email     530894516@qq.com
 * @date       2021-04-25
  *
 *  @detail    crc���㡣crc16 crc32
  *
 */

#ifndef crc_202104252128
#define crc_202104252128

#include <string>

// �������ȡ��ǰ�ļ��������Ŀ����
// ע��#include "../../hcdef.h"��ʹ�� #define API_20210425
#include "../../hcdef.h"
//#define API_20210425 

namespace api202104
{
	unsigned long API_20210425 crc8(const void *src, unsigned long size);
	unsigned long API_20210425 crc16(const void *src, unsigned long size);
	unsigned long API_20210425 crc32(const void *src, unsigned long size);
}

#endif

