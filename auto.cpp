#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

void intarrayinput(int sz,int a[]){for(int ___=0;___<sz;++___)scanf("%d",a+___);}
void intarrayoutput(int sz,int a[]){for(int ___=0;___<sz;++___)printf("%d ",a[___]);printf("\n");}
template<class T>T emin(T& t1,T t2){if(t1>t2)return t1=t2;else return t1;}
template<class T>T emax(T& t1,T t2){if(t1<t2)return t1=t2;else return t1;}
template<class T1,class T2>ostream& operator<<(ostream& out,pair<T1,T2> _p){out<<_p.first<<" "<<_p.second;return out;}
template<class T>ostream& operator<<(ostream& out,vector<T> _v){for(int i=0;i<_v.size();++i)out<<_v[i]<<(i+1==_v.size()?"":" ");return out;}
template<class T>void byebye(T t){cout<<t<<endl;exit(0);}

int sti(string s){
	int ret=0,i=0,flag=1;
	while(!isdigit(s[i])){
		if(s[i]=='-')flag=-1;
		i++;
	}
	while(isdigit(s[i]))ret=ret*10+(s[i]-'0'),++i;
	return ret*flag;
}

int main(int argc,char* argv[]){
	printf("%d\n",argc);
	for(int i=0;i<argc;++i){
		printf("%s\n",argv[i]);
	}
	string image_folder=argv[1];
	if(image_folder[(int)image_folder.size()-1]=='\\')image_folder=image_folder.substr(0,(int)image_folder.size()-1);
	int starting_image=sti(argv[2]);
	int ending_image=sti(argv[3]);
	int frag_size=sti(argv[4]);
	
	char command[205];
	sprintf(command,"python transfer.py %s %d %d %d",image_folder.c_str(),starting_image,ending_image,frag_size);
	
	system(command);
	
	printf("Image transferred!\n");
	
	for(int i=starting_image;i<=ending_image;++i){
		char s[25];
		sprintf(s,".\\output\\output%d.txt",i);
		sprintf(command,"initializer.exe \"%s\"",s);
		system(command);
		puts("Grey Value transferred!");
		sprintf(command,"checkadj.exe value0.in %d.png",i);
		system(command);
		printf("Image %d\n Finished\n",i);
	}
	
	return 0;
}


