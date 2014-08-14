//Day 3 ������������������ 


#include <iostream>
using namespace std;

/*���η�*/
/*
FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)
left_sum = -��
sum = 0
for i = mid downto low
	sum = sum + A[i]
	if sum > left_sum
		left_sum = sum
		max_left = i
right_sum = -��
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

//���ҿ�Խ�е����������� O(n) 
void max_cross_subarray(int a[], int low, int mid, int high, int &cross_low, int &cross_high, int &cross_sum)
{
	int left_sum = a[mid], right_sum = a[mid+1], sum;
	cross_low = mid;
	cross_high = mid + 1;
	//���е�����ɨ�� 
	for (int i = mid-1, sum = left_sum; i >= low; i--)
	{
		sum += a[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			cross_low = i;
		}
	}
	//���е�����ɨ�� 
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

//���η�������������� O(nlogn)
//����sub_low,sub_hihg,sum��ʾ�õ������������������±��������ĺ� 
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
		//�ݹ�������е���ߵ����������������� 
		max_subarray(a, low, mid, left_low, left_high, left_sum);
		//�ݹ�������е��ұߵ����������������� 
		max_subarray(a, mid+1, high, right_low, right_high, right_sum);
		//���ҿ�Խ�е����������� 
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

/*����ɨ�跨*/
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
		//������ӵ���ǰ�������У���������֮��С��0�����¿�ʼ�������� 
		for(int i = 0; i < len; i++)
		{
			cur_sum += a[i]; 
			if (cur_sum < 0)
			{
				cur_sum = 0;
				cur_low = i + 1;
			}
			//��ǰ���������ԭ����������󣬸��������������±꼰sum 
			else if (cur_sum > sum)
			{
				sum = cur_sum;
				sub_high = i;
				sub_low = cur_low; 
			}
		}
		//������ȫΪ������0����ʱsum=0�����Ҵ���������������Ϊ���͵������鷵�� 
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
	cout<<"���η���" << endl; 
	max_subarray(test1, 0, 14, low, high, sum);
	cout << "test1:" << endl << "low:" << low << " high:" << high << " sum:" <<sum <<endl;
	max_subarray(test2, 0, 0, low, high, sum);
	cout << "test2:" << endl << "low:" << low << " high:" << high << " sum:" <<sum <<endl;
	max_subarray(test3, 0, 1, low, high, sum);
	cout << "test3:" << endl << "low:" << low << " high:" << high << " sum:" <<sum <<endl;
	max_subarray(test4, 0, 15, low, high, sum);
	cout << "test4:" << endl << "low:" << low << " high:" << high << " sum:" <<sum <<endl;
	
	cout<<"ɨ�跨��" << endl; 
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

