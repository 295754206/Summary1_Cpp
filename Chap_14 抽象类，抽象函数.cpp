#include <iostream>
using namespace std;

// 上下代同名多载函数

#include <iostream>
using namespace std;

class B {
public:
	void show(int i,int j) {
		cout << "I J:" << i << " " << j << endl;
	}
};

class C :public B {
public:
	void show(const char s[]) {
		cout << "s:" << s << endl;
	}
};

int main() {
	C c;
	c.show("I love you.");
	c.B::show(1,2);			// 上一代同名函数调用方法
}


#include <iostream>
using namespace std;

// 超载（名字相同，参数个数可能相同可能不同）

class C {
public:
	int x, y;
	C(int a, int b) {
		x = a;
		y = b;
	};
	void show() {
		cout << x << y;
	}
};

class D: public C{
public:
	int z;
	D(int i, int j, int k) :C(i, j) {
		z = k;
	}
	void show() {			// 超载
		C::show();			// 直接引用上一代代码进来
		cout << z << endl;
	}
};

int main() {
	D d(1, 2, 3);
	d.show();
}

#include <iostream>
#include <cmath>
using namespace std;

// 上下代同名异式：
// 静态结合：根据从当代向上一代方向搜索到的函数，函数中引用另一个函数，此时 按定义空间中当代定义 中找
// 动态结合：按物件是那一层定义的来找 visual

// 静态可能会产生错误：

class A {
public:
	int a;
	A(int i) {
		a = i;
	}
	int get() {
		return a;
	}
	void p() {
		cout << pow(get(), 2) << endl;
	}
};

class B :public A {
public:
	int b;
	B(int j) :A(j * 2) {
		b = j;
	}
	int get() {
		return b;
	}
};

int main() {
	B b(2);
	b.p();		// 调用的是A中的return a; 结果是16
}



#include <iostream>
#include <cmath>
using namespace std;


// 加上virtual 进行动态结合

class A {
public:
	int a;
	A(int i) {
		a = i;
	}
	virtual int get() {
		return a;
	}
	void p() {
		cout << pow(get(), 2) << endl;
	}
};

class B :public A {
public:
	int b;
	B(int j) :A(j * 2) {
		b = j;
	}
	virtual int get() {
		return b;
	}
};

int main() {
	B b(2);
	b.p();		// 加上virtual 进行动态结合 结果是4
}


#include <iostream>
using namespace std;

// 多重继承中物件的指标选择

// 若不加干预，所有的指标都是指向基础类别的

class B {
public:
	void p() {
		cout << "这是B " << endl;
	}
};

class C :public B {
public:
	void p() {
		cout << "这是C " << endl;
	}
};

int main() {
	B t;
	C g;
	B* p;
	C* p2;

	p = &t;
	p->p();			// B 
	p = &g;
	p->p();			// B

	// 	p = &t; 不可以把B类型实体分配给A类型指标，下一代同时也是属于上一代类的那一类
	p2 = &g;		// C
	p2->p();
}

#include <iostream>
using namespace std;

// 加上virtual 动态结合

class B {
public:
	virtual void p() {
		cout << "这是B " << endl;
	}
};

class C :public B {
public:
	virtual void p() {
		cout << "这是C " << endl;
	}
};

int main() {
	B t;
	C g;
	B* p;
	C* p2;

	p = &t;
	p->p();			// B 
	p = &g;
	p->p();			// C

}


#include <iostream>
using namespace std;

// B和C分别继承A，D再继承B和C，那A中成员继承了2次会报错，需要加上virtual来动态合理合并

class A {
public:
	int a=1;
};

class B :virtual public A {	// 中间重复的2个来加virtual,有冲突的来virtual
public:
	int b=2;
};

class C :virtual public A {
public:
	int c=3;
};

class D :public B, public C {
public:
	int d=4;
	void show() {
		cout << a << b << c << d << endl;
	}
};

int main() {
	D d;
	d.show();
}

#include <iostream>
using namespace std;

// 抽象类别 要求下一代一定要实现
// 基础类别 宣告是virtual的函数下一代同名不用加virtual也可以

class B {
public:
	virtual void p() = 0;	// 宣告抽象函数方法，因为可能不同类别来继承，所以用virtual来分开
};							// 同时因为 物件可能直接是下一代来定义的，所以，需要virtual来防止指标直接指向基础类别（virtual动态选择）

class C :public B {
public:
	virtual void p() {
		cout << "这是C";
	}
};
