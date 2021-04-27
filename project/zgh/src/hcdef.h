/**
 * @author   化十
 * @email     530894516@qq.com
 * @date       2021-04-25
  *
 *  @detail 预定义
  *
 */

#ifndef hcdef_202104252128
#define hcdef_202104252128

 // 下列 ifdef 块是创建使从 DLL 导出更简单的
 // 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 API_20210425_EXPORTS
 // 符号编译的。在使用此 DLL 的
 // 任何项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
 // API_20210425 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
 // 符号视为是被导出的。

// *********************************************************************
// 如果做成DLL，记得定义 API_20210425_EXPORTS， 否则接口不会导出。

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

