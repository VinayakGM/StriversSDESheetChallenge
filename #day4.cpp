#include <bits/stdc++.h> 
using namespace std;
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
{
    // Write your code here.
    int n=arr.size();
	vector<vector<int>>ans;
	/*sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++)
	{
		int start=arr[i][0];
		int end=arr[i][1];
		if(!ans.empty() && end<=ans.back()[1])
		 {
			 continue;
		 }
		 for(int j=i+1;j<n;j++)
		 {
			 if(arr[j][0]<=end)
			 {
				 end=max(end,arr[j][1]);

			 }
			 else
			   break;
		 }
		 ans.push_back({start,end});
	}*/
	//Better Approach
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++)
	{
		if(ans.empty() || arr[i][0]>ans.back()[1])
		{
			ans.push_back(arr[i]);
		}
		else
		{
			ans.back()[1]=max(ans.back()[1],arr[i][1]);
		}
	}
	return ans;
}
 void swapgreater(vector<int>&arr1,vector<int>&arr2,int l,int r)
	{
		if(arr1[l]>arr2[r])
		{
			swap(arr1[l],arr2[r]);
		}
	}
 void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
  //Brute Force Method :TC:-2O(m+n) SC-O(n+m);
	/*  vector<int>arr3(m+n);
	int left=0;
	int right=0;
	int index=0;
	while(left<m && right<n)
	{
		if(arr1[left]<=arr2[right])
		{
			arr3[index]=arr1[left];
			left++;
			index++;
		}
		else{
			arr3[index]=arr2[right];
			right++;
			index++;
		}
	}
	while(left<m)
	{
		arr3[index++]=arr1[left++];
	}
	while(right<n)
	{
		arr3[index++]=arr2[right++];
	}
	for(int i=0;i<m+n;i++)
	{
		arr1[i]=arr3[i];
	}*/
	//optimal solution
/*	int left=m-1;
	int right=0;
	while(left>=0 && right<n)
	{
		if(arr1[left]>arr2[right])
		{
			swap(arr1[left],arr2[right]);
			left--;
			right++;
		}
		else
		{
          break;
		}
	}
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());
	*/
	int len=n+m;
	int gap=len/2+len%2;
	while(gap>0)
	{
		int left=0;
		int right=left+gap;
		while(right<len)
		{
			//left and rigth lies on arr1 and arr2
			if(left<=m && right>=m)
			{
				swapgreater(arr1,arr2,left,right-m);

			}
			else if(left>=m)//both lies on arr2
		   {
              swapgreater(arr2,arr2,left-m,right-m);
			 }
			 else
			 {
				 swapgreater(arr1,arr2,left,right);
			 }
				left++;
				right++;
		}
		if(gap==1)
		  break;
		gap=gap/2+gap%2;
	}
	if(n!=0)
	{
	for(int i=0;i<n;i++)
	{
    arr1[i+m]=arr2[i];
	}
	}
 }
   void inversionCount(long long arr[], long long N)
    {
        long long count=0;
        for(int i=0;i<N-1;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if(arr[j]<arr[i])
                   count++;
            }
        }
        cout<<count<<endl;;
    }
int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    int cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.
    return mergeSort(a,0,n-1);
}
int main()
{
    // vector<vector<int>>arr={{1,3},{2,4},{3,6},{8,9},{10,11},{13,17},{15,16}};
//   vector<vector<int>>ans=mergeIntervals(arr);
 long long arr[]={1,2,3,4,5};
  inversionCount(arr,5);
}