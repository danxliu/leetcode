class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        points.sort(key=lambda x: x[0])
        arrows = 1
        cstart, cend = points[0][0], points[0][1]
        for point in points[1:]:
            if point[0] > cend:
                arrows += 1
                cstart, cend = point[0], point[1]
            else:
                cstart = max(cstart, point[0])
                cend = min(cend, point[1])
        return arrows
