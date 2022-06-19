
// cin

	// 位于iostream档
	
		#include<iostream> 
	
	// cin是以enter键或为结束标志
	// 若cin只含一个变数，而输入资料中含有空白，则空白后的资料会被删除 (只一笔资料不应该使用空白而使用空白，自动截取） 
	
		int i;
		cin>>i;		
	
	// 包含2个以上变数时，以空格为间隔符号
	// 多重输入中如果输入的第一个变量后就按下enter，则系统海失会等待使用输入第二个并按enter来结束（应使用空白意外使用enter还是会等待） 
	
		cin>>x1>>x2>>x3;
		
	
// 输出格式化
	
	// '\t'
	
		cout<<14<<'\t'
			<<15<<'\t'
			<<16<<endl;
			
	// 前置文档 iomanip
	
		#inlcude <iomanip>
		
	// 设定输出长度
		
		cout<<25<<"\n"
			<<setw(3)<<25<<"\n"
			<<setw(5)<<25<<"\n";
		// (25)
		// ( 25)
		// (   25)
		
	// 设定有效位数
	
		const double PI = 3.141592653;
		
		cout<<setprecision(10)<<PI<<endl;
		cout<<setprecision(8)<<PI<<endl;
		cout<<setprecision(6)<<PI<<endl;
		
	// 设定输出旗号
	
		float n = 35.7;
		
		cout<<setprecision(4)<<n;
		// ( 35.7)
		cout<<setiosflags(ios::fixed)
			<<setprecison(2)<<n;
		// 根据setprecision()来确定小数的有效位数，可以用来对齐小数点 
		// 35.7
		cout<<setiosflags(ios::fixed|ios::showpoint)
			<<setprecison(2)<<n;
		// 不足位补0
		// 35.70		 
		
		// ios::left左对齐
	
	// cout成员函数
	
		cout.precision(2);		// 设置有效位数为2 
		cout.setf(ios::fixed);	// 改为有效小数位为2 
		cout.width(10); 		// 设定输出宽度为10，该函数一次输出有效，多次输出需要多次重复设置 
		
		cout.unsetf(ios::fixed);	// 关闭小数位置格式
		cout.unsetf(ios::left);		// 关闭左对齐格式 
		 

// 输入格式化
	
	// 前提档iomanip
	
	// 宽度 
	
		char s[4];
		cin>>setw(4)>>s;	 
		
		cout<<s<<endl;
		// 输入C++显示C++
		// 输入java显示jav
		
		cin.width(5);
		// 相同效果
	
	// getline将 取得一行输入，包含空白，直到读到enter
	
		char c[81];
		cin.getline(s,81);
		
	// cin.get()获取第一个字元，以enter为结束
	// 使用后需要使用cin.ignore()来清楚输入缓存，否则再次使用cin.get()会直接读取原来的缓存
	
		char k;
		cout<<"请输入一个key"<<endl; 
		cin>>k;
		cin.ignore();
		cout<<"请再输入一个来结束" <<endl;
		cin.get();
		cout<<"谢谢\n";
		


// 算术运算

	// 上下限溢位
	 
		short n1 = 32767;
		n1 = n1+1;	
		// 为-32768
		
		unsigned short n2 = 65535;
		n2 = n2+1;
		// 为0
		
		short n3 = -32768;
		n3 = n3-1;
		// 为32767
		
		unsigned short n4 = 0;
		n4 = n4-1;
		// 为65536
	
	// 类型转换
	
		int n;
		short n1 = 32767;
		n = int(n1+1);
		// 强制类型转换要加上int()而不是自动生成
		
		int a = 5;
		int b = 3;
		float c = (float(a)/float(b));
		// 做除法前就全部各自转换为float比较好
		
		int x = 65500;
		signed short y = short(65500);
		// y为-36，大范围转小范围可能会导致溢出效果
		
		int p = 65;
		char c = char(p);
		// c为'A' 
		
		float f = 70000.0f;
		short s = short(f);
		// s为4464，因为70000的16进位为0x11170,短整数只保留0x1170也就是4464

		
// 多重指定中多等号是可以的
	
	int a,b,c,d;
	a=b=c=d=10;

	
// 随机数

	// 需要有cstdlib文档
	
		#include <cstdlib>
		using namespace std;
		
	// 固定列表的随机数rand()
	
		cout<<rand();
		cout<<rand(); 
		// 41,18467...
		
	// 不同种子产生不同的乱数表（种子乱数） 
	
		srand(3);
		rand();
		rand();
		rand();
		srand(5);
		rand();
		rand();
		rand();
		// 各个表不一样 
	
	// 利用时间产生随机乱数*** 插入的是cstdlib!!!
	
		#include <ctime>
		
		srand(time(NULL));
		rand();
		rand();
		rand();
		// time和cstdlib中NULL定义为0
		
	// 设定乱数上下范围
	
		// 下限 + rand()%(上限-下限+1)
		x = 1+rand()%(10-1+1);
		// 1-10
		y = rand()%(100+1);
		// 0-100

		
// 数学函数

	// 标题档
		
		#include <cmath> // 注意这是cmath不是math,C++没有math文档！ 
		using namespace std;
		
	// 三角函数
	
		float degree = (3.1415926f)/180;
		
		cin>>d;	// 输入度数（0-360）
		
		cout<<sin(degree*d)<<endl;
		cout<<cos(degree*d)<<endl;
		cout<<tan(degree*d)<<endl;
		
		cout<<tan(45.0f/180.0f*3.1415926f); 
		// 计算tan45°45.0f/180.0f不可以写成45/180（这样直接等于0了） 
	
	// 指数与对数
	
		double exp(2);
		// e**2
		double log(2);
		// ln(2) / log e (2)
		double log10(2);
		// log(2) / log 10 (2)
		
	// 幂次与开方
	
		double a = pow(2,3);	// 注意C++中没有直接的**运算！
		// 2**3
		double b = sqrt(3);
		// 根号3
		
	// 小数的进位（填满）与切除（下溢） (取整函数)
	
		int m = ceil(3.33);
		// 4
		int n = floor(3.33);
		// 3
	
	// 绝对值
	
		int a = fabs(5.25);
		// 5.25
		int b = fabs(-5.25);
		// 5.25
 
		
