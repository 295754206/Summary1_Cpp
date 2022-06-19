#include <fstream>
using namespace std;

int main() {
	int i;
	char c;
	ofstream f;
	// 写入
	f.open("e:\\a.txt", ios::out);	// :不要写成；
	// 附加
	f.open("e:\\a.txt", ios::app);
	if (!f.is_open()) {
		cout << "打开失败" << endl;
	}
	else {
		cin >> i >> c;
		f << "I love you.\n";
		f << "It is true.\n";
		f << i << c;
	}
	f.close();
}

// 存取文字档

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	//以字符缓冲区写入文档

	ofstream f;
	char s[] = 
		"life is book.\n"
		"OK OK\n"
		"What is this\n";
	f.open("e:\\a.txt", ios::in);
	int l = strlen(s);
	for (int i = 0; i < l; i++) {
		f.put(s[i]);	
	}
	f.close();

}

// 存取文字档

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	// 输出文字档 (规格化文档)

	ifstream f;
	int id;
	char name[40];

	f.open("e:\\a.txt", ios::in);
	f >> id >> name ;
	while (!f.eof()) {		    // 判断是不是寻到最后了
		cout << id << " " << name << endl;
		f >> id >> name;		// 最后一对输不出来
	}
	f.close();
}

// 存取文字档

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	// get()缓冲区来读取

	ifstream f;
	char c;

	f.open("e:\\a.txt", ios::in);
	while (f.get(c)) {
		cout << c ;
	}

}


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char name[20] = "e:\\a.txt";

class Note {
	char s[80];
public:
	void write();
	void add();
	void read();
};

void Note::write() {
	ofstream f;
	f.open(name, ios::out);
	cout << "输入：（连续2次enter为结束）" << endl;	// 1次为输入\n表示结束，2次表示空+\n
	cin.ignore();
	while (1) {
		cin.getline(s, 80);
		if (!strlen(s) == 0) {
			f << s << '\n';
		}
		else {
			break;
		}
	}
	f.close();
}

void Note::add() {
	ofstream f;
	f.open(name, ios::app);
	cout << "输入：（连续2次enter为结束）" << endl;	// 1次为输入\n表示结束，2次表示空+\n
	cin.ignore();
	while (1) {
		cin.getline(s, 80);
		if (!strlen(s) == 0) {
			f << s << '\n';
		}
		else {
			break;
		}
	}
	f.close();
}

void Note::read() {
	ifstream f;
	f.open(name, ios::in);
	char c;
	while (f.get(c)) {
		cout << c;
	}
	f.close();
}

int main() {
	Note note;
	char c;
	while (1) {
		cout << "1写2加3读：" << endl;
		cin >> c;
		switch (c) {
		case '1':
			note.write();
			break;
		case '2':
			note.add();
			break;
		case '3':
			note.read();
			break;
		case '0':
			system("PAUSE");
		}
	}
}

#include <iostream>
#include <fstream>
using namespace std;

char file_name[20] = "e:\\a.txt";

class Student {
	int id;
	char name[20];
public:
	int getId();
	void setData();
	void showData();
	void write();
	void add();
	void read();
};

int Student::getId() {
	return id;
}

void Student::setData() {
	cout << "输入学号和名字：" << endl;
	cin >> id >> name;
}

void Student::showData() {
	cout << id << name << endl;
}

void Student::write() {
	ofstream f;
	f.open(file_name, ios::binary | ios::out);	// 二进制流输入输出
	while (1) {
		setData();
		if (getId() != 0) {
			f.write((char*)this, sizeof(*this));
			// f.write((char*)&Student_obj, sizeof(Student_obj));
			// 写入这个类
		}
		else {
			break;
		}// 实体转文字存入换新
	}
	f.close();
}

void Student::add() {
	ofstream f;
	f.open(file_name, ios::binary | ios::app);	
	while (1) {
		setData();
		if (getId() != 0) {
			f.write((char*)this, sizeof(*this));
		}
		else {
			break;
		}
	}
	f.close();
}

void Student::read() {
	ifstream f;
	f.open(file_name, ios::binary | ios::in);
	f.read((char*)this, sizeof(*this));
	while (!f.eof()) {		// 可全读出来
		showData();
		f.read((char*)this, sizeof(*this));
	}
	f.close();
}

int main() {
	Student class1;
	char n;
	while (1) {
		cout << "1写2加3读" << endl;
		cin >> n;
		switch (n) {
		case '1':
			class1.write();
			break;
		case '2':
			class1.add();
			break;
		case '3':
			class1.read();
			break;
		case '0':
			system("PAUSE");
		}
	}

	// 随意取第几笔资料

	int y;
	Student obj;
	cout << "?" << endl;
	cin >> y;
	int pos = (y - 1) * sizeof(obj);//计算
	ifstream k;
	k.open(file_name, ios::binary | ios::in);
	k.seekg(pos, ios::beg);	// 寻找
	k.read((char*)&obj, sizeof(obj));
	obj.showData();

	// 计算文件大小

	ifstream f;
	f.open(file_name, ios::binary | ios::in);
	f.seekg(0, ios::end);
	int pos = f.tellg();
	cout << "有" << pos << "bytes" << endl;

	// 计算资料数量

	int n = pos / sizeof(obj);
	cout << "有" << n << "笔" << endl;

}

// 文字档是以字元为单位，而二进位是一一笔资料为单位，二进制可以随意存取
