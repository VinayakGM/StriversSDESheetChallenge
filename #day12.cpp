#include<bits/stdc++.h>
using namespace std;

class Node
{
        public:
            int data;
            Node *next;
            Node* child;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
}* head=NULL;
bool detectCycle(Node *head)
{
	//	Write your code here
     if(head==NULL && head->next==NULL)
        return false;
    
    Node* fast=head;
    Node* slow=head;
    while(fast->next && fast->next->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
           return true;
    }
    return false;
//Brute force method
   /*unordered_set<ListNode*>ht;
         while(head!=NULL)
         {
             if(ht.find(head)!=ht.end())
               return true;
            ht.insert(head);
            head=head->next;
         }
         return false;*/
}

Node* reverse(Node* &head)
  { Node* p=head;
    Node* q=NULL;
    Node* r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    return q;

  }
    bool isPalindrome(Node* head) {
       /* ListNode* p=head;
        vector<int>arr;
        while(p!=NULL)
        {
          arr.push_back(p->val);
          p=p->next;

        }
        int high=arr.size()-1;
        int low=0;
        while(low<=high)
        {
          if(arr[low]!=arr[high])
             return false;
          low++;
          high--;

        }
        return true;*/
        Node* slow=head;
        Node* fast=head;

        while(fast->next!=NULL && fast->next->next)
        {
          slow=slow->next;
          fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        while(slow!=NULL)
        {
          if(head->data!=slow->data)
             return false;
           head=head->next;
           slow=slow->next;
        }
        return true;
     }
Node *firstNode(Node *head)
{
    //   Write your code here.
           /* unordered_set<ListNode*>st;
        while(head!=NULL)
        {
            if(st.find(head)!=st.end())
                return head;
            st.insert(head);
            head=head->next;
        }
        return NULL;*/
        if(head==NULL ||head->next==NULL)
           return NULL;
         
         Node* slow=head;
         Node* fast=head;
        Node* entry=head;

         while(fast->next!=NULL && fast->next->next!=NULL)
         {
             slow=slow->next;
             fast=fast->next->next;
             if(slow==fast)
             {
                 while(slow!=entry)
                 {
                     slow=slow->next;
                     entry=entry->next;
                 }
                 return entry;
             }
         }
         return NULL;
}
Node* merge(Node* a,Node* b)
{
    Node* temp=new Node(0);
    Node* res=temp;
    while(a!=NULL && b!=NULL)
    {
        if(a->data<b->data)
        {
            temp->child=a;
            temp=temp->child;
            a=a->child;
        }
        else
        {
            
            temp->child=b;
            temp=temp->child;
            b=b->child;
        
        }
    }
    if(a)
       temp->child=a;
    else
       temp->child=b;

    return res->child;
}
Node* flattenLinkedList(Node* root) 
{
	// Write your code here
	if(root==NULL ||root->next==NULL)
      return root;
    
  Node*L2=flattenLinkedList(root->next);
  root->next=NULL;
  
  Node* nhead=merge(root,L2);
  
  return nhead;
}
Node *rotate(Node *head, int k) {
     // Write your code here.
     if(!head|| !head->next || k==0)
        return head;
     int len=1;
     Node* p=head;
     while(p->next && ++len)
     {
          p=p->next;
     }
     p->next=head;

     //to cut the node;
     k=k%len;
     k=len-k;
     Node* q=head;
     while(k--)
     {
     p=p->next;
     }
     head=p->next;
     p->next=NULL;

    return head;
}