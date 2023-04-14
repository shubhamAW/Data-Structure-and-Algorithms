#include <iostream>
using namespace std;

// add employee data into a linkedlist

/// @brief Employee class
class Employee
{
public:
    int id;
    string name;
    // default constructor
    Employee()
    {
        this->id = 0;
        this->name = " ";
    }
    // parameterized constructor
    Employee(int id, string name)
    {
        this->id = id;
        this->name = name;
    }
    void print()
    {
        cout << "ID: " << id << " Name: " << name << endl;
    }
};

/// @brief Node class
class Node
{
public:
    Employee data;
    Node *next;
    Node(Employee data)
    {
        this->data = data;
        this->next = NULL;
    }
};

/// @brief Add Employee.
/// @param head
/// @param data
void AddEmployee(Node *head, Employee data)
{
    // if head is NULL
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

/// @brief Search Employee
/// @param head
/// @param id
/// @return
Employee SearchEmployee(Node *head, int id)
{
    // if head is NULL
    if (head == NULL)
    {
        return Employee();
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data.id == id)
        {
            return temp->data;
        }
        temp = temp->next;
    }
    return Employee();
}

void PrintEmployee(Node *head)
{
    // if head is NULL
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data.id << " " << temp->data.name << endl;
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    int choice;
    int id;
    string name;
    Employee emp;
    do
    {
        cout << "1. Add Employee" << endl;
        cout << "2. Search Employee" << endl;
        cout << "3. Print Employee" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            // add employee
            cout << "Enter id: ";
            cin >> id;
            cout << "Enter name: ";
            cin >> name;
            AddEmployee(head, Employee(id, name));
            break;
        case 2:
            // search employee
            emp = SearchEmployee(head, 2);
            if (emp.id != 0)
                emp.print();
            else
                cout << "Employee not found" << endl;
            break;
        case 3:
            // print employees
            PrintEmployee(head);
            break;
        case 4:
            // exit
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 4);
}

// problems : 1. add employee is not working.
//  2. search employee is not working.
//  3. print employee is not working.
// updated on 13/04/2023