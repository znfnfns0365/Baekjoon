#include<bits/stdc++.h>
using namespace std;
string parent, pattern;
int table[2000001];
int maketable(string pa, int size)
{
	int j=0;
	for(int i=1; i<size; i++){
		while(j>0&&pa[i]!=pa[j]){
			j=table[j-1];
		}
		if(pa[i]==pa[j]){
			j++;
			table[i]=j;
		}
	}
	return 0;
}
int main()
{
	vector<int> vec;
	getline(cin, parent); 
	getline(cin, pattern);
	int n=parent.size(), k=pattern.size();
	maketable(pattern, k);
	int j=0;
	for(int i=0; i<n; i++){
		while(j>0&&parent[i]!=pattern[j])j=table[j-1];
		if(parent[i]==pattern[j]){
			if(j==k-1){
				j=table[j];
				vec.push_back(i-k+1+1);
			}
			else j++;
		}
	}
	printf("%d\n",vec.size());
	for(int i=0; i<vec.size(); i++)printf("%d ",vec[i]);
	return 0;
}
