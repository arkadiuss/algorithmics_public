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
int main(){
	ios_base::sync_with_stdio(0);
	string s;
	cin>>s;
	int k;
	cin>>k;
	string res="";
	int len = 0;
	int sn=0,c=0;
	loop(i,0,s.size()){
		if(s[i]!='*'&&s[i]!='?') len++;
		else if(s[i]=='*') sn++;
		else if(s[i]=='?') c++;
	}
	if(len==k){
		loop(i,0,s.size()){
			if(s[i]!='*'&&s[i]!='?') res.pb(s[i]);
		}
	}else if(len>k){
		if(len-(c+sn)>k){
			pln("Impossible");
			return 0;
		}
		int tor = len-k;
		loop(i,0,s.size()){
			if(i<s.size()-1&&(s[i+1]=='*'||s[i+1]=='?')&&tor>0){
				tor--;
			}else if(s[i]!='*'&&s[i]!='?'){
				res.pb(s[i]);
			}
		}
	}else{
		if(sn==0){
			pln("Impossible");
			return 0;
		}
		bool was = false;
		loop(i,0,s.size()){
			if(s[i]=='*'&&!was){
				loop(j,0,k-len) res.pb(s[i-1]);
				was = true;
			}else if(s[i]!='*'&&s[i]!='?'){
				res.pb(s[i]);
			}
		}	
	}
	pln(res);
}
