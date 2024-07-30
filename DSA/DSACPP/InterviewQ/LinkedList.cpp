#include <iostream>

// Definition of a node in the linked list
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node in the list

    // Constructor to initialize a node with a given value
    Node(int value) : data(value), next(nullptr) {}
};

// Definition of a singly linked list
class LinkedList
{
private:
    Node *head; // Pointer to the first node in the list

public:
    // Constructor to initialize an empty list
    LinkedList() : head(nullptr) {}

    // Method to insert a new node with a given value at the end of the list
    void insert(int value)
    {
        Node *newNode = new Node(value); // Create a new node
        if ( head == nullptr )
        {                   // If the list is empty
            head = newNode; // The new node becomes the head of the list
        }
        else
        {
            Node *temp = head; // Start at the head of the list
            while (temp->next != nullptr)
            { // Traverse to the end of the list
                temp = temp->next;
            }
            
            temp->next = newNode; // Append the new node to the end of the list
        }
    }

    // Method to display all the nodes in the list
    void display() const
    {
        Node *temp = head; // Start at the head of the list
        while (temp != nullptr)
        {                                      // Traverse until the end of the list
            std::cout << temp->data << " -> "; // Print the data in the current node
            temp = temp->next;                 // Move to the next node
        }
        std::cout << "  Head is nullptr" << std::endl; // Indicate the end of the list
    }
};

// Main function demonstrating the use of the LinkedList class
int main()
{
    LinkedList list; // Create a LinkedList object
    list.insert(10); // Insert nodes with values 10, 20, and 30
    list.insert(20);
    list.insert(30);
    list.display();  // Display the list: Output should be "10 -> 20 -> 30 -> nullptr"
    return 0;
}
