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
string text,key,con;
int n,m;
int KMPNext[MAX];
queue<int> Q;
int howmany=0;
int* pref,prefback;
int* countPREF(string s){	
	int pref[MAX];
	loop(i,0,s.size()){
		pref[i]=0;
	}
	pref[0]=-1;
	int k=1;
	loop(i,1,s.size()){
		if(k<pref[i]&&pref[1+k]!=pref[i]-k)
			pref[i+k]=min(pref[k+1],pref[i]-k);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	cin>>text>>key;
	loop(i,0,m){
		con.push_back(key[i]);
	}
	con.push_back('#');
	loop(i,0,n){
		con.push_back(text[i]);
	}
	KMP();
	pln(howmany);
	while(!Q.empty()){
		cout<<Q.front()<<" ";
		Q.pop();
	}
}
