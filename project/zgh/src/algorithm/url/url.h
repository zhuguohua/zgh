/**
 * @author   ��ʮ
 * @email     530894516@qq.com
 * @date       2021-04-25
  *
 *  @detail    url����, ���롢���롣
  *
 */

#ifndef url_202104252128
#define url_202104252128

#include "LUrlParser/LUrlParser.h"
#include <string>

namespace api202104
{
	// url ���롣
	std::string urlEncode(const std::string &src);
	// url ���롣
	std::string urlDecode(const std::string &src);

	class url {
	public:
		url(const std::string &_url);
		virtual ~url();
	public:
		std::string raw();
		std::string scheme(); // http https ftp
		std::string host();
		std::string port();
		std::string uri();
		std::string query();
		std::string fragment();
		std::string user();
		std::string pwd();
	private:
		void init();
	private:
		std::string m_url;
		LUrlParser::ParseURL m_urlparser;
	};
}

#endif

