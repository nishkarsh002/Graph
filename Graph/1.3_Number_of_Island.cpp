#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int n,m;
//valid row and column checker.
bool check(int i,int j){
return i>=0&&j>=0&&i<n&&j<m;
}

void mark_component(vector<vector<int>>&v,vector<vector<bool>>&vis,int i,int j){
if(!check(i,j))return;
vis[i][j]=1;
//marking(connecting all possible part of single island.
if (v[i][j] == 1) {
		v[i][j] = 0;
		mark_component(v,vis,i+1,j);
		mark_component(v,vis,i-1,j);
		mark_component(v,vis,i,j+1);
		mark_component(v,vis,i,j-1);
		mark_component(v,vis,i+1,j+1);
		mark_component(v,vis,i-1,j-1);
		mark_component(v,vis,i+1,j-1);
		mark_component(v,vis,i-1,j+1);
	}
}

int main() {
	vector<vector<int>>v{{ 1, 1, 0, 0, 0 },
						{ 0, 1, 0, 0, 1 },
						{ 1, 0, 0, 1, 1 },
						{ 0, 0, 0, 0, 0 },
						{ 1, 0, 1, 0, 1 }};
	n=v.size();
	m=v[0].size();
int cnt=0;
//visit vector.
vector<vector<bool>>vis(n,vector<bool>(m,0));
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	if(!vis[i][j]&&v[i][j]==1){
		++cnt;
		mark_component(v,vis,i,j);
	}
	}
}
cout<<"The number of islands in the matrix are :"<<endl;
cout<<cnt<<endl;
//code by Nishkarsh Dixit
	return 0;
}
