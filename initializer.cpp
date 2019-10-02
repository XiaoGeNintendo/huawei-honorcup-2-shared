#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <assert.h>
#include <windows.h>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <chrono>
#include <time.h>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
const double at=0.99992;
const double discrete=2.8;
const int attempt=5000;
using namespace std;
const int dx[]={0,-1,0,1};
const int dy[]={-1,0,1,0};
vector <vector<double> > frag[64];
double adj[64][64][4];
int now[64];
int choose[64];
bool fix[64];
double best;
double cur;
srand();
int newadj[64][64][4];

/*
dir:
0
-------
| | | |
-------
|*|*| |
-------
| | | |
-------


1
-------
| |*| |
-------
| |*| |
-------
| | | |
-------

and so on..
*/
using namespace std;
double EstimateValue(int x);
double EstimateAdj(vector <vector<double> >&a,vector <vector<double> >&b,int dire,double k);
double EstimateVector(vector <double> &a,vector <double> &b,double k);
vector<vector<double> > ReadGreyFrag();
void PrintGreyFrag(vector<vector<double> > &vec);
const int n=64;
double EstimateAdj(vector <vector<double> >&a,vector <vector<double> >&b,int dire,double k)
{
	vector <double> v1;
	vector <double> v2;
	if(dire==0)
	{
		for(int i=0;i<n;i++)
		{
			v1.push_back(a[i][0]);
			v2.push_back(b[i][n-1]);
		}
	}
	if(dire==1)
	{
		v1=a[0];
		v2=b[n-1];
	}
	if(dire==2)
	{
		for(int i=0;i<n;i++)
		{
			v1.push_back(a[i][n-1]);
			v2.push_back(b[i][0]);
		}
	}
	if(dire==3)
	{
		v1=a[n-1];
		v2=b[0];
	}
	return EstimateVector(v1,v2,k);
}
double EstimateVector(vector <double> &a,vector <double> &b,double k)
{
	vector <bool> vec;
	vec.resize(n);
	for(int i=0;i<n;i++)
	{
		vec[i]=(abs(a[i]-b[i])<=k);
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=vec[i];
	}
	return EstimateValue(sum);
}
double sigmoid(double x)
{
	return 1.0/(1.0+exp(-x));
}
double EstimateValue(int x)
{
	double t=(double)(x-32)/64*15;
	return sigmoid(t);
}
vector<vector<double> > ReadGreyFrag()
{
	vector <vector<double> >vec;
	vector <double> v;
	v.resize(n);
	double x;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>v[j];
		}
		vec.push_back(v);
	}
	return vec;
}
void PrintGreyFrag(vector<vector<double> > &vec)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<(int)vec[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}

void test()
{
	vector<vector<double> >a=ReadGreyFrag(),b=ReadGreyFrag();
	double k=2;
	for(int i=0;i<4;i++)
	{
		cout<<EstimateAdj(a,b,i,k)<<endl;
	}
}

bool out(int x,int y)
{
	return (x<0 || y<0 || x>=8 || y>=8);
}

double calc(int now[])
{
	double res=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			for(int d=0;d<2;d++)
			{
				int nx=i+dx[d];
				int ny=j+dy[d];
				if(out(nx,ny)) continue;
				res+=adj[now[i*8+j]][now[nx*8+ny]][d];
			}
		}
	}
	return res;
}

void random(int use[],int l,int r)
{
	for(int i=l+2;i<r;i++)
	{
		swap(use[i],use[rand(l,i-1)]);
	}
}

inline double calcAhasB(int pos,int value)
{
	int i=pos/8,j=pos%8;
	double res=0;
	for(int d=0;d<4;d++)
	{
		int nx=i+dx[d];
		int ny=j+dy[d];
		if(out(nx,ny)) continue;
		res+=adj[value][now[nx*8+ny]][d];
	}
	return res;
}

inline bool isadj(int x,int y)
{
	if(x>y) swap(x,y);
	return (y-x==8 || (y-x==1 && y%8!=0));
//	return (abs(x-y)==1 || abs(x-y)==8);
}

inline double badadj(int x,int y,int bad)
{
	int i=x/8;
	int j=x%8;
	for(int d=0;d<4;d++)
	{
		if(((i+dx[d])*8+(j+dy[d]))==y)
		{
			return adj[now[x]][now[y]][d^bad];
		}
	}
	assert(false);
}

inline double calcswap(int x,int y)
{
	if(isadj(x,y)) assert(badadj(x,y,0)==badadj(y,x,0));
	if(isadj(x,y)) assert(badadj(x,y,2)==badadj(y,x,2));
	return calcAhasB(x,now[y])+calcAhasB(y,now[x])-calcAhasB(x,now[x])-calcAhasB(y,now[y])+(isadj(x,y)?badadj(x,y,2)+badadj(x,y,0):0);
}

inline double calcswapcol(int x)
{
	if(x==n) return 0;
	double res=0;
	double a1=0,a2=0;
	for(int i=0;i<8;i++)
	{
		res-=adj[now[i*8+x-1]][now[i*8+x]][2];
		a1-=adj[now[i*8+x-1]][now[i*8+x]][2];
		res+=adj[now[i*8]][now[i*8+7]][0];
		a2+=adj[now[i*8]][now[i*8+7]][0];
	}
	cout<<a1<<' '<<a2<<endl;
	return res;
}

inline double calcswaprow(int x)
{
	if(x==n) return 0;
	double res=0;
	for(int j=0;j<8;j++)
	{
		res-=adj[now[(x-1)*8+j]][now[x*8+j]][3];
		res+=adj[now[j]][now[7*8+j]][1];
	}
	return res;
}

void dfs(double Time)
{
//	assert(cur==calc(now));
	if(cur>best)
	{
		best=cur;
		for(int i=0;i<64;i++)
		{
			choose[i]=now[i];
		}
	}
	double delta;
	int times=0,x=-1,y=-1;
	do
	{
		delta=0;
		do
		{
			x=rand(0,63);
			y=rand(0,63);
		}while(fix[x] || fix[y] || x==y);
		times++;
		delta=calcswap(x,y);
		if(times>=attempt) break;
		if(delta>0 || (delta!=0 && exp(discrete*delta/Time)>1.0*rand(0,1000000)/1000000)) break;
	}while(true);
	if(times<attempt)
	{
		swap(now[x],now[y]);
		cur+=delta;
		dfs(Time*at);
		cur-=delta;
		swap(now[x],now[y]);
	}
}

void solve(int T)
{
//	memset(fix,0,sizeof(fix));
	random(now,0,64);
	random(now,0,64);
	random(now,0,64);
	random(now,0,64);
	random(now,0,64);
	if(T%8==0) best=cur=calc(now);
	dfs(1);
	for(int x=0;x<8;x++)
	{
		for(int y=0;y<8;y++)
		{
			for(int k=0;k<4;k++)
			{
				int nx=x+dx[k];
				int ny=y+dy[k];
				if(out(nx,ny)) continue;
				newadj[choose[x*8+y]][choose[nx*8+ny]][k]++;
			}
		}
	}
}

void Solve()
{
//	random(now,0,64);
	double Time=2000;
	double delta;
	cur=calc(now);
	int x,y;
	while(Time>=1e-14)
	{
		do
		{
			x=rand(0,63);
			y=rand(0,63);
		}while(fix[x] || fix[y] || x==y);
		delta=calcswap(x,y);
		if(delta>0)
		{
			swap(now[x],now[y]);
			cur+=delta;
		}
		else if(exp(delta/Time)>1.0*rand(0,1000000)/1000000)
		{
			swap(now[x],now[y]);
			cur+=delta;
		}
		if(cur>best)
		{
			best=cur;
			for(int i=0;i<63;i++)
			{
				choose[i]=now[i];
			}
		}
		Time*=at;
	}
	cout<<best<<endl;
}

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		cout<<"argc!=2\n";
		cout<<"Call 110, thank you\n";
		return -1;
	}
	freopen(argv[1],"r",stdin);
	ios_base::sync_with_stdio(false);
	for(int i=0;i<64;i++)
	{
		frag[i]=ReadGreyFrag();
	}
	vector <pair<pair<double,int>,int> >vec;
	for(int i=0;i<64;i++)
	{
		for(int j=0;j<64;j++)
		{
			for(int d=0;d<4;d++)
			{
				if(i==j)
				{
					adj[i][j][d]=0;
					continue;
				}
				adj[i][j][d]=EstimateAdj(frag[i],frag[j],d,4);
			}
		}
	}
//	for(int i=0;i<64;i++)
//	{
//		for(int j=0;j<4;j++)
//		{
//			cout<<adj[0][i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	return 0;
	fclose(stdin);
//	freopen("answer.txt","r",stdin);
	for(int i=0;i<64;i++)
	{
		now[i]=i;
	}
//	cout<<"DONE\n";
	for(int i=0;i<64;i++)
	{
		for(int j=0;j<64;j++)
		{
			if(i==j) continue;
			double t=calc(now)+calcswap(i,j);
			swap(now[i],now[j]);
			double tt=calc(now);
//			if(tt!=t)
//			{
//				cout.precision(20);
//				cout<<tt<<' '<<t<<endl;
//				cout<<i<<' '<<j<<endl;
//				return 0;
//			}
			swap(now[i],now[j]);
		}
	}
	for(int i=0;i<64;i++)
	{
		now[i]=i;
	}
	random(now,0,64);
	for(int i=0;i<128;i++)
	{
		solve(i);
//		Solve();
	}
	freopen("value0.out","w",stdout);
	for(int i=0;i<64;i++)
	{
		for(int j=0;j<64;j++)
		{
			for(int d=0;d<4;d++)
			{
				double t=((double)newadj[i][j][d]-64)/128*15;
				cout<<sigmoid(t)<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
	}
	for(int i=0;i<64;i++)
	{
		now[i]=choose[i];
	}
	cout<<calc(choose)<<endl;
	return 0;
}
