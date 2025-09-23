class Solution:
    def maxDiff(self, num: int) -> int:
        min_num_str = str(num)
        max_num_str = str(num)

        for i, num in enumerate(min_num_str):
            if i == 0 and num != '1':
                min_num_str = min_num_str.replace(num, '1')
                break
            else:
                if num != '0' and min_num_str[0] != num:
                    min_num_str = min_num_str.replace(num, '0')
                    break
        for num in max_num_str:
            if num != '9':
                max_num_str = max_num_str.replace(num, '9')
                break
        return int(max_num_str) - int(min_num_str)
