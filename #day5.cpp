#include<bits/stdc++.h>
using namespace std;
//1.searching element in 2d array
bool searchMatrix(vector<vector<int>>& mat, int target) {
     int N=mat.size();
     int M=mat[0].size();
     int X=target;
    /* for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             if(mat[i][j]==target)
                return true;
         }
     }*/
      int i=0,j=M-1;
        while(i<N && j>=0)
        {
            if(mat[i][j]==X)
               return true;
            else if(mat[i][j]>X)
               j--;
            else 
               i++;
        }
     return false;
}
double Mypow(double x,int n)
{
   double ans=1.0;
   long long nn=n;
   if(nn<0) nn=(-1)*nn;
   while(nn>0)
   {
         if(nn%2==1)
         {
          ans=ans*x;
          nn=nn-1;
         }
         else
         {
            x=x*x;
            nn=nn/2;
         }
   }
   if(n<0)
     ans=(double)(1.0)/(double)ans;
   return ans;
}
int main()
{
   cout<<Mypow(2.0,-10)<<endl;
}