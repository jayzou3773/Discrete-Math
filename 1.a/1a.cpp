#include <stdio.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int a[4];
	int i = -1,j = -1;
	char s;
 tt:cout << "***************************************\n";   //标语
	cout << "**                                   **\n"; 
	cout << "**        欢迎进入逻辑运算程序       **\n"; 
	cout << "**                                   **\n"; 
	cout << "***************************************\n\n";
	cout << "\n  请输入P的值（0或1）,以回车结束:";
	cin >> i;  //读取P的值
	if(i!=0 && i!=1)
	{
		cout << "\n  P的值输入有误,请重新输入!";
		Sleep(2000);
		system("cls");  //清屏
		goto tt;
	}
	cout << "\n  请输入Q的值（0或1）,以回车结束:";
	cin >> j;  //读取Q的值
	if(j!=0 && j!=1)
	{
		cout << "\n  Q的值输入有误,请重新输入!";
		Sleep(2000);
		system("cls");  //清屏
		goto tt;
	}
	a[0] = i && j;  //与运算
	a[1] = i || j;  //或运算
	a[2] = (!i) || j;  //蕴含运算，将其转化为与或非形式
	a[3] = ((!i) || j) && ((!j) || i);  //等值运算，将其转化为与或非形式
	cout << "\n\n  合取:\n       P/\\Q = " << a[0] << endl;   //输出结果
	cout << "  析取:\n       P\\/Q = " << a[1] << endl; 
	cout << "  条件:\n       P->Q = " << a[2] << endl; 
	cout << "  双条件:\n       P<->Q = " << a[3] << endl;
 bb:cout << "\n是否继续运算?（y/n）";  //询问是否继续操作
	cin >> s; 
	if (s == 'y' || s == 'n')
	{
		if (s == 'y')
		{ 
			system("cls");  //清屏
			goto tt;  //返回顶层
		}
		else
		{
			cout << "欢迎下次再次使用!\n";  //退出
			exit(0);
		}
	}
	else
	{
		cout << "输入错误,请重新输入!\n"; //错误校验
		goto bb;
	}
	return 0;
}
