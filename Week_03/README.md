学习笔记

dfs 的模版
```
def dfs(root):
   if 满足终止条件：
       return
   // 处理数据
   process_data();
   
   for child in childen:
      dfs(child);
  
   // 组合操作 -> 分治
   // 复原操作 -> 回溯
```

