#include <iostream>
using namespace std;

int point[100];
double sum=0;
struct edge {
	int start, end;
	int quan;
};
class Graph {
public:
	int len, n;
	edge* list;
	void Init(Graph& g);
};
void Graph::Init(Graph& g)
{
	g.len = 0;
	g.list = new edge[100];
}
void getinput_list(Graph& g)
{
	while (1) {
		cout << "�����붥������ͱߵĸ���(�ո�ָ�)";
		cin >> g.n >> g.len;
		if (cin.good() && g.len > 0 && g.n > 0)
			break;
		cout << "�����������������" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');

	}
	for (int k = 1; k <= g.n; k++)
		point[k] = k;
	int i = 1;
	for (; i <= g.len; i++) {
		cout << "�������������㼰�ߵ�Ȩֵ:"<<endl;
		cin >> g.list[i].start>>g.list[i].end>>g.list[i].quan;
		if (!cin.good() || g.list[i].start > g.n || g.list[i].end > g.n || g.list[i].start <= 0 || g.list[i].end <= 0 || g.list[i].quan <= 0)
		{
			cout << "�����������������" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			i--;
			continue;
		}
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}
void sort(Graph g)//��Ȩֵ��С����
{
	int i=1,j = 0;
	for (;i<=g.len;i++)
		for (j = i + 1; j < g.len; j++) {
			if (g.list[j].quan < g.list[i].quan) {
				g.list[0] = g.list[j];
				g.list[j] = g.list[i];
				g.list[i] = g.list[0];
			}
		}
}
int findroot(Graph g, int bingchaji[], int x)//��Դ����
{
	int y;
	for (int i = 1; i <= g.n; i++)
		if (point[i] == x)
			y = i;
	while (bingchaji[y] != y)//�ҵ�·���ľ�ͷ
		y = bingchaji[y];
	return y;
}
void output(int a[], int b[],int k)
{
	int i = 0;
	for (; i < k; i++)
		cout << "��С�ķ���" << a[i] << "��" << b[i] << endl;
}
void Kruskal(Graph g)//kruckal�㷨ʵ��
{
	int bingchaji[100],k=0,a[100]={0}, b[100]={0};
	for (int i = 1; i <= g.n; i++)
		bingchaji[i] = i;
	for (int i = 1; i <= g.len; i++) {
		int p1, p2;
		p1 = findroot(g, bingchaji, g.list[i].start);
		p2 = findroot(g, bingchaji, g.list[i].end);
		if (p1 != p2) {//Դͷ����ͬ��˵��������Ȧ
			bingchaji[p1] = p2;
			a[k] = g.list[i].start;
			b[k] = g.list[i].end;
			sum += g.list[i].quan;
			k++;
		}
	}
	output(a, b, k);
	cout << "�ܺķ�Ϊ" << sum << endl;
}
int main()
{
	Graph g;
	g.Init(g);
	getinput_list(g);
	sort(g);
	Kruskal(g);
	return 0;
}