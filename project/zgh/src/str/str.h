/**
 * @author   化十
 * @email     530894516@qq.com
 * @date       2021-04-25
  *
 *  @detail    字符串转化。-未实现。
  *
 */

#ifndef json_202104252128
#define json_202104252128

#include <string>
#include <sstream>

namespace api202104
{
	namespace str {
		// wstr--ansi
		std::string   wstr2str(const std::wstring &src);
		// ansi--wstr
		std::wstring str2wstr(const std::string &src);

		// ansi--utf8
		std::string ansi2utf(const std::string &src);
		// utf8--ansi
		std::string utf2ansi(const std::string &src);

		// wstr--utf8
		std::string   wstr2utf(const std::wstring &src);
		// utf8--wstr
		std::wstring utf2wstr(const std::string &src);

		template <typename ty>
		std::string numtostr(ty val) {
			return std::to_string(val);
			//std::stringstream str;
			//str << val;
			//return str.str();
		}

		template <typename ty>
		ty strtonum(const std::string &src) {
			ty val = 0;
			std::stringstream str;
			str << src;
			str >> val;
			return val;
		}
	}
}

#endif

