/**
 * @author   化十
 * @email     530894516@qq.com
 * @date       2021-04-25
  *
 *  @detail    impl文件夹下是别人开发的一个开源库。
  *
 */

#include <memory>
#include "b64c/b64.h"
#include "base64.h"

namespace api202104
{
	namespace base64 {

		std::string encodeStr(const std::string &src) {
			return encode(src.c_str(), src.size());
		}

		std::string decodeStr(const std::string &src) {
			return decodeStr(src.c_str(), src.size());
		}

		std::string decodeStr(const void *src, unsigned int len) {
			std::shared_ptr<char> b64((char *)b64_decode((const char *)src, len));
			std::string tmp = b64.get();
			return tmp;
		}

		std::string encode(const void *src, unsigned int len) {
			std::shared_ptr<const char> b64(b64_encode((const unsigned char *)src, len));
			std::string tmp = b64.get();
			return tmp;
		}

		// 解码：输入字符串，返回std::string字节缓存。
		// 则std::string用作缓存存放直接数据，std::string::size()表示缓存大小。
		std::string decodeByte(const std::string &src) {
			size_t len = 0;
			std::shared_ptr<char> b64((char *)b64_decode_ex(src.c_str(), src.size(), &len));
			std::string tmp(b64.get(), len);
			return tmp;
		}

		std::string encodeFile(const char *filePath) {
			return "";
		}
	}
}
