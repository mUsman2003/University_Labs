#include<iostream>
using namespace std;
//--------------------Q1-------------------------//
template <typename T, int N>
T DotProduct(T (&a)[N], T (&b)[N])
{
	T result = 0;
	for (int n = 0; n < N; n++)
		result += a[n] * b[n];
	return result;
}
template <typename T >
//--------------------Q2-------------------------//
T findNthModifiedFibonacci(T a)
{
	T n1 = 0;
	T n2 = 1;
	T n3 = 1;
	if (a == 0)
		return 0;
	if (a == 1)
		return 1;
	if (a == 2)
		return 1;
	if (a >= 3)
	{
		for (int n = 0; n <= a-3; n++)
		{
			T result = n1 + n2 + n3;
			n1 = n2;
			n2 = n3;
			n3 = result;
		}
	}
	return n3;
}
//--------------------Q3-------------------------//
template <typename T,int N,int M>
void spiralOrderTraversal(T (&arr)[N][M], T* final)
{


	int index = 0;
	int resultIndex = 0;
	int directionChecker = 1;

	int loopCounterRowTop = 0;
	int loopCounterRowBottom = N-1;

	int loopCounterColumnRight = M-1;
	int loopCounterColumnLeft = 0;
	
	for (int n = 0; n < N; n++)
		for (int m = 0; m < N; m++)
			index++;

	int jump = N;
	int jumpcounter = 1;

	for (int n = 0; n < 2 * (N - 1) + 1; n++)
	{
		if (directionChecker == 1)
		{
			for (int m = loopCounterColumnLeft; m <= loopCounterColumnRight; m++)
				final[resultIndex++] = arr[loopCounterRowTop][m];
			loopCounterRowTop++;
		}
		else if (directionChecker == 2)
		{
			for (int m = loopCounterRowTop; m <= loopCounterRowBottom; m++)
				final[resultIndex++] = arr[m][loopCounterColumnRight];
			loopCounterColumnRight--;
		}
		else if (directionChecker == 3)
		{
			for (int m = loopCounterColumnRight; m >= loopCounterColumnLeft; m--)
				final[resultIndex++] = arr[loopCounterRowBottom][m];
			loopCounterRowBottom--;
		}
		else if (directionChecker == 4)
		{
			for (int m = loopCounterRowBottom; m >= loopCounterRowTop; m--)
				final[resultIndex++] = arr[m][loopCounterColumnLeft];
			loopCounterColumnLeft++;
		}
		jumpcounter++;
		if (jumpcounter == 2)
		{
			jumpcounter = 0;
			jump--;
		}

		directionChecker = (directionChecker % 4) + 1;
	}

}
//--------------------Q4-------------------------//
template <typename T>
class OnlineBank
{
	T currentBalance;
	T* withdrawals;
	T* deposite;
	int  numOftransactions;
	int counterWithDrawal;
	int counterDeposite;
public:
	OnlineBank(T c, T t)
	{
		currentBalance = c;
		numOftransactions = t;
		counterWithDrawal = 0;
	}
	bool isWithdrawal()
	{
		if (counterWithDrawal < numOftransactions)
			return true;
		else 
			return false;
	}
	bool isDeposit()
	{
		if (counterDeposite < numOftransactions)
			return true;
		else
			return false;
	}
	T getCurrentBalance()
	{
		return currentBalance;
	}
	void makeDeposit(T a)
	{
		currentBalance += a;
	}
	bool makeWithdrawal(T a)
	{
		if (a <= currentBalance && counterWithDrawal<=numOftransactions)
		{
			currentBalance -= a;
			numOftransactions++;
			return true;
		}
		else
			return false;
	}
	void Print()
	{
		cout << "Current Balance : " << currentBalance << endl;
		cout << "Number of Transactions : " << numOftransactions << endl;

	}

};


/*

for (int n = 0; n < 2*(N - 1) + 1; n++)
{

	if (directionChecker == 4)
	{
		if (jumpcounter == 2)
		{
			jumpcounter = 0;
			jump--;
			for (int m = 0; m < jump; m++)
				result[resultIndex++] = arr[loopCounterRowBottom-1-m][loopCounterColumnLeft];
			loopCounterColumnLeft++;
			jumpcounter++;
			directionChecker = 1;
		}
		if (jumpcounter < 2)
		{
			for (int m = 0; m < jump; m++)
				result[resultIndex++] = arr[loopCounterColumnLeft][loopCounterRowBottom - 1 - m];
			loopCounterColumnLeft++;
			jumpcounter++;
			directionChecker = 1;
		}
	}
	else if (directionChecker == 3)
	{
		if (jumpcounter < 2)
		{
			for (int m = 0; m < jump; m++)
				result[resultIndex++] = arr[loopCounterRowBottom - 1][loopCounterColumnRight - 1 - m];
			loopCounterRowBottom--;
			jumpcounter++;
			directionChecker++;
		}
		if (jumpcounter == 2)
		{
			jump--;
			jumpcounter = 0;
			for (int m = 0; m < jump; m++)
				result[resultIndex++] = arr[loopCounterRowBottom - 1][loopCounterColumnRight - 1 - m];
			loopCounterRowBottom--;
			jumpcounter++;
			directionChecker++;
		}
	}
	else if (directionChecker == 2)
	{
		if (jumpcounter == 2)
		{
			jumpcounter = 0;
			jump--;
			for (int m = 0; m < jump; m++)
				result[resultIndex++] = arr[loopCounterRowTop + m][loopCounterColumnRight - 1];
			loopCounterColumnRight--;
			jumpcounter++;
			directionChecker++;
		}
		if (jumpcounter < 2)
		{
			for (int m = 0; m < jump; m++)
				result[resultIndex++] = arr[loopCounterColumnRight - 1][loopCounterRowTop + m];
			loopCounterColumnRight--;
			jumpcounter++;
			directionChecker++;
		}
	}
	else if (directionChecker == 1)
	{
		if (jump == N)
		{
			jumpcounter++;
			for (int m = 0; m < N; m++)
				result[resultIndex++] = arr[loopCounterRowTop][m];
			loopCounterRowTop++;
			directionChecker++;
		}
		else if (jump < N)
		{
			if (jumpcounter < 2)
			{
				for (int m = 0; m < jump; m++)
					result[resultIndex++] = arr[loopCounterRowTop][loopCounterColumnLeft + m];
				loopCounterRowTop++;
				directionChecker++;
				jumpcounter++;
			}
			if (jumpcounter == 2)
			{
				jump--;
				jumpcounter = 0;
				for (int m = 0; m < jump; m++)
					result[resultIndex++] = arr[loopCounterRowTop][loopCounterColumnLeft + m];
				loopCounterRowTop++;
				directionChecker++;
				jumpcounter++;

			}
		}

	}
}
*/