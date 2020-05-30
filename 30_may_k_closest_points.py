class Solution:
    
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        # points.sort(key = lambda x:x[0]**2+x[1]**2)
        # sorted function runs faster than list.sort
        points = sorted(points, key = lambda x:x[0]**2+x[1]**2)
        return points[:K]
