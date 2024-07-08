#include <iostream>

using namespace std;

int** Input(int** arr, int rows, int cols)
{
    // Input elements of the array
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
    return arr;
}

void Display(int** arr, int rows, int cols)
{
    // Output the elements of the array
    cout << "The 2D array you entered is:" << endl;
    for (int i = 0; i < rows; ++i) {
        cout << "\t";
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void MaxFinder(int** arr, int rowrunner, int colrunner, int* Max1C, int* Max2C, int* Max1C_Index, int* Max2C_Index)
{
    if (arr[rowrunner][colrunner] > Max1C[colrunner])
    {
        Max2C[colrunner] = Max1C[colrunner];
        Max2C_Index[colrunner] = Max1C_Index[colrunner];

        Max1C[colrunner] = arr[rowrunner][colrunner];
        Max1C_Index[colrunner] = rowrunner;
    }
    else if (arr[rowrunner][colrunner] > Max2C[colrunner])
    {
        Max2C[colrunner] = arr[rowrunner][colrunner];
        Max2C_Index[colrunner] = rowrunner;
    }
}

int main()
{
    int rows, cols;

    int CurrentMaxPower = 0;
    int CurrentMinPower = 0;

    // Input the number of rows and columns from the user
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Dynamically allocate memory for the 2D array
    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i)
        arr[i] = new int[cols];

    // Dynamically allocate memory for storing MaxValues and their indices

    int* DP_1st_MaxValues = new int[cols];
    int* DP_2nd_MaxValues = new int[cols];
    int* DP_1st_MaxValues_Index = new int[cols];
    int* DP_2nd_MaxValues_Index = new int[cols];

    int* DP_ValuesSelected = new int[cols];
    int* DP_ValuesSelected_Index = new int[cols];

    int* DP_NonSelected = new int[cols];
    int* DP_MinValues_Index = new int[cols];

    arr = Input(arr, rows, cols);
    Display(arr, rows, cols);

    if (rows == 1)
    {
        int temp = 0;
        for (int n = 0; n < cols; n++)
        {
            if (temp < arr[0][n])
                temp = arr[0][n];

        }
        cout << "Max Power: " << temp << endl;
        return 1;
    }

    int colrunner = 0;
    while (colrunner < cols)
    {
        int rowrunner = 0;
        while (rowrunner < rows)
        {
            MaxFinder(arr, rowrunner, colrunner, DP_1st_MaxValues, DP_2nd_MaxValues, DP_1st_MaxValues_Index, DP_2nd_MaxValues_Index);
            rowrunner++;
        }
        //cout << "1st Max: " << DP_1st_MaxValues[colrunner] << " at index: " << DP_1st_MaxValues_Index[colrunner] << "\t2nd Max: " << DP_2nd_MaxValues[colrunner] << " at index: " << DP_2nd_MaxValues_Index[colrunner] << endl;
        colrunner++;
    }

    int c = 0;
    while (c < cols)
    {
        if (c == 0)
        {
            CurrentMaxPower += DP_1st_MaxValues[c];
            CurrentMinPower += DP_2nd_MaxValues[c];

            DP_ValuesSelected[c] = DP_1st_MaxValues[c];
            DP_ValuesSelected_Index[c] = DP_1st_MaxValues_Index[c];

            DP_NonSelected[c] = DP_2nd_MaxValues[c];
            DP_MinValues_Index[c] = DP_2nd_MaxValues_Index[c];

        }
        else if (c >= 0)
        {
            if (DP_ValuesSelected_Index[c - 1] == DP_1st_MaxValues_Index[c])
            {
                cout << "\nMatched the previous Max!\n";

                if (c - 2 >= 0 && DP_ValuesSelected_Index[c - 2] == DP_MinValues_Index[c - 1])
                {
                    cout << "\nAfter change the value will be same at col: "<<c;
                    if ((DP_1st_MaxValues[c - 2] + DP_1st_MaxValues[c]) > (CurrentMaxPower + DP_2nd_MaxValues[c]))
                    {
                        cout << "\nChange Values";
                        CurrentMaxPower -= DP_ValuesSelected[c - 1];
                        CurrentMaxPower -= DP_ValuesSelected[c - 2];
                        CurrentMaxPower += DP_1st_MaxValues[c - 2];
                        CurrentMaxPower += DP_1st_MaxValues[c ];

                        DP_ValuesSelected[c] = DP_1st_MaxValues[c];
                        DP_ValuesSelected_Index[c] = DP_1st_MaxValues_Index[c];
                        DP_NonSelected[c] = DP_2nd_MaxValues[c];
                        DP_MinValues_Index[c] = DP_2nd_MaxValues_Index[c];
                    }
                    else if (CurrentMaxPower + DP_2nd_MaxValues[c] > CurrentMinPower + DP_1st_MaxValues[c])
                    {
                        cout << "\nCurrent Max: "<<CurrentMaxPower;
                        CurrentMaxPower += DP_2nd_MaxValues[c];
                        DP_ValuesSelected[c]= DP_2nd_MaxValues[c];
                        DP_ValuesSelected_Index[c] = DP_2nd_MaxValues_Index[c];
                        CurrentMinPower += DP_1st_MaxValues[c];
                        DP_NonSelected[c] = DP_1st_MaxValues[c];
                        DP_MinValues_Index[c] = DP_1st_MaxValues_Index[c];
                        cout << "\nUpdated Max: "<<CurrentMaxPower;
                    }
                }
                else if (DP_1st_MaxValues[c] + DP_NonSelected[c - 1] < DP_ValuesSelected[c - 1] + DP_2nd_MaxValues[c])
                {
                    cout << "\nMin Power will be selected at col: " << c;
                    CurrentMaxPower += DP_2nd_MaxValues[c];
                    CurrentMinPower += DP_1st_MaxValues[c];

                    DP_ValuesSelected[c] = DP_2nd_MaxValues[c];
                    DP_ValuesSelected_Index[c] = DP_2nd_MaxValues_Index[c];

                    DP_NonSelected[c] = DP_1st_MaxValues[c];
                    DP_MinValues_Index[c] = DP_1st_MaxValues_Index[c];

                }
                else
                {
                    CurrentMaxPower -= DP_1st_MaxValues[c - 1];
                    CurrentMaxPower += DP_2nd_MaxValues[c - 1];
                    CurrentMaxPower += DP_1st_MaxValues[c];

                    CurrentMinPower -= DP_2nd_MaxValues[c - 1];
                    CurrentMinPower += DP_1st_MaxValues[c - 1];
                    CurrentMinPower += DP_2nd_MaxValues[c];

                    DP_ValuesSelected[c] = DP_1st_MaxValues[c];
                    DP_ValuesSelected_Index[c] = DP_1st_MaxValues_Index[c];

                    DP_NonSelected[c] = DP_2nd_MaxValues[c];
                    DP_MinValues_Index[c] = DP_2nd_MaxValues_Index[c];
                }
            }
            else
            {

                CurrentMaxPower += DP_1st_MaxValues[c];
                CurrentMinPower += DP_2nd_MaxValues[c];


                DP_ValuesSelected[c] = DP_1st_MaxValues[c];
                DP_ValuesSelected_Index[c] = DP_1st_MaxValues_Index[c];
                DP_NonSelected[c] = DP_2nd_MaxValues[c];
                DP_MinValues_Index[c] = DP_2nd_MaxValues_Index[c];
                
                cout << "\nValue Selected: " << DP_ValuesSelected[c] << " at index: " << DP_ValuesSelected_Index[c];
            }
        }

        c++;
    }
    cout << "\nMax Values Array:";
    for (int n = 0; n < cols; n++)
        cout << " " << DP_ValuesSelected[n];

    cout << "\nMin Values Array:";
    for (int n = 0; n < cols; n++)
        cout << " " << DP_NonSelected[n];
   
    cout << "\n\nMaximum Power: " << CurrentMaxPower << endl;

    // Deallocate memory for arr
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    // Deallocate memory for DP_1st_MaxValues, DP_2nd_MaxValues, DP_1st_MaxValues_Index, and DP_2nd_MaxValues_Index
    delete[] DP_1st_MaxValues;
    delete[] DP_2nd_MaxValues;
    delete[] DP_1st_MaxValues_Index;
    delete[] DP_2nd_MaxValues_Index;

    return 0;
}