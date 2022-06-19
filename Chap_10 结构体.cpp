#include <iostream>
#include <cstring>
using namespace std;

struct Book {
	char title[25];
	char author[25];
	char number[10];
	float price;
};

void printBook(const Book &name) {	
	// 当结构体比较大时，用传址呼叫会节省大量记忆体 :
	// void printBook(Book &name) {}
	// 但是这样被呼叫的函数可以修改资料，所以加上const阻止修改
	cout << name.title << endl;
	cout << name.author << endl;
	cout << name.number << endl;
	cout << name.price << endl;
}

Book getBook() {
	Book name;
	cin.getline(name.title, 25);
	cin.getline(name.author, 25);
	cin.getline(name.number, 10);
	cin >> name.price;
	return name;
}

int main() {
	
	// 逐个赋值

	Book CPP;
	strcpy_s(CPP.title, "C++");
	strcpy_s(CPP.author, "Auto");
	strcpy_s(CPP.number, "AEL0023");
	CPP.price = 128.0;
	printBook(CPP);

	// 一次性赋值

	Book Java = { "Java","Auto","AEL1098",154.0 };
	printBook(Java);

	// 读入资料构建结构

	Book Python;
	Python = getBook();

	cin.ignore();	// 多个输入结构体需要忽略上一个输入，即enter，(应用于getline())，清除缓存
	
	Book Go;
	Go = getBook();
	printBook(Python);
	printBook(Go);

	// 结构体数组

	Book books[2];
	for (int i = 0; i < 2; i++) {
		books[i] = getBook();
	}
}

// 巢状结构体

struct Date {
	int y;
	int m;
	int d;
};

struct Book {
	char title[25];
	char author[25];
	char number[10];
	float price;
	Date date;
};

Book getBook() {
	Book name;
	cin.getline(name.title, 25);
	cin.getline(name.author, 25);
	cin.getline(name.number, 10);
	cin >> name.price;
	cin >> name.date.y >> name.date.m >> name.date.d; // cin是以空格（和enter）为分隔
	return name;
}

int main() {
	Book t;
	t = getBook();
	cout << t.date.d;
}

#include <iostream>
using namespace std;

// 结构与指标

struct Date {
	int year;
	int month;
	int day;
};

int main() {
	
	// 宣告

	Date d;
	Date* p = &d;

	// 2种存取

	p->day = 1;
	(*p).day = 1;	// .运算是优先于*运算

}

// struct 内是指标变数

struct Data {
	int *number;
};

int main() {

	Data t;
	Data *o = &t;

	*o->number = 1;

}


