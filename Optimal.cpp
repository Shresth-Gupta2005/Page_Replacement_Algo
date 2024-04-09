#include<bits/stdc++.h>
using namespace std;
void OPT(vector<int>pages,int frames)
{
	int numberOfPages=pages.size();
	vector<int>q;
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
    			q.push_back(currentPage);
			}
			else
			{
				int indexToBeReplaced=-1,maxDis=-1;
				for(int j=0;j<frames;j++)
				{
					int k;
					for(k=i+1;k<numberOfPages;k++)
					{
						if(pages[k]==q[j])
						{
							if(k-i>maxDis)
							{
								maxDis=k-i;
								indexToBeReplaced=j;
							}
							break;
						}
					}
					if(k==numberOfPages)
					{
						indexToBeReplaced=j;
						break;
					}
				}
				present[q[indexToBeReplaced]]=0;
				q[indexToBeReplaced]=currentPage;
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
	OPT(pages,frames);
}
/* Time Complexity : O(numberOfPages^2 * frames)
   Space Complexity: O(numberOfPages+frames) */