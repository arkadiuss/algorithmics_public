#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,c) for(VAR(i,c.begin());i!=c.end();i++)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) c.size()
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const int MAX=1000100;
const int MOD=1000000000;
const int INFTY=1000000000;
typedef vector<int> VI;

void coutTab(unsigned ll * tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
int n;
unsigned ll B=29;
unsigned ll hsh[MAX];
unsigned ll hshbck[MAX];
unsigned ll pwr[MAX];
void countPwr(){
	pwr[0]=1;
	loop(i,1,n+1){
		pwr[i]=pwr[i-1]*B;
	}
}
void hs(string* a){
	hsh[0]=(*a)[0]-'0';
	loop(i,0,n){
		hsh[i]=hsh[i-1]*B+((*a)[i]-'0');
	}
	hshbck[a->size()-1]=(*a)[a->size()-1]-'0';
	loopback(i,a->size()-2,0){
		hshbck[i]=hshbck[i+1]*B+((*a)[i]-'0');
	}
}
bool comphsh(int i,int j,int l){
	//ps(i);ps(j);ps(l);ps(pwr[l]);
	//cout<<hsh[j+l]-hsh[j]*pwr[l]<<" "<<hshbck[i-l]-hshbck[i]*pwr[l]<<"\n";
	
	return hsh[j+l]-hsh[j]*pwr[l]==hshbck[i-l]-hshbck[i]*pwr[l];
}
int bin(int i,int j,int s){
	int p=0;
	int e=min(i,s-j-1);
	int mid;
	while(p<e){
		mid=(p+e+1)/2;
		if(comphsh(i,j,mid)) p=mid;
		else e=mid-1;
	}
	return p;
}
int check(string* a){
	//pln(a);
	hs(a);
	//coutTab(hsh,a.size());
	//coutTab(hshbck,SIZE(a));
	int s=a->size();
	int maxl=0;
	loop(i,0,s){
		maxl=max(maxl,2*bin(i,i,s)+1);
	}
	loop(i,0,s-1){
		if((*a)[i]==(*a)[i+1]) maxl=max(maxl,2*bin(i,i+1,s)+2);
	}
	return maxl;
}
int main(){
	ios_base::sync_with_stdio(0);
	string s,nw;
	cin>>n;
	cin>>s;
	countPwr();
	int maxi=0;
	loop(i,0,n){
		nw="";
		loop(j,0,n){
			if(i!=j) nw.pb(s[j]);
			
		}
		maxi=max(maxi,check(&nw));
	}
	pln(maxi+1);
}
