/**
 * @author   化十
 * @email     530894516@qq.com
 * @date       2021-04-25
  *
 *  @detail    base64编码和解码。
					  支持内存字节数据，字符串数据。
  *
 */

#ifndef base64_202104252128
#define base64_202104252128

#include <string>

 // 如果先提取当前文件到别的项目编译
 // 注释#include "../../hcdef.h"，使用 #define API_20210425
#include "../../hcdef.h"
//#define API_20210425 

namespace api202104
{
	namespace base64 {

		// 字符串编码：输入字符串，返回字符串。
		std::string API_20210425 encodeStr(const std::string &src);
		// 字符串解码：输入字符串，返回字符串。
		std::string API_20210425 decodeStr(const std::string &src);
		// 字符串解码：输入字符串，返回字符串。
		std::string API_20210425 decodeStr(const void *src, unsigned int len);

		// 内存编码：可传入任意类型数据：字节、字符串等，返回字符串。
		std::string API_20210425 encode(const void *src, unsigned int len);

		// 内存解码：输入字符串，返回std::string字节缓存。
		// 则std::string用作缓存存放直接数据。
		// std::string::c_str()表示缓存地址，std::string::size()表示缓存大小。
		std::string API_20210425 decodeByte(const std::string &src);

		// 文件类型---未实现，请勿调用。
		// 编码：传入文件绝对路径+文件名，返回字符串。
		std::string API_20210425 encodeFile(const char *filePath);

	}
}

#endif

