#include <bits/stdc++.h>
using namespace std; 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	set<vector<int>>st;
/*	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{  long long sum=0;
			for(int k=j+1;k<n;k++)
			{  sum=arr[i]+arr[j]+arr[k];
			    if(sum==K)
				{
					vector<int>temp={arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
					st.insert(temp);
				}
				
			}
		}
	}
	*/
	/*for(int i=0;i<n;i++)
	{
	      set<int>hashset;
		for(int j=i+1;j<n;j++)
		{
			int rem=K-arr[i]-arr[j];
			if(hashset.find(rem)!=hashset.end())
			{
				vector<int>temp={arr[i],arr[j],rem};
                    sort(temp.begin(),temp.end());
					st.insert(temp);
			}
			hashset.insert(arr[j]);
		}
	}
	vector<vector<int>>ans(st.begin(),st.end());
   return ans;
   */
   vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {   if(i>0 && arr[i]==arr[i-1]) continue;
         int j=i+1;
         int k=n-1;
         while(j<k)
         {
             int sum=arr[i]+arr[j]+arr[k];
             if(sum<K)
             {
                 j++;
             }
             else if(sum>K)
             {
                 k--;
             }
             else
             {
                 vector<int>temp={arr[i],arr[j],arr[k]};
                 ans.push_back(temp);
                 j++;
                 k--;
                 while(j<k && arr[j]==arr[j-1]) j++;
                 while(j<k && arr[k]==arr[k+1])  k--;
             }
         }

    }
	return ans;
}

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	/*if(n==1)
	   return 1;
	int count=1;
	for(int i=1;i<n;i++)
     {
          if (arr[i] != arr[i - 1])
            count++;
        }
        return count;*/
		int i=0;
		for(int j=1;j<n;j++)
		{
			if(arr[i]!=arr[j])
			{
				i++;
				arr[i]=arr[j];
			}
		}
		return i+1;
}