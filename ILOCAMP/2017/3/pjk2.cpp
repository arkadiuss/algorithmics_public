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

void coutTab(bool * tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
bool c[MAX];
int n;
bool check(){
	loop(i,0,n-1){
		if(c[i]&&!c[i+1]) return 0;
	}
	return 1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	int l=0;
	loop(i,0,n){
		cin>>c[i];
		if(c[i]) l++;
	}
	int i=0;
	if(l==0){ pln(0); return 0;}
	while(!c[i]){
		i++;
	}
	
	int d=(n-l)-i;
	//ps(n);ps(l);ps(i);
	//pln(d);
	i++;
	int l0=0,l1=0;
	int sl=0;
	while(i<n){
		while(i<n-1&&c[i]==c[i+1]){
			if(c[i]) l1++;
			else l0++;
			//ps(i);ps(l0);pln(l1);
			i++;
		}
		if(c[i]) l1++;
		else l0++;
		if(i<n-1&&c[i]){ 
			sl+=max(0,l1-l0);
			
			
		}
		//ps(i);ps(l0);pln(l1);
		i++;
	}
	pln((d+sl));
}
