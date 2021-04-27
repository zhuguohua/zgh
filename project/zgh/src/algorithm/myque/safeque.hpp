/**
  @author   ��ʮ
  @email     530894516@qq.com
  @date       2021-04-23

  @detail    ���ļ����̰߳�ȫ����

  ֧�ֵĹ���
	 1��֧�ֶ��̡߳�
	 2���ȴ����ݳ�ʱ��
	 3�������г������á�
		 ����ʱ�򣬼�鳤�ȣ���������պ������С�
		 ����ʱ�򣬲���鳤�ȡ�
	 4��c++��ƽ̨��
	 5�������ݵ�����ʱ֪ͨ�ȴ����ݵ��̡߳�
	 6���Ƚ��ȳ���

	 ���ӣ���testque.cpp��

	 safeque<std::string> g_que(500); // ���г���500.
	 g_que.push("123"); // ����
	 g_que.pop(str, 5000); // ���У���ʱ5�롣

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
		// �����У����Ӷ����Ƴ����ݡ�
		bool pop(ty &v, unsigned long wait_timeout_ms) {
			std::unique_lock<std::mutex> lock(m_mtx);
			if (false == waitdata(lock, wait_timeout_ms))
				return false;
			v = mysuper::front();
			mysuper::pop();
			return true;
		}
		// �����
		void push(const ty &v) {
			{
				std::unique_lock<std::mutex> lock(m_mtx);
				if (mysuper::size() > m_maxquelen) {
					safeque<ty>().swap(*this);
				}
				mysuper::push(v);
			}
			m_cv.notify_all(); // �����ݣ���֪ͨwait_for��
			return;
		}
	private:
		bool waitdata(std::unique_lock<std::mutex> &lock, unsigned long wait_timeout_ms) {
			if (false == mysuper::empty())
				return true; // ��������ݣ����ȴ�,���ء�
			// �������Ҫ�ȴ���ֱ�ӷ��ء�
			if (0 == wait_timeout_ms)
				return false;
			// �ȴ�����������ݣ����������أ�����ֱ����ʱ��
			// �ȴ����̻��ͷ������ȴ�����������������
			m_cv.wait_for(lock, std::chrono::milliseconds(wait_timeout_ms));
			if (false == mysuper::empty())
				return true;  // �ȴ��������ݡ�
			// �ȴ���û�����ݡ�
			return false;
		}
	private:
		std::mutex m_mtx; // ������.
		std::condition_variable m_cv; // ��������.
		unsigned long m_maxquelen;
	};

}

#endif

