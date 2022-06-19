#include <iostream>
using namespace std;

// public 所有应用可取
// private 仅自己可取，外部不可取
// protected 专门为下一代提供内部使用接口，下一代可取，其他同private(即定义的物件不可以直接使用相关成员和函数)

// public 为外界直接使用 和 定义的物件直接使用
// protected 和 private 都是类的定义里面仅定义里面自己去使用

// public	 继承：上一代维护不变，权限不升级
// protected 继承：上一代权限不足 protected 的升级为 protected
// private   继承：上一代权限不足 private 的升级为 private




class Point {
protected:
	int x, y;		// 此处如果是private则下一代Area1中就不能直接使用x*y这种表述了
public:
	void setxy(int a,int b) {
		x = a;
		y = b;
	}
	void show() {
		cout << x << " " << y << endl;
	}
};

// public 继承

class Area1 :public Point {
public:
	void showarea() {
		cout << x * y << endl;
	}
};

// private 继承

class Area2 :private Point {
public:
	void setPoint(int a, int b) {
		setxy(a, b);
	}
	void showPoint() {
		show();
	}
	void showArea() {
		cout << x * y << endl;	// private 改写上一代继承下来，本定义中任然可以取读private，外界定义实作时候不可以使用上一代的.show()等
	}
};

// protected 继承同 private



// 多代继承

class TwoD {
protected:
	int x, y;
public:
	void setxy(int a,int b) {
		x = a;
		y = b;
	}
};

class ThreeD :public TwoD {
protected:
	int z;
public:
	void setz(int c) {
		z = c;
	}
};

class Cube :public ThreeD {
public:
	void show() {
		cout << "面积：" << x * y << endl;
		cout << "体积：" << x * y * z << endl;
	}
};

int main() {
	Cube c;
	c.setxy(1, 2);
	c.setz(3);
	c.show();
}


#include <iostream>
using namespace std;




// 多个继承

class XY {
protected:
	int x, y;
public:
	void setxy() {
		x = y = 2;
	}
};

class Z {
protected:
	int z;
public:
	void setz() {
		z = 3;
	}
};

class Cube :public XY, public Z {
public:
	void show() {
		cout << x << " " << y << " " << z << endl;
	}
};

int main() {
	Cube c;
	c.setxy();
	c.setz();
	c.show();
}


// 多代继承，多层继承时，分别是从 最开始代、从上向下、从左到右逐个来建立建立者函数

#include <iostream>
using namespace std;

// 多代继承中 传递建立者参数

class Point {
protected:
	int x, y;
public:
	Point(int a, int b) {
		x = a;
		y = b;
	}
};

class Area :public Point {
public:
	Area(int a, int b) :Point(a, b) {	// 传递给上一代建立者

	};
	void show() {
		cout << x << " " << y << endl;
	}
};

int main() {
	Area a(1, 2);
	a.show();
}


// 继承中函数如果上下代同名，则按照本代来算，其中如果要求相同：
void set(){
	Employee::set();	// 这样呼叫上一代的同名函数
}


// 三维坐标中正常使用（包含到）二维坐标这个类别

#include <iostream>
using namespace std;

class TwoD {
public:
	int x, y;
	TwoD() {
		x = y = 0;
	}
	TwoD(int a, int b) {
		x = a;
		y = b;
	}
};

class ThreeD {
public:
	int z;
	TwoD d;
	ThreeD(int i, int j, int k) {
		TwoD t(i, j);
		d = t;
		z = k;
	}
	void show() {
		cout << d.x << d.y << z << endl;
	}
};

int main() {
	ThreeD t(1, 2, 3);
	t.show();
}
