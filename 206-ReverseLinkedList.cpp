#include<iostream>
#include<vector>
using namespace std;

class NodeList
{
public:
    int data;
    NodeList* next;
public:
    NodeList(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

NodeList* CreateLinkedList(vector<int>& arr, int size)
{
    if(size==0)
    {
        return NULL;
    }

    NodeList* head=new NodeList(arr[0]);
    NodeList* tail=head;

    for(int i=1; i<size; i++)
    {
        NodeList* newNode=new NodeList(arr[i]);
        tail->next=newNode;
        tail=newNode;
    }
    return head;
}

NodeList* ReverseLinkedList(NodeList* &head)
{
    if(head==NULL)
        return NULL;

    NodeList* prevNode=NULL;
    NodeList* currNode=head;
    NodeList* currNext=NULL;

    while(currNode!=NULL)
    {
        currNext=currNode->next;
        currNode->next=prevNode;
        prevNode=currNode;
        currNode=currNext;
    }
    head=prevNode;
    return head;
}

void printLL(NodeList* head)
{
    NodeList* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ->";
        temp=temp->next;
    } 
}
int main()
{
    
    vector<int>arr={10, 20, 30, 40, 50};
    int n=arr.size();
    NodeList* head=CreateLinkedList(arr, n);
    printLL(head);
    cout<<endl;
    ReverseLinkedList(head);
    printLL(head);
}