# https://leetcode.com/problems/get-watched-videos-by-your-friends/

import queue

class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
        n = len(friends)
        visited = [False] * n
        
        # bfs
        q = queue.Queue()
        q.put(id)
        visited[id] = True
        d = 0   # distance from id
        
        while d < level:
            l = q.qsize()
            
            while l:
                l -= 1
                front = q.get()

                for x in friends[front]:
                    if not visited[x]:
                        q.put(x)
                        visited[x] = True
                    
            d += 1
            
        # elements in q are with distance == level
        videos = []
        
        while not q.empty():
            front = q.get()
            videos.extend(watchedVideos[front])
        
        # dictionary with key(video name) and value(frequence of that video)
        count = Counter(videos)
        # convert to list of tuples
        count = list(count.items())
        count.sort(key = lambda x: x[0])    # sort based on name
        count.sort(key = lambda x: x[1])    # sort based on frequence
        
        # extract video names
        return [v for v, f in count]
