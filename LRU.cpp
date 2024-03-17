#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ipair;

int main(){
	int frames;
	int req;
	cout<<"Enter the no. of requests\n";
	cin>>req;
	cout<<"Enter the no. of frames used\n";
	cin>>frames;
	vector<int> q;
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
			have[cur]++;
			if(q.size()<frames){
				q.push_back(cur);
			}
			else{
				vector<int> temp;
				for(int i=1;i<frames;i++){
					temp.push_back(q[i]);
				}
				temp.push_back(cur);
				have[q[0]]=0;
				q=temp;
			}
			cout<<cur<<"--->page miss\n";
		}
		else{
			int first=v_req[0];
			vector<int> temp;
			for(int i=0;i<q.size();i++){
				if(q[i]!=cur){
					temp.push_back(q[i]);
				}
			}
			temp.push_back(cur);
			q=temp;
			cout<<cur<<"--->page hit\n";
		}
	}
	cout<<"Total no. of page faults ="<<page_faults<<endl;
	return 0;
}

/*
Author: Shyam Sunder
Topic: Least Recently Used virtual page replacement algorithm
*/