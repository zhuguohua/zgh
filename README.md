# zgh
a small c++ common basic lib.
welcome everyone to contribute code, or fix bug.

git address: https://github.com/zhuguohua/zgh/edit/master

more info visit blog:   
https://blog.csdn.net/u012910342/article/details/116211465


surport:  
queue-hash-md5-crc-url-base64-convert-xml-json-httpsvr-interprocess  

![image](https://user-images.githubusercontent.com/11252116/116268585-0aab1900-a7b0-11eb-8eeb-72e65609a917.png)



```cpp
#include <iostream>
#include "src/zgh.h"

int main()
{
	// 库的所有的功能都在命名空间：api202104
	unsigned long ulcrc16 = api202104::crc16("123456", 6);
	unsigned long ulcrc35 = api202104::crc32("123456", 6);

	// zgh其实就是api202104，通过宏定义重命名。
	std::string md5     = zgh::md5("123456", 6);
	std::string sha1     = zgh::sha1("123456", 6);
	std::string sha256 = zgh::sha256("123456", 6);

	std::string b64enc = zgh::base64::encodeStr("1234568");
	std::string b64dec = zgh::base64::decodeStr(b64enc);

	std::string urlstr = "https://John:Dow@github.com:80/corporateshark/LUrlParser?a=你好&b=2";
	std::string urlenc = zgh::urlEncode(urlstr);
	std::string urldec = zgh::urlDecode(urlenc);

	zgh::url     url    = zgh::url(urlstr);
	std::string host = url.host();
	std::string port = url.port();
	std::string uri    = url.uri();
	
	return 0;
}

```
