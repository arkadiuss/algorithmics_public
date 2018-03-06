#include <iostream>
#define foreach(s) for(int i=0;i<s;i++)

using namespace std;
bool used[1000004];
int type[1000004];
int main(){
	int n,m;
	cin>>n>>m;
	foreach(n){
		cin>>type[i];
	}
	int j=0;
	int act_size=1;
	long long ways=0;
	foreach(n){
		used[type[i]]=1;
		if(j<i){
			i=j;
			act_size=1;
		}	
		while((used[type[j]]==0&&j<n)||i==j){
			used[type[j]]=1;
			ways+=act_size;
			j++;
			act_size++;
		}
		if(j==n)
			break;
		used[type[i]]=0;
		act_size--;
	}
	cout<<ways;
}
