//day 1 插入排序 
/*算法导论2.1 伪代码 
INSERTION-SORT(A) 
for j = 2 to A.length
    key = A[j]
    //Insert A[j] into the sorted sequence A[1 .. j - 1]
    i = j - 1
    while i > 0 and A[i] > key
        A[i + 1] = A[i]
        i = i - 1
    A[i + 1] = key
*/
#include <iostream>
#include <cstdio>
using namespace std;

void print_arr(int *a, int len)
{
	for(int i = 0; i < len; i++)
	    printf("%d ", a[i]);
	printf("\n");
}

void insert_sort(int *a, int len)
{
	if(len > 1)
	{
		int i, j;
		int key;
		for(j = 1; j < len; j++)
		{
			key = a[j];
			i = j - 1;
			for(; i >= 0  && a[i] > key; i--)
				a[i+1] = a[i];
			a[i+1] = key;
			/*
			printf("step %d: ", j);
			print_arr(a, len);
			*/
		}
	}
}

int main()
{
	int test1[] = {3, 4, 1, 8, 0, -199, 23, 289, 2, 4};
	insert_sort(test1, 10);
	
	int test2[] = {2, 93, 14, 85, 15, 29, 10, -3, 1, 5, 58, 26, 79};
	insert_sort(test2, 13);
	 
	return 0;
}

