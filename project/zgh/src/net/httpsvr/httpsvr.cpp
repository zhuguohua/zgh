/**
 * @author  化十
 * @email   530894516@qq.com
 * @date     2021-04-24
 */

#include <sstream>
#include <string>
#include "HttpService.h"
#include "httpsvr.h"
 

// 处理http请求包。
std::string handlePkt(std::string uri, std::string body) {
	static unsigned long count = 0;
	printf("***************************************************\r\n");
	printf("recv request count: %u.\r\n", ++count);
	printf(("uri: " + uri + "\r\n").c_str());
	printf(("body: " + body + "\r\n").c_str());

	std::string content = "response body content";

	if (std::string::npos != uri.find("/hello")) 
	{
		content = "response body hello";
	}
	else if (std::string::npos != uri.find("/request")) 
	{
		content = "response body request";
	}
	else if (std::string::npos != uri.find("/exit")) 
	{
		exit(0); //结束当前进程。
	}
	return content;
}

int httpSvrStart() {
	HttpService http;
	http.start("8611");  // http服务端口，web的config.json也要配置一样的端口
	return 0;
}

