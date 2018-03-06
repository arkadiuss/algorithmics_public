#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define ff first
#define ss second
using namespace std;
const int INFTY=20000000;
const int MAX=300010;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}

//------------------------------------------
int n,m,a,b;
bool go;
vector< vector<int> > G(MAX);
vector< pair<int,int> > V; 
bool deleted[MAX]={0},inQ[MAX];
int deg[MAX];
int maxk=2;
vector<int> Kmax,Kempty;	
bool biggerPair(pair<int,int> a,pair<int,int> b){
	if(a.ff==b.ff) return a.ss<b.ss;
	return a.ff<b.ff;
}
void coutVec(){
	loop(i,0,V.size()){
		cout<<"("<<V[i].ff<<","<<V[i].ss<<") ";
	}
	cout<<"\n";
}
bool find(int a,int b){
	pair<int,int> p=make_pair(a,b);
	int s=0,e=V.size();
	int m=(s+e)/2;
	while(s<e){
		//if(a==0&&b==1) cout<<s<<" "<<e<<"\n";
		if(p.ff==V[m].ff&&p.ss==V[m].ss)
			return true;
		else if(biggerPair(V[m],p))
			s=m+1;
		else
			e=m;
		m=(s+e)/2;			
	}
	return false;
}
bool check(int i){
	vector<int> K;
	bool pass=0;
	loop(mask,0,1<<deg[i]+1){
		if(pcnt(mask)>2||(maxk==3&&pcnt(mask)>3)){
			loop(j,0,deg[i]){
				if(deleted[G[i][j]]){
					G[i].erase(G[i].begin()+j);
					j--;
					continue;
				}
				if(1<<j&mask)
					K.push_back(G[i][j]);
			}
			pass=1;
			K.push_back(i);
			for(int i=0;i<K.size()&&pass;i++){
				loop(j,0,K.size()){
					if(i!=j){
						//cout<<K[i]<<" "<<K[j]<<" "<<find(min(K[i],K[j]),max(K[i],K[j]))<<"\n";
						if(!find(min(K[i],K[j]),max(K[i],K[j]))){
							pass=0;
							break;
						}
					}
				}
			}
			if(pass) {Kmax=K;return true;}
			K=Kempty;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	
	cin>>n>>m;
	loop(i,0,m){
		cin>>a>>b;
		G[a-1].push_back(b-1);
		G[b-1].push_back(a-1);
		V.push_back(make_pair(min(a-1,b-1),max(a-1,b-1)));
		if(i==0){
			Kmax.push_back(a-1);
			Kmax.push_back(b-1);
		}
	}
	sort(V.begin(),V.begin()+m,biggerPair);
	//coutVec();
	queue<int> Q;
	loop(i,0,n){
		deg[i]=G[i].size();
		if(deg[i]<=5){
			Q.push(i);
			inQ[i]=1;	
		}
	}
	while(!Q.empty()&&maxk<4){
		int v=Q.front();
		if(check(v)){
			maxk=Kmax.size();
		}
		deleted[v]=1;
		loop(j,0,G[v].size()){
			deg[G[v][j]]--;
			if(deg[G[v][j]]<=5&&!deleted[G[v][j]]&&!inQ[G[v][j]]){
				Q.push(G[v][j]);
				inQ[G[v][j]]=1;
			}
		}
		Q.pop();		
	}
	cout<<Kmax.size()<<"\n";
	loop(i,0,Kmax.size()){
		cout<<Kmax[i]+1<<" ";
	}
}
