#include<bits/stdc++.h>
using namespace std;
 int findDuplicate(vector<int>& nums) {
        
        unordered_map<int,int>mpp;
         int n=nums.size();
      /*  TC-O(n ^2 or n)+O(n) SC-O(n)
      for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        for(auto it:mpp)
        {
            if(it.second>1)
               return it.first;
        }*/
       /* 
       //Brute Force method 
       //TC O(n^2) SC-O(1)
         int count;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {   count=0;
            for(int j=0;j<n;j++)
            {
                if(nums[i]==nums[j])
                  count++;
            }
            if(count>1)
            {
                return nums[i];
                break;
            }
        }*/
        int freq[n+1]={0};
        for(int i=0;i<n;i++)
        {
            if(freq[nums[i]]==0)
              freq[nums[i]]==1;
            else
               return nums[i];
        }
        for(int i=0;i<n;i++)
        {

        }
        int slow=nums[0];
        int fast=nums[0];
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];

        }while(slow!=fast);
        fast=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
         return slow;
    }
    
void missingAndRepeating(vector<int> &arr, int n)
{ /*int miss=-1,repeat=-1;
 int count;
 for(int i=1;i<=n;i++)
 {  count=0;
    for(int j=0;j<n;j++)
    {
        if(arr[j]==i) 
          count++;
    }
      if(count==2)
      { 
        repeat=i;
        
      }
    if(count==0)
    {
        miss=i;
    }
 }*/





 /*int hash[n+1]={0};
 for (int i = 0; i <n; i++)
 {
    hash[arr[i]]++;

 }
 for(int i=1;i<=n;i++)
 {
    if(hash[i]==0)
       miss=i;
    if(hash[i]==2)
       repeat=i;
 }*/
 

 long long sn=(n*(n+1)/2);
 long long s2n=(n*(n+1)*(2*n+1))/6;
 long long s=0,s2=0;
 for(int i=0;i<n;i++)
 {
    s+=arr[i];
    s2+=(long long)arr[i]*(long long)arr[i];
 }
 int val1=s-sn;//x-y=s-sn;
  int val2=s2-s2n;//x^2-y^2=s2-s2n;
  val2=val2/val1;

  int x=(val1+val2)/2;
  int y=x-val1;



cout<<y<<" "<<x;
}
int main()
{
    vector<int>arr={5,4,2,4,1};
    // missingAndRepeating(arr,5);
    int s=0;
    int p=500000;
    for(int i=0;i<7;i++)
    {
      s+=p+(p*9.5)/100;
    }
    std::cout<<s<<endl;
}
