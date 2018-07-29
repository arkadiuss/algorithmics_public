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
string create(int a,int b,int x,int start){
	if(start==0) a--;
	else b--;
	string s;
	s.pb(start+'0');
	char l;
	loop(i,0,x-1){
		l = s[s.size()-1];
		if(l=='1'){
			s.pb('0');
			a--;
		}else{
			s.pb('1');
			b--;
		}
	}
	l = s[s.size()-1];
	if(l=='0'){
		while(a--) s.pb('0');
		while(b--) s.pb('1');
	}else{
		while(b--) s.pb('1');
		while(a--) s.pb('0');
	}
	return s;
}

bool check(string s,int x){
	int j=0;
	loop(i,1,s.size()){
		if(s[i-1]!=s[i]) j++;
	}
	return x==j;
}
int main(){
	ios_base::sync_with_stdio(0);
	int a,b,x;
	cin>>a>>b>>x;
	string res = create(a,b,x,0);
	if(!check(res,x)) res = create(a,b,x,1);
	pln(res);
}
