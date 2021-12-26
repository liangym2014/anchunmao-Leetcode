# https://leetcode.com/problems/process-tasks-using-servers/
import heapq
       
class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        ans = [0] * len(tasks)
        
        server_pool = [(w, i) for i, w in enumerate(servers)]  # available servers
        heapify(server_pool) # min heap, smallest weight (if tie, smallest index) at the top
        
        taskq = deque()
        task_heap = []  # tasks being processed, (end_time, server_idx)
        
        for i, time in enumerate(tasks):
            # add the current task to taskq
            taskq.append((i, time))
            
            # remove finished tasks from task_heap, put the servers into available server pool
            while task_heap and task_heap[0][0] <= i:
                _, server_idx = heappop(task_heap)
                heappush(server_pool, (servers[server_idx], server_idx))
                
            # assign available servers to the tasks in taskq
            while taskq and server_pool:
                task_idx, time = taskq.popleft()
                _, server_idx = heappop(server_pool)
                ans[task_idx] = server_idx
                heappush(task_heap, (time + i, server_idx))
        

        while taskq:
            i = task_heap[0][0]
                
            while task_heap and task_heap[0][0] <= i:
                _, server_idx = heappop(task_heap)
                heappush(server_pool, (servers[server_idx], server_idx))
            
            while taskq and server_pool:
                task_idx, time = taskq.popleft()
                _, server_idx = heappop(server_pool)
                ans[task_idx] = server_idx
                heappush(task_heap, (time + i, server_idx))
                
        return ans
