/**
 * @author  ��ʮ
 * @email   530894516@qq.com
 * @date     2021-04-24
 */

#include <sstream>
#include <string>
#include "HttpService.h"
#include "httpsvr.h"
 

// ����http�������
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
		exit(0); //������ǰ���̡�
	}
	return content;
}

int httpSvrStart() {
	HttpService http;
	http.start("8611");  // http����˿ڣ�web��config.jsonҲҪ����һ���Ķ˿�
	return 0;
}

