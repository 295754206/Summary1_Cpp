#include <iostream>
using namespace std;

// 多载一般函数

int area(int l, int w) {};

double area(int r) {};

int main() {
	area(1, 2);
	area(3);
}

// 多载建立者函数

class Timer {
	int s;
public:
	Timer() {
		s = 0;
	}
	Timer(int seconds) {
		s = seconds;
	}
	Timer(char* t) {
		s = atoi(t);
	}
};

int main() {
	char p[20] = "250";
	Timer t1();
	Timer t2(10);
	Timer t3(p);
}

// 多载运算元符号

// 多载 << （常多载为friend函数来增加效能）

class Test {
	int a, b;
public:
	Test() {
		a = b = 0;
	}
	Test(int n, int m) {
		a = n;
		b = m;
	}
	friend istream& operator>>(istream& in, Test& obj);	// 2个参数分别为左边和右边：cin >> obj
	friend ostream& operator<<(ostream& out, Test& obj);
};

istream& operator>>(istream& in, Test& obj) {	// 左边输入流，右边类型
	cout << "输入a和b:" << endl;
	in >> obj.a >> obj.b;
	return in;
}

ostream& operator<<(ostream& out, Test& obj) {
	out << "a和b:" << endl;		// cout 和 此处命名的 out 都是输出流，cout是通用输出流，此处命名的 out 也是输出流
	out << obj.a << obj.b << endl;	// cout是直接输出，out<< 是把东西加载到out里面，最后外面还是加载到cout里面，cout是直接输出
	return out;
}

int main() {
	Test s1;
	cin >> s1;
	cout << s1;
}

// 多载 << 和 >> （带分数化简）

#include <iostream>
#include <cmath>
using namespace std;

class F {		// 带分数
public:
	int a;		// 整数
	int b;		// 分子
	int c;		// 分母
	F() {
		a = b = c = 1;
	}
	int getgcd();
	friend istream& operator>>(istream& in, F& obj);
	friend ostream& operator<<(ostream& out, F& obj);
};

int F::getgcd() {	// 从最大的开始找
	int n = b < c ? b : c;
	for (int i = n; i >= 1; i--) {
		if (b % i == 0 && c % i == 0) {
			n = i;
			break;
		}
	}
	return n;
}

istream& operator>>(istream& in, F& obj) {	// 这里必须传的是位置 
	cout << "输入带分数（1 4 6）：" << endl;
	in >> obj.a >> obj.b >> obj.c;
	return in;
}

ostream& operator<<(ostream& out, F& obj) {
	int gcd = obj.getgcd();	// 单独一个getgcd()是错误的，getgcd()不是friend()函数，需要配合类名来使用
	out << obj.a << "-" << (obj.b / gcd) << "-" << (obj.c / gcd);
	return out;
}

int main() {
	F f;
	cin >> f;
	cout << f.getgcd();
	cout << f.a << f.b << f.c << endl;
	cout << f;
}



#include <iostream>
#include <cmath>
using namespace std;

class Test {
	int a, b;
public:
	Test() {
		a = b = 0;
	}
	Test(int x, int y) {
		a = x;
		b = y;
	}
	Test operator+(Test);	// 针对的都是符号右边的,内部用的都是左边的（自己这个类的）
	bool operator>(Test);
	bool operator!();		// 因为右边不需要新的物件所以没有参数
	Test operator++();		// 前置++a
	Test operator++(int);	// 后置a++
	friend istream& operator>>(istream& in, Test& t);
	friend ostream& operator<<(ostream& out, Test& t);
};

Test Test::operator+(Test t) {
	Test temp;
	temp.a = a + t.a;
	temp.b = b + t.b;
	return temp;
}

bool Test::operator>(Test t) {
	if (a > t.a && b > t.b) {
		return true;
	}
	else {
		return false;
	}
}

bool Test::operator!() {		// 把！看作是一个函数运算
	if (a != 0) {
		return true;
	}
	else {
		return false;
	}
}

Test Test::operator++() {
	++a;
	++b;
	return Test(a, b);
}

Test Test::operator++(int) {
	return Test(a++, b++);
}

istream& operator>>(istream& in, Test& t) {
	in >> t.a >> t.b;
	return in;
}

ostream& operator<<(ostream& out, Test& t) {
	out << t.a << " " << t.b << endl;
	return out;
}

int main() {
	Test t1(1, 2);
	Test t2(3, 4);
	Test t3;
	t3 = t1 + t2;
	cout << t3 << endl;
	if (t2 > t1) {
		cout << "t2>t1" << endl;
	}
	if (!t3) {
		cout << "t3!=0" << endl;
	}
	++t3;
	cout << t3 << endl;
	t3++;
	cout << t3 << endl;
}












// 形态转换

void p() {
	int i = 2;
	float p = 3.0;
	i = int(p);
	p = float(i);
}

// 基本形态 转 类别形态
// 类型中 = 相当于呼叫一个类型匹配的建立者

class D {
	int a;
	int b;
public:
	D() {
		a = b = 0;
	}
	D(int i) {
		a = i;
	}
	D(int i, int j) {
		a = i;
		b = j;
	}
};

int main() {
	D d1,d2;
	int p = 9;		// 直接 = 给值
	d1 = p;
	int k = 3;
	d2 = { p,k };
}

// 类别形态 转 基本形态

class H {
	int i;
	float j;
public:
	H(int a, float b) {
		i = a;
		j = b;
	}
	operator float() {		// 要写类别转换的函数
		return j;
	}
};

int main() {
	H h(1,2.0);
	float f = h;	// = 自动寻找可转换的相同类型
}


// 类型转换为类型 （坐标系转换）

// 通过多载类型转化方法 F() 来实现  在P（）中宣告XY()转化方法 被转化为XY（）方法   xy = p :  p被转化为xy的类型
 
class XY {
	float x;
	float y;
public:
	XY() {
		x = y = 0.0;
	}
	XY(float a, float b) {
		x = a;
		y = b;
	}
	friend ostream& operator<<(ostream& out, XY& a) {
		out << a.x << " " << a.y << endl;
		return out;
	}
};

class P {
	double radius;
	double angle;
public:
	P() {
		radius = angle = 0;
	}
	P(float a, float b) {
		radius = a;
		angle = b;
	}
	operator XY() {		// 多载转换方法
		double x, y;
		x = radius * cos(angle);
		y = radius * sin(angle);
		return XY(x, y);
	}
};

int main() {
	P p(2.0, 35.0);
	XY f;
	f = p;
	cout << f;
}

// 多载 = 主动变自己的类型

#include <iostream>
#include <cmath>
using namespace std;

class P {
	double r;
	double a;
public:
	P() {
		r = a = 0.0;
	}
	P(double i, double j) {
		r = i;
		a = j;
	}
	double getr() {
		return r;
	}
	double geta() {
		return a;
	}
};

class XY {
	double x;
	double y;
public:
	XY() {
		x = y = 0.0;
	}
	XY(double i, double j) {
		x = i;
		y = j;
	}
	XY operator=(P p);
	friend ostream& operator<<(ostream& out, XY& obj);
};

XY XY::operator=(P p) {
	double r = p.getr();
	double a = p.geta();
	x = r * cos(a);			// double x = 就会重新给定一个新的变量
	y = r * sin(a);
	return XY(x, y);
}

ostream& operator<<(ostream& out, XY& c) {
	out << c.x << " " << c.y ;
	return out;
}

int main() {
	P p(2.0, 35.0);
	XY c;
	c = p;
	cout << c;
}
