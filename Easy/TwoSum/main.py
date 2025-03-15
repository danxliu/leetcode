def twoSum(nums, target):
    dict = {}
    for i in range(len(nums)):
        dict.update({nums[i] : i})
    for i in range(len(nums)):
        s = dict.get(target-nums[i])
        if i != s and s != None:
            return [i, s]

print(twoSum([3, 2, 4], 6))