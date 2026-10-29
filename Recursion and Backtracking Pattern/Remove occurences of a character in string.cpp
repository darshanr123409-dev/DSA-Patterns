#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string removeChar(string &s, int n, int i, char c) {
        if (i == n) {
            return "";
        }

        string res = removeChar(s, n, i + 1, c);

        if (s[i] == c) {
            return res;
        }

        return s[i] + res;
    }

    void removeCharacter(string &s, char c) {
        int n = s.size();
        int i = 0;

        string ans = removeChar(s, n, i, c);
        s = ans;
    }
};