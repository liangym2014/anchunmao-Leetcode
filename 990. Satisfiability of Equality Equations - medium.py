# https://leetcode.com/problems/satisfiability-of-equality-equations/
class Union_find:
    def __init__(self):
        # corresponding to 26 lower case characters, the value is the index of group it belongs to.
        self.var = [-1] * 26
        # the value point to the leading group id. for leading group, idx = value
        self.groups = []
        # if x1 != x2, their leading group ids should present in exclusion
        self.exclusion = defaultdict(set)

        
    def find_lead(self, idx):
        if self.groups[idx] != idx:
            self.groups[idx] = self.find_lead(self.groups[idx])
            
        return self.groups[idx]

    
    def union(self, x1, x2, equal):
        if equal == '!':
            if x1 == x2:
                return False
            
            if self.var[x1] >= 0:  # x1 assigned to a group
                x1_lead = self.find_lead(self.var[x1]) # find the leading group id of x1
            else:
                x1_lead = len(self.groups) # assign a new group id to x1, use it as leading group of x1
                self.var[x1] = x1_lead
                self.groups.append(x1_lead)

                
            if self.var[x2] >= 0:    
                x2_lead = self.find_lead(self.var[x2]) # find the leading group id of x2
            else:
                # assign a new group id to x2, use it as leading group of x2
                x2_lead = len(self.groups) 
                self.var[x2] = x2_lead
                self.groups.append(x2_lead)

            # if x1 and x2 are in the same group, return False
            if x1_lead == x2_lead:
                return False

            self.exclusion[x1_lead].add(x2_lead) # add the leading group id of x1 and x2 to exclusion
            self.exclusion[x2_lead].add(x1_lead)
        else:  # equal == '='
            if self.var[x1] >= 0:  # x1 assigned to a group
                x1_lead = self.find_lead(self.var[x1]) # find the leading group id of x1

                if self.var[x2] < 0:  # x2 not assigned to any group
                    self.var[x2] = x1_lead  # use x1's leading group as its leading group
                else:
                    x2_lead = self.find_lead(self.var[x2])

                    # if x1 and x2 are mutually exclusive
                    if x2_lead in self.exclusion[x1_lead]:
                        return False
                    else:
                        self.groups[x1_lead] = x2_lead # otherwise, merge them

            else:  # x1 not assigned to any group
                if self.var[x2] < 0:  # x2 not assigned to any group
                    self.var[x1] = len(self.groups)
                    self.groups.append(self.var[x1])
                    self.var[x2] = self.var[x1]
                else:
                    x2_lead = self.find_lead(self.var[x2])
                    self.var[x1] = x2_lead        
        
        return True
        
        
        
class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        uf = Union_find()
        
        for e in equations:
            x1, equal, _, x2 = e
            
            if uf.union(ord(x1) - 97, ord(x2) - 97, equal):
                continue
                
            return False
           
        return True
