#_*_coding:utf_8_
#day 1 插入排序
def insert_sort(a):
	for j in range(1, len(a)):
		key = a[j]
		i = j - 1
		while i >= 0 and a[i] > key:
			a[i+1] = a[i]
			i = i - 1
		a[i+1] = key
		#print a

a=[4, 2, 1, 6, 21, 17, -4, 6, 0]
insert_sort(a)
print a