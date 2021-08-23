# https://leetcode.com/problems/lru-cache/

"""
A more efficient way is to use OrderedDict, using move_to_end() to move the specific key to the end, and using popitem() to remove the head.
"""

class Node:
    def __init__(self, val, prev = None, nxt = None):
        self.val = val
        self.prev = prev
        self.next = nxt
        
class LRUCache:

    def __init__(self, capacity: int):
        self.size = capacity
        self.cache = {} # key: key, value: [position in the linked list, value]
        self.head = None
        self.end = None


    def get(self, key: int) -> int:
        if key in self.cache:
            t = self.cache[key][0]
            self.update_position(t)
            return self.cache[key][1]
        return -1


    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            t = self.cache[key][0]
            self.update_position(t)
            self.cache[key][1] = value
            
        else:
            if len(self.cache) == self.size: # evict the head node
                self.cache.pop(self.head.val)
                self.head = self.head.next

                if not self.head:
                    self.end = None
                else:
                    self.head.prev = None
                    
            if not self.end:
                self.end = Node(key)
                self.head = self.end
            else:
                self.end = Node(key, self.end, None)
                self.end.prev.next = self.end
                
            self.cache[key] = [self.end, value]

            
    def update_position(self, t: Node) -> None:
        if self.end == t:
            return
        
        if self.head == t:
            self.head = t.next
            self.head.prev = None
        else:
            t.prev.next = t.next
            t.next.prev = t.prev
            
        self.end.next = t
        t.prev = self.end
        t.next = None
        self.end = t   
