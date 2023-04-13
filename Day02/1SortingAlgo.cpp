#include <iostream>
#include <vector>
using namespace std;

/// @brief sort the array using, Bubble Sort in ascending Order O(n^2)
/// @param arr
/// @param size
void Bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

/// @brief Sort the array using , Insertion sort in ascending order O(n^2)
/// @param arr
/// @param size
void Insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int pivot = arr[i];
        while (j >= 0 && arr[j] > pivot)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = pivot;
    }
}

/// @brief Sort the array using Selection sort in ascending order. O(n^2)
/// @param arr
/// @param size
void Selection_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

/// @brief merge the Array.
/// @param arr
/// @param left
/// @param mid
/// @param right
void merge(int arr[], int left, int mid, int right)
{
    // two temp array.

    int n1 = mid - left + 1;
    int n2 = right - mid;

    // declared the two temp array
    vector<int> L(n1);
    vector<int> R(n2);

    // copy data to temp array.
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    // Merget into the main array
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/// @brief Sort the array, using Merge sort in ascending order
/// @param arr
/// @param size
void Merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        // find the mid
        int mid = left + (right - left) / 2;

        // split the array into two halves
        Merge_sort(arr, left, mid);      // first half
        Merge_sort(arr, mid + 1, right); // second half

        // merge the array.
        merge(arr, left, mid, right);
    }
}

/// @brief Print the array.
/// @param arr
/// @param size
void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

/// @brief Driver Function.
/// @return
int main()
{
    int arr[11] = {1, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << endl
         << "Befor the sort: ";
    print_array(arr, size);
    // Bubble_sort(arr, size);
    // Insertion_sort(arr, size);
    // Selection_sort(arr, size);
    Merge_sort(arr, 0, size - 1);

    cout << endl
         << "after the sort: ";
    print_array(arr, size);
}
