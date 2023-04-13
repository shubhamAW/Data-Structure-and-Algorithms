#include <iostream>
using namespace std;

/// @brief Linear Search by sequentially.
/// @param arr
/// @param size
/// @param target
/// @return return index of target element, if not present return -1.
int Linear_search(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

/// @brief Binary Search required ordered List. O(logn)
/// @param arr
/// @param start
/// @param end
/// @param target
/// @return return the index of target element, if not present return -1.
int Binary_search(int arr[], int start, int end, int target)
{

    if (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] > target)
        {
            // find it in lower half
            return Binary_search(arr, start, mid - 1, target);
        }

        return Binary_search(arr, mid + 1, end, target);
    }
    else
    {
        return -1;
    }
}

/// @brief Driver Program.
/// @return
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter a Target element: ";
    cin >> target;

    // Linear Search..
    // int index = Linear_search(arr, size, target);
    int index = Binary_search(arr, 0, size - 1, target);
    if (index == -1)
    {
        cout << "Element is not found" << endl;
    }
    else
    {
        cout << "Element present at index : " << index << endl;
    }
}