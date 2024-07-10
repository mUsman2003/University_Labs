#include<iostream>
using namespace std;

struct StudentRecord
{
	int studentID; 
	string name;
	float GPA;
};
void insertionSortStudents(StudentRecord* arr, int size)
{
	int index = 0;
	int n = 0, m=0;
	for (n = 0; n < size; n++)
	{
		StudentRecord temp = arr[n];
		for (m = n; m > 0 && temp.GPA < arr[m - 1].GPA; m--)
		{
			arr[m] = arr[m - 1];
		}
		arr[m] = temp;
	}

	for (int n = 0; n < size; n++)
	{
		cout << arr[n].name << "	" << arr[n].GPA << "	" << arr[n].studentID << endl;
	}
	
}

//---------------------------------Q2------------------------------//
struct EmployeeRecord
{
	int employID;
	string name;
	float salary;
};
void iterativeQuickSortEmployees(EmployeeRecord* arr, int size)
{
	int pivot = size - 1;
	for (int n = 0; n < size; n++)
	{
		while (arr[pivot].salary < arr[n].salary)
		{
			if (arr[n].salary > arr[n + 1].salary && arr[n].salary<arr[pivot].salary)
			{
				EmployeeRecord temp = arr[n];
				arr[n] = arr[n + 1];
				arr[n + 1] = temp;
				break;
			}
		}
	}
	for(int n=0;n<size;n++)
		cout << arr[n].name << "	" << arr[n].salary << "	" << arr[n].employID << endl;

}


//---------------------------------Q3------------------------------//
void bubbleSort(int* arr, int size)
{
	for (int n = 0; n < size - 1; n++)
	{
		for (int m = 0; m < size - n - 1; m++)
		{
			if (arr[m] > arr[m + 1])
			{
				int temp = arr[m];
				arr[m] = arr[m + 1];
				arr[m + 1] = temp;
			}
		}
	}
	for (int n = 0; n < size; n++)
		cout << arr[n] << " ";
}
int binarySearch(int* arr, int size,int ID)
{
	int firstterm = 0;
	int lastterm = size;
	int mid = 0;
	bool found=false;
    int index = 0;
	while (!found && index<=size)
	{
	    mid = (firstterm + lastterm)/2;
		if (arr[mid] == ID)
			found = true;
		else if (arr[mid] > ID)
		    lastterm = mid - 1;
		else if (arr[mid] < ID)
			firstterm = mid + 1;
        index++;
		//cout << arr[mid] << " ";
    }
	if (found == false)
		ID = -1;
	return ID;

}