#include <iostream>
using namespace std;

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

// doubly Linked List
struct Node
{
    Employee data;
    Node *prev;
    Node *next;

    // when the standalone Node is created.
    Node(Employee data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

void AddNode(Node **head, Node **tail, Employee data)
{
    // create a new Node
    Node *newNode = new Node(data);

    // if the list is empty
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode; // update the tail.
    }
}

bool SearchById(Node *head, int id)
{
    Node *temp = head;
    while (temp != NULL && temp->data.id != id)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void DeleteNode(Node **head, int id)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = *head;
    Node *prev = NULL;

    while (temp != NULL && temp->data.id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL)
    {
        // delete the first Node itself
        *head = temp->next;
        delete temp;
    }
    else
    {
        prev->next = temp->next;
        delete temp;
    }
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data.id << "" << temp->data.name << " " << endl;
        temp = temp->next;
    }
}

void printReverseList(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data.id << " " << temp->data.name << endl;
        temp = temp->prev;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int id;
    string name;
    int choice;
    do
    {
        cout << "1. Add Node" << endl;
        cout << "2. Search by id" << endl;
        cout << "3. Delete by id" << endl;
        cout << "4. Print List" << endl;
        cout << "5. Print Reverse List" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "Enter id: ";
            cin >> id;
            cout << "Enter name: ";
            cin >> name;
            AddNode(&head, &tail, Employee(id, name));
            break;
        case 2:
            cout << "Enter id: ";
            cin >> id;
            if (SearchById(head, id))
            {
                cout << "element is found";
            }
            else
            {
                cout << "element is Not found.";
            }
            break;
        case 3:
            cout << "Enter id: ";
            cin >> id;
            DeleteNode(&head, id);
            break;
        case 4:
            printList(head);
            break;
        case 5:
            printReverseList(tail);
            break;
        case 6:
            cout << "Thanks";
            break;
        }

    } while (choice != 6);
}