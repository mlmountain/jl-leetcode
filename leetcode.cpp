#include "leetcode.h"
#include <iostream>
#include <algorithm>

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int index = m + n - 1;
    while(j >= 0) {
        if(i >= 0 && nums1[i] > nums2[j])
            nums1[index--] =  nums1[i--];
        else
            nums1[index--] =  nums2[j--];
    }
}

void Solution::testMerge()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    merge(nums1,3,nums2,3);
    for(size_t i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
}

int Solution::removeElement(vector<int>& nums, int val) {
    int size = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] == val) {
            size += 1;
            for (int j = i; j < nums.size() - size; j++) {
                nums[j] = nums[j+1];
            }
        }
    }
    return nums.size()-size;
}

void Solution::testRemoveElement()
{
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int result = removeElement(nums,2);
    for(int i = 0; i < result; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int Solution::removeDuplicates(vector<int> &nums)
{
    int index = 0;
    for(int i = 1; i < nums.size();  i++) {
        if(nums[i] != nums[index]) {
            index++;
            nums[index] = nums[i];
        }
    }
    return index+1;
}

void Solution::testRemoveDuplicates()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int result = removeDuplicates(nums);
    for(int i = 0; i < result; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int Solution::removeDuplicates2(vector<int> &nums)
{

}

void Solution::testremoveDuplicates2()
{
    vector<int> nums = {1,1,1,2,2,3};
    int result = removeDuplicates2(nums);
    cout << "result = " << result << endl;
    for(int i = 0; i < result; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

}

int Solution::trap(vector<int> &height)
{
    int sum = 0;
    for (int i = 1; i < height.size(); i++) {
        int leftMax = height[i];
        int rightMax = height[i];

        // 从当前点往右，找到最大一个 比当前点大 的点
        for (int right = i+1; right < height.size(); right++) {
            if (height[right] > rightMax) {
                rightMax = height[right];
            }
        }

        // 从当前点往左，找到最大一个 比当前点大 的点
        for (int left = i-1; left >= 0; left--) {
            if (height[left] > leftMax) {
                leftMax = height[left];
            }
        }

        // 当前点能存储的雨水量: min(rightMax, leftMax) - height[i]
        // 当前点能存储的雨水量是由右边最高点和左边最高点决定的
        sum += (min(rightMax, leftMax) - height[i]);
    }
    return sum;
}

void Solution::testTrap()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int sum = trap(height);
    cout << sum << endl;
}

int Solution::trapRainWater(vector<vector<int> > &heightMap)
{
    int sum = 0;
    for (int row = 1; row < heightMap.size(); row++) {
        for (int col = 1; col < heightMap[0].size(); col++) {
            int leftMax = heightMap[row][col];
            int rightMax = heightMap[row][col];
            int frontMax = heightMap[row][col];
            int backMax = heightMap[row][col];

            // 在行方向上，从当前点往左，找到最大一个 比当前点大 的点
            for (int left = col - 1; left >= 0; left--) {
                if (heightMap[row][left] > leftMax) {
                    leftMax = heightMap[row][left];
                }
            }

            // 在行方向上，从当前点往右，找到最大一个 比当前点大 的点
            for (int right = col + 1; right < heightMap[0].size(); right++) {
                if (heightMap[row][right] > rightMax) {
                    rightMax = heightMap[row][right];
                }
            }

            // 在列方向上，从当前点往前，找到最大一个 比当前点大 的点
            for (int front = row - 1; front >= 0; front--) {
                if (heightMap[front][col] > frontMax) {
                    frontMax = heightMap[front][col];
                }
            }

            // 在列方向上，从当前点往后，找到最大一个 比当前点大 的点
            for (int back = row +1; back < heightMap.size(); back++) {
                if (heightMap[back][col] > backMax) {
                    backMax = heightMap[back][col];
                }
            }

            sum += min(min(min(leftMax, rightMax), frontMax), backMax) - heightMap[row][col];
        }
    }

    return sum;
}

void Solution::testRrapRainWater()
{
    int matrix[3][6] = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    std::vector<std::vector<int> > heightMap(3,vector<int>(6,0));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            heightMap[i][j] = matrix[i][j];
        }
    }
    int sum = trapRainWater(heightMap);
    cout << sum << endl;
}

int Solution::fib(int n)
{
    // dp[i] 表示数字i对应的斐波那契数值
    // vector<int> dp(n+1);
    // dp[0] = 0;
    // dp[1] = 1;

    // for (int i = 2; i <= n; i++) {
    //     dp[i] = dp[i-1] + dp[i-2];
    // }
    if (n <= 1) {
        return n;
    }
    int dp[2] = {0, 1};
    for(int i = 2; i <= n; i++) {
        int dpN = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = dpN;
    }

    return dp[1];
}

void Solution::testFib()
{
    cout << "n = 2: " << fib(2) << endl;
    cout << "n = 3: " << fib(2) << endl;
    cout << "n = 4: " << fib(2) << endl;
}

int Solution::climbStairs(int n)
{
    // dp[i] 表示爬上i级台阶有dp[i]种方法
    // 爬上第i级台阶有两种方法：1. 从i-1级台阶爬1步 2. 从i-2级台阶爬2步
    // 递推公式: dp[i] = dp[i-1] + dp[i-2] 表示爬上i级台阶有爬上i-1级台阶的方法数+爬上i-2级台阶的方法数
    if(n <= 2) {
        return n;
    }
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

void Solution::testClimbStairs()
{
    cout << climbStairs(3) << endl;
}

int Solution::minCostClimbingStairs(vector<int> &cost)
{
    // dp[i] 表示爬上i级台阶需要的最低花费
    // dp[i] += min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])
    vector<int> dp(cost.size()+1);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i < cost.size()+1; i++) {
        dp[i] += min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
    }

    return dp[cost.size()];
}

void Solution::testMinCostClimbingStairs()
{
    vector<int> array1 = {10,15,20};
    cout << minCostClimbingStairs(array1) << endl;

    vector<int> array2 = {1,100,1,1,1,100,1,1,100,1};
    cout << minCostClimbingStairs(array2) << endl;
}

int Solution::tribonacci(int n)
{
    if (n <= 1) {
        return n;
    }
    if (n == 2) {
        return 1;
    }

    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-3] + dp[i-1] + dp[i-2];
    }

    return dp[n];
}

void Solution::testTribonacci()
{
    cout << tribonacci(4) << endl;
}

int Solution::minimumRounds(vector<int> &tasks)
{
    int sum = 0;
    sort(tasks.begin(), tasks.end());
    int i = 0;
    int cnt = 0;
    while (i < tasks.size()) {
        cnt = count(tasks.begin() + cnt, tasks.end(), tasks[i]);
        if(cnt < 2) { //有相同级别的任务只有1个, 不满足题意，返回-1
            return -1;
        }
        i += cnt;

        // 级别是任务i的任务有cnt个, 完成任务i有两种方式: 1. 有cnt-2个i任务时再选2个任务完成 2. 有cnt-3个i任务时再选3个任务完成
        // dp[j] = in(dp[cnt-2], dp[cnt-3]) + 1 表示完成j个有相同级别的任务需要的最小轮数, +1是还要再选一次2或者3个任务完成本任务
        if(cnt == 2 || cnt == 3) {
            sum += 1;
            continue;
        }
        if (cnt == 4) {
            sum += 2;
            continue;
        }

        vector<int> dp(cnt+1, 0);
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        for(int j = 5; j < dp.size(); j++) {
            dp[j] = min(dp[j-2], dp[j-3]) + 1;
        }

        sum += dp[cnt];
    }

    return sum;
}

void Solution::testMinimumRounds()
{
    vector<int> tasks = {2,2,3,3,2,4,4,4,4,4};
    cout << minimumRounds(tasks) << endl;

    vector<int> tasks2 = {2,3,3};
    cout << minimumRounds(tasks2) << endl;

    vector<int> tasks3 = {5,5,5,5};
    cout << minimumRounds(tasks3) << endl;

    vector<int> tasks4 = {7,7,7,7,7,7};
    cout << minimumRounds(tasks4) << endl;

}

int Solution::uniquePaths(int m, int n)
{
    // dp[i][j] 表示从(0,0) 到(i,j)的有dp[i][j]种不同路径。
    // 到达(i,j)有两种方式，1. 从(i-1,j)向右走一步 2. 从(i,j-1)向下走一步
    // dp[i][j] = dp[i-1][j] + dp[i][j-1]

    std::vector<std::vector<int> > dp(m,vector<int>(n));
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

void Solution::testUniquePaths()
{
    cout << uniquePaths(3,7) << endl;
}

int Solution::uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
{
    // dp[i][j] 表示从(0,0) 到(i,j)的有dp[i][j]种不同路径。
    // 到达(i,j)有两种方式, 1. 从(i-1,j)向右走一步 2. 从(i,j-1)向下走一步
    // dp[i][j] = dp[i-1][j] + dp[i][j-1]

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) //如果在起点或终点出现了障碍，直接返回0
        return 0;

    std::vector<std::vector<int> > dp(m,vector<int>(n));

    for (int i = 0; i < m && obstacleGrid[i][0] != 1; i++) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n && obstacleGrid[0][j] != 1; j++) {
        dp[0][j] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if(obstacleGrid[i][j] == 1)
                dp[i][j] = dp[i][j];
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

void Solution::testUniquePathsWithObstacles()
{
    vector<vector<int> > obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;
}

int Solution::minPathSum(vector<vector<int> > &grid)
{
    // dp[i][j] 表示从(0,0) 到(i,j)的路径上数字最小总和
    // 到达(i,j)有两种方式, 1. 从(i-1,j)向右走一步 2. 从(i,j-1)向下走一步
    // dp[i][j] = min(dp[i-1][j] + grid[i][j], dp[i][j-1] + grid[i][j])

    int m = grid.size();
    int n = grid[0].size();
    std::vector<std::vector<int> > dp(m,vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    for(int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i-1][j] + grid[i][j], dp[i][j-1] + grid[i][j]);
        }
    }

    return dp[m-1][n-1];
}

void Solution::testMinPathSum()
{
    vector<vector<int> > grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << minPathSum(grid) << endl;

    vector<vector<int> > grid2 = {{1,2,3},{4,5,6}};
    cout << minPathSum(grid2) << endl;
}

int Solution::integerBreak(int n)
{
    // dp[i]表示拆分整数i得到的最大乘积
    // 得到dp[i]的方法有: 1. j*(i-j) 将i拆分成j和i-j，拆分为两个数  2. j*dp[i-j] 获取拆分i-j的最大乘积，然后乘以j，拆分成大于2个数
    // dp[i] = max(j*(i-j), j*dp[i-j])
    if(n <= 1)
        return 0;

    vector<int> dp(n+1, 0);
    dp[2] = 1;
    for(int i = 3; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
        }
    }
    return dp[n];
}

void Solution::testIntegerBreak()
{
    cout << integerBreak(2) << endl;
    cout << integerBreak(10) << endl;
}

int Solution::numTrees(int n)
{
    // dp[i] 表示i个节点组成且节点值从1到i互不相同的二叉搜索树种树
    // dp[i] += dp[j-1] * dp[i-j] 表示j为根节点，1,2....j-1为左结点的互不相同二叉搜索数种树 * i-j,i-j+1.....i为右结点的互不相同二叉搜索数种树

    vector<int> dp(n+1,0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    return dp[n];
}

void Solution::testNumTrees()
{
    cout << numTrees(3) << endl;
    cout << numTrees(1) << endl;
}

bool Solution::canPartition(vector<int> &nums)
{
    // 物品nums[i] 物品重量nums[i]
    // dp[i][j] 表示从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和最大是多少
    // dp[i][j] 有两个方向推出:
    // 1. 不放物品i: 由dp[i - 1][j]推出，即背包容量为j，里面不放物品i的最大价值，此时dp[i][j]就是dp[i - 1][j]
    // 2. 放物品i:   由dp[i - 1][j - weight[i]]推出，dp[i - 1][j - weight[i]] 为背包容量为j - weight[i]的时候不放物品i的最大价值，那么dp[i - 1][j - weight[i]] + value[i] （物品i的价值），就是背包放物品i得到的最大价值
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    // 数组元素和不能整除2，即数组不可能分割成两个元素和相等的子集
    if(sum % 2 != 0) {
        return false;
    }
    int target = sum  / 2; // 背包容量

    vector<vector<int> > dp(nums.size(), vector<int>(target+1, 0));

    for (int j = nums[0]; j <= target; j++) {
        dp[0][j] = nums[0];
    }

    for (int i = 1; i < nums.size(); i++) { // 物品  nums[i]: 物品重量
        for (int j = 0; j <= target; j++) { // 背包容量
            if (j < nums[i]) // 不放物品i
                dp[i][j] = dp[i - 1][j];
            else // 放物品i
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i]] + nums[i]);
        }
    }

    return dp[nums.size()-1][target] == target;
}

void Solution::testCanPartition()
{
    vector<int> nums = {1,5,11,5};
    cout << canPartition(nums) << endl;

    vector<int> nums2 = {1,2,3,5};
    cout << canPartition(nums2) << endl;

    vector<int> nums3 = {1,5,10,6};
    cout << canPartition(nums3) << endl;

}

int Solution::lastStoneWeightII(vector<int> &stones)
{
    // 背包问题: 将两两碰撞的石头分为两堆，剩余的石头重量最小，那每堆石头的重量接近石头总重量的一半, 背包最大容量即为石头总重量的一半
    // dp[i][j] 表示从1...i的石头中取，放入容量为j的背包，最大石头重量为多少
    // dp[i][j] 有两个方向推出
    // 1. 不取石头i, dp[i][j] = dp[i-1][j]
    // 2.   取石头i, dp[i][j] = dp[i-1][j-stones[i]] + stones[i];

    int sum = 0;
    for(int i = 0; i < stones.size(); i++) {
        sum += stones[i];
    }

    int target = sum  / 2; // 背包容量

    vector<vector<int> > dp(stones.size(), vector<int>(target+1,0));
    for (int j = stones[0]; j <= target; j++) {
        dp[0][j] = stones[0];
    }

    for (int i = 1; i < stones.size(); i++) {
        for (int j = 0; j <= target; j++) {
            if (j < stones[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - stones[i]] + stones[i]);
        }
    }

    // 最后dp[stones.size()-1][target]里是容量为target的背包所能背的最大重量
    // 那么分成两堆石头，一堆石头的总重量是dp[target]，另一堆就是sum - dp[target], 
    // 所以相撞之后剩下的最小石头重量就是 (sum - dp[target]) - dp[target]
    return (sum - dp[stones.size()-1][target]) - dp[stones.size()-1][target];
}

void Solution::testLastStoneWeightII()
{
    vector<int> stones = {2,7,4,1,8,1};
    cout << lastStoneWeightII(stones) << endl;

    vector<int> stones2 = {31,26,33,21,40};
    cout << lastStoneWeightII(stones2) << endl;


}










