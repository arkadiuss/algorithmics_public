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
	int num;
};
struct weakness{
	int weak;
	int wzrd;
};
wiz wizs[MAX];
weakness weak1[MAX],weak2[MAX];
vector<int> wins;
bool toSortWeakness(weakness a, weakness b){
	if(a.weak==b.weak) return a.wzrd<b.wzrd;
	return a.weak<b.weak;
}
int theweakest(int a, int b, int c){
	return min(a,min(b,c));	
}
int middle(int a, int b, int c){
	if(a<=max(b,c)&&a>=min(b,c))
		return a;
	else if(b<=max(a,c)&&b>=min(a,c))
		return b;
	else if(c<=max(a,b)&&c>=min(a,b))
		return c;	
}
int thestrongest(int a, int b, int c){
	return max(a,max(b,c));
}
bool checkwiz(wiz w){
	int st=thestrongest(w.a,w.b,w.c);
	int mid=middle(w.a,w.b,w.c);
	if(st>weak2[n-1].weak&&mid>weak1[n-1].weak){
		return 1;
	}else if(st>weak1[n-1].weak&&mid>weak2[n-1].weak){
		return 1;	
	}else if(st>weak2[n-1].weak&&weak1[n-1].wzrd==w.num&&weak1[n-2].weak<mid){
		return 1;
	}else if(st>weak1[n-1].weak&&weak2[n-1].wzrd==w.num&&weak2[n-2].weak<mid){
		return 1;
	}else if(st>weak1[n-1].weak&&weak2[n-1].wzrd==w.num&&weak2[n-2].weak<mid){
		return 1;
	}
	return 0;
	
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>wizs[i].a>>wizs[i].b>>wizs[i].c;
		wizs[i].num=i;
		weak1[i].weak=theweakest(wizs[i].a,wizs[i].b,wizs[i].c);
		weak2[i].weak=middle(wizs[i].a,wizs[i].b,wizs[i].c);	
		weak1[i].wzrd=i;
		weak2[i].wzrd=i;
	}
	sort(weak1, weak1+n,toSortWeakness);
	sort(weak2, weak2+n,toSortWeakness);
	loop(i,0,n){
		if(checkwiz(wizs[i])) wins.push_back(i+1);
	}
	pln(wins.size());
	loop(i,0,wins.size()){
		ps(wins[i]);
	}
}
