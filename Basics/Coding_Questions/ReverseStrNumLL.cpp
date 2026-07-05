#include<iostream>
#include<vector>
using namespace std;

std::string reverseStr(std::string ipStr)
{
    int i=0,j=ipStr.length()-1;

    while(i<j)
    {
        char temp = ipStr[i];
        ipStr[i] = ipStr[j];
        ipStr[j] = temp;
        i++;
        j--;
    }
    return ipStr;
}

int reverseNum(int ipNum)
{
    int reverseN = 0;
    while(ipNum>0)
    {
        int dig = ipNum%10;
        reverseN = (reverseN * 10)+dig;;
        ipNum/=10;
    }
    return reverseN;
}

struct Node
{
    int data;
    Node* next;
    Node(int x) : data(x){}
};

Node* reverseLL(Node* head)
{
    Node* prev = nullptr;
    Node* temp = head;
    while(temp!=nullptr)
    {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* constructLL(std::vector<int> vec)
{
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    for(int i=0;i<vec.size();i++)
    {
        Node* newN = new Node(vec[i]);
        curr->next = newN;
        curr = curr->next;
    }
    Node* getHead = dummyNode->next;
    delete dummyNode;
    return getHead;
}

void printLL(Node* head)
{
    cout<<"Printing LL : "<<endl;
    while(head!=nullptr)
    {
        cout<<head->data<<endl;
        head = head->next;
    }
}

int main()
{
    std::string str = "String";
    cout<<"Original string : "<<str<<"reversed string : "<<reverseStr(str)<<endl;

    int orgN = 123;
    cout<<"Original num : "<<orgN<<"reversed Num : "<<reverseNum(orgN)<<endl;

    std::vector<int> vec = {10,20,30,40};
    Node* headL = constructLL(vec);
    printLL(headL);
    Node* revHead = reverseLL(headL);
    printLL(revHead);

    return 0;
}