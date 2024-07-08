#include<iostream>
using namespace std;

long long int combinations(int N, int max, int** memo) 
{
    if (N == 0)
        return 1;  

    long long int count = 0;

    int i = (N < max - 1) ? N : max - 1;
    for (; i > 0; --i)
    {
        if (memo[N - i][i] == -1)
            count += combinations(N - i, i, memo);

        else
            count += memo[N - i][i];
    }
    memo[N][max] = count;
    return count;
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;
    if (N < 3 || N>200) 
    {
        cout << "Invalid input. Please enter a value of N greater than or equal to 2." << endl;
        return 0;
    }
    int** memo = new int* [N+1];

    for (int i = 0; i < N+1; i++) 
    {
        memo[i] = new int[N+1];
    }

    for (int i = 0; i < N+1; i++)
    {
        for (int j = 0; j < N+1; j++)
            memo[i][j] = -1;
    }

    long long int Total_structures = combinations(N, N, memo);
    cout << "Total partitions: " << Total_structures << endl << endl;;

    //for (int i = 0; i < N+1; i++)
    //{
    //    for (int j = 0; j < N+1; j++)
    //    {
    //        if(memo[i][j] != -1)
    //            cout << i << " " << j << ": " << memo[i][j] << endl;
    //    }
    //} 

    for (int i = 0; i < N+1; i++)
    {
        delete[] memo[i];
    }
    delete[] memo;
    return 0;
}
