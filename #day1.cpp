#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
int ncr(int n,int r)
{
  int res=1;
    
    for(int i=0;i<r;i++)
    {
      res=res*(n-i);
      res=res/(i+1);
    }
    return res;
}

void printPascal(int n) 
{
  // Write your code here.
  vector<vector<int>>ans;
  for(int i=1;i<=n;i++)
  {
    vector<int>temp;
    for(int j=1;j<=i;j++)
    {
      temp.push_back(ncr(i-1,j-1));

    }
    ans.push_back(temp);
  }
  for(int i=0;i<ans.size();i++)
  {
    for(int j=0;j<ans.size();j++)
    {
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }

}
vector<int> generaterow(int row)
{ int ans=1;
    vector<int>res;
    res.push_back(1);
    for(int j=1;j<row;j++)
    {
        ans=ans*(row-j);
        ans=ans/j;
       res.push_back(ans);
    }
    return res;
}
void pascaltraingle(int n)
{
    vector<vector<int>>ans;
    for(int i=1;i<=n;i++)
    {
        ans.push_back(generaterow(i));
    }
    for(int i=0;i<ans.size();i++)
  {
    for(int j=0;j<ans.size();j++)
    {
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main()
{   printPascal(5);


    return 0;

}
