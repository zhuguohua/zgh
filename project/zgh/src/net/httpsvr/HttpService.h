#ifndef _httpservice_202104241428_
#define _httpservice_202104241428_

/*
Http服务
*/

/**
 * @brief HttpService
 * @author Peng Chaowen
 * @web www.pcwen.top
 * @version 1.0
 * @date 2019/06/19
 */

 // 以上是HttpService.cpp源码的最初作者，这里拿来直接用。
// 化十，邮箱530894516@qq.com

#include "mongoose/mongoose.h"

class HttpService {
  public:
    bool start(const char *port);
  private:
    static void mgEvHandler(struct mg_connection *nc, int ev, void *p);
    static void mgSendBody(struct mg_connection *nc, const char *content); //发送body信息
    static void mgSendFile(struct mg_connection *nc, struct http_message *hm, const char* filePath);
    static struct mg_serve_http_opts s_http_server_opts;
};

#endif

