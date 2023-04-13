#include <iostream>
using namespace std;

// Summary
//  Input employee details in object and display
//  delete employee no using employee id
//  display employee details using employee id
//  add employee in array using employee id

/// @brief Employee class
class Employee
{
public:
    int employeeid;
    string name;
    string address;
    string department;
    string designation;
    double salary;
    string email;
    string phone;
};

/// @brief display all the employee details
/// @param emp_arr
/// @param emp_count
void display_details(Employee emp_arr[], int &emp_count)
{
    if (emp_count == 0)
    {
        cout << "No employee details to display" << endl;
        return;
    }
    for (int i = 0; i < emp_count; i++)
    {
        cout << " ";
        cout << "Employee id: " << emp_arr[i].employeeid << endl;
        cout << "Name: " << emp_arr[i].name << endl;
        cout << "Address: " << emp_arr[i].address << endl;
        cout << "Department: " << emp_arr[i].department << endl;
        cout << "Designation: " << emp_arr[i].designation << endl;
        cout << "Salary: " << emp_arr[i].salary << endl;
        cout << "Email: " << emp_arr[i].email << endl;
        cout << "Phone: " << emp_arr[i].phone << endl;
        cout << "____________________________________________" << endl;
    }
}

/// @brief display employee details using employeeid
/// @param emp_arr
/// @param emp_count
/// @param target_employeeid
void displayEmpDetail_byId(Employee emp_arr[], int &emp_count, int target_employeeid)
{
    bool found = false;
    for (int i = 0; i < emp_count; i++)
    {
        if (emp_arr[i].employeeid == target_employeeid)
        {
            found = true;
            // details of employee to be displayed
            cout << " ";
            cout << "Employee id: " << emp_arr[i].employeeid << endl;
            cout << "Name: " << emp_arr[i].name << endl;
            cout << "Address: " << emp_arr[i].address << endl;
            cout << "Department: " << emp_arr[i].department << endl;
            cout << "Designation: " << emp_arr[i].designation << endl;
            cout << "Salary: " << emp_arr[i].salary << endl;
            cout << "Email: " << emp_arr[i].email << endl;
            cout << "Phone: " << emp_arr[i].phone << endl;
            cout << "_____________________________________________" << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "Employee not found" << endl;
    }
}

/// @brief delete employee from array using employeeid
/// @param emp_arr
/// @param emp_count
/// @param target_employeeid
void delete_employee(Employee emp_arr[], int &emp_count, int target_employeeid)
{
    bool found = false;
    for (int i = 0; i < emp_count; i++)
    {
        if (emp_arr[i].employeeid == target_employeeid)
        {
            found = true;
            for (int j = i; j < emp_count - 1; j++)
            {
                emp_arr[j] = emp_arr[j + 1];
            }
            emp_count--;
            cout << "Employee deleted successfully" << endl;
            break;
        }
    }
    if (!found)
    {
        cout << "Employee not found" << endl;
    }
}

/// @brief Adds an employee to the array
/// @param emp_arr
/// @param size
/// @param emp_count
void Add_employee(Employee emp_arr[], int size, int &emp_count)
{

    if (emp_count < size)
    {
        cout << " ";
        cout << "Enter the employee id: ";
        cin >> emp_arr[emp_count].employeeid;
        cout << "Enter the name: ";
        cin >> emp_arr[emp_count].name;
        cout << "Enter the address: ";
        cin >> emp_arr[emp_count].address;
        cout << "Enter the department: ";
        cin >> emp_arr[emp_count].department;
        cout << "Enter the designation: ";
        cin >> emp_arr[emp_count].designation;
        cout << "Enter the salary: ";
        cin >> emp_arr[emp_count].salary;
        cout << "Enter the email: ";
        cin >> emp_arr[emp_count].email;
        cout << "Enter the phone: ";
        cin >> emp_arr[emp_count].phone;
        emp_count++;
    }
    else
    {
        cout << "Array is full" << endl;
    }
}

/// @brief Sorts the employee array by employee id in ascending order
/// @param emp_arr
/// @param count
void EmployeeSort_byId(Employee emp_arr[], int &count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (emp_arr[i].employeeid > emp_arr[j].employeeid)
            {
                Employee temp = emp_arr[i];
                emp_arr[i] = emp_arr[j];
                emp_arr[j] = temp;
            }
        }
    }
    cout << "Employee details sorted successfully" << endl;
}

/// @brief sort the employee array by employee id in ascending order using insertion sort
/// @param emp_arr
/// @param count
void EmployeeSort_byIdInsertion(Employee emp_arr[], int &count)
{
    int i, j;
    Employee key;
    for (i = 1; i < count; i++)
    {
        key = emp_arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && emp_arr[j].employeeid > key.employeeid)
        {
            emp_arr[j + 1] = emp_arr[j];
            j = j - 1;
        }
        emp_arr[j + 1] = key;
    }
}

/// @brief Sorts the employee array by employee id in descending order
/// @param emp_arr
/// @param count
void EmployeeSort_byIdInDesc(Employee emp_arr[], int &count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (emp_arr[i].employeeid > emp_arr[j].employeeid)
            {
                Employee temp = emp_arr[i];
                emp_arr[i] = emp_arr[j];
                emp_arr[j] = temp;
            }
        }
    }
}

/// @brief update the employee detail by using employeeid
/// @param emp_arr
/// @param emp_count
/// @param target_employeeid
void updateEmpDetail_byId(Employee emp_arr[], int emp_count, int target_employeeid)
{

    for (int i = 0; i < emp_count; i++)
    {
        if (emp_arr[i].employeeid == target_employeeid)
        {
            displayEmpDetail_byId(emp_arr, emp_count, target_employeeid);
            cout << "Enter the new details" << endl;
            cout << "Enter a new Name ";
            cin >> emp_arr[i].name;
            cout << "Enter a new Address ";
            cin >> emp_arr[i].address;
            cout << "Enter a new Department ";
            cin >> emp_arr[i].department;
            cout << "Enter a new Designation ";
            cin >> emp_arr[i].designation;
            cout << "Enter a new Salary ";
            cin >> emp_arr[i].salary;
            cout << "Enter a new Email ";
            cin >> emp_arr[i].email;
            cout << "Enter a new Phone ";
            cin >> emp_arr[i].phone;
            cout << "Employee details updated successfully" << endl;
            break;
        }
    }
}

/// @brief driver function
/// @return
int main()
{
    // array of employee

    Employee emp_arr[10];
    int emp_count = 0;
    int choice = 0;

    do
    {
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Display All  Employee Details" << endl;
        cout << "4. Display Employee Details using employeeid" << endl;
        cout << "5. Update Employee Details using employeeid" << endl;
        cout << "6. Sort Employee Details using employeeid" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            // add employee
            Add_employee(emp_arr, 10, emp_count);
            break;
        case 2:
            // delete employee
            int target_employeeid;
            cout << "Enter the employee id to delete:";
            cin >> target_employeeid;
            delete_employee(emp_arr, emp_count, target_employeeid);
            break;
        case 3:
            // display employee details
            display_details(emp_arr, emp_count);
            break;
        case 4:
            // display employee details using employeeid
            cout << "Enter the employee id to display:";
            cin >> target_employeeid;
            displayEmpDetail_byId(emp_arr, emp_count, target_employeeid);
            break;
        case 5:
            // update employee details using employeeid
            cout << "Enter the employee id to update:";
            cin >> target_employeeid;
            updateEmpDetail_byId(emp_arr, emp_count, target_employeeid);
            break;
        case 6:
            // sort employee details using employeeid
            EmployeeSort_byId(emp_arr, emp_count);
            break;
        case 7:
            cout << "Thank you for using our application" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 7);
}
