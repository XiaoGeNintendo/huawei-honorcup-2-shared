#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <deque>
#include <bits/stdc++.h>
//#include "testlib.h"
using namespace std;
#define ll long long
#define pii pair<int,int>
#define qi ios::sync_with_stdio(0)

bool debug=true;

/*    *************************************
	  * Written in New Computer           *
	  * The following code belongs to     *
	  * XiaoGeNintendo of HellHoleStudios *
	  *************************************
*/
template<typename T1,typename T2>ostream& operator<<(ostream& os,pair<T1,T2> ptt){
	os<<ptt.first<<","<<ptt.second;
	return os;
}
template<typename T>ostream& operator<<(ostream& os,vector<T> vt){
	os<<"{";
	for(int i=0;i<vt.size();i++){
		os<<vt[i]<<" ";
	}
	os<<"}";
	return os;
}


int l[]={1800,2100,2400};
int r[]={2099,2399,2699};
int sz[]={32,16,8};

const int DATA16=0;
const int DATA32=1;
const int DATA64=2;

void solve(int ds){
	for(int i=l[ds];i<=r[ds];i++){
		cout<<i<<".png"<<endl;
		vector<int> v;
		for(int i=0;i<sz[ds]*sz[ds];i++){
			v.push_back(i);
		}
		
		random_shuffle(v.begin(),v.end());
		
		for(int x:v){
			cout<<x<<" ";
		}
		cout<<endl;
	} 
}
int main(int argc,char* argv[]){
	srand(time(0));
	freopen("out.txt","w",stdout);
	
	solve(DATA64);
	
	return 0;
}


