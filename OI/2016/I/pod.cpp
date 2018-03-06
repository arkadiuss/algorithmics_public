#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
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
struct sum{
	ll s;
	vector<int> ing;
};
vector< sum  > rests;
vector<int> res;
bool was[MAX];
vector<int> num;
ll mod;
int B;
int a[MAX];
sum ms(ll s, vector<int> ing){
	sum su;
	su.s=s;
	su.ing = ing;
	return su;
}
void coutNum(){
	loop(i,0,num.size()){
		cout<<num[i]<<"";
	}
	cout<<"\n";
}
void coutRes(){
	loop(i,0,res.size()){
		cout<<res[i]<<"";
	}
	cout<<"\n";
}
void coutRests(){
	loop(i,0,rests.size()){
		cout<<rests[i].s<<": ";
		loop(j,0,rests[i].ing.size()){
			cout<<rests[i].ing[j]<<" ";
		}
		entr;
	}
}
void countMod(){
	mod=0;
	ll p=1;
	loop(i,0,num.size()){
		mod=(mod+num[i]*p)%(B-1);
		p=(p*B)%(B-1);
	}
}	
vector<int> addRests(){	
	loopback(i,num.size()-1,0){
		
		loopback(j,rests.size()-1,0){
			if(!was[rests[j].s+num[i]]){
				was[rests[j].s+num[i]]=1;
				vector<int> newr = rests[j].ing;
				newr.pb(num[i]);
				rests.pb(ms(rests[j].s+num[i],newr));
				if(rests[rests.size()-1].s==mod){
					return rests[rests.size()-1].ing;
				}
			}
		}
		if(!was[num[i]]){
			was[num[i]]=1;
			vector<int> newing;
			newing.push_back( num[i] );
			rests.pb(ms(num[i],newing));
			if(rests[rests.size()-1].s==mod){
				return rests[rests.size()-1].ing;
			}
		}
	}
	int mini=0;
	int minmod=INFTY;
	loop(i,0,rests.size()){
		if(rests[i].s%(B-1)==mod){
			if((rests[i].s-mod)/(B-1)<minmod){
				minmod=(rests[i].s-mod)/(B-1);
				mini=i;
			}
		}
	}
	return rests[mini].ing;
}
int main(){
	ios_base::sync_with_stdio(0);
	int q;
	cin>>B>>q;
	loop(i,0,B){
		cin>>a[i];
	}
	loopback(i,B-2,1){
		loop(j,0,a[i]){
			num.pb(i);
		}
	}
	countMod();
	coutNum();
	pln(mod);
	if(mod==0){
		loop(i,0,a[B-1]){
			res.pb(B-1);
		}
		loop(i,0,num.size()){
			res.pb(num[i]);
		}
		loop(i,0,a[0]){
			res.pb(0);
		}
	}else{
		vector<int> del=addRests();
		//coutRests();
		loop(i,0,del.size()){
			a[del[i]]--;
		}
		loopback(i,B-1,0){
			loop(j,0,a[i]){
				res.pb(i);
			}
		}	
	}
	coutRes();
	/*int k;
	while(q--){
		cin>>k;
		pln(res[res.size()-k-1]);
	}*/
}
