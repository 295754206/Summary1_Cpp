#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

int main() {
	char s1[80],s2[80];
	char t1[80];
	cout << "输入字串s1:";
	// 获取字串 [cstring]
	cin.getline(s1, 80, '\n');
	// 取得字串长度
	cout << "字串长度：" << strlen(s1);
	// 复制字串（第一个是target,第二个是原字串）
	strcpy_s(t1, s1);
	cout << "复制后的字串t1:" << t1;
	cout << "输入s2:";
	cin.getline(s2, 80, '\n');
	// 比较字串
	int flag = strcmp(s1, s2); // 第一个与第二个比较的结果（1，0，-1）（ASCII码的比较）
	cout << flag;
	// 串接字串(串接到第一个字串中)
	strcat_s(s1, s2);
	cout << s1 << endl;
	// 大小写转换(字元逐个转换) [cctype]
	int len = strlen(s1);
	for (int i = 0; i < len; i++) {
		s1[i] = tolower(s1[i]);
	};
	cout << s1;
	for (int i = 0; i < len; i++) {
		s1[i] = toupper(s1[i]);
	};
	cout << s1;

}


#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc,char** argv) {
	double d;
	int i;
	long l;
	char s1[] = "-1998.12E-25abc";
	char s2[] = " 686 pigs";
	char s3[] = " 98689 dollars";
	// 字串转换为float、int、long
	d = atof(s1);
	i = atoi(s2);
	l = atol(s3);
	cout << d << endl
		 << i << endl
		 << l << endl;
	// 数字转换为字串(最后一个参数为进制)
	_itoa_s(1234, s1, 10);
	_itoa_s(1234, s2, 8);
	_itoa_s(1234, s3, 16);
	cout << s1 << endl
		 << s2 << endl
		 << s3 << endl;
}



#include <iostream>
#include <string>
using namespace std;

// C++字串类别

int main() {

	// char 类别字串

	const char* name = "abc";
	char name2[20] = "defg";

	// string 类别字串

	string s1;
	string s2("John Arich");
	string s3 = "Mary";
	string s4("A", 4);	  // "AAAA"
	string s5(s2);		  // == s2
	string s6(s2, 0, 4);  // "John"

	string s7;
	s7.assign(s2, 0, 4);
	s7[0] = 'n';

	// 输入 string

	string s1;
	cin >> s1;	// 这种方式会切除子串中空白以后的部分

	string s2;
	getline(cin, s2);

	// 类别中的 = 是复制成员资料给新的物件

	string s1("QRQ");
	string s2 = s1;

	// 串接字串

	s3 = s1 + s2;
	s3 += " VR";
	string s4(s3 + "!");

	s1.append(s2);
	s1.append(s3, 4, 2);	// 从s3[4]开始截取2个

	// 比较字串

	s1 == s2;	// bool
	s1 != s2;
	s1 > s2;	// 首字母比较ASCII

	s1.compare(0, 3, s2, 7, 3);	// 分别从0和7开始各截取3个比较，0为相同

	// 截取子字串、对调字串、寻找字串、插入字串

	s2 = s3.substr(6, 5);	// 6开始取5个
	s2.swap(s3);
	s1.find("C++");			// 返回第一个字符位置
	s1.find(s2);			// 没找到则为-1
	s1.insert(4, s3);		// 从4开始插入s3
	s1.insert(4, "\0");

	// 替换字符

	string s("Tom OBJ WE");
	int p = s.find(" ");
	while (p < string::npos) {	// p不是最后一个
		s.replace(p, 1, "-");
		s.find(" ",p++);
	}

	// 成员函数

	s1.length();
	s1.size();
	s1.capacity();

	s1.max_size();
	s1.at(10);

	// string 数组

	string s[3] = { "Q","P","VR" };
	string s2[] = { "Q","P","VR" };

}

#include <iostream>
#include <string>
using namespace std;

// 获取子串中对称字的个数
// 先每个逐个截取，直到读到空白

int main() {
	string s = "Tom I noon later";
	string s1, s2;
	int c, len;
	len = s.length();
	for (int i = 0; i < len; i++) {
		// 截取子字串
		if (isalnum(s.at(i))) {		// 英文或数字
			s1 += s.at(i);
			if (i != (len - 1)) {
				continue;
			}
		}
		// 检查对称字
		bool f = true;
		int len2 = s2.length();
		for (int j = 0; j < (len2 / 2); j++) {
			if (s2.at(j) != s2.at(len2 - 1 - j)) {
				f = false;
				break;
			}
		}
		// 计数并清空
		if (f == true) {
			c++;
		}
		s1 = "";
	}
}
