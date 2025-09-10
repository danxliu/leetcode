class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        ic = set()
        for friendship in friendships:
            lu = languages[friendship[0]-1]
            lv = languages[friendship[1]-1]

            slu = set(lu)
            f = False
            for l in lv:
                if l in slu:
                    f = True
            if not f:
                ic.add(friendship[0] - 1)
                ic.add(friendship[1] - 1)
        langs = [0] * (n+1)
        for p in ic:
            for l in languages[p]:
                langs[l]+=1
        m = max(langs)
        return len(ic) - m
