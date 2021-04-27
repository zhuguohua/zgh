/**
 * @brief HttpService
 * @author Peng Chaowen
 * @web www.pcwen.top
 * @version 1.0
 * @date 2019/06/19
 */

// 以上是HttpService.cpp源码的最初作者，这里拿来直接用。
// 化十，邮箱530894516@qq.com

#include <string>
#include "HttpService.h"
#include "httpsvr.h"

struct mg_serve_http_opts HttpService::s_http_server_opts;

//请求事件处理
void HttpService::mgEvHandler(struct mg_connection *nc, int ev, void *p) {
    //处理request
    if (ev == MG_EV_HTTP_REQUEST) {
        struct http_message *msg = (struct http_message *)p;

        //body内容
        char* body = new char[msg->body.len + 1];
        memset(body, 0, msg->body.len + 1);
        memcpy(body, msg->body.p, msg->body.len);

        //uri内容
        char* uri = new char[msg->uri.len + 1];
        memset(uri, 0, msg->uri.len + 1);
        memcpy(uri, msg->uri.p, msg->uri.len);

		std::string content = handlePkt(uri, body);

        //返回body信息
        mgSendBody(nc, content.c_str());

        //返回下载文件
        //mgSendFile("相对于s_http_server_opts.document_root的文件路径");

        delete uri;
        delete body;
    }
}

//发送body信息
void HttpService::mgSendBody(struct mg_connection *nc, const char *content) {
    mg_send_head(nc, 200, strlen(content), "Content-Type: text/plain\r\nAccess-Control-Allow-Origin: *\r\nConnection: close");
    mg_send(nc, content, strlen(content));
    nc->flags |= MG_F_SEND_AND_CLOSE;
}

//发送文件，文件的位置是相对于s_http_server_opts.document_root的路径
void HttpService::mgSendFile(struct mg_connection *nc, struct http_message *hm, const char* filePath) {
    mg_http_serve_file(nc, hm, filePath, mg_mk_str("text/plain"), mg_mk_str(""));
}

//初始化并启动
bool HttpService::start(const char *port) {
    struct mg_mgr mgr;
    struct mg_connection *nc;

    mg_mgr_init(&mgr, NULL);
    printf("Starting web server on port %s\n", port);
    nc = mg_bind(&mgr, port, mgEvHandler);
    if (nc == NULL) {
        printf("Failed to create listener\n");
        return false;
    }

    // Set up HTTP server parameters
    mg_set_protocol_http_websocket(nc);
    s_http_server_opts.document_root = ".";  //文件相对路径 Serve current directory
    s_http_server_opts.enable_directory_listing = "yes";

    for (;;) {
        mg_mgr_poll(&mgr, 50); //1s轮训一次
    }
    mg_mgr_free(&mgr);

    return true;
}
