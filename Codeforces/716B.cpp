#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define foreach(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcnt(i)
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
string s;
int cnt[26];
bool checkOnePos(int p){
	loop(i,0,26){
		cnt[i]=0;
	}
	loop(i,p,p+26){
		if(s[i]!='?'){ 
			cnt[s[i]-'A']++;
			if(cnt[s[i]-'A']>1) return false;
		}
	}
	int j=0;
	while(cnt[j]==1) j++;
	loop(i,p,p+26){
		if(s[i]=='?'){ 
			s[i]=j+'A';
			cnt[j]=1;
			while(cnt[j]==1) j++;
		}
	}
}

bool check(){
	loop(i,0,s.size()-25){
		if(checkOnePos(i)){
			loop(j,0,s.size()){
				if(s[j]=='?') s[j]='A';
			}
			return true;
		}
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>s;
	if(s.size()<26) pln(-1);
	else{
		if(check()) pln(s);
		else pln(-1);
	}
}
