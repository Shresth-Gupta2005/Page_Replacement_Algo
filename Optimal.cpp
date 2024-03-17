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
				stack<int> st;
				map<int,int> st_;
				for(int j=i+1;j<req;j++){
					if(st_[v_req[j]]==1){
						continue;
					}
					else{
						st_[v_req[j]]++;
						st.push(v_req[j]);
					}
				}
				int rem=st.top();
				vector<int> temp;
				temp.push_back(cur);
				for(int j=0;j<frames;j++){
					if(q[j]!=rem){
						temp.push_back(q[j]);
					}
				}
				q=temp;
			}
			cout<<cur<<"--->page miss\n";
		}
		else{
//			int first=v_req[0];
//			vector<int> temp;
//			temp.push_back(cur);
//			for(int i=0;i<v_req.size();i++){
//				if(v_req[i]!=cur){
//					temp.push_back(v_req[i]);
//				}
//			}
			cout<<cur<<"--->page hit\n";
		}
	}
	cout<<"Total no. of page faults ="<<page_faults<<endl;
	return 0;
}

/*
Author: Shyam Sunder
Topic: Optimal  virtual page replacement algorithm
Note:This algorithm can't be implemented in reality in any OS as we can never have info about future
This is just an illustration
*/