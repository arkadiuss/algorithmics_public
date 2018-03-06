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
int counter[100];
int main(){
	ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	string s;
	char maxi;
	int maxl=0;
	while(T--){
		loop(i,0,50){
			counter[i]=0;
		}
		cin>>s;
		maxl=0;
		loop(i,0,s.size()){
			counter[s[i]-'a']++;
			if(counter[s[i]-'a']>maxl){
				maxl=counter[s[i]-'a'];
				maxi=s[i];
			}
		}
		cout<<maxi<<"\n";
	}
}
