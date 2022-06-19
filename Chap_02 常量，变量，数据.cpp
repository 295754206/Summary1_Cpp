
// <> 用来插入C++程序库标题档

	#include <iostream.h> 	// 旧型标题档含有.h 

// "" 用来插入使用者自订的标题档

	#include "user.h"

// 新型标题档不含.h 并需要使用 using namespace std; 来宣告使用标准函式库 

	#include <iostream>
	using namespace std;

// 无参数呼叫，也不需要传回系统任何值 

	void main(void)
	void main()


// cout 中使用 endl来换行

	cout<<"ABC";
	cout<<"DEF";
	// ABCDEF : 默认不换行的
	
	cout<<"ABC"<<endl;
	cout<<"DEF"<<endl;
	// ABC
	// DEF
	
	cout<<"ABC"<<endl	// 注意没有分号，cout未结束
		<<"DEF"<<endl;
	
// 子串中使用\n也可以实现换行
	
	cout<<"ABC\n"
		<<"DEF\n";
	// 一个字串中可以有多个\n
	
 	
// 变量命名使用 字母(a-z,A-Z)+数字(0-9)+下划线(_) 的组合，并且必须要以字母为开头

// 变量声明
	
	int a;
	a = 1;
	
	int a = 1;
	
	int a,b = 1;	
	// a,b均为 1
	
	cout<<a<<b;
	// 11
	
// 宣告常数时，必须同时赋予初始值，并且该符号的值不能再改变

	const float fPI = 3.14159f;
	const double PI = 3.1415926;
	
// 对等前置替换处理符号 #define
	
	#include <iostream>
	using namespace std; 
	
	#define PI 3.14159f 	// 前置处理命令没有分号 
	// ... 

// 变数类型
	
	unsigned int a = 1;		// 无符号整数
	signed int b = -1;		// 有符号整数
	
	char str = 'L';
	char str[3] = {'C','+','+'};	// 字元阵列资料 
	char str[4] = "C++";		// 字串中会自动加个'\0'作为结尾，所以会要4个分配空间
	// 注意：如果书写了"*\0\0\0\0***"，则只会展现第一个*，因为尽管\0是空格，但是读到会直接判定该字串结束
	char str[] = "C++全方位学习";
	// 注意：是char name[]不是str[],也不是char[] name;
		
	char h = 'c';
	char h = 67;	// 还是c,ASCII值定义
	char h = 0x43;	// 16进位的ASCII值
	
	float v = 4.5e+16;	// 4.5*10**16
	float o = 4.5e10;	// 4.5*10**10
	
	bool t = true;
	bool f = false;
	
// 使用sizeof()获取类型或者变量的byte数

	cout<<sizeof(int)<<bytes<<endl;
	cout<<sizeof(a)<<bytes<<endl;

	
