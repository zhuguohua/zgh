/**
 * @author   化十
 * @email     530894516@qq.com
 * @date       2021-04-26
  *
 *  @detail    json。
 *
 * 这里使用CJsonObject开源库，因为可以直接用来编译。
 *
 * 有需要的可以单独用jsoncpp:
 *  https://github.com/open-source-parsers/jsoncpp
  *
 */

#ifndef json_202104262128
#define json_202104262128

#include <string>
#include "CJsonObject/CJsonObject.hpp"
namespace api202104
{
	namespace json {
		using namespace neb;
		// 可以这样直接用neb命名空间的CJsonObject：
		// zgh::json::CJsonObject ojson;
		
		// 使用说明见 CJsonObject/demo
	}
}

#endif

