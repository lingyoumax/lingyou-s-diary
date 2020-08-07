#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;
int tot = 0;//边的数量*2
int help_army_number = 0;//调整后可用军队数
int need_city_number = 0;//调整后仍需要驻扎子节点数
int army_number = 0;//调整前到达根节点的军队数
const int N = 60000;
const int nn = 17;
int m;//军队数
int n;//城市数
int  ver[2*N];//ver[tot]:存储第tot次add的y值
int edge[2*N];//edge[tot]:存储第tot次add的z值
int Next[2*N];//Next[tot]:存储第tot次add的x值上一次的tot'值
int head[N];//head[x]:存储x值最后一次add对应的tot值
int army[N];//army[i]:第i号军队的军队位置
int deep[N];//deep[i]:第i号城市的深度
int f[N][20];//f[i][j]:第i个节点第2^j个组先节点编号
long long dist[N][20];//dist[i][j]:第i个到它第2^j个节点的路径距离
long long l_time = 0;//二分搜索的初始左边界
long long r_time = 0;//二分搜索的初始右边界
bool stay[N];//stay[i]:i号城市是否有军队驻扎，有则stay[i]=1,否则stay[i]=0
bool need[N];//need[i]:i号城市需要军队驻扎
int tim[N];//tim[i]:重新调整军队后仍停留在根节点的军队的可用距离,这里没有记录这个军队从哪里来
int ned[N];//ned[i]:城市i在重新调整军队后仍然处于无军队驻扎,ned[i]=1,否则，ned[i]=0
long long ans;//最后时间
stack<int> mystack;
pair<long long, int> h[N];//h[i].first:该军队到达根节点后还有余力走多远;h[i].second:该军队从根节点的哪个子节点来
int read() {
	int q = 0; char ch = ' ';
	while (ch<'0' || ch>'9')ch = getchar();
	while (ch >= '0'&&ch <= '9')q = q * 10 + ch - '0', ch = getchar();
	return q;
}//读入函数
void add_line(int x, int y, int z)
{
	tot++;
	ver[tot] = y ;
	edge[tot] = z;
	Next[tot] = head[x];
	head[x] = tot;
}//添加一条边，(u,v,w)=(x,y,z)
void dfs()
{
	mystack.push(1);
	deep[1] = 1;
	while (!mystack.empty())
	{
		int x = mystack.top();
		mystack.pop();
		for (int i = head[x];i;i = Next[i]) {
			int y = ver[i];
			if (!deep[y]) {
				deep[y] = deep[x] + 1;
				f[y][0] = x;
				int k = f[y][0];
				dist[y][0] = edge[i];
				for (int j = 1;j <nn;j++)
				{
					f[y][j] = f[f[y][j - 1]][j - 1];
					dist[y][j] = dist[y][j - 1] + dist[f[y][j - 1]][j - 1];
				}
				mystack.push(y);
			}
		}
	}
}//用深度优先搜索方法构造dist数组和f数组
bool dfs(int x)
{
	bool pson = 0;//判断是否为叶子节点
	if (stay[x])
		return 1;//若当前节点已被驻扎，则返回1
	for (int i = head[x];i;i = Next[i])//遍历x的出边
	{
		int y = ver[i];
		if (deep[y] < deep[x])
			continue;//遇到父节点
		pson = 1;//若有一条不是连接着父节点的边，说明不是叶子节点
		if (!dfs(y))//若某个子节点搜索时遇到路径未被驻扎的叶子节点，直接返回0
			return 0;
	}
	if (!pson)//当前节点是叶子节点且未被驻扎
		return 0;
	return 1;//没有遇到路径未被驻扎的叶子节点，返回1
}
bool check(long long lim)
{
	memset(stay, 0, sizeof(stay));
	memset(tim, 0, sizeof(tim));
	memset(ned, 0, sizeof(ned));
	memset(h, 0, sizeof(h));
	memset(need, 0, sizeof(need));
	help_army_number = 0;
	need_city_number = 0;
	army_number = 0;
	for (int i = 1;i <= m;i++)
	{
		long long x = army[i], cnt = 0;
		for (int j = nn;j >= 0;j--)
			if (f[x][j] > 1 && cnt + dist[x][j] <= lim)
			{
				cnt += dist[x][j];
				x = f[x][j];
			}
		if (f[x][0] == 1 && cnt + dist[x][0] <= lim)
			h[++army_number] = make_pair(lim - cnt - dist[x][0], x);
		else
			stay[x] = 1;
	}//上移军队，能到根节点就到根节点，到不了就停在最浅节点
	for (int i = head[1];i;i = Next[i]) {
		if (!dfs(ver[i]))
			need[ver[i]] = 1;
	}//dfs寻找路径未被驻扎的叶子节点
	sort(h + 1, h + army_number + 1);
	for (int i = 1;i <= army_number;i++) {
		if (need[h[i].second] && h[i].first < dist[h[i].second][0])
			need[h[i].second] = 0;
		else
			tim[++help_army_number] = h[i].first;
	}//对根节点的需要被驻扎的子节点进行初步处理
	for (int i = head[1];i;i = Next[i]) {
		if (need[ver[i]])
			ned[++need_city_number] = dist[ver[i]][0];
	}//找到仍需要被驻扎的节点并存储
	if (help_army_number < need_city_number) {
		return 0;
	}
	sort(tim + 1, tim + help_army_number + 1);
	sort(ned + 1, ned + need_city_number + 1);
	int i = 1, j = 1;
	while (i <= need_city_number && j <= help_army_number) {
		if (tim[j] >= ned[i]){
			i++, j++;
		}
		else {
			j++;
		}
	}
	if (i > need_city_number) {
		return 1;
	}
	return 0;//利用贪心策略完成最后的匹配
}
int main()
{
	n = read();
	int son = 0;
	for (int i = 1;i < n;i++) {
		int x, y, z;
		x = read();
		y = read();
		z = read();
		add_line(x, y, z);
		add_line(y, x, z);
		if (x == 1 || y == 1) {
			son++;
		}
		r_time += z;
	}//输入u,v,w
	dfs();
	m = read();
	for (int i = 1;i <= m;i++) {
		army[i] = read();
		stay[i] = 1;
	}//构造军队初始信息
	if (m < son) {
		cout << -1;
		return 0;
	}
	while (l_time <= r_time) {
		long long mid = (l_time + r_time) >> 1;
		if (check(mid)) {
			r_time = mid - 1;
			ans = mid;
		}
		else {
			l_time = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
