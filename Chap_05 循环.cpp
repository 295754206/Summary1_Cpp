
// 自增自减运算符只能用在 变量 上，不可以使用于 常数 

// for

	for(int i=1;i<5;i++){
		cout<<i;
	} 
	
// while 

	while(count<5){
		cout<<"some";
		count++;
	}
	
// break;跳出循环 
// continues;进入下一轮循环 

// 由于有的编译器不支持两次局部宣告 int x,所以最好直接在外部定义 int x然后两次使用

	for(int x=1;x<5,x++){
		cout<<"some";
	};
	for(int x=1;x<5;x++){
		cout<<"other";
	};
	// 有的编译器不支持这么做
	
	int x;
	for(x=1;x<5,x++){
		cout<<"some";
	};
	for(x=1;x<5;x++){
		cout<<"other";
	};
	// 这么做会比较好
	

// 计时器案例***

	#include <iostream>
	#include <iomanip>
	#include <ctime> ***
	
	using namespace std;
	
	int main(){
		cout.setf(ios::fixed|ios::right);	// 设定输出向右对齐 
		cout.fill('0');						// 填充0
		while(true){
			for(int h=0;h<24;h++){
				for(int m=0;m<60;m++){
					for(int s=0;s<60;s++){
						cout<<setw(2)<<h<<":"
							<<setw(2)<<m<<":"
							<<setw(2)<<s<<" ";
						cout<<'\r';			// 游标回到前面，可以覆盖上一秒
						unsigned int start = time(0)+1;
						while(time(0)<start);	// 延迟1秒 
					}
				}
			}
		}
	}
	// 按ctrl+c可中断程序

// 寻找质数（1不是质数，2=1*2是质数）（因数只有1和它本身）

	cout<<"1-30的质数有："<<endl;
	
	for(int i=2;i<=30;i++){
		for(j=2;j<i;j++){
			if(i%j==0){
				break;		// 除数从2->这个数减 1 
			}
		}
	} 
	
// 求二数的GCD(最大公因数)
	
	int a,b,n;
	cin>>a>>b;
	// 任取一个数字不管谁大谁小，从它开始不断减一（直到最小为1），用2个数去%这个数字，得到的第一个公因数即是gcd
	for(n=a;a>=1;n--){
		if(a%n==0&&b%n==0){
			break;
		}
	} 
	cout<<"gcd is "<<n;

//	求二数的LCM(最小公倍数)

	int a,b,n;
	cin>>a>>b;
	// 任取一个数字不管谁大谁小，从它开始不断倍加（直到大于2数字的积），用这个数去%第二个数，得到的第一个即为最小公倍数
	for(n=a;n<a*b;n+=a){
		if(n%b==0){
			break;
		}
	} 
	cout<<"lcm is "<<n;
	
	
