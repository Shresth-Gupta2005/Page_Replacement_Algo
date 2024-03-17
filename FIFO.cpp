#include <bits/stdc++.h>
using namespace std;


int main(){
	int frames;
	int req;
	cout<<"Enter the no. of requests\n";
	cin>>req;
	cout<<"Enter the no. of frames used\n";
	cin>>frames;
	queue<int> q;
	map<int,int> have;
	int page_faults=0;
	vector<int> v_req(req);
	cout<<"Enter the page requests\n";
	for(int i=0;i<req;i++){
		cin>>v_req[i];
	}
	for(int i=0;i<req;i++){
		int cur=v_req[i];
		if(have[cur]==0){
			page_faults++;
			have[cur]=1;
			if(q.size()<frames){
				q.push(cur);
			}
			else{
				have[q.front()]=0;
				q.pop();
				q.push(cur);
			}
			cout<<cur<<"--->page miss\n";
		}
		else{
			cout<<cur<<"--->page hit\n";
		}
	}
	cout<<"Total no. of page faults ="<<page_faults<<endl;
	return 0;
}
/*
Author: Shyam Sunder
Topic: First in,First out virtual page replacement algorithm
*/