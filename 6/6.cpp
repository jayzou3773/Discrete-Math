#include <iostream>
using namespace std;
void warshall(int a[],int n)
{
	//(1)i＝1；
	//(2)对所有j如果a[j，i]＝1，则对k＝0，1，…，n-1，a[j，k]＝a[j，k]∨a[i，k]；
	//(3)i加1；
	//(4)如果i<n，则转到步骤2，否则停止
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[n*j+i])
			{
				for (k = 0; k < n; k++)
				{
					a[n*j+k] = a[n*j+k] | a[n*i+k];//逻辑加 
				}
			}
		}
	}
}

int main()
{
	int n,i,j,flag=0;
	while (1)
	{
		cout << "请输入方阵的阶数:";
		cin >> n;
		if (!cin.good()) {
			cout << "输入错误，请重新输入" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		else
			break;
	}
	int* a = new int[n * n];
	for (i = 0; i < n; i++)
	{
		cout << endl;
		cout << "请输入矩阵的第" << i+1 << "行元素(元素以空格分隔):";
		for (j = 0; j < n; j++)//输入错误处理
		{
			cin >> a[i*n+j];
			if (cin.good() != 1) {
				flag = 1;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				break;
			}
			if (a[i * n + j] != 1 && a[i * n + j] != 0) {
				flag = 1;
				cin.ignore(INT_MAX, '\n');
				break;
			}
			flag = 0;
		}
		if (flag == 1)
		{
			cout << "第" << i << "行输入错误，请重新输入！" << endl;
			i--;
		}
	}
	warshall(a, n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			cout << a[i * n + j]<<" ";
		cout << endl;
	}
	return 0;
}