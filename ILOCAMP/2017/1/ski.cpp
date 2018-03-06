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

void coutTab(bool* tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
int n;
bool b[MAX];
bool was[MAX];
bool checkWas(int k){
	int p=pow(2,k);
	loopback(i,p-1,0) if(!was[i]) return 1;
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	char s;
	loop(i,0,n){
		cin>>s;
		b[i]=s-'0';
	}
	//entr;
	if(n==1){
		pln(1);
		return 0;
	}
	int p=1;
	int mini=ceil(log2(n));
	loopback(k,floor(log2(n)),1){
		loop(i,0,n-k){
			p=0;
			loop(j,i,i+k){
				p=p*2+b[j];
			}
			was[p]=1;
		}
		//coutTab(was,n);
		if(!checkWas(k)) break;
		else mini=k;
	}
	pln(mini);
}
