#include <iostream>
using namespace std;

int main() {
	
	// 宣告
	
	int* p, num;	// p为指标，num为一般变数
	int *p, num;	// 与上同

	// 取地址 & 运算

	int n = 10;
	cout << &n;

	// 起始宣告

	int num;

	int* p;
	p = &num;		

	// 或者直接   （注：不同类型不可以连接）（在宣告的时候不可以赋予的是内容数，只能是地址）
	int* p = &num;

	// 取内容 * 运算 （相当于直接在用变数名称）

	int number = 100;
	int* p = &number;

	number == *p == *(&number);	// 都是内容
	&number == p;				// 都是地址

	// 数组名本身就是指标，可以直接用，也可以再赋给其他指标变量

	int s[10];
	int* p;
	p = s;		// 本身就是指标变量 p = &s 是不对的！

	int s[10];
	int* p = s;	// 合并叙述的写法

}
   
#include <iostream>
using namespace std;

int main() {
	
	// 数组元素的指标

	int s[3] = { 2,1,3 };
	int* p = s;
	for (int i = 0; i < 3; i++) {
		cout << *(p++) << " ";
	}

	// 指定输出某个元素

	p = &s[1];			// 因为元素s[1]是元素不是指标变量，这里要加&
	cout << *p;

	p = s;
	cout << *(p + 1);	// 也是s[1]

	// 计算数组元素个数

	int size = (sizeof s) / (sizeof s[0]);

	// sizeof 也可以用作字符形态

	cout << sizeof(bool);

}

#include <iostream>
using namespace std;

int main() {

	// 数组指标递增输入，递减输出

	int s[5];
	int* p = s;
	for (int i = 0; i < 5; i++) {
		cin >> *(p++);		// 做完后p已经更新到最末尾了
	}
	for (int i = 4; i >= 0; i--) {
		cout << *(--p)<<"-";
	}

}

#include <iostream>
using namespace std;

int main() {

	// 指标与函数

	// 传递地址

	int var1, var2;
	swap(&var1, &var2);

	void swap(int* num1, int* num2) {
		int buffer;
		buffer = *num1;
		*num1 = *num2;
		*num2 = buffer;
	}

	// 传递指标变量

	int var1, var2;
	int* p1 = &var1;
	int* p2 = &var2;
	swap(p1, p2);

	void swap(int* num1, int* num2) {
		int buffer;
		buffer = *num1;
		*num1 = *num2;
		*num2 = buffer;
	}

	// 其实还是传递地址，只是直接赋给了新的内容变量

	int var1, var2;
	swap(var1, var2);

	void swap(int& num1, int& num2) {	// 取传递的参数地址立即赋予新内容变量
		int buffer;
		buffer = num1;
		num1 = num2;
		num2 = buffer;
	}// 直接内容传递也好

}
   
// 函数外传递指标数组

int main() {
	int s[3] = { 1,2,3 };
	show(s);
}

void show(int *s) {
	for (int i = 0; i <= 2; i++) {
		cout << *(s + i);
	}
}
// 或者
void show(int s[]) {
	for (int i = 0; i <= 2; i++) {
		cout << s[i];
	}
}

// 防止函数修改原来资料，加上const

int main() {
	int len = 5;
	power(&len);
}

void power(const int* num) {
	cout << *num * *num;
}

// 传回函数指标

int main() {
	cout << *get();	// 2处必须一致，传回的必须是指标变量，用*在置换回来
}

float* get() {		// float* 意思是传回的变量是一个指标
	float* num;
	cin >> *num;
	return num;
}

#include <iostream>
using namespace std;

int main() {
	
	// 动态记忆体（可回收）

	// 宣告

	int* p;
	p = new int;
	*p = 100;

	int* p = new int(100);	// 一次性赋值

	// 删除

	delete p;

	// 数组的操作

	int* p = new int[3];
	p[2] = 1;	// p[2] == *(p+2)

	// 删除

	delete[] p;
}



   
   
