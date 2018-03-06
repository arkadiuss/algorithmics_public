#include<bits/stdc++.h>
#define loop(i,j,n) for(long long i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define ps( v ) cout<<v<<" "
#define pln( v ) cout<<v<<"\n"
#define entr cout<<"\n"
#define pb(v) push_back(v)
#define ll long long
#define mp(a,b) make_pair(a,b)
using namespace std;
const int MAX=1000100;

void coutTab(int* tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
void coutLLTab(ll* tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//--------------------

ll start, finish;
ll n,k;
const int bsize=500006;
ll blocked[bsize];
int bprev[bsize];
int bhash[bsize];
int bfree=0;
const int vsize=5300007;
ll visited[vsize];
int vprev[vsize];
int vhash[vsize];
int vfree=0;

void hashInsert(ll* set, int* prev, int* hash, int &free, int size, ll value){
	set[free]=value;
	prev[free]=hash[value%size];
	hash[value%size]=free;
	free++;
}
bool inSet(ll* set, int* prev, int* hash, int &free, int size, ll value){
	int pos=hash[value%size];
	while(pos>=0){
		//pln(pos);
		if(set[pos]==value)
			return true;
		pos=prev[pos];	
	}
	return false;
}
void clearSet(ll* set, int* prev, int* hash, int &free, int size){
	free=0;
	loop(i,0,size){
		set[i]=0;
		prev[i]=-1;
		hash[i]=-1;
	}
}
ll change(string s){
	ll p=1;
	ll changed=0;
	loopback(i,n-1,0){
		changed = changed + (s[i]-'0')*p;
		p=p*2;
	}
	return changed;
}
ll Q[vsize];
bool dfs(ll s,ll e,ll size){
	
	int b=0, c=1;
	Q[b]=s;
	ll p=1;//ps(s);
	hashInsert(visited,vprev,vhash,vfree,vsize,s);
	
	while(b<c){
		ll v=Q[b]; 
		b++;
		//ps(v);
		//ps(size);
		//ps(vfree);
		
		if(size>=n*k+1) return 1;
		if(v==e) return 1;
		p=1;	
		loop(i,0,n){
			ll tmp = v ^ (1LL<<i);
			//ps(tmp);
			if(tmp==e) return 1;
			if(!inSet(blocked,bprev,bhash,bfree,bsize,tmp)&&!inSet(visited,vprev,vhash,vfree,vsize,tmp)){
				Q[c++]=tmp;
				hashInsert(visited,vprev,vhash,vfree,vsize,tmp);
				//ps(i);
				//ps(v-p);
				//pln("fi1");
				size++;
			}
		
			p=p*2;
		}
		//entr;
	}
	if(size>=n*k+1) return 1;
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);
	
	//cout<<(1<<0);
	cin>>n;
	cin>>k;
	string s;
	cin>>s;
	start=change(s);
	cin>>s;
	finish=change(s);
	//ps(start);
	//pln(finish);
	clearSet(blocked,bprev,bhash,bfree,bsize);
	clearSet(visited,vprev,vhash,vfree,vsize);
	loop(i,0,k){
		cin>>s;
		hashInsert(blocked,bprev,bhash,bfree,bsize,change(s));
	}
	//coutLLTab(blocked,bsize);
	//coutTab(bprev,bsize);
	//coutTab(bhash,bsize);
	bool first=dfs(start,finish,0);
	clearSet(visited,vprev,vhash,vfree,vsize);
	vfree=0;
	if(first&&dfs(finish,start,0)) pln("TAK");
	else pln("NIE");
}

