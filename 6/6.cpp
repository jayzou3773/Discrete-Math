#include <iostream>
using namespace std;
void warshall(int a[],int n)
{
	//(1)i��1��
	//(2)������j���a[j��i]��1�����k��0��1������n-1��a[j��k]��a[j��k]��a[i��k]��
	//(3)i��1��
	//(4)���i<n����ת������2������ֹͣ
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
					a[n*j+k] = a[n*j+k] | a[n*i+k];//�߼��� 
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
		cout << "�����뷽��Ľ���:";
		cin >> n;
		if (!cin.good()) {
			cout << "�����������������" << endl;
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
		cout << "���������ĵ�" << i+1 << "��Ԫ��(Ԫ���Կո�ָ�):";
		for (j = 0; j < n; j++)//���������
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
			cout << "��" << i << "������������������룡" << endl;
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