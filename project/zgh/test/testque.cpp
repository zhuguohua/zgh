/**
 * @author   化十
 * @email     530894516@qq.com
 * @date       2021-04-25
 *
 *  @detail    测试myque.hpp
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
		// 等待数据出列。
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
		// 入列数据
		g_que.push("123");
	}
}

int testmyque()
{
	// 启动一个线程处理数据
	std::thread(threadProcessData).detach();
	// 启动10个线程添加数据
	for (size_t i = 0; i < 10; i++) {
		std::thread(threadAddData).detach();
	}
	// main流程持续等待。
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}

