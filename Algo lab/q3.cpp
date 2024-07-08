#include <iostream>
#include<string>
using namespace std;

int* Input(int* array, int n)
{
    for (int i = 0; i < n; ++i)
    {
        int temp = n + 1;
        do
        {
            cout << "Enter element " << i + 1 << ": ";
            cin >> temp;
        } while (temp > n);
        array[i] = temp;
    }
    return array;
}
int* SetZero(int* array, int n)
{
    for (int i = 0; i < n; ++i)
        array[i] = 0;
    return array;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0)
        return 1;

    int* arr = new int[n];
    arr = Input(arr, n);
    int* Occurencses = new int[n + 1];
    int* DPsegments = new int[n + 1];

    Occurencses = SetZero(Occurencses, n + 1);
    DPsegments = SetZero(DPsegments, n + 1);

    for (int i = 0; i < n; ++i)
        Occurencses[arr[i]] = Occurencses[arr[i]] + 1;
   
    int MinVal = 0;
    int minIterator = 0;
    while (Occurencses[minIterator] != 0)
        minIterator++;
    MinVal = minIterator;
    cout << endl << "Minimum Value that is not present in the array: " << MinVal;

    int start = 0;
    int end = n - 1;
    int min = 0;

    string segments = "(";
    segments += to_string(start+1);
    segments += "->";

    bool direction = true;

    while (start <= end)
    {
        if (direction)
        {
            DPsegments[arr[start]]++;

            if (min == arr[start])
            {
                while (DPsegments[++min] != 0);
                cout << "\nNew Min at: " << arr[start] << " -> " << min;
            }
            if (min == MinVal)
            {
                segments += to_string(start+1);
                direction = !direction;
                DPsegments = SetZero(DPsegments, n + 1);
                min = 0;
                segments += ") -> (";
                segments += to_string(start+2);
            }
            else if (start == end-1)
            {
                cout << "\n\nNot possible -1";
                return 0;
            }
            start++;
        }
        else
        {
            DPsegments[arr[start]]++;

            if (min == arr[start])
            {
                while (DPsegments[++min] != 0);
                cout << "\nNew Min at: " << arr[start] << " -> " << min;
            }
            if (start == end)
                break;

            start++;
        }
    }
    if (min != MinVal)
    {
        cout << "\n\nNot possible -1";
        return 0;
    }

    segments += "->";
    segments += to_string(n);
    segments += ")";
    cout << "\nTotal Segments: 2" << endl;
    cout << "Segments: " << segments << endl;

    // Free dynamically allocated memory
    delete[] arr; 
    delete[] Occurencses;
    delete[] DPsegments;

    return 0;
}