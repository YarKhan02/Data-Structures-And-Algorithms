def quick_sort(nums, start = 0, end = None):
    if end is None:
        nums = list(nums)
        end = len(nums) - 1

    if start < end:
        pivot = partition(nums, start, end)
        quick_sort(nums, start, pivot - 1)
        quick_sort(nums, pivot + 1, end)

    return nums

def partition(nums, start = 0, end = None):
    if end is None:
        end = len(nums) - 1

    l = start
    r = end - 1

    while r > l:

        if nums[l] <= nums[end]:
            l += 1
        elif nums[r] > nums[end]:
            r -= 1
        else:
            nums[l], nums[r] = nums[r], nums[l]

    if nums[l] > nums[end]:
        nums[l], nums[end] = nums[end], nums[l]
        return l
    else:
        return end
        
print(quick_sort([0, 5, 0, 4, 2]))