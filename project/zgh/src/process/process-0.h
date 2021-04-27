/**
 * @author   化十
 * @email     530894516@qq.com
 * @date       2021-04-25
  *
 *  @detail    字符串转化。
  *
 */

#ifndef process_0_202104252128
#define process_0_202104252128

#include <string>

namespace api202104
{
	class proc_0 {
	public:
		proc_0(const std::string &channal_name, bool iscreate) {
			m_channal_name = channal_name;
			m_iscreate = iscreate;
			init();
		}
	public:
		void init();
	public:
		int getErrCode() {
			return m_errcode;
		}
		std::string getErrString() {
			return m_errinfo;
		}
	public:
		// 发送一个包给对方进程。
		virtual bool send(const std::string &pkt) {}
		// 接收一个包给对方进程。
		virtual bool recv(std::string &pkt) {}
	private:
		bool m_iscreate;
		int m_errcode;
		std::string m_errinfo;
		std::string m_channal_name;
	};
}

#endif

