1. [Valid parantheses](https://leetcode.com/problems/valid-parentheses/)

### M-1.

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char, char> bracketPairs = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char c : s) {
            if (bracketPairs.find(c) == bracketPairs.end()) {
                // If it's an opening bracket, push onto the stack
                st.push(c);
            } else {
                // If it's a closing bracket
                if (st.empty() || st.top() != bracketPairs[c]) {
                    return false;  // No matching opening bracket
                }
                st.pop();  // Matching opening bracket found
            }
        }
        return st.empty();
    }
};
```

### M-2

#### Approach

We push the opening bracket in the stack and if we encounter any type of closing bracket then we check if stack top should be equal to that closing bracket else we return false

```cpp
bool isValid(std::string s) {
        std::stack<char> st;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else if (!st.empty() &&
                       ((s[i] == ')' && st.top() == '(') ||
                        (s[i] == ']' && st.top() == '[') ||
                        (s[i] == '}' && st.top() == '{'))) {
                st.pop();
            } else {

                return false;
            }
        }

        return st.empty();
}
```

2. ### Redundant Parenthesis

#### Approach

If we encounter a closing bracket and immediately on top we find an opening bracket then it is redundant, else we pop all elements until we reach the opening bracket.

```cpp
bool isRedundantParenthesis(string s){
	stack<char> st ;
	for(int i=0 ; i < s.size() ; i++ ){
		if(s[i] == ')'){
			if(st.top() == '('){
				return true ;
			}else{
				while(st.top() != '('){
					st.pop() ;
				}
				st.pop() ;
			}
		}else{
			st.push(s[i]) ;
		}
	}
	return false ;
}
```

3. [Minimum to Make Parantheses valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)

### M-1.

```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        stack<char>st;
        for(char c: s){
            if(c == '('){
                st.push(c);
            }else{
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    cnt++;
                }
            }
        }
        while(!st.empty()){
            if(st.top() == '('){
                st.pop();
                cnt++;
            }
        }
        return cnt;
    }
};
```

### M-2

```cpp
int minAddToMakeValid(string s) {
    stack<char> st ;
    int count = 0 ;
    for(int i = 0 ;i < s.size() ; i++ ){
        if(s[i] == '('  ){
          st.push(s[i]) ;
        }
		// If the character is closing bracket and either if stack is empty or stack top is not an opening bracket then it is invalid
		else if(s[i] == ')' && (st.empty() ||  st.top() != '(' )){
          count++ ;
        }else{
            st.pop() ;
        }
    }
	// if stack is not empty we add that to the count as well
    return count + st.size();
}
```

4. [Longest Valid Parantheses](https://leetcode.com/problems/longest-valid-parentheses/)

### M-1.

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {

        int cnt = 0;
        if(!s.length()) return cnt;

        stack<int>st;
        st.push(-1);
        for(int i=0; i<s.length(); ++i){
            if(s[i] =='(') st.push(i);
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    cnt = max(cnt, i - st.top()) ;
                }
            }
        }
        return cnt;
    }
};
```

### M-2.TLE

```cpp
class Solution {
private:
    bool isValid(string s) {
      stack<char> st ;
      for(int i = 0 ;i < s.size() ; i++ ){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{' ){
            st.push(s[i]) ;
        }else if(s[i] == ')' && (st.empty() ||  st.top() != '(' )){
            return false ;
        }else if(s[i] == ']' &&  (st.empty() || st.top() != '[' )){
            return false ;
        }else if(s[i] == '}' &&  (st.empty() || st.top() != '{')){
            return false ;
        }else{
            st.pop() ;
        }
    }
    return st.empty() ;
}
public:
    int longestValidParentheses(string s) {
        int mx = 0 ;
        for(int i = 0; i < s.size(); i++){
            string temp = "" ;
            temp += s[i] ;
            for(int j = i + 1; j < s.size(); j++){
                temp += s[j] ;
                if(isValid(temp)){
                    int n = temp.size() ;
                    mx = max(mx, n) ;
                }
            }
        }
        return mx ;
    }
};
```

## Important Articles
[https://leetcode.com/problems/valid-parenthesis-string/solutions/543521/java-count-open-parenthesis-o-n-time-o-1-space-picture-explain/?envType=daily-question&envId=2024-04-07](https://leetcode.com/problems/valid-parenthesis-string/solutions/543521/java-count-open-parenthesis-o-n-time-o-1-space-picture-explain/?envType=daily-question&envId=2024-04-07)
