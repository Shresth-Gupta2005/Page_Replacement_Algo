#include <bits/stdc++.h>
using namespace std;

int main(){
	int frames;
	int req;
	cout<<"Enter the no. of requests\n";
	cin>>req;
	cout<<"Enter the no. of frames used\n";
	cin>>frames;
	vector<int> avail;
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
			if(avail.size()<frames){
				avail.push_back(cur);
			}
			else{
				vector<int> temp;
				have[avail[frames-1]]=0;
				avail[frames-1]=cur;
				
			}
			cout<<cur<<"--->page miss\n";
		}
		else{
			vector<int> temp;
			for(int i=0;i<avail.size();i++){
				if(avail[i]!=cur){
					temp.push_back(avail[i]);
				}
			}
			temp.push_back(cur);
			avail=temp;
			cout<<cur<<"--->page hit\n";
		}
	}
	cout<<"Total no. of page faults ="<<page_faults<<endl;
	return 0;
}
/*
MRU Algorithm -Page Replacement
Author- Shyam Sunder

*/
