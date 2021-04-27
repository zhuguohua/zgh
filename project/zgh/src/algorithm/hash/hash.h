/**
 * @author   化十
 * @email     530894516@qq.com
 * @date       2021-04-25
  *
 *  @detail    hash计算。
  *
 */

#ifndef hash_202104252128
#define hash_202104252128

#include <string>

 // 如果先提取当前文件到别的项目编译
 // 注释#include "../../hcdef.h"，使用 #define API_20210425
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

