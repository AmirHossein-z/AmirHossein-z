#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *link;
    Node(int data);
};

class priorityQueue
{
private:
    Node *Head;

public:
    priorityQueue();
    ~priorityQueue();
    bool empty();
    void push(int x);
    void pop();
    int top();
    void print(); // this functions aren't in real priority queue
};

// create a node
Node::Node(int data)
{
    this->data = data;
    link = nullptr;
}

// create an empty linked list
priorityQueue::priorityQueue() { Head = nullptr; }

// free heap
priorityQueue::~priorityQueue()
{
    while (Head != nullptr)
    {
        Node *temp = Head;
        Head = Head->link;
        delete temp;
    }
}

// check if linked list is empty
bool priorityQueue::empty() { return Head == nullptr; }

// add a node base on priority
void priorityQueue::push(int x)
{
    Node *temp = new Node(x);
    if (empty())
    {
        Head = temp;
        return;
    }
    else
    {
        Node *s = Head;
        // find proper position
        while (s != nullptr)
        {
            if (s->data <= x)
                break;

            s = s->link;
        }

        // if we want to add at Head of linked list
        if (s == Head)
        {
            temp->link = Head;
            Head = temp;
        }
        // if we want to add in middle or at end of linked list
        else
        {
            Node *pre = Head;
            while (pre->link != s)
                pre = pre->link;

            temp->link = s;
            pre->link = temp;
        }
    }
}

// remove from Head
void priorityQueue::pop()
{
    if (empty())
        return;

    Node *temp = Head;
    Head = Head->link;
    delete temp;
}

// print all node in linked list
void priorityQueue::print()
{
    Node *temp = Head;
    while (temp != nullptr)
    {
        cout << temp->data << '\t';
        temp = temp->link;
    }
    cout << endl;
}

int main()
{
    priorityQueue pq;
    return 0;
}