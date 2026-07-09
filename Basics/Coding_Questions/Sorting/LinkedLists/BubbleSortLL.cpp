#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) : data(x){}
};

int getLength(Node* head)
{
    int res=0;
    while(head!=nullptr)
    {
        res++;
        head=head->next;
    }
    return res;
}

Node* bubbleSortLL(Node* head)
{
    int itr =0;
    int length = getLength(head);

    while(itr<length)
    {
        Node* traverseN = head;
        Node* prevN = head;
        Node* front = traverseN->next;
        bool swapped = false;

        while(traverseN->next)
        {
            if(traverseN->data > front->data)
            {
                swapped = true;
                if(traverseN == head)
                {
                    traverseN->next = front->next;
                    front->next = traverseN;
                    prevN = front;
                    head = prevN;
                }
                else
                {
                    traverseN->next = front->next;
                    front->next = traverseN;
                    prevN->next = front;
                    prevN = front;
                }
            }
            else
            {
                prevN = traverseN;
                traverseN = traverseN->next;
            }
        }
        printLL(head);

        if(!swapped){break;}
        itr++;
    }

    return head;
}

void printLL(Node* head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = new Node(5);
}