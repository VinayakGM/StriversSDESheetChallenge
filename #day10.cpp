#include<bits/stdc++.h>
using namespace std;

 class LinkedListNode
    {
    public:
        int data;
        LinkedListNode *next;
        LinkedListNode(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
    class Node
    {
        public:
        int data;
        Node* next;

        Node(int x)
        {
            this->data=x;
            this->next=NULL;

        }
    };
Node *findMiddle(Node *head) {
    // Write your code here
    Node* p=head;
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    int index=(count/2)+1;
    p=head;
    count=0;
    while(p)
    {  count++;
        if(index==count)
           return p;
        p=p->next;
    }
    return NULL;
}
LinkedListNode *reverseLinkedList(LinkedListNode *head) 
{
    // Write your code here
        LinkedListNode* p=head;
        LinkedListNode* q=NULL;
        LinkedListNode* r=NULL;
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
               q->next=r;       
         }
    
     head=q;
    return head;
}
Node* sortTwoLists(Node* l1, Node* l2)
{
     if(l1 == NULL) return l2; 

        // when list2 is empty then our output 
        // will be same as list1
        if(l2 == NULL) return l1;

        // pointing l1 and l2 to smallest and greatest one
        if(l1->data > l2->data) std::swap(l1,l2);

        // act as head of resultant merged list
        Node* res = l1;

        while(l1 != NULL && l2 != NULL) {
 
            Node* temp = NULL;

            while(l1 != NULL && l1->data <= l2->data) {

                temp = l1;//storing last sorted node  
                l1 = l1->next;
            }

            // link previous sorted node with 
            // next larger node in list2
            temp->next = l2;
             swap(l1,l2);
        }

        return res;
}
Node* removeKthNode(Node* head, int K)
{
  //Brute Force method
  //TC-O(2n)
     Node* p=head;
        Node* q=NULL;
        int len=0;
        int x;
        while(p!=NULL)
        {
            len++;
            p=p->next;
        }
        p=head;
        int pos=len-K+1;
       if(pos==1)
     {
        head=head->next;
        x=p->data;
        delete p;


     }
     else
     {
        for(int i=1;i<=pos-1;i++)
        {
            q=p;
            p=p->next;
        }
        if(p)
        {
            q->next=p->next;
            x=p->data;
            delete p;
        }

     }
     return head;
}

