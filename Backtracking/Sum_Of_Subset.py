def is_subset_sum(arr, n, target_sum, current_sum, index):
    if current_sum == target_sum:
        return True

    if index == n or current_sum > target_sum:
        return False

    if is_subset_sum(arr, n, target_sum, current_sum + arr[index], index + 1):
        return True

    if is_subset_sum(arr, n, target_sum, current_sum, index + 1):
        return True

    return False

def subset_sum(arr, target_sum):
    return is_subset_sum(arr, len(arr), target_sum, 0, 0)

arr = [3, 34, 4, 12, 5, 2]
target_sum = 35
print(subset_sum(arr, target_sum))