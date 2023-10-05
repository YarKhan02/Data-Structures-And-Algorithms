def insertion_sort(nums):
    # nums = list(nums)

    # nums = [int(x) for x in input().split()]

    for i in range(len(nums)):
        # print('\ni:', i)
        current = nums.pop(i)
        # print('current', current)
        j = i - 1
        # print('j:', j)

        while j >= 0 and nums[j] > current:
            j -= 1
            # print('j:', j)
        nums.insert(j + 1, current)
        # print('nums:', nums)

    return nums

nums = [2, 5, 6, 3, 1, 4]

print(insertion_sort(nums))