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
