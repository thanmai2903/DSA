# [ Time Needed to Inform All Employees](https://leetcode.com/problems/time-needed-to-inform-all-employees/)

## Intuition

1. create unordered map of int, vector<int> to store manager value connection such as tree
2. here headID = head of the tree
3. push manager values exxcept head into map
4. find max of all informItem for each from root to leaf path

-   temp = informTime[i],res
-   res=max(res, temp)
-   traverse map to find temp and update res

## Code

```cpp
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>>mp;
        for(int i=0; i<n; ++i){
            if(manager[i] != -1){
                mp[manager[i]].push_back(i);
            }
        }
        int res = 0, temp=0;
        helper(mp, headID, informTime, temp, res);
        return res;
    }
    void helper(unordered_map<int, vector<int>>& mp, int i, vector<int>& informTime, int temp, int& res){
        temp += informTime[i];
        res = max(res, temp);

        for(auto it = mp[i].begin(); it != mp[i].end(); ++it){
            helper(mp, *it, informTime, temp, res);
        }
    }
};
```
