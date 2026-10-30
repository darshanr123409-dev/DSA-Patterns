#include<bits/stdc++.h>
using namespace std;

// 
class Solution {
public:

    void solve(int n, int open, int close,string current, vector<string>& ans) {

        // Base case:
        // We have used all n opening and n closing brackets
        if (open == n && close == n) {
            ans.push_back(current);
            return;
        }

        // We can add '(' only if we still have opening brackets left
        if (open < n) {
            current.push_back('(');
            solve(n, open + 1, close,current , ans);
            current.pop_back();
        }

        // We can add ')' only if there are unmatched '(' brackets
        if (close < open) {
           current.push_back(')');
            solve(n, open , close + 1,current , ans);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string temp ="";
        solve(n, 0, 0, temp, ans);

        return ans;
    }
};