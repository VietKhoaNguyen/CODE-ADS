Node* Insert(Node* head, int pos, int newData)
{
    if (pos < 1 || pos > LengthLinkedList(head) + 1)
    {
         return head;
    }

    Node* newNode = Init(newData);
    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

     Node*  current = head;
     for (int i = 1; i < pos - 1; i++)
     {
         current = current->next;
     }

    newNode->next = current->next;
    current->next = newNode;
}