#include <bits/stdc++.h> 
using namespace std;
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //TC O(n^2);
    // next_permutation(permutation.begin(),permutation.end());
    // return permutation;

    int index=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(permutation[i]<permutation[i+1])
        {
            index=i;
            break;
        }
    }
    if(index==-1)
    {
        reverse(permutation.begin(),permutation.end());

    }
    else{
    //step2:
    for(int i=n-1;i>=index;i--)
    {
      if (permutation[i] > permutation[index]) {
        swap(permutation[i], permutation[index]);
        break;
      }
    }
    // step3:
    reverse(permutation.begin() + index + 1, permutation.end());
    }

    return permutation;

}
void sort012(int *arr, int n)
{
   //   Write your code here
  //TC O(n logn)
  //  sort(arr,arr+n);
  int count1=0,count2=0,count3=0;
  for(int i=0;i<n;i++)
  {
    if(arr[i]==0)
    {
      count1++;

    }
    else if(arr[i]==1)
    {
      count2++;
    }
    else if(arr[i]==2)
    {
      count3++;
    }
  }
 /* int count=0;
  for(int i=0;i<count1;i++)
  {
    arr[i]=0;
    count++;
  }
  for(int i=count1;i<count1+count2;i++)
  {
    arr[i]=1;
    count++;
  }
  for(int i=count2+count1;i<n;i++)
  {
    arr[i]=2;
    count++;
  }*/
  //Dutch National Flag Algorithm
  int low=0,high=n-1,mid=0;
  while(mid<=high)
  {
    if(arr[mid]==0)
    {
      swap(arr[mid],arr[low]);
      low++;
      mid++;
    }
    else if(arr[mid]==1)
    {
      mid++;
    }
    else
    {
      swap(arr[mid],arr[high]);
      high--;
    }
  }
  cout<<"The sorted array: ";
  for(int i=0;i<5;i++)
    cout<<arr[i]<<" ";
   
}
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int profit=0;
    int maxProfit=0;
    int n=prices.size();
    for(int i=0;i<n-1;i++)
    {
      for(int j=i+1;j<n;j++)
      {
        profit=prices[j]-prices[i];
        maxProfit=max(maxProfit,profit);
      }
    }

    //optimal appraoch
    int minprice=prices[0];
    for(int i=1;i<prices.size();i++)
    {
        minprice=min(minprice,prices[i]);
        profit=prices[i]-minprice;
        maxProfit=max(maxProfit,profit);
    }
     return maxProfit;
 cout<<" Maximum Profit "<<maxProfit<<endl;
}
long long maxSubarraySum(int arr[], int n)
{
   
   int maxi=INT_MIN;
   //Brute Force approach; TC-O(n^3) SC-O(n)
   for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                  sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }
    //Better Approach -O(n^2)
     for(int i=0;i<n;i++)
    {
      int sum=0;
      for(int j=i;j<n;j++)
      {
        sum+=arr[j];

      maxi=max(maxi,sum);
      }
    }
   
   //Optimal Approach -O(n) Kadanes algorithm
    long long sum,maxi=LONG_MIN;
    for(int i=0;i<n;i++)
    { sum=sum+arr[i];
        if(sum>maxi)
         {
             maxi=sum;
         }
         if(sum<0)
         {
             sum=0;
         }
    }
    if(maxi<0)
      return 0;
    else 
      return maxi;
      cout<<maxi<<" ";
}
int main()
{
  int arr[]={-2,-3,4,-1,-2,1,5,-3};
  // sort012(arr,5);
  vector<int>prices={7,1,5,6,4};
  // maximumProfit(prices);
  maxSubarraySum(arr,8);

  return 0;
}