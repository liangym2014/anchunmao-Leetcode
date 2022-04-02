# https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        res = []
        self.n = len(supplies)
        self.m = dict((s, i) for i, s in enumerate(supplies)) | dict((r, self.n + i) for i, r in enumerate(recipes))
        self.exist = [-2] * len(recipes) # -2: unexplored, -1: on the path, 0: unavailable, 1: available      
        self.ingredients = ingredients

        for i, r in enumerate(recipes):
            if self.exist[i] == 0:
                continue
            elif self.exist[i] == 1 or self.dfs(r):
                res.append(r)
                
        return res
    
    def dfs(self, item) -> bool:
        if item in self.m:
            idx = self.m[item]
            if idx < self.n:  # item is a supply
                return True
                
            idx -= self.n   # item is a recipe
            if self.exist[idx] == 1:
                return True
            
            if self.exist[idx] == -1: # item is in a loop
                self.exist[idx] = 0
                
            if self.exist[idx] == 0:
                return False

            self.exist[idx] = -1 # marked as on the path
            for g in self.ingredients[idx]:
                if not self.dfs(g):
                    self.exist[idx] = 0
                    return False
                
            self.exist[idx] = 1
            return True
        
        return False  # item is neither a supply or a recipe
