/**
 * @author   ��ʮ
 * @email     530894516@qq.com
 * @date       2021-04-25
  *
 *  @detail Ԥ����
  *
 */

#ifndef hcdef_202104252128
#define hcdef_202104252128

 // ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
 // ��ı�׼�������� DLL �е������ļ��������������϶���� API_20210425_EXPORTS
 // ���ű���ġ���ʹ�ô� DLL ��
 // �κ���Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
 // API_20210425 ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
 // ������Ϊ�Ǳ������ġ�

// *********************************************************************
// �������DLL���ǵö��� API_20210425_EXPORTS�� ����ӿڲ��ᵼ����

#ifdef _WIN32
#ifdef API_20210425_EXPORTS
#define API_20210425 __declspec(dllexport)
#else
//#define API_20210425 __declspec(dllimport)
#define API_20210425 
#endif
#else
#define API_20210425
#endif

#endif

