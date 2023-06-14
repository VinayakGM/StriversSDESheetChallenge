#include<bits/stdc++.h>
using namespace std;
//Problem 20
string fourSum(vector<int> nums, int target, int n) {
    // Write your code here.
     vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {  if(i>0 && nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<n;j++)
            {
                if(j!=(i+1) &&nums[j]==nums[j-1]) 
                   continue;
                int k=j+1;
                int l=n-1;
                while(k<l)
                {
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target)
                    { return "Yes";
                     /* ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                      k++,l--;
                     while(k<l && nums[k]==nums[k-1]) 
                        k++;
                     while(k<l && nums[l]==nums[l+1]) 
                        l--;*/
                    
                    }
                    else if(sum<target) 
                       k++;
                    else
                      l--;
                }
            }
        }
        return "No";
}
//Problem 65
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // vector<int>v;
        int n=nums1.size();
        int m=nums2.size();
        if(n>m)
           return findMedianSortedArrays(nums2,nums1);
        int low=0,high=n;
        while(low<=high)
        {
            int cut1=(low+high)/2;
            int cut2=(n+m+1)/2-cut1;
            int l1=cut1==0?INT_MIN:nums1[cut1-1];
            int l2=cut2==0?INT_MIN:nums2[cut2-1];
            int r1=cut1==n?INT_MAX:nums1[cut1];
            int r2=cut2==m?INT_MAX:nums2[cut2];
            if(l1<=r2 && l2<=r1)
            {
                if((n+m)%2==0)
                   return (max(l1,l2)+min(r1,r2))/2.0;
                else
                   return (double)max(l1,l2);
            }
            else if(l1>r2)
            {
                high=cut1-1;
            }
            else
            {
                low=cut1+1;
            }
        }
        return 0.0;


       //Brute Force Method TC-O(n+m) SC-O(m+n)
       /* int i=0,j=0;
        int k=0;
        int v[n+m];
        while(i<n && j<m)
        {
            if(nums1[i]<nums2[j])
            { 
              v[k]=nums1[i];
              i++;
              k++;  
            }
            else
            {
                v[k]=nums2[j];
                j++;
                k++;
            }
        }
        while(i<n)
        {
            v[k++]=nums1[i++];
        }
        while(j<m)
        {
            v[k++]=nums2[j++];
        }
        int s=n+m;
        double ans;
    if(s%2==0)
    {
        int index=s/2;
          ans=(double)(v[index]+v[index-1])/2;
    }
    else
    {
      int index=(s/2);
        ans=(double)(v[index]);
    }
    
    return ans;*/
    //optimal solution
    }
int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) {
    // Write your code here.
    //Brute Force method
    /*if(n==0)
      return 0;
    sort(nums.begin(),nums.end());
    int ans=1;
    int count=1;
    int pre=nums[0];
    for(int i=1;i<n;i++)
    {
      if (nums[i] == pre + 1) {
        count++;
      } 
      else if (nums[i] != pre) {
        count = 1;
      }
        pre=nums[i];
        ans=max(ans,count);
    }
    return ans;*/
    set<int>hashset;
    for(int num:nums)
    {
        hashset.insert(num);
    }
    int ans=0;
    for(int num:nums)
    {
        if(!hashset.count(num-1))
        {
            int currentele=num;
            int count=1;

            while (hashset.count(currentele + 1) == true) {
              count++;
              currentele += 1;
            }
            ans = max(count, ans);
        }
    }
    return ans;
}
int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  int n=arr.size();
  unordered_map<int,int>mpp;
  int maxlen=0;
  int sum=0;
  for(int i=0;i<n;i++)
  {
    sum+=arr[i];
    if(sum==0)
    {
      maxlen=i+1;
    }
    else
    {
      if(mpp.find(sum)!=mpp.end())
      {
         maxlen=max(maxlen,i-mpp[sum]);
      }
      else
         mpp[sum]=i;
    }
  }
  return maxlen;
}
int findMajorityElement(int arr[], int n) {
	// Write your code here.
	unordered_map<int,int>mpp;
	for(int i=0;i<n;i++)
	{
		mpp[arr[i]]++;
	}
	for(auto it:mpp)
	{
		if(it.second>(n/2))
		   return it.first;
	}
	return -1;
}
vector<int> majorityElementII(vector<int> &arr)
{
    // 
    vector<int>ans;
    unordered_map<int,int>mpp;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        mpp[arr[i]]++;
    }
    for(auto it:mpp)
    {
      if (it.second > (n / 3)) {
        ans.push_back(it.first);
      }
    }
    return ans;

}
vector<vector<int>> pairSum(vector<int> &arr, int s){
   int n=arr.size();
   vector<vector<int>>ans;
   for(int i=0;i<n;i++)
   {
      for(int j=i+1;j<n;j++)
      {
         int sum=arr[i]+arr[j];
          if(sum==s)
          {
             vector<int>res={arr[i],arr[j]};
             
             sort(res.begin(),res.end());
            ans.push_back(res);
          }

      }
   }
   sort(ans.begin(),ans.end());
   return ans;
}
int main()
{
    vector<int>nums1={7,12,14,15};
    vector<int>nums2={1,2,3,4,11};
   cout<<findMedianSortedArrays(nums1,nums2)<<endl;
}