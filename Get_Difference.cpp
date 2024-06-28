#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}


int find_max(Node *head)
{
    int max = head->val;
    Node *temp = head;
    if(head->next == NULL){
        return max;
    }
    while (temp != NULL)
    {
        if (temp->val > max)
        {
            max = temp->val;
        }
        temp = temp->next;
    }
    return max;
}

int find_min(Node *head)
{
    int min = head->val;
    Node *temp = head;
    if(temp->next == NULL){
        return min;
    }
    while (temp != NULL)
    {
        if (temp->val < min)
        {
            min = temp->val;
        }
        temp = temp->next;
    }
    return min;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
            break;
        insert_at_tail(head, tail, val);
    }
    int max = find_max(head);
    int min = find_min(head);
    cout << max - min;
    return 0;
}