/**
 * @author   ��ʮ
 * @email     530894516@qq.com
 * @date       2021-04-25
  *
 *  @detail    base64����ͽ��롣
					  ֧���ڴ��ֽ����ݣ��ַ������ݡ�
  *
 */

#ifndef base64_202104252128
#define base64_202104252128

#include <string>

 // �������ȡ��ǰ�ļ��������Ŀ����
 // ע��#include "../../hcdef.h"��ʹ�� #define API_20210425
#include "../../hcdef.h"
//#define API_20210425 

namespace api202104
{
	namespace base64 {

		// �ַ������룺�����ַ����������ַ�����
		std::string API_20210425 encodeStr(const std::string &src);
		// �ַ������룺�����ַ����������ַ�����
		std::string API_20210425 decodeStr(const std::string &src);
		// �ַ������룺�����ַ����������ַ�����
		std::string API_20210425 decodeStr(const void *src, unsigned int len);

		// �ڴ���룺�ɴ��������������ݣ��ֽڡ��ַ����ȣ������ַ�����
		std::string API_20210425 encode(const void *src, unsigned int len);

		// �ڴ���룺�����ַ���������std::string�ֽڻ��档
		// ��std::string����������ֱ�����ݡ�
		// std::string::c_str()��ʾ�����ַ��std::string::size()��ʾ�����С��
		std::string API_20210425 decodeByte(const std::string &src);

		// �ļ�����---δʵ�֣�������á�
		// ���룺�����ļ�����·��+�ļ����������ַ�����
		std::string API_20210425 encodeFile(const char *filePath);

	}
}

#endif

