#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {

        int i = s.size() - 1;
        int j = t.size() - 1;

        int skip_cnt1 = 0;
        int skip_cnt2 = 0;

        while (i >= 0 || j >= 0) {

            // Process s
            while (i >= 0) {
                if (s[i] == '#') {
                    skip_cnt1++;
                    i--;
                }
                else if (skip_cnt1 > 0) {
                    skip_cnt1--;
                    i--;
                }
                else {
                    break;
                }
            }

            // Process t
            while (j >= 0) {
                if (t[j] == '#') {
                    skip_cnt2++;
                    j--;
                }
                else if (skip_cnt2 > 0) {
                    skip_cnt2--;
                    j--;
                }
                else {
                    break;
                }
            }

            // Both have characters
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false;
                }
            }

            // One has character, other doesn't
            else if (i >= 0 || j >= 0) {
                return false;
            }

            // Move both pointers
            i--;
            j--;
        }

        return true;
    }
};