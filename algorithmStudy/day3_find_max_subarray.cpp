//Day 3 查找连续子数组最大和 


#include <iostream>
using namespace std;

/*分治法*/
/*
FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)
left_sum = -∞
sum = 0
for i = mid downto low
	sum = sum + A[i]
	if sum > left_sum
		left_sum = sum
		max_left = i
right_sum = -∞
sum = 0
for j = mid+1 to high
	sum = sum + A[j]
	if sum > right_sum
		right_sum = sum
		max_right = i
return (max_left, max_right, left_sum+right_sum)

FIND-MAX-SUBARRAY(A, low, high)
if high == low
	return (low, high, A[low])
else
	mid = (low + high) / 2
	(left_low, left_high, left_sum) = FIND-MAX-SUBARRAY(A, low, mid)
	(right_low, right_high, right_sum) = FIND-MAX-SUBARRAY(A, mid+1, high)
	(cross_low, cross_high, cross_sum) = FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)
	if left_sum >= right_sum and left_sum >= cross_sum
		return (left_low, left_high, left_sum)
	else if right_sum >= left_sum and right_sum >= cross_sum
		return (right_low, right_high, right_sum)
	else
		return (cross_low, cross_high, corss_sum)
*/

//查找跨越中点的最大子数组 O(n) 
void max_cross_subarray(int a[], int low, int mid, int high, int &cross_low, int &cross_high, int &cross_sum)
{
	int left_sum = a[mid], right_sum = a[mid+1], sum;
	cross_low = mid;
	cross_high = mid + 1;
	//从中点向左扫描 
	for (int i = mid-1, sum = left_sum; i >= low; i--)
	{
		sum += a[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			cross_low = i;
		}
	}
	//从中点向右扫描 
	for (int i = mid+2, sum = right_sum; i <= high; i++)
	{
		sum += a[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			cross_high = i;
		}
	}
	cross_sum = left_sum + right_sum;
}

//分治法查找最大子数组 O(nlogn)
//传入sub_low,sub_hihg,sum表示得到的最大子数组的两个下表和子数组的和 
void max_subarray(int a[], int low, int high, int &sub_low, int &sub_high, int &sum)
{
	if (high == low)
	{
		sub_low = sub_high = low;
		sum = a[low];
	}
	else
	{
		int mid = (low + high) / 2;
		int left_low, left_high, left_sum;
		int right_low, right_high, right_sum;
		int cross_low, cross_high, cross_sum;
		//递归查找在中点左边的子数组的最大子数组 
		max_subarray(a, low, mid, left_low, left_high, left_sum);
		//递归查找在中点右边的子数组的最大子数组 
		max_subarray(a, mid+1, high, right_low, right_high, right_sum);
		//查找跨越中点的最大子数组 
		max_cross_subarray(a, low, mid, high, cross_low, cross_high, cross_sum);
		
		if (left_sum >= right_sum && left_sum >= cross_sum)
		{
			sub_low = left_low;
			sub_high = left_high;
			sum = left_sum;
		}
		else if (right_sum >= left_sum && right_sum >= cross_sum)
		{
			sub_low = right_low;
			sub_high = right_high;
			sum = right_sum;
		}
		else
		{
			sub_low = cross_low;
			sub_high = cross_high;
			sum = cross_sum;
		}		
	}
}

/*线性扫描法*/
void max_subarray2(int a[], int len, int &sub_low, int &sub_high, int &sum)
{
	sub_low = sub_high = 0;
	if (len == 1)
		sum = a[0];
	else
	{
		int cur_sum = 0;
		int cur_low = 0; 
		sum = 0;
		//逐个数加到当前子数组中，若子数组之和小于0，重新开始找子数组 
		for(int i = 0; i < len; i++)
		{
			cur_sum += a[i]; 
			if (cur_sum < 0)
			{
				cur_sum = 0;
				cur_low = i + 1;
			}
			//当前的子数组比原来的子数组大，更新最大子数组的下标及sum 
			else if (cur_sum > sum)
			{
				sum = cur_sum;
				sub_high = i;
				sub_low = cur_low; 
			}
		}
		//若数组全为负数或0，此时sum=0，则找处数组中最大的数作为最大和的子数组返回 
		if (sum == 0)
		{
			sum = a[0];
			sub_low = 0;
			for (int i = 1; i < len; i++)
			{
				if (a[i] > sum)
				{
					sum = a[i];
					sub_low = i;
				} 
			}
			sub_high = sub_low;
		}
	}
} 


int main()
{
	int test1[] = {2, -3, -4, 2, -5, 3, 0, 2, 2, -3, -3, -1, -2, -3, 1};
	int test2[] = {0};
	int test3[] = {1, -1};
	int test4[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	int low, high, sum;
	cout<<"分治法：" << endl; 
	max_subarray(test1, 0, 14, low, high, sum);
	cout << "test1:" << endl << "low:" << low << " high:" << high << " sum:" <<sum <<endl;
	max_subarray(test2, 0, 0, low, high, sum);
	cout << "test2:" << endl << "low:" << low << " high:" << high << " sum:" <<sum <<endl;
	max_subarray(test3, 0, 1, low, high, sum);
	cout << "test3:" << endl << "low:" << low << " high:" << high << " sum:" <<sum <<endl;
	max_subarray(test4, 0, 15, low, high, sum);
	cout << "test4:" << endl << "low:" << low << " high:" << high << " sum:" <<sum <<endl;
	
	cout<<"扫描法：" << endl; 
	max_subarray2(test1, 15, low, high, sum);
	cout << "test1:" << endl << "low:" << low << " high:" << high << " sum:" <<sum <<endl;
	max_subarray2(test2, 1, low, high, sum);
	cout << "test2:" << endl << "low:" << low << " high:" << high << " sum:" <<sum <<endl;
	max_subarray2(test3, 2, low, high, sum);
	cout << "test3:" << endl << "low:" << low << " high:" << high << " sum:" <<sum <<endl;
	max_subarray2(test4, 16, low, high, sum);
	cout << "test4:" << endl << "low:" << low << " high:" << high << " sum:" <<sum <<endl;
	
	return 0;
}

