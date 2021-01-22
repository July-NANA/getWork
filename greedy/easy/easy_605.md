
# 题解1：两边加0，处理边界
```
class Solution 
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int count =  0;
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.insert(flowerbed.end(),0);
        for(int i = 1; i < flowerbed.size()-1; i++)
        {
            if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0)
            {
                flowerbed[i] = 1;
                count++;
            }
        }
        return n <= count;
    }
};

作者：lu-guo-de-feng-2
链接：https://leetcode-cn.com/problems/can-place-flowers/solution/zui-qing-xi-zui-jian-ji-de-cdai-ma-by-lu-guo-de-fe/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

```