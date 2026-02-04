# Linear Search with comparison count

# Input
n = int(input())                     # size of array
arr = list(map(int, input().split()))  # array elements
k = int(input())                     # key to search

# Linear search
comparisons = 0
found_index = -1

for i in range(n):
    comparisons += 1
    if arr[i] == k:
        found_index = i
        break

# Output
if found_index != -1:
    print(f"Found at index {found_index}")
else:
    print("Not Found")

print(f"Comparisons = {comparisons}")
