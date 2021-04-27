/**
 * @author   化十
 * @email     530894516@qq.com
 * @date       2021-04-25
  *
 *  @detail    字符串转化。
  *
 */

#ifndef process_202104252128
#define process_202104252128

#include <string>
#include "process-0.h"

namespace api202104
{
	class proc :public proc_0 {
	public:
		proc(const std::string &channal_name, bool iscreate) 
			: proc_0(channal_name, iscreate) 
		{}
	public:
		virtual bool send(const std::string &pkt);
		virtual bool recv(std::string &pkt, unsigned long wait_time_ms); 
	};
}

#endif

