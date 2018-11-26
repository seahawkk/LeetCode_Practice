## 566 重塑矩阵

* **题目来源：** [566 Reshape the Matrix](https://leetcode-cn.com/problems/reshape-the-matrix/submissions/)

> **示例 1:**
>
> ```
> 输入: 
> nums = 
> [[1,2],
>  [3,4]]
> r = 1, c = 4
> 输出: 
> [[1,2,3,4]]
> 解释:
> 行遍历nums的结果是 [1,2,3,4]。新的矩阵是 1 * 4 矩阵, 用之前的元素值一行一行填充新矩阵。
> ```
>
> **示例 2:**
>
> ```
> 输入: 
> nums = 
> [[1,2],
>  [3,4]]
> r = 2, c = 4
> 输出: 
> [[1,2],
>  [3,4]]
> 解释:
> 没有办法将 2 * 2 矩阵转化为 2 * 4 矩阵。 所以输出原矩阵。
> ```

**思路：** 根据新的矩阵中的行列位置，可以直接求出对应的原矩阵的位置。

### python实现

```python
class Solution:
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        row=len(nums)
        column=len(nums[0])
        if row*column!=r*c:
            return nums
        matrix=[[0]*c for i in range(r)] #python的浅拷贝与深拷贝问题
        for m in range(r):
            for n in range(c):
                num=m*c+n
                matrix[m][n]=nums[num//column][num%column]
        return matrix
```

### C++实现

```C++
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row=nums.size();
        int column=nums[0].size();
        vector<int> k(c);
        vector<vector<int>> matrix(r,k);
        if(row*column!=r*c)
            return nums;
        for(int m=0;m<r;m++){
            for(int n=0;n<c;n++){
                int num=m*c+n;
                matrix[m][n]=nums[num/column][num%column];
            }
        }
        return matrix;
    }
};
```

