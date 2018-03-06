#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
using namespace std;
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
string text,key;
int n,m;
bool check(int i){
	bool fail=0;
	loop(j,i,i+m){
		if(key[j-i]!=text[j]&&!fail)
			fail=1;
		else if(key[j-i]!=text[j]&&fail)
			return 0;	
	}
	return 1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	cin>>text>>key;
	queue<int> Q;
	int howmany=0;
	loop(i,0,n){
		if(check(i)){
			howmany++;
			Q.push(i+1);
		}
	}
	pln(howmany);
	while(!Q.empty()){
		cout<<Q.front()<<" ";
		Q.pop();
	}
}
