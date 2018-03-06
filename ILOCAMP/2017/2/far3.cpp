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
int check(int i, int j){
	int acg=a[i];
	loop(k,i,j+1){
		acg=gcd(a[k],acg);
		if(acg==1) return 0;
	}
	return 1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>a[i];
	}
	int s;
	loop(i,0,n){
		loop(j,0,n){
			if(check(i,j)){
				s=0;
				loop(k,i,j+1){
					s+=a[k];
				}
				//ps(i);ps(j);pln(s);
				loop(k,i,j+1){
					maxi[k]=max(maxi[k],s);
				}
			}
		}
	}
	loop(i,0,n){
		if(a[i]==1) ps(0);
		else ps(maxi[i]);
	}
}
