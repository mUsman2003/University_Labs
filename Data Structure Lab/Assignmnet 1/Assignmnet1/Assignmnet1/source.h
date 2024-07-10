
#include<iostream>
using namespace std;

void CountSort(int* arr, int* p, float* ProfitRatio, int size) 
{
	float maxProfitRatio = ProfitRatio[0];
	for (int i = 1; i < size; i++) {
		if (ProfitRatio[i] > maxProfitRatio) {
			maxProfitRatio = ProfitRatio[i];
		}
	}
	float minProfitRatio = ProfitRatio[0];
	for (int i = 1; i < size; i++) {
		if (ProfitRatio[i] < minProfitRatio) {
			minProfitRatio = ProfitRatio[i];
		}
	}
	int range = static_cast<int>(maxProfitRatio - minProfitRatio) + 1;
	// Create count and output arrays
	int* count = new int[range] {0};
	int* outputArr = new int[size];
	int* outputP = new int[size];
	float* outputProfitRatio = new float[size];

	// Count the occurrences of each ProfitRatio value
	for (int i = 0; i < size; i++) {
		int index = static_cast<int>(ProfitRatio[i] - minProfitRatio);
		count[index]++;
	}

	// Calculate the cumulative count
	for (int i = 1; i < range; i++) {
		count[i] += count[i - 1];
	}

	// Populate the output arrays in sorted order
	for (int i = size - 1; i >= 0; i--) {
		int index = static_cast<int>(ProfitRatio[i] - minProfitRatio);
		outputArr[count[index] - 1] = arr[i];
		outputP[count[index] - 1] = p[i];
		outputProfitRatio[count[index] - 1] = ProfitRatio[i];
		count[index]--;
	}

	// Copy the sorted values back to the original arrays
	for (int i = 0; i < size; i++) {
		arr[i] = outputArr[i];
		p[i] = outputP[i];
		ProfitRatio[i] = outputProfitRatio[i];
	}

	// Clean up dynamically allocated memory
	delete[] count;
	delete[] outputArr;
	delete[] outputP;
	delete[] outputProfitRatio;
}
void CountSort(int* arr, int n) {
	int maxVal = arr[0];
	int minVal = arr[0];

	for (int i = 1; i < n; i++) {
		if (arr[i] > maxVal) {
			maxVal = arr[i];
		}
		if (arr[i] < minVal) {
			minVal = arr[i];
		}
	}

	// Determine the range based on the maximum and minimum values
	int range = maxVal - minVal + 1;
	int* count = new int[range];
	for (int i = 0; i < range; i++)
		count[i] = 0;
	int* output = new int[n];

	// Count the occurrences of each element in the input array
	for (int i = 0; i < n; i++) {
		count[arr[i] - minVal]++;
	}

	// Modify the count array to store the cumulative count
	for (int i = 1; i < range; i++) {
		count[i] += count[i - 1];
	}

	// Build the output array by placing elements in their correct positions
	for (int i = n - 1; i >= 0; i--) {
		output[count[arr[i] - minVal] - 1] = arr[i];
		count[arr[i] - minVal]--;
	}

	// Copy the sorted elements back to the original array
	for (int i = 0; i < n; i++) {
		arr[i] = output[i];
	}
}
void removeDuplicates(int* arr, int& n) {
	if (n <= 1) {
		return; 
	}

	int newSize = 1;

	for (int i = 1; i < n; i++) 
	{
		bool isDuplicate = false;
		for (int j = 0; j < newSize; j++) 
		{
			if (arr[i] == arr[j]) 
			{
				isDuplicate = true;
				break;
			}
		}
		if (!isDuplicate) 
		{
			arr[newSize] = arr[i];
			newSize++;
		}
	}

	n = newSize; // Update the size of the array
}

template <typename T>
class ArrayBasics
{
public:
	ArrayBasics()
	{
	}
	static T findMax(T* arr, int i, int j)
	{
		T max = arr[i];
		for (int n = i; n < j; n++)
			if (max < arr[n])
				max = arr[n];
		return max;
	}
	static T findMaxPos(T* arr, int i, int j) 
	{
		T max = arr[i];
		T position = 0;
		for (int n = i; n <= j; n++)
			if (max < arr[n])
			{
				max = arr[n];
				position = n;
			}
		return position;
	}
	static T findMin(T* arr, int i, int j)
	{
		T min = arr[i];
		for (int n = i; n < j; n++)
			if (min > arr[n])
				min = arr[n];
		return min;
	}
	static T findMinPos(T* arr, int i, int j)
	{
		T min = arr[i];
		int position = 0;
		for (int n = i; n <= j; n++)
			if (min > arr[n])
			{
				min = arr[n];
				position = n;
			}
		return position;
	}
	static void swap(T* arr, int i, int j)
	{
		T temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	static T* createRandomArray(int size, int min, int max) 
	{
		T* arr = new T[size];
		for (int n = 0; n < size; n++)
			arr[n] = min + rand() % (max - min);
		return arr;
	}
	static T** createRandomMatrix(int rows, int cols, int min, int max)
	{
		T** arr = new int* [rows];
		for (int n = 0; n < rows; n++)
		{
			arr[n] = new T[cols];
			for(int m=0;m<cols;m++)
				arr[n][m] = min + rand() % (max - min);
		}
		return arr;	
	}
	static T* copyArray(T* arr, int size)
	{
		T* newArr = new T[size];
		for (int n = 0; n < size; n++)
			newArr[n] = arr[n];
		return newArr;
	}
	static T** copyMatrix(T** arr, int rows, int cols)
	{
		T** newArr = new T* [rows];
		for (int n = 0; n < rows; n++)
		{
			newArr[n] = new T[cols];
			for (int m = 0; m < cols; m++)
				newArr[n][m] = arr[n][m];
		}
		return newArr;
	}
	static T findInArray(T* arr, T q, int size)
	{
		for (int n = 0; n < size; n++)
			if (arr[n] == q)
				return n;
		return - 1;
	}
	static T findInSortedArray(T* arr, T q, int size)
	{
		for (int n = 0; n < size-1; n++)
		{
			for (int m = 0; m < size - n - 1; m++)
			{
				if (arr[m] > arr[m+1])
				{
					T temp = arr[m];
					arr[m] = arr[m+1];
					arr[m+1] = temp;
				}
			}
		}
		for (int n = 0; n < size; n++)
		{
			if (arr[n] == q)
				return n;
		}
		return -1;
	}
	static T findFirstInSortedArray(T* arr, T q, int size)
	{
		for (int n = 0; n < size - 1; n++)
		{
			for (int m = 0; m < size - n - 1; m++)
			{
				if (arr[m] > arr[m + 1])
				{
					T temp = arr[m];
					arr[m] = arr[m + 1];
					arr[m + 1] = temp;
				}
			}
		}
		for (int n = 0; n < size; n++)
		{
			if (arr[n] == q)
				return n;
		}
		return -1;
	}	
	static void shiftRight(T* A, int i, int j)
	{
		for (int n = j; n > i; n--)
			A[n] = A[n - 1];
	}
	static void shiftLeft(T* A, int i, int j)
	{
		for (int n = i; n < j; n++)
			A[n] = A[n + 1];
	}
};

template <typename T>
class ArrayUtility
{
public:
	ArrayUtility()
	{
	}
	static void maxSortWithShiftRight(T* arr, int size)
	{
		for (int n = 0; n < size - 1; n++)
		{
			for (int m = 0; m < size - n - 1; m++)
			{
				if (arr[m] < arr[m + 1])
				{
					T temp = arr[m];
					arr[m] = arr[m + 1];
					arr[m + 1] = temp;
				}
			}
		}
	}
	static void maxSortWithSwap(T* arr, int size)
	{
		for (int n = 0; n < size - 1; n++)
		{
			for (int m = 0; m < size - n - 1; m++)
			{
				if (arr[m] < arr[m + 1])
				{
					T temp = arr[m];
					arr[m] = arr[m + 1];
					arr[m + 1] = temp;
				}
			}
		}
	}
};

template <typename T>
class WarehouseAlgorithm
{
public:
	WarehouseAlgorithm()
	{

	}
	static bool hasClosePair(T* arr,int size,int r)
	{			
		CountSort(arr, size);		
		int n = 0;
		int m = size - 1;

		while (n < m && n!=m )
		{
			int sum = arr[n] + arr[m];
			if (sum == r && (n - m) < size / 10.0)
				return true;
			else if (sum < r)
				n++;
			else
				m--;
		}
		return false;
	}
};

template <typename T>
T maximizeProfit(int m, int size, T arr[], T p[], int s)
{
	T maxProfit = 0;
	int sum = 0;
	int rent=s;

	for (int n = 0; n < size; n++)
		sum += arr[n];
	
	if (sum < m)	//secound case
	{
		for (int n = 0; n < size; n++)
			maxProfit +=  p[n];
		rent = m - sum;
		maxProfit = maxProfit - s * rent;
	}
	else if(sum > m)
	{
		int newSum = 0; 
		int index = 0;
		float* ProfitRatio = new float[size];
		for (int n = 0; n < size; n++)
			ProfitRatio[n] = (p[n]) / (arr[n]);
		CountSort(arr, p, ProfitRatio, size);

		while (newSum<m)
		{
			newSum += arr[index];
			index++;
		}
		for (int n = 0; n < index; n++)
			maxProfit += p[n];
		for (int n = 0; n < m - sum; n++)
			maxProfit -= s;
	}
	return maxProfit;
}

template <typename T>
void mergeBookingSchedules(T R1[][2], int n1, T R2[][2], int n2, T mergedSchedule[][3], int& m)
{
	int size=2*(n1+n2);
	//cout << size;
	int* arr = new int[size];
	int index = 0;
	for (int n = 0; n < n1 ; n++)
	{
		arr[index] = R1[n][0];
		index++;
		arr[index] = R1[n][1];
		index++;
	}
	for (int n = 0; n < n2 ; n++)
	{
		arr[index] = R2[n][0];
		index++;
		arr[index] = R2[n][1];
		index++;
	}

	CountSort(arr, size);
	removeDuplicates(arr, size);


	int start = arr[0];
	int end = arr[1];
	int max = arr[size - 1];
	int newSize = 0;
	m = 0;
	while (start!=max)
	{
		int k = 0;
		for (int n = 0; n < n1; n++)
		{
			if ((start <= R1[n][0] && end > R1[n][0]) || (start < R1[n][1] && end >= R1[n][1]) || (start<R1[n][0] && end>R1[n][1]) || (start >= R1[n][0] && end <= R1[n][1]))
			{
				k++;
			}
		}
		for (int n = 0; n < n2; n++)
		{
			if ((start <= R2[n][0] && end > R2[n][0]) || (start < R2[n][1] && end >= R2[n][1]) || (start<R2[n][0] && end>R2[n][1]) || (start >= R2[n][0] && end <= R2[n][1]))
			{
				k++;
			}
		}
		if (k > 0)
		{
			mergedSchedule[m][0] = k;
			mergedSchedule[m][1] = start;
			mergedSchedule[m][2] = end;
			m++;

			newSize++;
			start = arr[newSize];
			end = arr[newSize + 1];
		}
		if(k==0)
		{
			start = arr[newSize];
			end = arr[newSize + 1];
			newSize++;
		}

	}
}

template <typename T>
void makeBookingSchedules(T R1[][2], int n1, T Schedule[][3], int &m)
{
	int size = 2 * n1;
	//cout << size;
	int* arr = new int[size];
	int index = 0;
	for (int n = 0; n < n1; n++)
	{
		arr[index] = R1[n][0];
		index++;
		arr[index] = R1[n][1];
		index++;
	}

	CountSort(arr, size);
	removeDuplicates(arr, size);


	int start = arr[0];
	int end = arr[1];
	int max = arr[size - 1];
	int newSize = 0;
	m = 0;
	while (start != max)
	{
		int k = 0;
		for (int n = 0; n < n1; n++)
		{
			if ((start <= R1[n][0] && end > R1[n][0]) || (start < R1[n][1] && end >= R1[n][1]) || (start<R1[n][0] && end>R1[n][1]) || (start >= R1[n][0] && end <= R1[n][1]))
			{
				k++;
			}
		}
		if (k > 0)
		{
			Schedule[m][0] = k;
			Schedule[m][1] = start;
			Schedule[m][2] = end;
			m++;

			newSize++;
			start = arr[newSize];
			end = arr[newSize + 1];
		}
		if (k == 0)
		{
			start = arr[newSize];
			end = arr[newSize + 1];
			newSize++;
		}

	}
}
