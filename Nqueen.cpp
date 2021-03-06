#include <iostream>
using namespace std;

int place(int x[], int k)
{
	for(int i=1; i<k; i++)
		if(x[i] == x[k] || abs(x[i] - x[k]) == abs(i-k))
			return 0;
	return 1;
}

void printSolution(int n,int x[])
{
	char c[10][10];

	for(int i=1; i<=n; i++)
	{
		for(int j=1;j<=n;j++)
	 		c[i][j]='X';
	}


	for(int i=1;i<=n;i++)
 		c[i][x[i]]='Q';

	for(int i=1;i<=n;i++)
	{
 		for(int j=1;j<=n;j++)
 		{
 			 cout << c[i][j] << "\t";
 		}
 		cout << endl;
	}
}

void Nqueen(int n)
{
	int x[10], count=0, k=1;
	x[k] = 0;

	while(k)
	{
		x[k] = x[k] + 1;

		while(x[k] <= n && !place(x,k))
		{
			x[k] = x[k] + 1;
		}


		if(x[k] <= n)
		{
			if( k == n)
			{
				count++;
				cout << "Solution : " << count << endl;
				printSolution(n,x);
			}

			else
			{
				k++;
				x[k] = 0;
			}
		}

		else
		{
			k--;
		}
	}

	return;
}




int main()
{
	int n;
	cout << "Enter the number of queens: " << endl;
	cin >> n;
    Nqueen(n);
}
