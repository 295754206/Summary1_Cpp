#include <iostream>
using namespace std;

// 例外处理（分母为0）

int main() {
	int a, b;
	cout << "a: " << endl;
	cin >> a;
	cout << "b: " << endl;
	cin >> b;
	try {
		if (b == 0) {
			throw b;
		}
		else {
			cout << a << "/" << b << endl;
		}
	}
	catch (int i) {
		cout << "除数不能为：" << i << endl;
	}
}

//  可拆分

void check(int a, int b) {
	if (b == 0) {
		throw b;
	}
	else {
		cout << a << "/" << b << endl;
	}
}

int main() {
	int a, b;
	cout << "a: " << endl;
	cin >> a;
	cout << "b: " << endl;
	cin >> b;
	try {
		check(a, b);
	}
	catch (int i) {
		cout << "除数不能为：" << i << endl;
	}
}

// 检查密码

int main() {
	const char p[6] = "12345";
	char s[6];
	cout << "输入密码：" << endl;
	cin >> s;
	try {
		for (int i = 0; i < 6; i++) {
			if (s[i] != p[i]) {
				throw i;
			}
		}
		cout << "密码对了" << endl;
	}
	catch (int i) {
		cout << "密码不对" << endl;
	}
}

// 也可以把try-catch代码部分做成一个函数来使用 bool类型 2个返回


#include <iostream>
using namespace std;

// 类 和 try-catch 实作 栈 （类别错误处理）

#define MAX 80

class Stack {
	int s[MAX];
	int top;
public:
	class Full {};
	class Empty{};
	Stack() {
		top = -1;
	}
	void push(int i) {
		if (top > MAX - 1) {
			throw Full();
		}
		else {
			s[++top] = i;
		}		
	}
	int pop() {
		if (top == -1) {
			throw Empty();
		}
		else {
			return s[top--];
		}
	}
};

int main() {
	Stack s;
	try {
		s.push(1);
		s.push(2);
		cout << s.pop() << endl;
		cout << s.pop() << endl;
		cout << s.pop() << endl;
	}
	catch (Stack::Full) {
		cout << "满了" << endl;
	}
	catch (Stack::Empty) {
		cout << "空了" << endl;
	}
}

#include <iostream>
#include <cstring>
using namespace std;

// 错误类处理（要求b不能大于12）

class H {
	int a, b;
public:
	class InErr {
		char* s;
		int t;
	public:
		InErr(char* p, int k) {
			s = p;
			t = k;
		};
		void why() {
			cout << s << " " << t << endl;
		}
	};
	H() {
		a = b = 0;
	}
	H(int i, int j) {
		char s2[20] = "建立输入值不对";
		if (j > 12) {
			throw InErr(s2, j);
		}
		a = i;
		b = j;
	}
	void set() {
		char s1[20] = "输入值大于12了";
		cout << "输入a和b:" << endl;
		cin >> a >> b;
		if (b > 12) {
			throw InErr(s1, b);
		}
	}
};

int main() {
	try {
		H h2(1, 2);
		H h1;
		h1.set();
		H h3(1, 13);
	}
	catch (H::InErr e) {
		e.why();
	}
}


#include <iostream>
using namespace std;

// 抽象类定义的直接使用  （模板）

template <class X>
void Swap(X& a, X& b) {		// 按地址传才能正真改变值
	X t;
	t = a;
	a = b;
	b = t;
}

int main() {
	int x = 4;
	int y = 8;
	float a = 1.0;
	float b = 2.0;
	Swap(x, y);
	Swap(a, b);
	cout << x << y << a << b << endl;
}

// 模板也可以被多载，有明确类型的按照类型算，没有的按照模板来算

#include <iostream>
using namespace std;

// 多载模板和双类型模板

template <class X>
void f(X a) {
	cout << a;
}

template <class X,class Y>
void f(X a, Y b) {
	cout << a << " " << b << endl;
}

int main() {
	f(1);
	f(2.0, 3);
}

// 模板可以使用半固定形态参数
// template <class X>
// void sort(X *i,int max)	// i可以是字符数组或者整数或者float

#include <iostream>
using namespace std;

// 范本也可以应用于类别定义中，用来简化单是形态上的变化

template <class TYPE1,class TYPE2>
class Test {
	TYPE1 x;
	TYPE2 y;
public:
	Test(TYPE1 a, TYPE2 b) {
		x = a;
		y = b;
	}
	void show() {
		cout << x << " " << y << endl;
	}
};

int main() {
	Test<int,char> t(1, 'a');		// 使用类来用模板需要加<int,char>来明确指出，函数就不需要了
	t.show();
}

#include <iostream>
#include <string>
using namespace std;

// 用范本和类来同时定义多个类型的栈

#define MAX 3

template <class TYPE>
class Stack {
	TYPE s[MAX];
	int p;
public:
	Stack() {
		p = -1;
	}
	void push(TYPE a) {
		if (p == MAX - 1) {
			char e[20] = "满了";
			throw e;
		}
		else {
			s[++p] = a;
		}
	}
	TYPE pop();
};

template <class TYPE>			// 外围定义方式
TYPE Stack<TYPE>::pop() {
	if (p == -1) {
		char e[20] = "已空";
		throw e;
	}
	else {
		return s[p--];
	}
}

int main() {
	try {
		Stack<int> is;
		Stack<char> cs;
		is.push(1);
		is.push(2);
		is.push(3);
		cout << is.pop() << " ";
		cout << is.pop() << " ";
		cout << is.pop() << " ";
		// cout << is.pop() << " ";
		cs.push('a');
		cs.push('b');
		cs.push('c');
		cs.push('d');
	}
	catch (char* c) {
		cout << c;
	}
}
