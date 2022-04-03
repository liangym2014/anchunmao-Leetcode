# https://leetcode.com/problems/tweet-counts-per-frequency/
class TweetCounts:

    def __init__(self):
        self.m = defaultdict(list)  # key: tweetName, val: time stamp in ascending order

    def recordTweet(self, tweetName: str, time: int) -> None:
        insort_left(self.m[tweetName], time)

    def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: int, endTime: int) -> List[int]:
        chk = 60 if freq == "minute" else 3600 if freq == "hour" else 86400
        n = ceil((endTime - startTime + 1) / chk)
        if tweetName not in self.m:
            return [0] * n
        
        ts = self.m[tweetName]
        if startTime > ts[-1] or endTime < ts[0]:
            return [0] * n

        start = bisect_left(ts, startTime)
        end = bisect_left(ts, endTime)
        if start == end:
            return [0] * n

        res = []
        
        for i in range(1, n + 1):
            time = min(endTime + 1, startTime + i * chk)
            end = bisect_left(ts, time)
            res.append(end - start)

            if end == len(ts):
                res += [0] * (n - len(res))
                break
                
            start = end
                
        return res
