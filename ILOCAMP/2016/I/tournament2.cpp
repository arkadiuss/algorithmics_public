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
int n;
struct wiz{ //wizard
	int a,b,c;
};
wiz wizs[MAX];
int weak1[MAX],weak2[MAX];
vector<int> wins;
int theweakest(int a, int b, int c){
	if(a<b&&a<c)
		return a;
	else if(b<a&&b<c)
	    return b;
	else if(c<a&&c<b)
		return c;	
}
int middle(int a, int b, int c){
	if(a<max(b,c)&&a>min(b,c))
		return a;
	else if(b<max(a,c)&&b>min(a,c))
		return b;
	else if(c<max(a,b)&&c>min(a,b))
		return c;	
}
int thestrongest(int a, int b, int c){
	if(a>b&&a>c)
		return a;
	else if(b>a&&b>c)
	    return b;
	else if(c>a&&c>b)
		return c;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>wizs[i].a>>wizs[i].b>>wizs[i].c;
		weak1[i]=theweakest(wizs[i].a,wizs[i].b,wizs[i].c);
		weak2[i]=middle(wizs[i].a,wizs[i].b,wizs[i].c);	
	}
	sort(weak1, weak1+n);
	sort(weak2, weak2+n);
	loop(i,0,n){
		if((thestrongest(wizs[i].a,wizs[i].b,wizs[i].c)>weak2[n-1]&&middle(wizs[i].a,wizs[i].b,wizs[i].c)>weak1[n-1])||(thestrongest(wizs[i].a,wizs[i].b,wizs[i].c)>weak1[n-1]&&middle(wizs[i].a,wizs[i].b,wizs[i].c)>weak2[n-1])){
			wins.push_back(i+1);
		}
	}
	pln(wins.size());
	loop(i,0,wins.size()){
		ps(wins[i]);
	}
}
