#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,c) for(VAR(i,c.begin());i!=c.end();i++)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) c.size()
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const int MAX=1000100;
const int MOD=1000000000;
const int INFTY=1000000000;
typedef vector<int> VI;

void coutTab(int * tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
int n;
int a[MAX];
int maxi[MAX];
int gcd(int a, int b){
	if(a<b)
		swap(a,b);
	if(b==0) return a;	
	return gcd(b,a%b);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>a[i];
	}
	int agcd=a[0];
	int sum=a[0];
	int j=0;
	loop(i,0,n){
	//	maxi[i]=i;
	}
	loop(i,0,n){
		agcd=a[i];
		//ps(i);ps(j);
		loop(k,i,j+1){
			agcd=gcd(a[k],agcd);
		}
		if(j<=i){ 
			j=i+1;
			agcd=gcd(a[i],a[j]);
			sum=a[i]+a[j];
		}
		//ps(agcd);
		while(j<n&&agcd>1){
			j++;
			sum=sum+a[j];
			agcd=gcd(agcd,a[j]);
		}
		if(j<n-1||(j==n-1&&agcd==1)){
			sum-=a[j];
			j--;
		}
		//ps(i);ps(j);pln(sum);
		loop(k,i,j+1){
			maxi[k]=max(maxi[k],sum);
		}
		sum-=a[i];
	}
	loop(i,0,n){
		ps(maxi[i]);
	}
}
