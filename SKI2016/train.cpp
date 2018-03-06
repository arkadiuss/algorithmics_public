#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,s,j) for(int i=s;i>=j;i--)
#define entr cout<<"\n"
#define ps( v ) cout<<v<<" "
#define pln( v ) cout<<v<<"\n"
#define pb( v ) push_back(v)
#define mp make_pair
#define ff first
#define ss second

using namespace std;
const int MAX=100000;

int N,K,C;
vector< vector<bool> > dp;
vector< vector<int> > moves;
vector< vector<bool> > was;
vector<bool> clr;
vector<int> clrint;
void coutDp(){
	loop(i,0,C){
		loop(j,0,N){
			cout<<dp[i][j];
		}
		cout<<"\n";
	}
}
void coutMoves(){
	loop(i,0,C){
		loop(j,0,N){
			cout<<moves[i][j];
		}
		cout<<"\n";
	}
}
bool bfs(int a){
	queue<pair<int,int> > Q;
	Q.push(mp(a,0));
	while(!Q.empty()){
		pair<int,int> v = Q.front();
		was[v.ss][v.ff]=0;
		//ps(v.ff);
		//pln(v.ss);
		if(v.ss==C-1){
			while(!Q.empty()){
				v=Q.front();
				was[v.ss][v.ff]=0;
				Q.pop();
			} 
			return 1;
		}
		if(dp[v.ss+1][v.ff]==1){
			if(v.ff-1>=0&&moves[v.ss+1][v.ff]%2!=0&&!dp[v.ss+1][v.ff-1]&&!was[v.ss+1][v.ff-1]){
				was[v.ss+1][v.ff-1]=1; 
				Q.push(mp(v.ff-1,v.ss+1));
			}	
			if(v.ff+1<N&&moves[v.ss+1][v.ff]%3!=0&&!dp[v.ss+1][v.ff+1]&&!was[v.ss+1][v.ff+1]) {
				was[v.ss+1][v.ff+1]=1;
				Q.push(mp(v.ff+1,v.ss+1));
			}
		}else{
			if(!was[v.ss+1][v.ff]){
				Q.push(mp(v.ff,v.ss+1));
				was[v.ss+1][v.ff]=1;
			}
			if(v.ff+1<N&&!dp[v.ss+1][v.ff+1]&&!was[v.ss+1][v.ff+1]){
				was[v.ss+1][v.ff+1]=1;
				Q.push(mp(v.ff+1,v.ss+1));
			}	
			if(v.ff-1>=0&&!dp[v.ss+1][v.ff-1]&&!was[v.ss+1][v.ff-1]){
				was[v.ss+1][v.ff-1]=1;
				Q.push(mp(v.ff-1,v.ss+1));
			}	
		}
		Q.pop();
	}
	return 0;
}
bool check(){
	loopback(i,N-1,0){
		if(!dp[0][i]){
			if(bfs(i)) return 1;
		}
	}
	return 0;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>N>>K>>C;
        dp.erase(dp.begin(),dp.end());
        clr.erase(clr.begin(),clr.end());
        moves.erase(moves.begin(),moves.end());
        clrint.erase(clrint.begin(),clrint.end());
        was.erase(was.begin(),was.end());
        string s;
        loop(i,0,N){
            clr.pb(0);
            clrint.pb(1);
        }
        loop(i,0,C){
            dp.pb(clr);
            moves.pb(clrint);
            was.pb(clr);
        }
        int w0;
        loop(j,0,K){
            cin>>w0;
            dp[0][w0-1]=1;
            int last=w0-1;
            cin>>s;
            loop(i,1,C){
                if(s[i-1]=='+'){
					dp[i][last+1]=1;
					if(moves[i][last+1]%2!=0)
						moves[i][last+1]*=2;
					last++;
                }else if(s[i-1]=='-'){
                	dp[i][last-1]=1;
                	if(moves[i][last-1]%3!=0)
						moves[i][last-1]*=3;
                	last--;
                }else{
                	dp[i][last]=1;
                }
            }
        }
        //coutDp();
        //entr;
        //coutMoves();
        if(check())
        	cout<<"TAK";
        else
        	cout<<"NIE";
        entr;		    
	}
}
