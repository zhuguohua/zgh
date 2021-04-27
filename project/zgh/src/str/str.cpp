/**
 * @author   »¯Ê®
 * @email     530894516@qq.com
 * @date       2021-04-25
  *
 *  @detail
  *
 */

#include "str.h"

namespace api202104
{
	namespace str {
		// wstr--ansi
		std::string   wstr2str(const std::wstring &src) {
			return "";
		}

		// ansi--wstr
		std::wstring str2wstr(const std::string &src) {
			return L"";
		}

		// ansi--utf8
		std::string ansi2utf(const std::string &src) {
			return "";
		}

		// utf8--ansi
		std::string utf2ansi(const std::string &src) {
			return "";
		}

		// wstr--utf8
		std::string   wstr2utf(const std::wstring &src) {
			return "";
		}

		// utf8--wstr
		std::wstring utf2wstr(const std::string &src) {
			return L"";
		}

	}
}