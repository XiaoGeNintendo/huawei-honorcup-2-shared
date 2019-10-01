#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <assert.h>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <chrono>
#include <time.h>
#include <E:\C++\dev c++\ShiMaoC++\¿¼ÊÔ\HuaweiHonorCup\JudgeAdjacent.h>
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
const double discrete=3;
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

class Rubbish
{
//	for(int i=0;i<64;i++)
//	{
//		memset(adj[i].nei,-1,sizeof(adj[i].nei));
//	}
	pair<int,double> predict(vector <vector<double> > &a,vector <vector<double> >&b,double k)
	{
		for(int i=0;i<4;i++)
		{
			if(EstimateAdj(a,b,i,k)!=0) return mp(i,EstimateAdj(a,b,i,k));
		}
		return mp(-1,-1.0);
	}
//	for(int i=0;i<64;i++)
//	{
//		vec.clear();
//		for(int j=0;j<64;j++)
//		{
//			if(i==j) continue;
//			pair<int,double> t=predict(frag[i],frag[j],4);
//			vec.push_back(mp(mp(t.second,t.first),j));
//		}
//		sort(all(vec));
//		reverse(all(vec));
//		vec.erase(unique(all(vec)),vec.end());
//		if(vec.size()<4)
//		{
//			cout<<"FUCK\n";
//			cout<<i<<endl;
//			return 0;
//		}
//		for(int j=0;j<4;j++)
//		{
//			for(int k=0;k<vec.size();k++)
//			{
//				if(vec[k].first.second==j)
//				{
//					adj[i].nei[j]=vec[k].second;
//					break;
//				}
//			}
//		}
//	}
//	for(int i=0;i<64;i++)
//	{
//		for(int j=0;j<4;j++)
//		{
//			cout<<adj[i].nei[j]<<' ';
//		}
//		cout<<endl;
//	}
};

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

void dfs(double Time)
{
//	if(cur!=calc(now))
//	{
//		cout<<cur<<' '<<calc(now)<<endl;
//		exit(0);
//	}
	assert(cur==calc(now));
//	cout<<Time<<endl;
	if(cur>best)
	{
		best=calc(now);
//		best=cur;
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
		}while(fix[x] || fix[y] || x==y/* || isadj(x,y)*/);
		times++;
		delta=calcswap(x,y);
		if(times>=attempt) break;
//		if(delta>0) break;
		if(delta>0 || (delta!=0 && exp(discrete*delta/Time)>1.0*rand(0,1000000)/1000000)) break;
	}while(true);
//	cout<<x<<' '<<y<<endl;
	if(times<attempt)
	{
		swap(now[x],now[y]);
		cur+=delta;
		dfs(Time*at);
		cur-=delta;
		swap(now[x],now[y]);
	}
}

void solve()
{
	memset(fix,0,sizeof(fix));
	for(int i=0;i<64;i++)
	{
		now[i]=i;
	}
	random(now,0,64);
	for(int i=0;i<64;i++)
	{
		if(now[i]==32)
		{
			swap(now[0],now[i]);
			break;
		}
	}
//	fix[0]=true;
//	best=calc(now);
	cur=calc(now);
	best=max(best,cur);
	dfs(1);
	assert(calc(now)==cur);
//	cout<<best<<endl;
}

int main()
{
	freopen("1200.txt","r",stdin);
//	freopen("½×¶ÎÐÔ³É¹û.txt","w",stdout);
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
	fclose(stdin);
	freopen("answer.txt","r",stdin);
	for(int i=0;i<64;i++)
	{
//		now[i]=i;
		cin>>now[i];
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
			if(tt!=t)
			{
				cout<<i<<' '<<j<<endl;
				return 0;
			}
			swap(now[i],now[j]);
		}
	}
//	cout<<calc(now)<<endl;
//	cout<<calcswap(48,47)<<endl;
//	cout<<calc(now)+calcswap(48,47)<<endl;
//	swap(now[48],now[47]);
//	cout<<calc(now)<<endl;
//	return 0;
	freopen("shit.txt","w",stdout);
	cout<<"1200.png\n";
	for(int i=0;i<100;i++)
	{
		solve();
	}
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			cout<<choose[i*8+j]<<' ';
		}
		cout<<' ';
//		cout<<endl;
	}
//	cout<<calc(choose)<<endl;
	return 0;
}
