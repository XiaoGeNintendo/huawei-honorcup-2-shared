#include <iostream>
#include <algorithm>
#include <cmath>
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
double EstimateValue(int x);
double EstimateAdj(vector <vector<double> >a,vector <vector<double> >b,int dire,double k);
double EstimateVector(vector <double> a,vector <double> b,double k);
vector<vector<double> > ReadGreyFrag();
void PrintGreyFrag(vector<vector<double> > vec);
const int n=64;
double EstimateAdj(vector <vector<double> >a,vector <vector<double> >b,int dire,double k)
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
double EstimateVector(vector <double> a,vector <double> b,double k)
{
	vector <bool> vec;
	vec.resize(n);
	for(int i=0;i<n;i++)
	{
		vec[i]=(abs(a[i]-b[i])<=k);
	}
	for(int i=0;i<n;i++)
	{
		cout<<vec[i];
	}
	cout<<endl;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=vec[i];
	}
	return EstimateValue(sum);
}
double EstimateValue(int x)
{
	if(x<=n/2) return 0;
	return (double)x*x/n/n;
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
void PrintGreyFrag(vector<vector<double> > vec)
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

int main()
{
	freopen("output.txt","r",stdin);
	test();
	double x;
	return 0;
}
