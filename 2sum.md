
#### [2 sum](https://leetcode-cn.com/problems/two-sum/)

```
vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) { 
            auto it = m.find(target - nums[i]);
            if (it != m.end()) {
                res.push_back(it->second);
                res.push_back(i);
                break;
            } else {
                m[nums[i]] = i;
            }
        }
        return res;
    }
```
思考过程：做过很多次了，上来直接想的最优方案，这里需要一个 map，关键是map的key和value分别存的是什么。
题目要求nums 数组的两数之和等于target，所以我们判断的是数字，但输出要求输出数字所在的下标，而使用map通常是一致的，所以要么key是数字，要么key是下标。
简单思考，key存数字，value存下标。
获取结果的时候，需要思考是哪两个数字对应的下标，这里就是当前数字 nums[i] 对应的下标其实就是i，另外一个就是 target-nums[i]对应的下标，就是 it->second。
最后还有一个部分，什么时候给m赋值，一开始就赋值，会有一个test case通不过。
[3,2,4]
target=6
这里，一开始就赋值，会发现nums[i]=3,要找的数=target-nums=3;立即就找到了，但实际上只有这一个数字，立刻返回0。
或者
[3,3]
target=6
这是易错的答案：
```
vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) { 
            m[nums[i]] = i;
            auto it = m.find(target - nums[i]);
            if (it != m.end()) {
                res.push_back(it->second);
                res.push_back(i);
                break;
            }
        }
        return res;
    }
```
这里有几个问题，因为数字是顺序放入map的，我们只能查找之前的数字是否是当前数字和目标数字的差值，
如果出现上面的情况，map的key会出现覆盖或不生效的现象，所以只能放在最后。

```
vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) { 
            auto it = m.find(target - nums[i]);
            if (it != m.end() && it->second != i) {
                res.push_back(it->second);
                res.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return res;
    }
```
这里是否加 `&& it->second != i` 的判断，对结果没有影响，但对运行时间影响比较大，应该是可以避免某些test case里的冗余计算。
