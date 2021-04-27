/**
 * @author   »¯Ê®
 * @email     530894516@qq.com
 * @date       2021-04-25
  *
 *  @detail
  *
 */

#include "URLParser/URLParser.hpp"
#include "url.h"

namespace api202104
{
	std::string urlEncode(const std::string &src) {
		return urlhelper::URLEncode(src);
	}

	std::string urlDecode(const std::string &src) {
		return urlhelper::URLDecode(src);
	}

	url::url(const std::string &_url) 
		: m_url(_url)
		, m_urlparser(LUrlParser::ParseURL::parseURL(m_url))
	{
		init();
	}

	url::~url() {
		
	}

	void url::init() {
		//LUrlParser::ParseURL tmp = LUrlParser::ParseURL::parseURL("https://John:Dow@github.com:80/corporateshark/LUrlParser");
	}

	std::string url::raw() {
		return m_url;
	}

	std::string url::scheme() {
		if (false == m_urlparser.isValid()) 
			return "";
		return m_urlparser.scheme_;
	}

	std::string url::host() {
		if (false == m_urlparser.isValid()) 
			return "";
		return m_urlparser.host_;
	}

	std::string url::port() {
		if (false == m_urlparser.isValid()) 
			return "";
		return m_urlparser.port_;
	}

	std::string url::uri() {
		if (false == m_urlparser.isValid()) 
			return "";
		return m_urlparser.path_;
	}

	std::string url::query() {
		if (false == m_urlparser.isValid()) 
			return "";
		return m_urlparser.query_;
	}

	std::string url::fragment() {
		if (false == m_urlparser.isValid()) 
			return "";
		return m_urlparser.fragment_;
	}

	std::string url::user() {
		if (false == m_urlparser.isValid()) 
			return "";
		return m_urlparser.userName_;
	}

	std::string url::pwd() {
		if (false == m_urlparser.isValid()) 
			return "";
		return m_urlparser.password_;
	}

}