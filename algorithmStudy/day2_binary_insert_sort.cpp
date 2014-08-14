//day 2 二分插入排序 
#include <iostream>
#include <cstdio>
#include <ctime> 
using namespace std;

void print_arr(int *a, int len)
{
	for(int i = 0; i < len; i++)
	    printf("%d ", a[i]);
	printf("\n");
}

//数组a中index之前的部分有序，返回把index插入的位置 
int binary_search(int *a, int index)
{
	int start = 0, end = index - 1;
	int mid;
	while(start <= end)
	{
		mid = (start + end) / 2;
		if(a[mid] == a[index])
			return mid + 1;	 //a[index]与a[mid]相等，把a[index]插在mid后 
		else if(a[mid] < a[index])
			start = mid + 1; 
		else
			end = mid - 1; 
	}
	//循环到只有一个数，若a[mid] < a[index]，把index插在该数后一位，即mid+1
	//否则，把index插在该数的位置 
	return start;   
}

void insert_sort(int *a, int len)
{
	if(len > 1)
	{
		int i, j, k;
		int key;
		for(j = 1; j < len; j++)
		{
			i = binary_search(a, j);
			if(i != j)
			{
				key = a[j];
				for(k = j; k > i;k--)
					a[k] = a[k-1];
				a[i] = key;
			}
			/*
			printf("step %d: ", j);
			print_arr(a, len);
			*/
		}
	}
}


int main()
{
	int test1[] = {12,22,32,2,13,11,42,56,9,5,10,39,43,8,36}
	insert_sort(test1, 15);
	
	int test2[] = {2, 93, 14, 85, 15, 29, 10, -3, 1, 5, 58, 26, 79};
	insert_sort(test2, 13);
	 
	return 0;
}

