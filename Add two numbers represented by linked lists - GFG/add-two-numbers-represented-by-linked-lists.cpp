//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends

class Solution
{
public:
    struct Node* reverseList(struct Node* head) {
        struct Node* prev = NULL;
        struct Node* current = head;
        struct Node* next = NULL;
        
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverseList(first);
        second = reverseList(second);
        
        struct Node* res = NULL;
        struct Node* prev = NULL;
        int carry = 0;
        
        while (first != NULL || second != NULL)
        {
            int sum = carry;
            if (first) {
                sum += first->data;
                first = first->next;
            }
            if (second) {
                sum += second->data;
                second = second->next;
            }
            
            carry = sum / 10;
            sum = sum % 10;
            
            struct Node* newNode = new Node(sum);
            if (!res) {
                res = newNode;
            } else {
                prev->next = newNode;
            }
            prev = newNode;
        }
        
        if (carry > 0) {
            struct Node* newNode = new Node(carry);
            if (!res) {
                res = newNode;
            } else {
                prev->next = newNode;
            }
        }
        
        return reverseList(res);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends