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
const int MAX=1000100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
vector< set<int> > L(MAX);
int n,m,maxa=0;
int a[MAX];
void coutL(){
	set<int>::iterator it;
	loop(i,1,maxa+1){
		cout<<i<<": ";
		for(it=L[i].begin();it!=L[i].end();it++){
			cout<<(*it)<<" ";
		}
		entr;
	}
}
bool check(int mi, int* b){
	set<int>::iterator it;
	int pos=0;
	loop(i,0,mi){
		it=L[b[i]].lower_bound(pos);
		//ccout<<pos<<" "<<*it<<" | ";
		if(a[(*it)]!=b[i]||((*it)<pos))
			return false;
		pos=(*it)+1;	
	}
	
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>m;
	int tmp;
	loop(i,0,m){
		cin>>tmp;
		a[i]=tmp;
		maxa=max(tmp,maxa);
		L[tmp].insert(L[tmp].end(),i);
	}
	//coutL();
	cin>>n;
	int mi;
	int b[MAX];
	loop(i,0,n){
		cin>>mi;
		loop(j,0,mi){
			cin>>b[j];
		}
		if(check(mi,b))
			pln("TAK");
		else
			pln("NIE");	
	//	entr;
	}
}
