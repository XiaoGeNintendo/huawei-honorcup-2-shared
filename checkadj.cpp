#include <iostream>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
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
using namespace std;
bool adj[64][64][4];
int dir[64][4];
int res[8][8];
const int dx[]={0,-1,0,1};
const int dy[]={-1,0,1,0};

void print()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			cout<<res[i][j]<<' ';
		}
//		cout<<endl;
	}
//	cout<<endl;
}

int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		cout<<"argc!=3\n";
		cout<<"Please call 100, thank you\n";
		return -1;
	}
//	freopen("value2.out","r",stdin);
	freopen(argv[1],"r",stdin);
	for(int i=0;i<64;i++)
	{
		for(int j=0;j<64;j++)
		{
			for(int k=0;k<4;k++)
			{
				double x;
				cin>>x;
//				if(i==14) cout<<j<<' '<<k<<' '<<x<<endl;
				adj[i][j][k]=(x>=0.5);
			}
		}
	}
//	return 0;
	for(int i=0;i<64;i++)
	{
		for(int d=0;d<4;d++)
		{
			bool flag=false;
			int k=-1;
			for(int j=0;j<64;j++)
			{
				if(adj[i][j][d])
				{
					if(flag==true)
					{
						cout<<"more than one fragments are adjacent to a specific side of one fragment\n";
						cout<<"please call 110\n";
						return -1;
					}
					k=j;
					flag=true;
				}
			}
			dir[i][d]=k;
		}
	}
	int lu=-1;
	for(int i=0;i<64;i++)
	{
		if(dir[i][0]==-1 && dir[i][1]==-1)
		{
			lu=i;
			break;
		}
	}
	if(lu==-1)
	{
		cout<<"No left upper corner fragment found\n";
		cout<<"Please call 110\n";
		return -1;
	}
	res[0][0]=lu;
	for(int i=1;i<8;i++)
	{
		if(res[i-1][0]==-1)
		{
			cout<<"Some fragments went wrong!\n";
			cout<<"Please call 110\n";
			return -1;
		}
		res[i][0]=dir[res[i-1][0]][3];
	}
	for(int i=0;i<8;i++)
	{
		for(int j=1;j<8;j++)
		{
			if(res[i][j-1]==-1)
			{
				cout<<"Some fragments went wrong!\n";
				cout<<"Please call 110\n";
				return -1;
			}
			res[i][j]=dir[res[i][j-1]][2];
//			print();
		}
	}
	bool flag=true;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			for(int k=0;k<4;k++)
			{
				int x=i+dx[k];
				int y=j+dy[k];
				if(x<0 || y<0 || x>=8 || y>=8)
				{
					if(dir[res[i][j]][k]!=-1) flag=false;
					continue;
				}
				if(dir[res[i][j]][k]!=res[x][y]) flag=false;
			}
		}
	}
	if(!flag)
	{
		cout<<"Some fragments went wrong!\n";
		cout<<"Please call 110\n";
		return -1;
	}
	freopen("answer.out","w",stdout);
	cout<<argv[2]<<endl;
	print();
	return 0;
}
