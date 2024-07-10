#include<iostream>
using namespace std;
//-----------------Q1---------------------//
int Count(int *a, int b,int *c, int d)
{
	int counter = 0;
	for (int n = 0; n < b; n++)
	{
		for (int m = 0; m < d ; m++)
		{
			if (a[n] == c[m])
			{
				counter++;
				break;
			}
		}
	}
	return counter;
}
int* Intersection(int* a, int* b, int c,int d)
{
	int* temp = new int[2];
	int Value=0;
	for (int n = 0; n < c ; n++)
	{
		for (int m = 0; m < d; m++)
		{
			if (a[n] == b[m])
			{
				temp[Value]=a[n];
				Value++;
			}
		}
	}
	return temp;
}
//-----------------Q2---------------------//
bool Permutor(int a)
{
	int check = false;
	for (int n = 1; n <= 10; n++)
	{
		if (sqrt(a) == n)
			check = true;
	}
	return check;
}

int main()
{
//-----------------Q1---------------------//
	int Num1[5] = { 2,1,3,1,3 };
	int Num2[2] = { 2,3 };
	int TotalSize = 0;
	TotalSize = Count(Num1, 5, Num2, 2);
	cout << "Size : " << TotalSize << endl;
	int* Intersect;
	Intersect = Intersection(Num1, Num2, 5, 2);
	cout << "Intersection : ";

	for (int n = 0; n < TotalSize; n++)
		cout << Intersect[n]<<" ";

	cout << endl << "--------------------------------------------------------";
//----------------Q2----------------------//
	int Num3[3] = { 1,14,8 };
	int PermCounter = 0;
	for (int n = 1; n <8; n++)
	{
		if(Permutor(Num3[0]+Num3[1]) && Permutor(Num3[1]+Num3[2]))
		{
			PermCounter++;
		}
		if (n % 2 == 0)
		{
			int a = Num3[1];
			int b = Num3[2];
			Num3[1] = b;
			Num3[2] = a;
		}
		else
		{
			int a = Num3[0];
			int b = Num3[1];
			Num3[0] = b;
			Num3[1] = a;
		}
	}
	cout << endl <<"Total Valid Permutations: "<< PermCounter << endl;
	cout << "--------------------------------------------------------" << endl;
//-----------------Q3---------------------//
	int Num4[6] = { 1,12,-5,-6,50,3 };
	int sizeofArray4 = sizeof(Num4)/4;
	int K = 4;
	int temp3size = sizeofArray4 + 1 - K;
	float* temp3 = new float[temp3size];
	for (int n = 0; n < temp3size; n++)
	{
		temp3[n] = 1.0*(Num4[n] + Num4[n+1] + Num4[n+2] + Num4[n+3])/K;
	}
	float Max = temp3[0];
	for (int n = 0; n < temp3size; n++)
	{
		for (int m = 1; m < temp3size; m++)
		{
			if (temp3[n] < temp3[m])
				Max = temp3[m];
		}
	}
	cout << "Maximum Average : " << Max<< endl << "--------------------------------------------------------"<<endl;
//-----------------Q4---------------------//
	int ID;
	string friend_recomendation[5] = { "Mahad","Hashim","Husain","Irtaza","Mufti" };
	string friend_intersts[5][1] = {{"hiking"},{"gaming"},{"cooking"},{"travel"}, {"painting"}};
	
	string user_profiles[4] = {"Ali","Ahmed","Umer","Usman"};
	string user_interests[4][3] = {
	{"hiking" ,"photography" ,"cooking" },
	{"photography" ,"travel" ,"painting" },
	{"cooking" ,"gaming" ,"movies" },
	{"hiking" ,"travel" ,"photography" }
	};
	cout << "For whom you want to recommend some friends ? " << endl;
	for (int n = 0; n < 4; n++)
	{
		cout << "\t" << n + 1 << "." << " " << user_profiles[n] << endl;
	}
	cout << "Enter the Friend number : ";
	cin >> ID;
	cout << "Following are some good recomendation according to your interest : "<<endl;
	for (int i = 0; i < 3; i++)
	{
		for (int n = 0; n < 5; n++)
		{
			for (int m = 0; m < 1; m++)
			{
				if (user_interests[ID - 1][i] == friend_intersts[n][m])
				{
					cout << friend_recomendation[n]<<endl;
				}
			}
		}
	}
	cout << "--------------------------------------------------------";
}