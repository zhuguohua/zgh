/**
  @author   化十
  @email     530894516@qq.com
  @date       2021-04-23

  @detail    单文件，线程安全队列

  支持的功能
	 1、支持多线程。
	 2、等待数据超时。
	 3、最大队列长度设置。
		 入列时候，检查长度，过长则清空后再入列。
		 出列时候，不检查长度。
	 4、c++跨平台。
	 5、新数据到来及时通知等待数据的线程。
	 6、先进先出。

	 例子，见testque.cpp：

	 safeque<std::string> g_que(500); // 队列长度500.
	 g_que.push("123"); // 入列
	 g_que.pop(str, 5000); // 出列，超时5秒。

 */

#ifndef _MYQUE_20210423_
#define _MYQUE_20210423_

#include <queue>
#include <mutex>
#include <condition_variable>

namespace api202104
{
	template <typename ty>
	class safeque : public std::queue<ty> {
		typedef std::queue<ty> mysuper;
	public:
		safeque() { m_maxquelen = ~0; }
		safeque(unsigned long maxquelen) { m_maxquelen = maxquelen; }
	public:
		// 出队列，并从队列移除数据。
		bool pop(ty &v, unsigned long wait_timeout_ms) {
			std::unique_lock<std::mutex> lock(m_mtx);
			if (false == waitdata(lock, wait_timeout_ms))
				return false;
			v = mysuper::front();
			mysuper::pop();
			return true;
		}
		// 入队列
		void push(const ty &v) {
			{
				std::unique_lock<std::mutex> lock(m_mtx);
				if (mysuper::size() > m_maxquelen) {
					safeque<ty>().swap(*this);
				}
				mysuper::push(v);
			}
			m_cv.notify_all(); // 新数据，并通知wait_for。
			return;
		}
	private:
		bool waitdata(std::unique_lock<std::mutex> &lock, unsigned long wait_timeout_ms) {
			if (false == mysuper::empty())
				return true; // 如果有数据，不等待,返回。
			// 如果不需要等待，直接返回。
			if (0 == wait_timeout_ms)
				return false;
			// 等待，如果有数据，则立即返回，否则直到超时。
			// 等待过程会释放锁，等待结束会重新上锁。
			m_cv.wait_for(lock, std::chrono::milliseconds(wait_timeout_ms));
			if (false == mysuper::empty())
				return true;  // 等待后有数据。
			// 等待后没有数据。
			return false;
		}
	private:
		std::mutex m_mtx; // 互斥锁.
		std::condition_variable m_cv; // 条件变量.
		unsigned long m_maxquelen;
	};

}

#endif

