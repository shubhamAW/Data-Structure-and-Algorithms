#include <iostream>
using namespace std;

// class Employee
class Employee
{
    int id;
    string name;

    Employee(int id, string name)
    {
        this->id = id;
        this->name = name;
    }
};

// linked list.
struct Node
{
    int data;
    Node *next;
};

/// @brief Add New Node to at the End of List
/// @param head
/// @param tail
/// @param data
void AddToTail(Node **head, Node **tail, int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL)
    {
        *head = temp;
        *tail = temp;
    }
    else
    {
        (*tail)->next = temp;
        *tail = temp;
    }
}

/// @brief Add New Node to Start of the List
/// @param head
/// @param data
void AddToStart(Node **head, int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

/// @brief Print the List from head
/// @param head
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/// @brief search element in the list
/// @param head
/// @param data
/// @return return true if it is found, return false if not found.
bool SearchList(Node *head, int data)
{
    if (head == NULL)
    {
        return false;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

/// @brief Insert at specific position.
/// @param head
/// @param data
/// @param position
void InsertAtPosition(Node **head, int data, int position)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;

    if (position == 0)
    {
        temp->next = *head;
        *head = temp;
    }
    else
    {
        Node *temp2 = *head;
        for (int i = 0; i < position - 1; i++)
        {
            temp2 = temp2->next;
        }
        temp->next = temp2->next;
        temp2->next = temp;
    }
}

/// @brief Delete position from the list.
/// @param head
/// @param data
/// @param position
void DeletePosition(Node **head, int position)
{
    if (*head == NULL)
    {
        return;
    }

    if (position == 0)
    {
        Node *temp = *head;
        *head = (*head)->next;
        delete temp;
    }
    else
    {
        Node *temp = *head;
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
    }
}

/// @brief driver Function.
/// @return
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *temp = NULL;

    int position;
    int choice;
    do
    {
        cout << "1. Add to tail." << endl;
        cout << "2. Add to start." << endl;
        cout << "3. Search." << endl;
        cout << "4. Insert at specific  position." << endl;
        cout << "5. Print List." << endl;
        cout << "6.Delete Node at specific Position." << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter data: ";
            cin >> data;
            AddToTail(&head, &tail, data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            AddToStart(&head, data);
            break;
        case 3:
            cout << "Enter data: ";
            cin >> data;
            if (SearchList(head, data))
            {
                cout << "Found" << endl;
            }
            else
            {
                cout << "Not Found" << endl;
            }
            break;
        case 4:
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter position: ";
            cin >> position;
            InsertAtPosition(&head, data, position);
            break;
        case 5:
            printList(head);
            break;
        case 6:
            cout << "Enter Position: ";
            cin >> position;
            DeletePosition(&head, position);
            break;
        case 7:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 7);
}