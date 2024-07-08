#include<iostream>
using namespace std;

//long long int combinations(int N, int max, int** memo) 
//{
//    if (N == 0)
//        return 1;  
//
//    long long int count = 0;
//
//    int i = (N < max - 1) ? N : max - 1;
//    for (; i > 0; --i)
//    {
//        if (memo[N - i][i] == -1)
//            count += combinations(N - i, i, memo);
//
//        else
//            count += memo[N - i][i];
//    }
//    memo[N][max] = count;
//    return count;
//}
//
//int main() {
//    int N;
//    cout << "Enter N: ";
//    cin >> N;
//    if (N < 3 || N>200) 
//    {
//        cout << "Invalid input. Please enter a value of N greater than or equal to 2." << endl;
//        return 0;
//    }
//    int** memo = new int* [N+1];
//
//    for (int i = 0; i < N+1; i++) 
//    {
//        memo[i] = new int[N+1];
//    }
//
//    for (int i = 0; i < N+1; i++)
//    {
//        for (int j = 0; j < N+1; j++)
//            memo[i][j] = -1;
//    }
//
//    long long int Total_structures = combinations(N, N, memo);
//    cout << "Total partitions: " << Total_structures << endl << endl;;
//
//    //for (int i = 0; i < N+1; i++)
//    //{
//    //    for (int j = 0; j < N+1; j++)
//    //    {
//    //        if(memo[i][j] != -1)
//    //            cout << i << " " << j << ": " << memo[i][j] << endl;
//    //    }
//    //} 
//
//    for (int i = 0; i < N+1; i++)
//    {
//        delete[] memo[i];
//    }
//    delete[] memo;
//    return 0;
//}


int strategicValue(int attacks, int svr, int Depots, int* railway)
{
	int sum = 0;
	for (int i = 0; i < Depots; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = j + 1; k < i; k++)
				sum += railway[j] * railway[k];
		}
		for (int j = i; j < Depots; j++)
		{
			for (int k = j + 1; k < Depots; k++)
				sum += railway[j] * railway[k];
		}
		if (sum < svr)
		{
			svr = sum;
		}
		sum = 0;
	}
	return svr;
}


int main()
{
	int attacks;
	int depots;
	int svr = 0; //strategic value of railway
	cout << "Enter No of Depots: ";
	cin >> depots;
	cout << "Enter No of Attacks: ";
	cin >> attacks;

	int* railway = new int[depots];
	cout << "Enter Depots Values:" << endl;
	for (int i = 0; i < depots; i++)
	{
		cin >> railway[i];
	}

	//int* a_index = new int[attacks];
	//for (int i = 0; i < 1; i++)
	//{
	//	a_index[i] = 0;
	//}

	for (int i = 0; i < depots; i++)
	{
		for (int j = i + 1; j < depots; j++)
		{
			svr += railway[i] * railway[j];
		}
	}
	cout << svr << endl;
	cout << "Smallest Strategic Value for the railroad: " << strategicValue(attacks, svr, depots, railway) << endl;

	delete[] railway;
}
