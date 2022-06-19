
// if

	if(){
		
	};
	
	if(){
		
	}else if(){
		
	}else{
		
	};
	
// do .. while

	do{
		
	}while();
	
// switch

	switch(x+1){
		case 12:
			cout<<"是12";
			break;
		case 'Y':
		case 'y':			// 注意case后面跟的是一个量，而不是表达式，所以不会有case 'Y'||'y' 这种 
			cout<<"是Y/y";
			break;
		default:
			cout<<"其它";
	} 
	
// 获取键盘输入按键

	char c;
	cout<<"请按Y键";
	cin>>c;
	if(c=='Y'||c=='y'){
		cout<<"OK";
	};
	// 判断字母大小写>='A'&&<='Z' 
	// 闰年：4的倍数不是100的倍数：普通闰年；400的倍数：世纪闰年 
	
// bool x = true, 则 x 为 1, 关系比较中的flag 最终计算结果也是 0/1。 

// short范围是-32768->32767，不得大于这2个数 

// 条件运算式

	cout<<((num>0)?"正数":"负数"); 
	
