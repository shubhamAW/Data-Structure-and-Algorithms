#include <iostream>
#include <vector>
using namespace std;

class Task
{
public:
    int start;
    int end;
    Task(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

int main()
{
    Task arr[] = {Task(0, 4), Task(1, 2), Task(2, 4), Task(3, 5), Task(3, 6), Task(5, 6), Task(5, 7), Task(6, 7), Task(7, 9), Task(8, 10)};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sort by the end time of Task using Bubble sort..
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j].end < arr[i].end)
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    int count = 1;
    int prev = 0;

    vector<Task> choosen;
    choosen.push_back(arr[0]);
    int k = 1;

    for (int i = 1; i < size; i++)
    {
        if (arr[i].start >= arr[prev].end)
        {
            count++;
            prev = i;
            choosen.push_back(arr[i]);
        }
    }

    // choosen Tasks

    for (int i = 0; i < choosen.size(); i++)
    {
        cout << choosen[i].start << " " << choosen[i].end << endl;
    }

    cout << "Total Tasks:" << count << endl;
}