# https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/

class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        record = defaultdict(lambda:defaultdict(int))
        foods = set()  # a set of food's name
        
        for _, table, food in orders:
            record[table][food] += 1
            foods.add(food)
        
        foods = sorted(list(foods))   # sort food's name in alphabetical order
        ans = [["Table"] + foods]
        
        table_order = list(record.keys())
        table_order.sort(key = lambda x: int(x))  # sort rows in numerical order

        for table in table_order:
            row = [table]

            for food in foods:
                if food in record[table]:
                    row.append(str(record[table][food]))
                else:
                    row.append("0")
                
            ans.append(row)
            
        return ans        
