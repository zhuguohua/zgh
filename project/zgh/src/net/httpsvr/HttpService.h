#ifndef _httpservice_202104241428_
#define _httpservice_202104241428_

/*
Http����
*/

/**
 * @brief HttpService
 * @author Peng Chaowen
 * @web www.pcwen.top
 * @version 1.0
 * @date 2019/06/19
 */

 // ������HttpService.cppԴ���������ߣ���������ֱ���á�
// ��ʮ������530894516@qq.com

#include "mongoose/mongoose.h"

class HttpService {
  public:
    bool start(const char *port);
  private:
    static void mgEvHandler(struct mg_connection *nc, int ev, void *p);
    static void mgSendBody(struct mg_connection *nc, const char *content); //����body��Ϣ
    static void mgSendFile(struct mg_connection *nc, struct http_message *hm, const char* filePath);
    static struct mg_serve_http_opts s_http_server_opts;
};

#endif

