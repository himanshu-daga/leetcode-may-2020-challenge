class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        c0 = coordinates[0]
        c1 = coordinates[1]
        x0,y0 = (c0[0],c0[1])
        x1,y1 = (c1[0],c1[1])
        if (x1!=x0):
            slope = (y1-y0)/(x1-x0)

            for c in coordinates[2:]:
                (x0,y0) = (x1,y1)
                (x1,y1) = (c[0],c[1])
                if x1==x0: return False
                s_new = (y1-y0)/(x1-x0)
                if s_new!=slope:
                    return False
        else:
            for c in coordinates[2:]:
                (x0,y0) = (x1,y1)
                (x1,y1) = (c[0],c[1])
                if x1!=x0:
                    return False
        return True
