Node* Delete(Node* head, int pos)
{
    // If the position is out of range, return the head unchanged
    if (pos < 1 || pos > LengthLinkedList(head)) {
        return head;
    }

    // If the node to delete is the first one
    if (pos == 1) {
        Node* temp = head;     // Save the current head
        head = head->next;     // Move the head to the next node
        free(temp);            // Free the memory of the old head
        return head;
    }

    // Traverse to the node just before the one to delete
    Node* current = head;
    for (int i = 1; i < pos - 1; i++) {
        current = current->next;
    }

    // Save the node to be deleted
    Node* temp = current->next;

    // Bypass the node to be deleted
    current->next = current->next->next;

    // Free the memory of the deleted node
    free(temp);

    return head;
}
