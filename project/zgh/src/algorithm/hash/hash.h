/**
 * @author   ��ʮ
 * @email     530894516@qq.com
 * @date       2021-04-25
  *
 *  @detail    hash���㡣
  *
 */

#ifndef hash_202104252128
#define hash_202104252128

#include <string>

 // �������ȡ��ǰ�ļ��������Ŀ����
 // ע��#include "../../hcdef.h"��ʹ�� #define API_20210425
#include "../../hcdef.h"
//#define API_20210425

namespace api202104
{
	std::string API_20210425 md5(const void *src, unsigned long len);
	std::string API_20210425 hash(const void *src, unsigned long len);
	std::string API_20210425 sha1(const void *src, unsigned long len);
	std::string API_20210425 sha3(const void *src, unsigned long len);
	std::string API_20210425 sha256(const void *src, unsigned long len);
}

#endif

