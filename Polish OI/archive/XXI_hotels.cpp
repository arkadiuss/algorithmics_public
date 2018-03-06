#include <iostream>
#include <vector>
#include <queue>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define size(v) tree[v].size()
using namespace std;
const int MAX=5050;
int n;
vector< vector<int> > tree(MAX);
long long depth[MAX];
struct VinQ{
	int v;
	int level;
	int last;
};
long long S[4][MAX];
long long analyse(int r){
	int max_depth=1;
	loop(i,0,n){
		depth[i]=0;
	}
	queue<VinQ> Q;
	VinQ vq,tmp;
	;
	loop(i,0,n){
		S[1][i]=0;
		S[2][i]=0;
		S[3][i]=0;
	}
	loop(j,0,size(r)){
		loop(i,0,n){
			depth[i]=0;
		}
		vq.v=tree[r][j];
		vq.level=1;
		vq.last=r;
		Q.push(vq);
		while(!Q.empty()){
			vq=Q.front();
			depth[vq.level]++;
			max_depth=max(max_depth,vq.level);		
			loop(i,0,size(vq.v)){
				if(tree[vq.v][i]!=vq.last){
					tmp.last=vq.v;
					tmp.v=tree[vq.v][i];
					tmp.level=vq.level+1;
					Q.push(tmp);
				}
			}
			Q.pop();
		}
		max_depth++;
		loop(i,1,max_depth){
			//cout<<depth[i]<<" ";
			S[1][i]=S[1][i]+depth[i];
			S[2][i]=S[2][i]+depth[i]*depth[i];
			S[3][i]=S[3][i]+depth[i]*depth[i]*depth[i];
		}
		//cout<<"||";
	}
	//cout<<"\n";
	long long sum=0;
	loop(i,1,max_depth){
		//cout<<S[1][i]<<" "<<S[2][i]<<" "<<S[3][i]<<"\n";
		sum=sum+(S[1][i]*S[1][i]*S[1][i]-3*S[1][i]*S[2][i]+2*S[3][i])/6;
	}
	//cout<<sum<<"\n";
	return sum; 
}

int main(){
	cin>>n;
	int a,b;
	loop(i,0,n-1){
		cin>>a>>b;
		tree[a-1].push_back(b-1);
		tree[b-1].push_back(a-1);
	}
	long long sum=0;
	loop(i,0,n){
		sum=sum+analyse(i);
	}
	cout<<sum;
}
