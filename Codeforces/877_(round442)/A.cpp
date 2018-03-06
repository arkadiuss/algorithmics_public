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
string s;
int n;
int count(string pat){
	int c=0;
	loop(i,0,n){
		int j=i;
		while(j<n&&j-i<SIZE(pat)&&s[j]==pat[j-i]){
			j++;
		}
		if(j-i==SIZE(pat)) c++;  
	}
	return c;
}
string nms[]={"Danil","Olya","Slava","Ann","Nikita"};
int main(){
	ios_base::sync_with_stdio(0);
	cin>>s;
	n=SIZE(s);
	int t=0;
	loop(i,0,5){
		t+=count(nms[i]);
	}
	if(t==1) pln("YES");
	else pln("NO");
}
