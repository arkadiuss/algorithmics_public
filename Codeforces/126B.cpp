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
typedef pair<int, int> PII;
typedef vector<vector<int> > VVI;
const int INFTY=20000000;
const int MAX=1000100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}

template<class T> void coutVec(vector<T> tab){
	for(T t : tab){
		cout<<t<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int pref[MAX];
int c[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	string s;
	cin>>s;
	int n=s.size();
	pref[0]=-1;
	int k=-1;
	loop(i,0,s.size()) {
		while(k != -1 && s[i]!=s[k]) k = pref[k];
		pref[i+1]=++k;
		if(i!=s.size()-1) c[pref[i+1]]++;
	}
	if(pref[n]<=0) {
		pln("Just a legend");
	} else {
		int k = pref[n];
		while(k>0) {
			//pln(k);
			if(c[k]>=1) break;
			k=pref[k];
		}
		if(k>0)
			pln(s.substr(0, k));
		else
			pln("Just a legend");
	}
}
