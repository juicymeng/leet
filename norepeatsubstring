#### [无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)

比较难，看了答案也要想半天。

滑动窗口的思路去解答，用一个map记录每个字符最后一次出现的位置，这个是为了更新滑动窗口的左边界。
更新规则：
1. 如果字符在map中出现过，滑动串口的左边界更新为map所记录的位置
2. 如果没有出现过，滑动窗口右边界继续往右走
这里有两个地方需要注意：
1. 对于所有字符都是不重复的串 "abcdefg"，这种窗口一直往右滑动，左边界其实是起点最初的位置，这个初始值如何设置，这里设为-1；
2. 对弈最长子串出现在字符串的末尾的情况 "bbbbcdfge"，这种因为最后的字符都没有出现过，如果使用-1为初始值会出问题，这里仍然需要和上一次的左边界进行比较。
其实关键的就是判断当前的左边界到底在什么位置。

```
int lengthOfLongestSubstring(string s) {
        map<char, int> pos;
        int left = -1;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto it = pos.find(s[i]);
            int tmp=-1;
            if (it != pos.end()) {
                tmp = it->second;
            }
            left = max(left, tmp);
            ans = max(ans, i - left);
            pos[s[i]] = i;
        }
        return ans;
    }
```
