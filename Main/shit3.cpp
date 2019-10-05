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

int dir[32*33][4];
int n,sz;

bool put[32*33];
int ans[32][33];

struct result{
	bool ok;
	int tmp[32][33];
	
	result(bool ok){
		this->ok=ok;
	}
};

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

result makeAdj(int x,int y,int put){
	
	int tmp[32][33];
	memset(tmp,-1,sizeof(tmp));
	
	queue<pii> q;
	q.push(make_pair(x,y));
	tmp[x][y]=put;
	
	while(!q.empty()){
		
		pii last=q.front();
		
		q.pop();
		
		x=last.first;
		y=last.second;
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(dir[tmp[x][y]][i]!=-1){
				if(nx>=0 && nx<n && ny>=0 && ny<n){
					if(tmp[nx][ny]!=-1 && tmp[nx][ny]!=dir[tmp[x][y]][i]){
						return result(false); //reason: wrong data 
					}else{
						if(tmp[nx][ny]!=-1){
							tmp[nx][ny]=dir[tmp[x][y]][i];
							q.push(make_pair(nx,ny));	
						}
					}
				}else{
					return result(false); //reason: out of bounds
				}
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(tmp[i][j]!=-1 && ans[i][j]!=-1 && tmp[i][j]!=ans[i][j]){
				return result(false);
			}
		}
	}
	
	result r(true);
	
	memcpy(r.tmp,tmp,sizeof(tmp));
	return r;
}

ll ran;

void dfs(int x,int y){
	
//	cout<<"CJ"<<endl;
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<ans[i][j]<<" ";
//		}
//		cout<<endl;
//	}
		
	if(y==n){
		dfs(x+1,0);
		return;
	}
	
	if(x==n){
		cout<<"Final Answer="<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
		
		exit(0);
	}
	
	for(int i=0;i<n*n;i++){
		if(put[i]){
			continue;	
		}
		
//		cout<<"At "<<x<<" "<<y<<" "<<i<<" "<<dir[i][0]<<" "<<dir[i][2]<<" "<<ans[x-1][y]<<" "<<ans[x][y-1]<<endl;
		if(x>0 && dir[i][0]!=-1 && dir[i][0]!=ans[x-1][y]){
			continue;
		}
		if(y>0 && (dir[i][2]!=-1 && dir[i][2]!=ans[x][y-1])){
			continue;
		}
		if(x>0 && dir[ans[x-1][y]][1]!=-1 && dir[ans[x-1][y]][1]!=i){
			continue;
		}
		if(y>0 && dir[ans[x][y-1]][3]!=-1 && dir[ans[x][y-1]][3]!=i){
			continue;
		}
//		cout<<"S"<<endl;
		
		put[i]=true;
		ans[x][y]=i;
		dfs(x,y+1);
		
		put[i]=false;
		ans[x][y]=-1;
	}
}

int main(int argc,char* argv[]){
	
	memset(ans,-1,sizeof(ans));
	memset(dir,-1,sizeof(dir));
	
	cout<<"block(n*n)=";
	cin>>n;
	
	
//	int m;
//	cout<<"edge information count=";
//	cin>>m;
	cout<<"Edge information(0,0,0) to end"<<endl;
	while(true){
		int a,b,c;
		cout<<"[[a b should be 1-indexed]]"<<endl;
		cout<<"a is (up0/down1/left2/right3) of b=";
		cin>>a>>b>>c;
		
		if(a==0 && b==0 && c==0){
			break;
		}
		
		a--;c--;
		
		dir[c][b]=a;
		dir[a][(b<2?1-b:5-b)]=c;
	}
	
//	for(int i=0;i<n*n;i++){
//		for(int j=0;j<4;j++){
//			if(dir[i][j]!=-1){
//				cout<<i<<" "<<j<<"="<<dir[i][j]<<endl;
//			}
//		}
//	}
	dfs(0,0);
	
	cout<<"Was not able to find any solution"<<endl;
	return 0;
}


