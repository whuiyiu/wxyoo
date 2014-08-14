#_*_coding:utf_8_
#day 2 二分插入排序

def binary_search(a, index):
	start = 0
	end = index - 1
	while start <= end:
		mid = (start + end) / 2
		if a[mid] == a[index]:
			return mid
		elif a[mid] < a[index]:
			start = mid + 1
		else:
			end = mid - 1
	return start

def insert_sort(a):
	for j in range(1, len(a)):
		i = binary_search(a, j)
		if i != j:
			key = a[j]
			for k in range(j, i, -1):
				a[k] = a[k-1]
			a[i] = key
		#print a

a=[4, 2, 1, 6, 21, 17, -4, 6, 0]
insert_sort(a)
print a