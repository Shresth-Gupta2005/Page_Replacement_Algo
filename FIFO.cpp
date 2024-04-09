#include<bits/stdc++.h>
using namespace std;
void fifo(vector<int>pages,int frames)
{
	int numberOfPages=pages.size();
	queue<int>q;
	vector<int>present(numberOfPages,0);
	int pageFaults=0;
	for(int i=0;i<numberOfPages;i++)
	{
		int currentPage=pages[i];
		if(present[currentPage]==0)
		{
			pageFaults++;
			if(q.size()<frames)
			{
				q.push(currentPage);
			}
			else
			{
				present[q.front()]=0;
				q.pop();
				q.push(currentPage);
			}
			present[currentPage]=1;
			cout<<currentPage<<" is a page miss."<<endl;
		}
		else
		{
			cout<<currentPage<<" is a page hit."<<endl;
		}
	}
	cout<<"Total number of page faults : "<<pageFaults<<endl;
}
int main()
{
	int numberOfPages,frames;
	cout<<"Enter the number of pages : ";
	cin>>numberOfPages;
	cout<<"Enter the number of frames : ";
	cin>>frames;
	vector<int>pages(numberOfPages);
	cout<<"Enter the page requests : ";
	for(int i=0;i<numberOfPages;i++)
	{
		cin>>pages[i];
	}
	fifo(pages,frames);
}
/* Time Complexity : O(numberOfPages)
   Space Complexity: O(numberOfPages+frames) */