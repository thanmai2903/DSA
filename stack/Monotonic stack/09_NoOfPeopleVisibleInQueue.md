[No of visible people in a queue](https://leetcode.com/problems/number-of-visible-people-in-a-queue/description/)

**Question**
There are n people standing in the queue. They are numbered from 0 to n-1 in left to right order. You are given with an array heights of distinct integers where heights[i] is the height of the ith person.

A person can see another person to their right if everybody in between is shorter than both of them.

Return an array answer of length n where answer[i] is the number of people the ith person can see to their right in the queue.

**Solution**
The questions seems to be tailor made for our templates here. Intuition - for every person we decide only to things.

The next person with greater or equal height (no person after this would be visible to the current person). But multiple people behind the current person with bigger height can see the current person. Let's take care of them in the second point.
The previous person with strictly greater height than the current person.
1 and 2 both select mutually exclusive people. Every time we find a person from both the cases, we increase their corresponding number of visisble people by 1.

We should be able to use the merged template for next greater and previous greater for this question.

**Code:**

```cpp
 vector<int> canSeePersonsCount(vector<int>& heights) {
        // using the next greater template + previous greater merged
        int n = heights.size();
        stack<int>st;
        vector<int>res(n,0);
        for(int i=0; i<n; ++i){
            while(!st.empty() && heights[st.top()] <= heights[i]){
                // next greater section
                int stkTop = st.top();
                st.pop();
                res[stkTop] += 1;
            }
            if(!st.empty()){
                // previous greater section
                res[st.top()] += 1;
            }
            st.push(i);
        }
        return res;
    }
```
