#include<bits/stdc++.h>
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n=arr.size();
    int count=0;
   /* for(int i=0;i<n;i++)
    {
        int xr=0;
        for(int j=i;j<n;j++)
        {
            xr=xr^arr[j];
            if(xr==x)
             {
                 count++;
             }
        }
    }*/
    int xr=0;
    unordered_map<int,int>mpp;
    mpp[xr]++;
    for(int i=0;i<n;i++)
    {
        xr=xr^arr[i];
        int k=xr^x;
        count+=mpp[k];
        mpp[xr]++;
    }
    return count;
}
int uniqueSubstrings(string input)
{
    //Write your code here
    int maxlen=0;
    int len=input.length();
    /*vector<int>mpp(256,-1);
    int left=0,right=0;
    while(right<len)
    {
        if(mpp[input[right]]!=-1)
          left=max(mpp[input[right]]+1,left);
        mpp[input[right]]=right;
    maxlen=max(maxlen,right-left+1);
    right++;
    }*/
    for(int i=0;i<len;i++)
    { unordered_set<int>st;
        for(int j=i;j<len;j++)
        {
           if(st.find(input[j])!=st.end())
           {
               maxlen=max(maxlen,j-i);
               break;
           }
           st.insert(input[j]);
        }
    }
    /* int l=0;
    unordered_set<int>st;
    
    for(int r=0;r<len;r++)
    {  if(st.find(input[r])!=st.end())
        {
        while (l < r && st.find(input[r]) != st.end()) {
          st.erase(input[l]);
          l++;
        }
      }
        st.insert(input[r]);
        maxlen=max(maxlen,r-l+1);
    }*/
    return maxlen;
}
int main()
{
    cout<<uniqueSubstrings("abcabcabb")<<endl;
}