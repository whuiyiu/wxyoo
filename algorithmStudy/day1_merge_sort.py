#_*_coding:utf_8_
#day 1 归并排序
def merge(left, right):
	result = []
	i = 0
	j = 0
	while i < len(left) and j < len(right):
		if left[i] <= right[j]:
			result.append(left[i])
			i += 1
		else:
			result.append(right[j])
			j += 1
	if i == len(left):
		for k in range(j, len(right)):
			result.append(right[k])
	else:
		for k in range(i, len(left)):
			result.append(left[k])
	return result

def merge_sort(a):
	if len(a) <= 1:
		return a
	else:
		mid = len(a) / 2
		l = merge_sort(a[:mid])
		r = merge_sort(a[mid:])
		return merge(l, r)

a=[4, 2, 1, 6, 21, 17, -4, 6, 0]
b = merge_sort(a)
print b