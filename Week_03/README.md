学习笔记

dfs 的模版
```
visited = set()
def dfs(node, visited):
    if node in visited: # terminator    	
        # already visited     	
        return 	
    visited.add(node) 	
    # process current node here. 	
    ...	
    for next_node in node.children(): 		
        if next_node not in visited: 			
            dfs(next_node, visited)
```

bfs 的模版
```
def BFS(graph, start, end):
    visited = set()
    queue = []
    queue.append([start]) 	
    while queue: 		
        node = queue.pop()
        visited.add(node)
        process(node)
        nodes = generate_related_nodes(node)
        queue.push(nodes)	
   # other processing work 
```


二分查找的模版
```
def binary_search(nums, target):
   left = 0
   right = len(nums) - 1
   
   while left <= right:
      mid = (left + right) / 2;
      if nums[mid]  == target:
          return mid
      if nums[mid] < target:
          left = mid + 1
      else:
          right = mid - 1
      
```

二分查找的变种：
二维数组：降为一维，mid -> matrix[mid / n][mid % n]
旋转数组：左右一段条件的变更， 区分 mid 在旋转点之后和之前的情况

回溯问题汇总：
1.子集，组合，排列
2.搜索(n皇后，扫雷，岛屿问题)

回溯问题的模版：
```
def search():
   if 终止条件：
      return
   
   for 可能的结果 in 所有可能的结果：
       path.append(可能的结果)
       search();
       path.pop()
```
       


