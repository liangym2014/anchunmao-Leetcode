# https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/

class Solution:
    def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
        favoriteCompanies = [[e, i] for i, e in enumerate(favoriteCompanies)]
        favoriteCompanies.sort(reverse = True, key = lambda x: len(x[0]))   # sort in descending order of length

        ans = [favoriteCompanies[0][1]]   # the longest list must not be a subset of any other list
        favoriteCompanies[0][0] = set(favoriteCompanies[0][0])
        
        for i in range(1, len(favoriteCompanies)):
            favoriteCompanies[i][0] = set(favoriteCompanies[i][0])   # convert each list into set
            is_subset = False
            
            for j in range(i):
                if len(favoriteCompanies[j][0]) == len(favoriteCompanies[i][0]):
                    break
                    
                if favoriteCompanies[i][0].issubset(favoriteCompanies[j][0]):
                    is_subset = True
                    break
                    
            if not is_subset:
                ans.append(favoriteCompanies[i][1])
                
        return sorted(ans)
