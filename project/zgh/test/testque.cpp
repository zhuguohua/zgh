/**
 * @author   ��ʮ
 * @email     530894516@qq.com
 * @date       2021-04-25
 *
 *  @detail    ����myque.hpp
 *
 */

#include <string>
#include <thread>
#include <iostream>
#include <sstream>
#include "../src/algorithm/myque/myque.hpp"

api202104::myque<std::string> g_que(500);

void threadProcessData() {
	int count = 0;
	while (true) {
		std::string str;
		std::stringstream strfmt;
		strfmt << "loop count: " << count++ << ".   ";
		// �ȴ����ݳ��С�
		if (g_que.pop(str, 5000)) {
			strfmt << "new data: " << str << std::ends;
		}
		else {
			strfmt << "5000 ms time out. " << std::ends;
		}
		std::cout << strfmt.str() << std::endl;
	}
}

void threadAddData() {
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		// ��������
		g_que.push("123");
	}
}

int testmyque()
{
	// ����һ���̴߳�������
	std::thread(threadProcessData).detach();
	// ����10���߳��������
	for (size_t i = 0; i < 10; i++) {
		std::thread(threadAddData).detach();
	}
	// main���̳����ȴ���
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}

