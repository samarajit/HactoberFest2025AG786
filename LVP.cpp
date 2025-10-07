// Longest Valid Parentheses - find the longest substring of valid parentheses.
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int maxLen = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }
    
    return maxLen;
}

int main() {
    cout << longestValidParentheses("(()") << endl;
    cout << longestValidParentheses(")()())") << endl;
    cout << longestValidParentheses("") << endl;
    cout << longestValidParentheses("()(()") << endl;
    cout << longestValidParentheses("(()())") << endl;
    return 0;
}
