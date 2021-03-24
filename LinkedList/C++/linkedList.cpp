#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void insert(Node **head, int val)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data = val;
    new_node->next = *head;
    *head = new_node;
}

Node* XOR(Node* a, Node* b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b)); 
}

void convert(struct Node *head) 
{ 
    struct Node *next_node; 
    struct Node *prev = NULL; 
    while (head != NULL) 
    { 
        next_node = head->next; 
        head->next = XOR(next_node, prev); 
        prev = head; 
        head = next_node; 
    } 
} 
void pairSum(struct Node *head, int x) 
{ 
    struct Node *first = head; 
    struct Node *next_node = NULL, *prev = NULL; 
    struct Node *second = head; 
    while (second->next != prev) 
    { 
        struct Node *temp = second; 
        second = XOR(second->next, prev); 
        prev = temp; 
    } 
    next_node = NULL; 
    prev = NULL; 

    bool flag = false; 
    while (first != NULL && second != NULL && 
            first != second && first != next_node) 
    { 
        if ((first->data + second->data)==x) 
        { 
            cout << "(" << first->data << ","
                 << second->data << ")" << endl; 
  
            flag = true; 
  
            struct Node *temp = first; 
            first = XOR(first->next,prev); 
            prev = temp; 
  
            temp = second; 
            second = XOR(second->next, next_node); 
            next_node = temp; 
        } 
        else
        { 
            if ((first->data + second->data) < x) 
            { 
                struct Node *temp = first; 
                first = XOR(first->next,prev); 
                prev = temp; 
            } 
            else
            { 
                struct Node *temp = second; 
                second = XOR(second->next, next_node); 
                next_node = temp; 
            } 
        } 
    } 
    if (flag == false) 
        cout << "No pair found" << endl; 
} 
  
int main(int args, char **argc)
{
    struct Node *head = NULL;
    int x = 17;

    /* Use insert() to construct below list 
    3-->6-->7-->8-->9-->10-->11 */
    insert(&head, 11);
    insert(&head, 10);
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 7);
    insert(&head, 6);
    insert(&head, 3);

    // convert singly linked list into XOR doubly
    // linked list
    convert(head);
    pairSum(head, x);
    return 0;
}