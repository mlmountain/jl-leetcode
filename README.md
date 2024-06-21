## 1. 动态规划
### 1.1 leetcode 题目完成统计
leetcode 62(已完成)    相关题目63(已完成), 64(已完成), 174  
leetcode 63           相关题目980, 2304, 2435  
leetcode 64           相关题目174, 741, 2304  
leetcode 343          相关题目1808  
leetcode 96           相关题目95  
leetcode 416          相关题目698, 1981, 2025  
leetcode 1049         相关题目2035  

### 1.2  01背包和完全背包对比
#### 1.2.1 概念对比
**01背包:** 有n件物品和一个最多能背重量为w的背包。第i件物品的重量是`weight[i]`, 得到的价值是`value[i]`。每件物品只能用一次, 求解将哪些物品装入背包里物品价值总和最大  
**完全背包:** 有N件物品和一个最多能背重量为W的背包。第i件物品的重量是`weight[i]`, 得到的价值是`value[i]`。每件物品都有无限个(也就是可以放入背包多次), 求解将哪些物品装入背包里物品价值总和最大  

#### 1.2.2 推导对比
**01背包推导:**  
1. `dp[i][j]` 表示从下标为[0-i]的物品里任意取, 放进容量为j的背包, 价值总和最大是多少  
  
2. `dp[i][j]` 有两个方向推导出来:  
(1) 不放物品i: 由`dp[i - 1][j]`推出, 即背包容量为j, 里面不放物品i的最大价值, 此时`dp[i][j]`就是`dp[i - 1][j]`  
(2) 放物品i:   由`dp[i - 1][j - weight[i]]`推出, `dp[i - 1][j - weight[i]]`表示背包容量为j - weight[i]的时候不放物品i的最大价值, 那么`dp[i - 1][j - weight[i]] + value[i]`(物品i的价值)就是背包放物品i得到的最大价值  
  
3. 递推公式:  
`dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);`  

**完全背包推导:**  
1. `dp[i][j]` 表示从下标为[0-i]的物品里任意取, 每个物品取任意个, 放进容量为j的背包, 价值总和最大是多少
  
2. `dp[i][j]` 有两个方向推出:  
(1) 不放物品i: 由`dp[i - 1][j]`推出, 即背包容量为j, 里面不放物品i的最大价值, 此时`dp[i][j]`就是`dp[i - 1][j]`  
(2) 放物品i: 物品是重复的, 可以再次放入物品i, `dp[i][j - weight[i]]` 表示存放当前物品(第i件物品)时, 重量为`j-weight[i]`时的最大价值, 那么`dp[i][j - weight[i]] + value[i]`就是第i件物品再次放入的最大价值  
  
3. 递推公式:  
`dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);`
  
**总结:**
1. 01背包  
`dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i]] + value[i])`  
- `dp[i-1][j]`: 是指 **不选择** 第i件物品,  将**前i - 1**的物品放入容量为j的价值。  
- `dp[i-1][j - weight[i]] + value[i]` 是指**选择**第i件物品, 将**前i-1**物品 放入容量为j - weight[i]背包的价值 再加上第i件物品的价值。此时 第i件已经放入了, 故为`dp[i-1] [j - weight[i]] + value[i]`。 因为01背包(每个物品都只选一次)  

2. 完全背包  
`dp[i][j] = max(dp[i-1][j], dp[i][j - weight[i]] + value[i])`
- `dp[i][j - weight[i]] + value[i]` 存放当前物品(第i件物品)时, 重量为j-weight[i]的最大价值 再加上当前物品的价值 (第i件物品是可以重复存放的)

#### 1.2.3 代码对比
```c++
// 01背包
vector<vector<int>> dp(weight.size(), vector<int>(bigweight + 1, 0));

for (int j = weight[0]; j <= bigweight; j++) {
    dp[0][j] = value[0];
}

for(int i = 1; i < weight.size(); i++) { // 遍历物品
    for(int j = 0; j <= bigweight; j++) { // 遍历背包容量
        if (j < weight[i])
            dp[i][j] = dp[i - 1][j];
        else
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);

    }
}

return dp[weight.size() - 1][bigweight];
```

```c++
vector<vector<int> > dp(weight.size()+1, vector<int>(bigWeight + 1,0));

for (int j = weight[0]; j <= bigWeight; j++) {
    dp[0][j] = dp[0][j-1] + value[0]; // 第0个物品取多次，放入容量为j的背包
}

for (int i = 1; i <= weight.size(); i++) {  // 遍历物品
    for (int j = 0; j <= bigWeight; j++) { // 遍历背包容量
        if (j < weight[i])
            dp[i][j] = dp[i-1][j];
        else
            dp[i][j] = max(dp[i-1][j], dp[i][j - weight[i]] + value[i]);
    }
}

return dp[weight.size()-1][bigWeight];
```

#### 1.2.4 二维矩阵对比
物品重量 weight = {1, 3, 4}
物品价值 value = {15, 20, 30}
背包容量 bigweight = 4

1. 01背包二维矩阵
| i\j         | 0    | 1    | 2    | 3    | 4    |
| :---------- | ---- | ---- | ---- | ---- | ---- |
| 1(value:15) | 0    | 15   | 15   | 15   | 15   |
| 3(value:20) | 0    | 15   | 15   | 20   | 35   |
| 4(value:30) | 0    | 15   | 15   | 20   | 35   |

2. 完全背包二维矩阵
| i\j         | 0    | 1    | 2    | 3    | 4    |
| :---------- | ---- | ---- | ---- | ---- | ---- |
| 1(value:15) | 0    | 15   | 30   | 45   | 60   |
| 3(value:20) | 0    | 15   | 30   | 45   | 60   |
| 4(value:30) | 0    | 15   | 30   | 45   | 60   |
