#include <iostream>
using namespace std;

struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        data = node_data;
        next = nullptr;
    }
};

SinglyLinkedListNode *reverse(SinglyLinkedListNode *head)
{
    SinglyLinkedListNode *prev = nullptr;
    SinglyLinkedListNode *curr = head;

    while (curr != nullptr)
    {
        SinglyLinkedListNode *next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }

    return prev;
}

void printLinkedList(SinglyLinkedListNode *head)
{
    SinglyLinkedListNode *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    SinglyLinkedListNode *head = new SinglyLinkedListNode(1);
    head->next = new SinglyLinkedListNode(2);
    head->next->next = new SinglyLinkedListNode(3);
    head->next->next->next = new SinglyLinkedListNode(4);

    cout << "Original List: ";
    printLinkedList(head);

    head = reverse(head);

    cout << "Reversed List: ";
    printLinkedList(head);

    return 0;
}
