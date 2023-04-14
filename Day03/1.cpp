#include <iostream>
using namespace std;

// class Employee
class Employee
{
public:
    int id;
    string name;

    Employee(int id, string name)
    {
        this->id = id;
        this->name = name;
    }
    Employee()
    {
        this->id = 0;
        this->name = "";
    }
};

struct Node
{
    Employee data;
    Node *next;

    Node(Employee data)
    {
        this->data = data;
        this->next = NULL;
    }
};

/// @brief Add New Node to at the End of List
/// @param head
/// @param tail
/// @param data
void AddToTail(Node **head, Node **tail, Employee data)
{
    cout << "Tempararly disabled" << endl;
    // Node *temp = new Node(data);

    // if (*head == NULL)
    // {
    //     *head = temp;
    //     *tail = temp;
    // }
    // else
    // {
    //     (*tail)->next = temp;
    //     *tail = temp;
    // }
}

/// @brief Add New Node to Start of the List
/// @param head
/// @param data
void AddToStart(Node **head, Employee data)
{
    cout << "Tempararly disabled" << endl;
    // Node *temp = new Node(data);
    // temp->data = data;
    // temp->next = *head;
    // *head = temp;
}

/// @brief Print the List from head
/// @param head
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data.id << " " << temp->data.name << " ";
        temp = temp->next;
    }
    cout << endl;
}

/// @brief search element in the list
/// @param head
/// @param data
/// @return return true if it is found, return false if not found.
bool SearchList(Node *head, Employee data)
{
    if (head == NULL)
    {
        return false;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data.id == data.id)
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
void InsertAtPosition(Node **head, Employee data)
{
    Node *temp = new Node(data);
    // first check if the id is already present in the list
    if (SearchList(*head, data))
    {
        cout << "ID already present in the list" << endl;
        return;
    }
    else
    {
        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            int key = data.id;
            Node *temp2 = *head;
            Node *prev = NULL;
            while (temp2 != NULL && temp2->data.id < key)
            {
                prev = temp2;
                temp2 = temp2->next;
            }
            if (prev == NULL)
            {
                temp->next = *head;
                *head = temp;
            }
            else
            {
                temp->next = prev->next;
                prev->next = temp;
            }
        }
    }
}

/// @brief Delete position from the list.
/// @param head
/// @param data
/// @param position
void DeleteAtPosition(Node **head, int id)
{
    if (*head == NULL)
    {
        return;
    }
    // if the id is not present in the list
    Node *temp = *head;
    Node *prev = NULL;
    while (temp != NULL && temp->data.id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "ID not present in the list" << endl;
        return;
    }
    if (prev == NULL)
    {
        *head = temp->next;
        delete temp;
    }
    else
    {
        prev->next = temp->next;
        delete temp;
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
    string name;

    do
    {
        cout << "1. Add to tail." << endl;
        cout << "2. Add to start." << endl;
        cout << "3. Search." << endl;
        cout << "4. Insert in List using id." << endl;
        cout << "5. Print List." << endl;
        cout << "6.Delete Node using id." << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Tempararly disabled" << endl;
            int data;
            // cout << "Enter data: ";
            // cin >> data;
            // cout << "Enter a Name: ";
            // cin >> name;
            // AddToTail(&head, &tail, Employee(data, name));
            break;
        case 2:
            cout << "Tempararly disabled" << endl;
            // cout << "Enter data: ";
            // cin >> data;
            // cout << "Enter a Name: ";
            // cin >> name;
            // AddToStart(&head, Employee(data, name));
            break;
        case 3:
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter a Name: ";
            cin >> name;
            if (SearchList(head, Employee(data, name)))
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
            cout << "Enter a Name: ";
            cin >> name;
            InsertAtPosition(&head, Employee(data, name));
            break;
        case 5:
            printList(head);
            break;
        case 6:
            int id;
            cout << "Enter id: ";
            cin >> id;
            DeleteAtPosition(&head, id);
            break;
        case 7:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 7);
}
