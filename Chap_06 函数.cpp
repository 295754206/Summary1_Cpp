
// 宣告函数如果在main()前面，可直接使用
// 如果宣告函数写完整在main()后面，则在main()之前要先声明

	void some();
	
	int main(){
		some();
	} 
	
	void some(){
		cout<<"some"; 
	}
	
// 传递常数符号

	#define PI 3.14f
	
	void area(float,float);
	
	int main(){
		int r;
		cin>>r;
		area(PI,r);
	}
	
	void area(float pi,float r){
		cout<<PI*r*r;
	}

// 参数设定好预设值

	void weight(float lb = 1.0);
	
	int main(){
		weight(150.0);
		weight();
	}
	
	void weight(float lb){
		cout<<lb<<"磅 = "<<lb/2.20462<<"公斤";
	} 
	
// return 0; 表示正常结束，严格编译环境下要这么写


// 变数范围

	// 区域变数 auto : 未指明就是auto
	
		// Dev
		auto int i = 1;
		// Visual
		auto i = 1;
		
	// 共用变数 ： 在函数区域外面宣告变数，称为公用变数或全域变数
	
		double m;
		
		int main(){
			// ... m ...
		} 
	
		void c(){
			// ... m ...
		}	
		
	// 外部变数 extern : 若有个公用变数被宣告于函数之后，则使用该函数前必须宣告该变数为外部变数
	
		double d(){
			extern double c;
		} 
		 
		double c;
		
		int main(){
			for(c=0;c<=9;c++){
				// ...
			}
		}
 
 // 外部变数 实作
 
 	#include <iostream>
	#include "example.h"
	
	// example.h如下：
		double de(){
			extern double c;	// 宣告外部变数 
			double f;			// 宣告局域变数 
			f = 9*c+32;
			return f; 
		} 
	
	using namespace std;
	
	double c;	// c必须要是公用变数才能引用
	
	int main(){
		c = 12.0;
		de();		// 不用传递，直接引用 
	} 

// 寄存器变数 register ： 只适用于区域变数的宣告，不能超过2个，否则会自动转换为 auto

	register double f;	// 常用于循环，会快一点
	
// 静态变数 static 
	
	// 初始值自动为0
	// 相当于一个全域变数
	// 在大程式中sum只是total函数的区域变数，如果使用全域变数来宣告的话，会导致其他函数不能再使用sum这个名
	
	int main(){
		// ..
		for(i=1;i<=100;i++){
			oddsum = total(count);
		}
		return 0;
	} 

	int total(int n){
		static int sum;
		sum += n;
	}

// 回传函数计算总和

	int total(int);
	
	int main(){
		total(10);
	} 
	
	int total(int n){
		if(n>1){
			return n+total(n-1);
		}else{
			return 1;
		}
	}

// 定义函数巨集

	#define PI 3.14
	
	#define BEGIN {
	#define END }
	#define TAB '\t'
	
	#define ABS(n) (n<0?-n:n)
	#define EVEN(n) (n%2==0?"偶数":"奇数")
	
	// 实作
		
		#define MAX(x,y) ((x>y)?x:y)
		#define MIN(x,y) ((x<y)?x:y)
		
		int main(){
			int x = 1;
			int y = 2;
			cout<<MAX(x,y);
			cout<<MIN(x,y);
		} 
	// #define MAX(x,y,z) (x>y?x:y)>z?(x>y?x:y):z
	 
