#include <iostream>
#include <cstring>
using namespace std;

/* class与struct的区别在于struct只包含成员资料，而class还包含成员函数 */

// 无private、无初始建立函数 的class

class Cuboid {
public:
	int length;
	int width;
	int height;
	int volumn() {
		return length * width * height;
	}
};

int main() {
	Cuboid rt = { 6,8,10 };
	cout << rt.length << endl;
	cout << rt.volumn();
}

// 无初始建立函数 的class

class Cylinder {
	float radius;		// private 外界不可直接使用 rt.radius来读取成员变量了
	float height;
	int ID;
public:					// public 以上默认为 private （private可以写可以不写）
	void setCylinder(int x,int y){
		radius = x;		// 直接使用类别里面的成员名字
		height = y;
	}
	void setID();		// 类别外定义方法（用于隐藏代码）
};

void Cylinder::setID() {		// class外实现，如果是建立者函数，则前面无需加返回类型
	cout << "输入ID:";
	cin >> ID;			// 同样直接使用类别里面的成员名字
}

// 有建立函数的标准 class

class Employee {
	int ID;
	char name[20];
public:
	Employee() {
		ID = 0;
		strcpy_s(name, "none");
	}
	Employee(int id, char *name);
	void p() {
		cout << ID << endl;		// 默认的其实是 this->ID , this是本类别对象的指标，或者像(*this）.ID
		cout << name << endl;
	}
};

Employee::Employee(int id, char s[20]) {
	ID = id;
	strcpy_s(name, s);
}

int main() {
	Employee e1;
	Employee e2;
	e1.p();
	e2.p();
}

// 以上可以直接写成预设格式

class Employee {
	int id;
	char name[20];
public:
	Employee(int id = 0, const char s[20] = "none") {
		ID = id;
		strcpy_s(name, s);
	}
};

int main() {
	Employee e1;
	Employee e2(123,"Tom");
	e1.p();
	e2.p();
	e1 = e2;	// 类别的直接复制
	e1.p();
}

// const 类别不可变动，宣告后也只能用后面加const的函数

#include <iostream>
#include <cstring>
using namespace std;

class Employee {
	int ID;
	char name[20];
public:
	Employee(int id, const char s[20]) {
		ID = id;
		strcpy_s(name, s);
	}
	void p() const {
		cout << this->ID << endl;
		cout << this->name << endl;
	}
};

int main() {
	const Employee e1(123, "Jim");
	e1.p();
	Employee e2(1234, "Tim");		// 不影响非const的对象正常使用
	e2.p();
}

#include <iostream>
#include <cstring>
using namespace std;

// friend 函数是通用函数，是外界使用该类别的一个接口,包含private都可存取

class First {
	int x;
public:
	void setx(int y) {
		this->x = y;
	}
	friend int getx(First obj) {
		return obj.x;
	}
};

int main() {
	First a, b;
	a.setx(1);
	b.setx(2);
	cout << (getx(a) + getx(b));		// 类别内函数需要A.func()来运用，friend通用函则不需要
}

// 适用于例如 累加运算 的 static 资料成员 和 成员函数

class Oddsum {
	static int sum;
public:
	static void add(int n);
	void display();
};

int Oddsum::sum = 0;	// 每次运算都是从0开始

void Oddsum::add(int n) {
	sum += n;
}

void Oddsum::display() {
	cout << "sum=" << sum << endl;
}

int main() {
	Oddsum a;
	a.add(9);
	a.display();
}

// 传递物件参数

class A {
public:
	int x = 0;
};

class B {
public:
	int y = 1;
	int sum(A obj) {
		return y+obj.x;
	}
	// 透过指标的写法：
	int sum(A *obj) {
		return y + obj->x;
	}
};

int main() {
	B b;
	A a;
	cout << b.sum(a);
	// 透过指标的写法：
	cout << b.sum(&a);
}

// 传回类别

class Ca {
	int x;
public:
	Ca(int n) {
		x = n;
	}
	// 传回类型（内容）
	Ca CaSum(Ca obj) {
		x += obj.x;
		return *this;
	}
	// 传回类型的指标
	Ca* CaSum2(Ca obj) {
		x += obj.x;
		return this;
	}
};

int main() {
	Ca a(100),b(200),c(0);
	// 传回类型
	c = a.CaSum(b);
	// 传回指标
	c = *(a.CaSum2(b));
}
