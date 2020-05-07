# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        if root.val==x or root.val==y:
            return False
        x_parent, x_depth = self.search(root,x,0)
        y_parent, y_depth = self.search(root,y,0)
        print(x_parent,y_parent,x_depth,y_depth)
        if ((x_depth==y_depth) and (x_parent!=y_parent)):
            return True
        else:
            return False
    
    def search(self, root, x, d):
        p1,p2,dep1,dep2 = (None,None,None,None)
        
    # if left and right are empty
        if (root.left==None) and (root.right == None):
            return (None, None)

    # else if left or right has expected value
        if (root.left != None):
            if (root.left.val == x):
                return (root.val, d+1)
        if (root.right != None):
            if (root.right.val == x):
                return (root.val, d+1)

    # else search left and right if possible
        if root.left!=None:
            p1,dep1 = self.search(root.left, x, d+1)
            if p1 != None:
                return (p1,dep1)
        if root.right!=None:
            p2,dep2 = self.search(root.right, x, d+1)
            if p2!= None:
                return (p2,dep2)
            
    # if nothing found in left and right sub tree, return None
        return (None, None)
