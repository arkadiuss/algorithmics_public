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
vector<int> wins;
bool duel(int i, int j){
	int sci=0,scj=0; //score i  and score j
	if(wizs[i].a>wizs[j].a){
		sci++;
	}else if(wizs[i].a==wizs[j].a){
		sci++;
		scj++;
	}else{
		scj++;
	}
	if(wizs[i].b>wizs[j].b){
		sci++;
	}else if(wizs[i].b==wizs[j].b){
		sci++;
		scj++;
	}else{
		scj++;
	}
	if(wizs[i].c>wizs[j].c){
		sci++;
	}else if(wizs[i].c==wizs[j].c){
		sci++;
		scj++;
	}else{
		scj++;
	}
	if(sci>scj) return 1;
	return 0;
}
bool fullduel(int i, int j){
	int win=0;
	if(i==j) win=1;
	win=win||duel(i,j);
	swap(wizs[j].b,wizs[j].c);
	win=win||duel(i,j);
	swap(wizs[j].a,wizs[j].c);
	win=win||duel(i,j);
	swap(wizs[j].b,wizs[j].c);
	win=win||duel(i,j);
	swap(wizs[j].a,wizs[j].c);
	win=win||duel(i,j);
	swap(wizs[j].b,wizs[j].c);
	win=win||duel(i,j);
	swap(wizs[j].a,wizs[j].c);
	return win;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>wizs[i].a>>wizs[i].b>>wizs[i].c;
	}
	loop(i,0,n){
		bool winall=1,win=0;
		loop(j,0,n){
			win=fullduel(i,j);
			if(!win){
				winall=0;
				break;
			}
		}
		//entr;
		if(winall) wins.push_back(i+1); 
	}
	pln(wins.size());
	loop(i,0,wins.size()){
		ps(wins[i]);
	}
}
