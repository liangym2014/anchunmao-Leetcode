# https://leetcode.com/problems/best-team-with-no-conflicts/
class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        players = list(zip(scores, ages))
        players.sort(key = lambda x: x[0])  # sort in ascending order of score
        players.sort(key = lambda x: x[1])  # sort in ascending order of age
        
        ans = 0
        team = []  # sort the keys in end_with_score in ascending order
        end_with_score = defaultdict(int)  # key: score, value: the maximum score of a team ending with the key
        for score, _ in players:
            pos = bisect_right(team, score)
            mx = score
            
            if pos == 0:
                end_with_score[score] = mx
                team = [score] + team
            else:
                for i in range(pos):
                    mx = max(mx, end_with_score[team[i]] + score)

                end_with_score[score] = mx
                
                if team[pos - 1] != score:
                    team.insert(pos, score)
            
            ans = max(ans, mx)

        return ans
