class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        f = [False, False, False]

        for triplet in triplets:
            # make sure that none of values are greater than target
            if triplet[0] > target[0] or triplet[1] > target[1] or triplet[2] > target[2]:
                continue
            for i in range(3):
                if triplet[i] == target[i]:
                    f[i] = True
        return all(f)