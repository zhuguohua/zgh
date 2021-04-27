/**
 * @author   化十
 * @email     530894516@qq.com
 * @date       2021-04-25
  *
 *  @detail    
  *
 */
#include <thread>
#include "../algorithm/myque/safeque.hpp"
#include "process-0.h"
#include "process.h"

static api202104::safeque<std::string> g_sendque(50);
static api202104::safeque<std::string> g_recvque(50);

namespace api202104
{
	void threadHandleSend(void *param) {
		proc_0 *proc0 = (proc_0 *)param;
		for (;;) {
			std::string str;
			if (g_sendque.pop(str, 2000)) {
				// TODO send data..
			} else {
				// no data.
			}
		}
	}

	void threadHandleRecv(void *param) {
		proc_0 *proc0 = (proc_0 *)param;
		for (;;) {
			// recv data and push.
			g_recvque.push("123");
		}
	}

	void init() {
		//std::thread(threadHandleSend).detach();
		//std::thread(threadHandleRecv).detach();

		// 打开进程通信通道。
	}

	bool proc::send(const std::string &pkt) {
		g_sendque.push(pkt);
		return true;
	}

	bool proc::recv(std::string &pkt, unsigned long wait_time_ms) {
		return g_recvque.pop(pkt, wait_time_ms);
	}
}
