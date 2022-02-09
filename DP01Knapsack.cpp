
#include <iostream>
#include <vector>
using namespace std;


class DP
{
public:
	int max(int a, int b);

	int KnapsackRecursive_with_Memorization(int w, int wt[], int vl[], int n, int** t);
	void callKnapsack();

	int KnapsackRecursive_without_Memorization(int w, int wt[], int vl[], int n);
	void KS_Recursive();

	int Knapsack_TopDown(int w, int wt[], int val[], int n);
	void topDown();

	bool isSubSet_of_Sum_Exist(int sum, int arr[], int n);
	void subsetSumProb();

	bool isEqualSum_Subset_Exist(int arr[], int n);
	void call_equalSum();

	int CountSubset_of_Sum(int sum, int arr[], int n);
	void call_Count_Subset();

	int min_subset_sum_diff(int arr[], int n);
	void call_minSubSetSumDiff();

	void count_subset_of_given_diff();
};



int DP::max(int a, int b)
{
	return (a > b) ? a : b;
}

/*    V4      Knapsack with recursion with memorization
=============================Started=============================*/
int DP::KnapsackRecursive_with_Memorization(int w, int wt[], int vl[], int n, int** t)
{
	if (w == 0 || n == 0)
	{
		return 0;
	}

	if (t[n - 1][w - 1] != -1)
	{
		return t[n - 1][w - 1];
	}
	if (wt[n - 1] > w)
	{
		t[n - 1][w - 1] = KnapsackRecursive_with_Memorization(w, wt, vl, n - 1, t);
		return t[n - 1][w - 1];
	}
	else //if (wt[n - 1] <= w)
	{
		t[n - 1][w - 1] = max(vl[n - 1] + KnapsackRecursive_with_Memorization(w - wt[n - 1], wt, vl, n - 1, t), KnapsackRecursive_with_Memorization(w, wt, vl, n - 1, t));
		return t[n - 1][w - 1];
	}
}

void DP::callKnapsack()
{
	cout << "\n\t\tKnapsack with recursion with memorization\n";
	int val[] = { 3, 4, 5,6 };
	int wt[] = { 2, 3, 4,5 };
	int n = sizeof(val) / sizeof(val[0]);
	int w = 5;

	int** t = new int*[n + 1];
	for (int i = 0; i <= n; i++)
	{
		t[i] = new int[w + 1];
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			t[i][j] = -1;//fill 2D array with -1
		}
	}
	cout << "Recursion+memorization max profit is: " << KnapsackRecursive_with_Memorization(w, wt, val, n, t) << endl;
}

/*   V3       Knapsack with recursion with memorization
===========================ends here=========================*/


/*					Knapsack with recursion
=======================Started here================

Driver program
	int val[] = { 3, 4, 5,6};
	int wt[] = { 2, 3, 4,5 };
	int n = sizeof(val) / sizeof(val[0]);
	int w = 5;
	cout << "Only Recursion max profit is: " << KnapsackRecursive_without_Memorization(w, wt, val, n) << endl;
*/
int DP::KnapsackRecursive_without_Memorization(int w, int wt[], int vl[], int n)
{
	//base condition
	if (w == 0 || n == 0)
	{
		return 0;
	}

	if (wt[n - 1] > w)
	{
		return KnapsackRecursive_without_Memorization(w, wt, vl, n - 1);
	}
	else //if (wt[n - 1] <= w)
	{
		return max(vl[n - 1] + KnapsackRecursive_without_Memorization(w - wt[n - 1], wt, vl, n - 1), KnapsackRecursive_without_Memorization(w, wt, vl, n - 1));
	}
}

void DP::KS_Recursive()
{
	cout << "\n\t\tKnapsack with recursion without memorization\n";

	int val[] = { 6, 10, 12 };
	int wt[] = { 1, 2, 3 };
	int n = sizeof(val) / sizeof(val[0]);
	int w = 5;
	/*int val[] = {3, 4, 5,6};
	int wt[] = {2, 3, 4,5};
	int n = sizeof(val) / sizeof(val[0]);
	int w = 5;*/
	cout << "max profit is: " << KnapsackRecursive_without_Memorization(w, wt, val, n) << endl;
}
/*				Knapsack with recursion with memorization
===========================ends here================================*/


/*		V5				Top Down knapsack
===========================Start=================================*/
int DP::Knapsack_TopDown(int w, int wt[], int val[], int n)
{
	cout << "Knapsack with Top Down \n";

	//crete a 2d metrix with pointers
	int** t = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		t[i] = new int[w + 1];
	}

	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < w + 1; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;//initilize 1st row and cloumn with 0
			else if (wt[i - 1] > j)//compare metrix wt(w->j) index 
			{
				t[i][j] = t[i - 1][j];
			}
			else {
				t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
			}
		}
	}

	/*//print metrix
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < w + 1; j++)
		{
			cout << t[i][j] << "		";
		}
		cout << "\n";
	}*/
	return t[n][w];
}
void DP::topDown()
{
	int val[] = { 6, 10, 12 };
	int wt[] = { 1, 2, 3 };
	int n = sizeof(val) / sizeof(val[0]);
	int w = 5;
	/*int val[] = {3, 4, 5,6};
	int wt[] = {2, 3, 4,5};
	int n = sizeof(val) / sizeof(val[0]);
	int w = 5;*/
	cout << "max profit is: " << Knapsack_TopDown(w, wt, val, n) << endl;
}
/*						Top Down knapsack
===========================ends here=================================*/


/*		V7				SubSet Sum problem
============================Started====================================*/
bool DP::isSubSet_of_Sum_Exist(int sum, int arr[], int n)
{
	bool **t = new bool*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		t[i] = new bool[sum + 1];
	}

	//initilize first row with F and 1st colum with T and 0,0 with T
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < sum + 1; j++)
		{
			if (i == 0)
			{
				t[i][j] = false;
			}
			if (j == 0)
			{
				t[i][j] = true;
			}
		}

	}

	//code for filling the metrix and find the solution
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < sum + 1; j++)
		{
			if (arr[i - 1] <= j)
			{
				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
			}
			else {
				t[i][j] = t[i - 1][j];
			}
		}
	}

	//print metrix
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < sum + 1; j++)
		{
			cout << t[i][j] << "\t";
		}
		cout << "\n";
	}

	return t[n][sum];
}

void DP::subsetSumProb()
{
	cout << "\t\tSub Set Sum Problem\n";
	int arr[] = { 1,2,3,4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 5;
	cout << "is Sub Set of sum " << sum << " exist? " << isSubSet_of_Sum_Exist(sum, arr, n);
}

/*						SubSet Sum problem
============================ends here==============================*/

/*			V8			Equal Sum Partition
=============================started================================*/


bool DP::isEqualSum_Subset_Exist(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	if (sum % 2 != 0)
	{
		return false;
	}
	else {
		return isSubSet_of_Sum_Exist(sum / 2, arr, n);
	}
}
void DP::call_equalSum()
{
	//find two subset such that sum of elements of both subset is equal
	cout << "\t\tEqual SubSet Problem\n";
	int arr[] = { 3, 5, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "is Equal Sum Sub Set exist? " << isEqualSum_Subset_Exist(arr, n);
}
/*						Equal Sum Partition
=============================end here================================*/

/*		V9				count subset of summ
=============================Started================================*/
int DP::CountSubset_of_Sum(int sum, int arr[], int n)
{
	int **t = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		t[i] = new int[sum + 1];
	}
	//initilize 1st row with 0 and 1st column with 1 and 0,0 with 1
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < sum + 1; j++)
		{
			if (i == 0)
				t[i][j] = 0;
			if (j == 0)
				t[i][j] = 1;
		}
	}

	//fill matrix
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < sum + 1; j++)
		{
			if (arr[i - 1] <= j)
				t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}

	//print metrix
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < sum + 1; j++)
		{
			cout << t[i][j] << "\t";
		}
		cout << "\n";
	}
	return t[n][sum];
}


void DP::call_Count_Subset()
{
	cout << "\t\tCount SubSet of Sum Problem\n";
	int arr[] = { 2,3,5,6,8,10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 10;//output:3
	/*int arr[] = { 2,3,7,1,4,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 7;//output:4*/
	cout << "count of subset with sum " << sum << " :" << CountSubset_of_Sum(sum, arr, n);
}
/*						count subset of summ
=============================end here================================*/


/*		V10				minimun difference of sum of subset
=============================Started================================*/

int DP::min_subset_sum_diff(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	bool **t = new bool*[n + 1];
	for (int i = 0; i < n+1; i++)
	{
		t[i] = new bool[sum + 1];
	}

	//initilize
	for (int i = 0; i < n+1; i++)
	{
		for (int j = 0; j < sum + 1; j++)
		{
			if (i == 0)
				t[i][j] = false;
			if (j == 0)
				t[i][j] = true;
		}
	}

	//fill the metrix
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < sum + 1; j++)
		{
			if (arr[i - 1] <= j)
				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}

	//print metrix
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < sum + 1; j++)
		{
			cout << t[i][j] << "\t";
		}
		cout << "\n";
	}

	vector<int> v;
	for (int i = 0; i < (sum+1)/2; i++)
	{
		if (t[n][i] == true)
		{
			v.push_back(sum -2*i);

			//cout << i << " ";
		}
	}

	int min = INT_MAX;
	cout << "\nvector has elements: ";
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		cout << *i << " ";
		if (min > *i)
			min = *i;
	}
	return min;
}

void DP::call_minSubSetSumDiff()
{
	int arr[] = { 1,2,7 };//output:4
	//int arr[] = { 1,6,11,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<<"\nMinimum difference of sum of subset: "<<min_subset_sum_diff(arr, n);
}

/*						minimun difference of sum of subset
=============================end here================================*/

void DP::count_subset_of_given_diff()
{
	int arr[] = { 1,2,3,4,5,6 };//output:5
	int diff = 1;
	//int arr[] = { 1,6,11,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	sum = (sum + diff) / 2;
	cout << "\nCount of subset sum with given difference: " << CountSubset_of_Sum(sum, arr, n);
}
int main()
{
	cout << "Welcome in DP!\n";
	DP dp;
	dp.count_subset_of_given_diff();
	
	return 0;
}
