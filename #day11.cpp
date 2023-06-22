#include<bits/stdc++.h>
using namespace std;
class Node
{  public:
    int data;
    Node* next;
    Node()
    {
       this->data=0;
        this->next=NULL;
    }
    Node(int data)
    {
       this->data=data;
        this->next=NULL;
    }
    
};
Node *addTwoNumbers(Node *l1, Node *l2)
{
    // Write your code here.
    Node* dummy=new Node();
    Node* temp=dummy;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry==1)
    {
        int sum=0;
        if(l1!=NULL)
        {
            sum+=l1->data;
            l1=l1->next;
        }
         if(l2!=NULL)
        {
            sum+=l2->data;
            l2=l2->next;
        }
        sum+=carry;
        carry=(sum/10);
        Node* node=new Node(sum%10);
        temp->next=node;
        temp=temp->next;
    }
    return dummy->next;
}

void deleteNode(Node* node) {
    // Write your code here.
    node->data=node->next->data;
    node->next=node->next->next;
}
Node* findIntersection(Node *headA, Node *headB)
{
    //Write your code here
     if(headA==NULL || headB==NULL)  
          return NULL;
       Node* a=headA;
       Node* b=headB;
       while(a!=b)
       {
           a=a==NULL?headB:a->next;
           b=b==NULL?headA:b->next;
       }
       return a;

}