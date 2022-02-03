# https://leetcode.com/problems/operations-on-tree/
class LockingTree:

    def __init__(self, parent: List[int]):
        self.locked = [0] * len(parent)  # 0: unlocked
        self.parent = parent
        self.children = [[] for _ in range(len(parent))]
        for i in range(1, len(parent)):
            self.children[parent[i]].append(i)

    def lock(self, num: int, user: int) -> bool:
        if self.locked[num]:
            return False
        
        self.locked[num] = user
        return True
        

    def unlock(self, num: int, user: int) -> bool:
        if self.locked[num] != user:
            return False
        
        self.locked[num] = 0
        return True
        

    def upgrade(self, num: int, user: int) -> bool:
        if self.locked[num]:
            return False
        
        # check descendant
        locked_children = self.locked_descendant(num)
        if locked_children and not self.locked_ancestors(num):  # check ancestors
            self.locked[num] = user
            for child in locked_children:
                self.locked[child] = 0
            return True
            
        return False
    
    def locked_descendant(self, root) -> List[int]:
        locked_children = []

        for child in self.children[root]:
            if self.locked[child]:
                locked_children.append(child)
                
            locked_children.extend(self.locked_descendant(child))

        return locked_children
    
    def locked_ancestors(self, root) -> bool:
        p = self.parent[root]

        while p != -1:
            if self.locked[p]:
                return True
            p = self.parent[p]
            
        return False
