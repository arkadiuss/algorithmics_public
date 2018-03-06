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
struct wiz{ //wizsard
	int a,b,c;
};
wiz wizs[MAX],wizsa[MAX],wizsb[MAX];

int maxb, maxc;
vector<int> wins;
bool toSortA(wiz w1,wiz w2){
	if(w1.a==w2.a){
		if(w1.b==w2.b)
			return w1.c<w2.c;
		return w1.b<w2.b;	
	}
	return w1.a<w2.a;
}
bool toSortB(wiz w1,wiz w2){
	if(w1.b==w2.b){
		if(w1.a==w2.a)
			return w1.c<w2.c;
		return w1.a<w2.a;	
	}
	return w1.b<w2.b;
}
void quicksort(wiz* w){
	if(w->c>w->b)
		swap(w->c,w->b);
	if(w->b>w->a)
		swap(w->b,w->a);
	if(w->c>w->b)
		swap(w->b,w->c);		
}
bool checkwiz(wiz w){
	if(w.a>maxb&&w.b>maxc)
		return 1;
	if(w.a>maxb&&w.b==maxc){
		if(wizsb[n-1].a==w.a&&wizsb[n-1].b==w.b&&wizsb[n-1].c==w.c){
			if(w.a>wizsb[n-2].b&&w.b==wizsb[n-2].c){
				if(wizsb[n-2].a==w.c) return 1;
				else if(wizsb[n-2].a<w.a&&w.b==wizsb[n-2].b){
					if(wizsb[n-2].c==w.c)
						return 1;
					else return 0;	
				}else return 0;
			}
			if(wizsb[n-2].a<w.a&&w.b==wizsb[n-2].b){
				if(wizsb[n-2].c==w.c)
					return 1;
				else return 0;	
			}
			return 1;
		}else{
			if(wizsb[n-1].a==w.c) return 1;
			else return 0;
		}
				
	}
	if(w.a==maxb&&w.b>=maxc){
		if(wizsb[n-1].a==w.a&&wizsb[n-1].b==w.b&&wizsb[n-1].c==w.c){
			if(w.a>wizsb[n-2].b&&w.b>maxc) return 1;
			if(wizsb[n-2].a==w.c&&w.b>wizsb[n-2].c)
				return 1;
			if(wizsb[n-2].a==w.a&&wizsb[n-2].b<w.b&&wizsb[n-2].c<=w.c)
				return 1;
			if(wizsb[n-2].b==w.b&&wizsb[n-2].c<w.c)
				return 1;	
			return 0;		
		}else{
			if(wizsb[n-1].a==w.c)
				return 1;
			if(wizsb[n-1].a==w.a&&wizsb[n-1].b<w.b&&wizsb[n-1].c<=w.c)
				return 1;
			if(wizsb[n-1].b==w.b&&wizsb[n-1].c<w.c)
				return 1;	
			return 0;
		}
	}	
	return 0;	
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>wizs[i].a>>wizs[i].b>>wizs[i].c;
		quicksort(&wizs[i]);
		wizsa[i]=wizs[i];
		wizsb[i]=wizs[i];
	}
	sort(wizsa,wizsa+n,toSortA);
	sort(wizsb,wizsb+n,toSortB);
	/*entr;
	loop(i,0,n){
		ps(wizsb[i].a);
		ps(wizsb[i].b);
		pln(wizsb[i].c);
	}
	entr;*/
	loop(i,0,n){
		maxb=max(maxb,wizs[i].b);
		maxc=max(maxc,wizs[i].c);
		
	}
	//cout<<maxb<<" "<<maxc<<" "<<wizsb[n-2].b<<"\n";
	loop(i,0,n){
		if(checkwiz(wizs[i])) wins.push_back(i+1);
	}
	pln(wins.size());
	loop(i,0,wins.size()){
		ps(wins[i]);
	}
}
