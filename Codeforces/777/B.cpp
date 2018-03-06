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
const int MAX=1100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
string ST,MT;
int S[MAX],M[10];
int n;
int haveBorE(int x){
	loop(i,x,10){
		if(M[i]>0) return i;
	}
	return -1;
}
int haveB(int x){
	loop(i,x+1,10){
		if(M[i]>0) return i;
	}
	return -1;
}
int getMin(){
	loop(i,0,10){
		if(M[i]>0) return i;
	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	cin>>ST>>MT;
	loop(i,0,10) M[i]=0;
	loop(i,0,n){
		S[i]=ST[i]-'0';
		M[MT[i]-'0']++;
	}
	int mini=0;
	loop(i,0,n){
		int bore=haveBorE(S[i]);
		if(bore==-1) mini++;
		else M[bore]--;
	}
	pln(mini);
	int maxi=0;
	loop(i,0,10) M[i]=0;
	loop(i,0,n){
		M[MT[i]-'0']++;
	}
	loop(i,0,n){
		int b=haveB(S[i]);
		//ps(b);
		if(b==-1) M[getMin()]--;
		else{
			maxi++;
			M[b]--;
		}
	}
	//entr;
	pln(maxi);
}
