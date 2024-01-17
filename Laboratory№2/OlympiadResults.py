n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))
for i in range(1, n):
    k = i
    while (k>0 and arr[k-1][1]<arr[k][1]):
        tmp = arr[k-1]
        arr[k-1] = arr[k]
        arr[k] = tmp
        k-=1

for i in range(1, n):
    k = i
    while (k>0 and arr[k-1][0]>arr[k][0] and arr[k-1][1]==arr[k][1]):
        tmp = arr[k-1]
        arr[k-1] = arr[k]
        arr[k] = tmp
        k-=1

for i in range(n):
    print(arr[i][0], arr[i][1])