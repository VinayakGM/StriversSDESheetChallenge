#include<bits/stdc++.h>
using namespace std;
template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };




LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head) {
  // Write your code here.
        unordered_map<LinkedListNode<int>*, LinkedListNode<int>*> map;
    LinkedListNode<int> *temp = head;

    while(temp != NULL){
        map[temp] = new LinkedListNode<int>(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        map[temp]->next = map[temp->next];
        map[temp]->random = map[temp->random];
        temp = temp->next;
    }

    return map[head];

    if(head==NULL|| head->next==NULL)
       return 

/* optimal 
    //step 1;
        LinkedListNode<int>* itr=head;
        LinkedListNode<int>* fast=head;
        while(itr!=NULL)
        {
            fast=itr->next;
           LinkedListNode<int>* temp=new LinkedListNode<int>(itr->data);
           itr->next=temp;
           temp->next=fast;
           itr=itr->next->next;
        }
        //step 2
        itr=head;
        while(itr!=NULL)
        {
            if(itr->random!=NULL)
                itr->next->random=itr->random->next;
            itr=itr->next->next;
        }
        //step 3
        LinkedListNode<int>* dummy = new LinkedListNode<int>(0);
    itr = head;
   LinkedListNode<int>* temp = dummy;
    while(itr != NULL) {
        fast = itr->next->next;
        temp->next = itr->next;
        itr->next = fast;
        temp = temp->next;
        itr = fast;
    }
    return dummy->next;*/
}
    int trap(vector<int>& arr) {
       /*optimal :TC-O(n) SC-O(1)
        int res=0;
        int leftmax=0;
        int rightmax=0;
        int left=0;
        int right=height.size()-1;
        while(left<=right)
        {
            if(height[left]<=height[right])
            {   if(height[left]>=leftmax)
                  leftmax=height[left];
                else
                   res+=leftmax-height[left];
               left++;
            }
            else
            {
                if(height[right]>=rightmax)
                     rightmax=height[right];
                else
                     res+=rightmax-height[right];
               right--;
            }
        }
        return res;*/
        //Brute Force method
        /*
        int n=arr.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            int j=i;
            int maxl=0,maxr=0;
            while(j>=0)
            {
                maxl=max(maxl,arr[j]);
                j--;
            }
            j=i;
            while(j<n)
            {
                maxr=max(maxr,arr[j]);
                j++;
            }
            res+=min(maxl,maxr)-arr[i];
        }
        return res;
        */
        //Better approach
      //  TC-O(n)
        //SC-O(2n)
        int n=arr.size();
        int res=0;
        int prefix[n];
        prefix[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=max(prefix[i-1],arr[i]);
        }
        int suffix[n];
      suffix[n-1]=arr[n-1];
      for(int i=n-2;i>=0;i--)
      {
          suffix[i]=max(suffix[i+1],arr[i]);
      }
      for(int i=0;i<n;i++)
      {
          res+=min(prefix[i],suffix[i])-arr[i];
      }
      return res;
    }