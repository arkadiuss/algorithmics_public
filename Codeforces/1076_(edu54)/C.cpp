#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define foreach(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define SIZE(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
using namespace std;
typedef vector<int> VI;
const int INFTY=20000000;
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
double eps=1e-6;
int main(){
	ios_base::sync_with_stdio(0);
	double d;
	int t;
	cin>>t;
	while(t--){
		cin>>d;
		double dlt=d*d-4*d;
		if(abs(dlt)<eps) dlt=0;
		if(dlt<0){
			pln("N");
		}else{
			double b1=(d-sqrt(dlt))/2;
			double b2=(d+sqrt(dlt))/2;
			double a1=d-b1;
			double a2=d-b2;
			if(abs(a1+b1-a1*b1)<eps&&abs(a1+b1-d)<eps){
				ps("Y");cout<<fixed<<setprecision(9)<<a1<<" "<<b1<<"\n";
			}
			else if(abs(a2+b2-a2*b2)<eps&&abs(a2+b2-d)<eps){
				ps("Y");cout<<fixed<<setprecision(9)<<a2<<" "<<b2<<"\n";
			}
			else{
				pln("N");
			}
		}
	}
}
