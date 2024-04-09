#include<bits/stdc++.h>
using namespace std;
void LRU(vector<int>pages,int frames)
{
	int numberOfPage=pages.size();
	vector<int>q;
	/* pages are stored in q, a such way that least recently used page is at front of vector*/
	vector<int>present(numberOfPage,0);
	int pageFaults=0;
	for(int i=0;i<numberOfPage;i++)
	{
		int currentPage=pages[i];
		if(present[currentPage]==0)
		{
			pageFaults++;
			if(q.size()<frames)
			{
				q.push_back(currentPage);
			}
			else
			{
				present[q[0]]=0;
				q.erase(q.begin());
				q.push_back(currentPage);
			}
			present[currentPage]=1;
			cout<<currentPage<<" is a page miss."<<endl;
		}
		else
		{
			int j=0;
			while(q[j]!=currentPage)
			{
				j++;
			}
			q.erase(q.begin()+j);
			q.push_back(currentPage);
			cout<<currentPage<<" is a page hit."<<endl;
		}
	}
	cout<<"Total number of page faluts : "<<pageFaults<<endl;
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
	LRU(pages,frames);
}
/* Time Complexity : O(numberOfPages*frames)
   Space Complexity: O(numberOfPages+frames) */
