#include<iostream>
#include<vector>
using namespace std;

class NodeList
{
    public:
    int data;
    NodeList* next;

    NodeList(int data): data(data), next(NULL){};
    
};

NodeList* CreateLinkedList(vector<int>& arr, int size)
{
    if(size==0)
    {
        return NULL;
    }

    NodeList* head=new NodeList(arr[0]);
    NodeList* tail=head;

    for(auto i: arr)
    {
        NodeList* newNode=new NodeList(i);
        tail->next=newNode;
        tail=newNode;
    }
    return head;
}

//find middle
NodeList* findmidNode(NodeList* &head)
{
    if(head==nullptr) return head;
    
    NodeList* slow=head;
    NodeList* fast=head;
    while(fast->next!=NULL)
    {
        fast=fast->next;
        if(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}

//reverse linked list
NodeList* ReverseLinkedList(NodeList* & head)
{
    NodeList* prevNode=NULL;
    NodeList* currNode=head;
    NodeList* currNext=NULL;

    while (currNode!=NULL)
    {
        currNext=currNode->next;
        currNode->next=prevNode;
        prevNode=currNode;
        currNode=currNext;
    }
    prevNode->next=NULL;
    return prevNode;
}

//compare linked list
bool compareList(NodeList* &head1, NodeList* &head2)
{
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data!=head2->data)
        {
            return false;
        }
        else
        {
            head1=head1->next;
            head2=head2->next;
        }
    }
    return true;
}

bool PalindromeList(NodeList* &head)
{
    if(head==NULL || head->next==NULL)
    {
        return true;
    }
    //step 1: find mid
    NodeList* midNode=findmidNode(head);
    
    //step 2: create 2 halves and 1 st half is head1 and 2nd halves head2
    NodeList* head2=midNode->next;
    midNode->next=NULL;
    //reverse 2nd linked list
    head2=ReverseLinkedList(head2);

    //step 3: compare
    return compareList(head, head2);
}

int main()
{
    vector<int>arr={10, 20, 40, 10};
    //vector<int>arr={1,2,2,1};
    int n=arr.size();
    NodeList* head=CreateLinkedList(arr, n);
    
    if(PalindromeList(head))
    {
        cout<<"it is Palindrome Linked List."<<endl;
    }
    else
    {
        cout<<"it is Not - Palindrome Linked List."<<endl;
    }
}