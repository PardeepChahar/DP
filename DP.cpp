
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* utility functions*/
int max(int a, int b);
int min(int a, int b);

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

class DP_O_OneKS
{//this call contains all problems related to 0-1 Knapsack
public:
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


/*    V4      Knapsack with recursion with memorization
=============================Started=============================*/
int DP_O_OneKS::KnapsackRecursive_with_Memorization(int w, int wt[], int vl[], int n, int** t)
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

void DP_O_OneKS::callKnapsack()
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
int DP_O_OneKS::KnapsackRecursive_without_Memorization(int w, int wt[], int vl[], int n)
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

void DP_O_OneKS::KS_Recursive()
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
int DP_O_OneKS::Knapsack_TopDown(int w, int wt[], int val[], int n)
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
void DP_O_OneKS::topDown()
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
bool DP_O_OneKS::isSubSet_of_Sum_Exist(int sum, int arr[], int n)
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

void DP_O_OneKS::subsetSumProb()
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


bool DP_O_OneKS::isEqualSum_Subset_Exist(int arr[], int n)
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
void DP_O_OneKS::call_equalSum()
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
int DP_O_OneKS::CountSubset_of_Sum(int sum, int arr[], int n)
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


void DP_O_OneKS::call_Count_Subset()
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

int DP_O_OneKS::min_subset_sum_diff(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	bool **t = new bool*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		t[i] = new bool[sum + 1];
	}

	//initilize
	for (int i = 0; i < n + 1; i++)
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
	for (int i = 0; i < (sum + 1) / 2; i++)
	{
		if (t[n][i] == true)
		{
			v.push_back(sum - 2 * i);

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

void DP_O_OneKS::call_minSubSetSumDiff()
{
	int arr[] = { 1,2,7 };//output:4
	//int arr[] = { 1,6,11,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "\nMinimum difference of sum of subset: " << min_subset_sum_diff(arr, n);
}

/*						minimun difference of sum of subset
=============================end here================================*/

void DP_O_OneKS::count_subset_of_given_diff()
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

class UnB_KS
{//this class contain all the problems related to Unbounded Knapsack
public:
	int Rod_Cutting(int val[], int n);
	void call_Road_Cutting();

	int max_Num_ofWays_Coin_Change(int coins[], int sum, int n);
	void call_CoinChange();

	int min_number_ofCoins_for_Sum(int coins[], int sum, int n);
	void Call_min_Coins();
};

/*		V14				Rod cutting problem
=============================start================================*/
int UnB_KS::Rod_Cutting(int val[], int n)
{
	//create an array of size lenght and fill it from 1 to n
	int *len = new int[n];
	for (int i = 0; i < n; i++)
	{
		len[i] = i + 1;
	}

	int **t = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		t[i] = new int[n + 1];
	}
	//initilize
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				t[i][j] = 0;
			}
		}
	}

	//fill metrix
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (len[i - 1] <= j)
			{
				t[i][j] = max(val[i - 1] + t[i][j - len[i - 1]], t[i - 1][j]);
			}
			else {
				t[i][j] = t[i - 1][j];
			}
		}
	}
	//print metrix
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			cout << t[i][j] << "\t";
		}
		cout << "\n";
	}
	return t[n][n];
}
void UnB_KS::call_Road_Cutting()
{
	int val[] = { 3, 5, 8, 9, 10, 17, 17, 20 };
	int n = sizeof(val) / sizeof(val[0]);
	cout << "Max profit is: " << Rod_Cutting(val, n);
}
/*						Rod cutting problem
=============================end here================================*/

/*		V15				Max number of ways to change coins
=============================start================================*/
int UnB_KS::max_Num_ofWays_Coin_Change(int coins[], int sum, int n)
{
	int **t = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		t[i] = new int[sum + 1];
	}
	//initilize
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < sum + 1; j++)
		{
			if (i == 0)
			{
				t[i][j] = 0;
			}
			if (j == 0)
			{
				t[i][j] = 1;
			}
		}
	}
	//fill the metrix
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < sum + 1; j++)
		{
			if (coins[i - 1] <= j)
				t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}
	return t[n][sum];

}
void UnB_KS::call_CoinChange()
{
	int coins[] = { 1,2,5 };//output:5
	int sum = 5;
	int n = sizeof(coins) / sizeof(coins[0]);
	cout << "Max number of ways to change coins for sum " << sum << " is: " << max_Num_ofWays_Coin_Change(coins, sum, n);
}
/*						Max number of ways to change coins
=============================ends here================================*/

/*		V16				min number of coins for given sum/change
=============================start================================*/
int UnB_KS::min_number_ofCoins_for_Sum(int coins[], int sum, int n)
{
	int **t = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		t[i] = new int[sum + 1];
	}

	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < sum + 1; j++)
		{

			if (j == 0)
				t[i][j] = 0;
			if (i == 0)
				t[i][j] = INT_MAX - 1;
		}
	}

	for (int i = 1; i < 2; i++)
	{
		for (int j = 0; j < sum + 1; j++)
		{
			if (j%coins[0] == 0)
				t[i][j] = j / coins[0];
			else {
				t[i][j] = INT_MAX - 1;
			}
		}
	}

	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 1; j < sum + 1; j++)
		{
			if (coins[i - 1] <= j)
				t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
			else
				t[i][j] = t[i - 1][j];
		}
	}
	//print metrix
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < sum + 1; j++)
		{
			cout << t[i][j] << "\t   ";
		}
		cout << "\n";
	}
	return t[n][sum];
}
void UnB_KS::Call_min_Coins()
{
	/*int coins[] = { 1,2,3 };//output:2
	int sum = 5;*/
	int coins[] = { 2,3,4 };//output:2
	int sum = 5;
	int n = sizeof(coins) / sizeof(coins[0]);
	cout << "min number of coins are: " << min_number_ofCoins_for_Sum(coins, sum, n);
}

/*		V16				min number of coins for given sum/change
=============================ends here================================*/


class String_Problems
{//this class contains all the problem related to strings and sequences
public:
	int max_Len_OfSubSeq_withRecursion(string a, string b, int m, int n);
	void subSeq_withRecursion();

	int max_Len_OfSubSeq_withRecursion_Memorization(string a, string b, int m, int n, int **t);
	void subSeq_withRecursion_Memorization();

	int max_Len_OfSubSeq_withTopDown(string a, string b, int m, int n);
	void subSeq_withTopDown();

	int max_Len_OfSubString_withTopDown(string a, string b, int m, int n);
	void subString_withTopDown();

	string print_Longest_SubSeq_withTopDown(string a, string b, int m, int n);
	void pring_SubSeq_withTopDown();

	void length_Of_Shortest_Common_SuperSeq();

	string print_Shortest_Super_Seq_withTopDown(string a, string b, int m, int n);
	void print_Shortest_Common_SuperSeq();

	int Len_Of_Longest_Repeating_SubSeq(string a, string b, int m, int n);
	void repeating_longest_subSeq();

};
/*		V19				max length of common subseq in two strings
=============================start================================*/
int String_Problems::max_Len_OfSubSeq_withRecursion(string a, string b, int m, int n)
{
	if (m == 0 || n == 0)
		return 0;
	if (a[m - 1] == b[n - 1])
		return 1 + max_Len_OfSubSeq_withRecursion(a, b, m - 1, n - 1);
	else
		return max(max_Len_OfSubSeq_withRecursion(a, b, m - 1, n), max_Len_OfSubSeq_withRecursion(a, b, m, n - 1));
}
void String_Problems::subSeq_withRecursion()
{
	string a = "abcdef";
	string b = "abpdqfk";//output:4
	int m = a.length();
	int n = b.length();
	cout << "Max length of Sub seq: " << max_Len_OfSubSeq_withRecursion(a, b, m, n);

}
/*		V19				max length of common subseq in two strings
=============================start================================*/

/*		V20				max length of common subseq in two strings with recursion+memorization
=============================start================================*/
int String_Problems::max_Len_OfSubSeq_withRecursion_Memorization(string a, string b, int m, int n, int **t)
{
	if (m == 0 || n == 0)
		return 0;

	if (t[m][n] != -1)
		return t[m][n];

	if (a[m - 1] == b[n - 1]) {
		t[m][n] = 1 + max_Len_OfSubSeq_withRecursion_Memorization(a, b, m - 1, n - 1, t);
		return t[m][n];
	}
	else {
		t[m][n] = max(max_Len_OfSubSeq_withRecursion_Memorization(a, b, m - 1, n, t), max_Len_OfSubSeq_withRecursion_Memorization(a, b, m, n - 1, t));
		return t[m][n];
	}
}
void String_Problems::subSeq_withRecursion_Memorization()
{
	string a = "abcdef";
	string b = "fabpdqk";//output:3
	int m = a.length();
	int n = b.length();
	int **t = new int*[m + 1];
	for (int i = 0; i < m + 1; i++)
	{
		t[i] = new int[n + 1];
	}
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			t[i][j] = -1;
		}
	}
	cout << "Max length of Sub seq: " << max_Len_OfSubSeq_withRecursion_Memorization(a, b, m, n, t);

}
/*		V20				max length of common subseq in two strings with recursion+memorization
=============================ends here================================*/

/*		V21				max length of common subseq in two strings with TopDown
=============================start================================*/
int String_Problems::max_Len_OfSubSeq_withTopDown(string a, string b, int m, int n)
{
	if (m == 0 || n == 0)
		return 0;

	int **t = new int*[m + 1];
	for (int i = 0; i < m + 1; i++)
	{
		t[i] = new int[n + 1];
	}
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (a[i - 1] == b[j - 1])
				t[i][j] = 1 + t[i - 1][j - 1];
			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}
	//print metrix
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			cout << t[i][j] << "\t   ";
		}
		cout << "\n";
	}
	return t[m][n];
}
void String_Problems::subSeq_withTopDown()
{
	cout << "\nMax sub seq string problem\n";
	string a = "abc";
	string b = "abpdqk";//output:2
	int m = a.length();
	int n = b.length();
	cout << "Max length of Sub seq: " << max_Len_OfSubSeq_withTopDown(a, b, m, n);
}
/*		V21				max length of common subseq in two strings with Top Down
=============================ends here================================*/


/*		V22				max length of common substring in two strings with Top Down
=============================start================================*/
int String_Problems::max_Len_OfSubString_withTopDown(string a, string b, int m, int n)
{
	if (m == 0 || n == 0)
		return 0;

	int **t = new int*[m + 1];
	for (int i = 0; i < m + 1; i++)
	{
		t[i] = new int[n + 1];
	}
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}
	int res = 0;
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				t[i][j] = 1 + t[i - 1][j - 1];
				res = max(res, t[i][j]);
			}
			else
				t[i][j] = 0;
		}
	}
	//print metrix
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			cout << t[i][j] << "\t   ";
		}
		cout << "\n";
	}
	return res;
}
void String_Problems::subString_withTopDown()
{
	cout << "\nMax sub seq string problem\n";
	string a = "abckkk";
	string b = "abpdqkkk";//output:2
	int m = a.length();
	int n = b.length();
	cout << "Max length of Sub seq: " << max_Len_OfSubString_withTopDown(a, b, m, n);
}
/*		V22				max length of common substring in two strings with Top Down
=============================ends here================================*/
/*		V23				print longest subseq in two strings with TopDown
=============================start================================*/
string String_Problems::print_Longest_SubSeq_withTopDown(string a, string b, int m, int n)
{
	if (m == 0 || n == 0)
		return 0;

	int **t = new int*[m + 1];
	for (int i = 0; i < m + 1; i++)
	{
		t[i] = new int[n + 1];
	}
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (a[i - 1] == b[j - 1])
				t[i][j] = 1 + t[i - 1][j - 1];
			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}
	/*//print metrix
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			cout << t[i][j] << "\t   ";
		}
		cout << "\n";
	}*/

	//back tracking
	int x = m, y = n;
	string s = "";
	while (x > 0 && y > 0)
	{
		if (a[x - 1] == b[y - 1])
		{
			s.push_back(a[x - 1]);
			x--;
			y--;
		}
		else
		{
			if (t[x - 1][y] > t[x][y - 1])
			{
				x--;
			}
			else
				y--;
		}
	}
	return s;
}
void String_Problems::pring_SubSeq_withTopDown()
{
	cout << "\n\t\tMax sub seq string problem\n";
	/*string b = "abcdaf";
	string a = "acbcf";//output:2*/
	string a = "abcdexkk";
	string b = "abcdepdqkkk";//output:2
	int m = a.length();
	int n = b.length();
	cout << "Max Sub seq: ";
	string maxSubSeq = print_Longest_SubSeq_withTopDown(a, b, m, n);
	for (int i = 0; i < maxSubSeq.length(); i++)
	{
		cout << maxSubSeq[maxSubSeq.length() - i - 1];
	}
}
/*		V23				print longest subseq in two strings with Top Down
=============================ends here================================*/

/*		V24				shortes common super Sequence
=============================started================================*/
void String_Problems::length_Of_Shortest_Common_SuperSeq()
{
	string a = "geek";
	string b = "ekc";//output:5
	int m = a.length();
	int n = b.length();
	cout << "length of shortest Super seq: " << m + n - max_Len_OfSubSeq_withTopDown(a, b, m, n);
}
/*		V24				shortes common super Sequence
=============================ends here================================*/

/*		V29				print shortest common super sequence
=============================started================================*/
string String_Problems::print_Shortest_Super_Seq_withTopDown(string a, string b, int m, int n)
{
	if (m == 0)
		return b;
	if (n == 0)
		return a;

	int **t = new int*[m + 1];
	for (int i = 0; i < m + 1; i++)
	{
		t[i] = new int[n + 1];
	}
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (a[i - 1] == b[j - 1])
				t[i][j] = 1 + t[i - 1][j - 1];
			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}
	/*//print metrix
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			cout << t[i][j] << "\t   ";
		}
		cout << "\n";
	}*/

	//back tracking
	int x = m, y = n;
	string s = "";
	while (x > 0 && y > 0)
	{
		if (a[x - 1] == b[y - 1])
		{
			s.push_back(a[x - 1]);
			x--;
			y--;
		}
		else
		{
			if (t[x - 1][y] > t[x][y - 1])
			{
				s.push_back(a[x - 1]);
				x--;
			}
			else
			{
				s.push_back(b[y - 1]);
				y--;
			}
		}
	}
	//in backtracking if x>0 it means elements are pending from string a so add them
	while (x > 0)
	{
		s.push_back(a[x - 1]);
		x--;
	}
	//in backtracking if y>0 it means elements are pending from string b so add them
	while (y > 0)
	{
		s.push_back(b[y - 1]);
		y--;
	}
	return s;
}
void String_Problems::print_Shortest_Common_SuperSeq()
{
	string a = " ";
	string b = "ekc";//output:geekc
	int m = a.length();
	int n = b.length();
	string maxSuperSeq = print_Shortest_Super_Seq_withTopDown(a, b, m, n);
	cout << "\nShortest Super seq: ";
	for (int i = 0; i < maxSuperSeq.length(); i++)
	{
		cout << maxSuperSeq[maxSuperSeq.length() - i - 1];
	}
}
/*		V2-				print shortest common super sequence
=============================ends here================================*/

/*		V30				length of longest repeating subseq given strings
=============================start================================*/
int String_Problems::Len_Of_Longest_Repeating_SubSeq(string a, string b, int m, int n)
{
	if (m == 0 || n == 0)
		return 0;

	int **t = new int*[m + 1];
	for (int i = 0; i < m + 1; i++)
	{
		t[i] = new int[n + 1];
	}
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (a[i - 1] == b[j - 1] && i != j)
				t[i][j] = 1 + t[i - 1][j - 1];
			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}
	//print metrix
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			cout << t[i][j] << "\t   ";
		}
		cout << "\n";
	}
	return t[m][n];
}
void String_Problems::repeating_longest_subSeq()
{
	cout << "\nMax sub seq string problem\n";
	string a = "aaabebcdd";
	int m = a.length();
	cout << "Max length of Sub seq: " << Len_Of_Longest_Repeating_SubSeq(a, a, m, m);
}
/*		V30				length of longest repeating subseq given strings
=============================ends here================================*/

/*						print balanced parenthesis
=============================start here================================*/
vector<string> v;
void rec(string s, int close, int opened)
{
	if (close == 0 && opened == 0)
		v.push_back(s);

	if (opened != 0)
		rec(s + "(", close, opened - 1);
	if (close > opened)
		rec(s + ")", close - 1, opened);
}
void Print_BalancedParenthesis(int n)
{
	rec("", n, n);
	for (auto i = v.begin(); i != v.end(); i++)
	{
		cout << *i << "\n";
	}
}
/*						print balanced parenthesis
=============================ends here================================*/
int main()
{
	cout << "Welcome in DP_O_OneKS!\n";
	//DP_O_OneKS dp;
	//dp.count_subset_of_given_diff();

	UnB_KS uk;
	//uk.Call_min_Coins();

	String_Problems sp;
	//sp.repeating_longest_subSeq();

	Print_BalancedParenthesis(2);
	return 0;
}
