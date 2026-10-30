#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    void decide(string &s, int index, string &dairy,
                vector<string> &ans) {

        if (index == s.size()) {
            ans.push_back(dairy);
            return;
        }

        unordered_map<char, string> letter;

        letter['2'] = "abc";
        letter['3'] = "def";
        letter['4'] = "ghi";
        letter['5'] = "jkl";
        letter['6'] = "mno";
        letter['7'] = "pqrs";
        letter['8'] = "tuv";
        letter['9'] = "wxyz";

        string choice = letter[s[index]];

        for (int i = 0; i < choice.size(); i++) {
            dairy.push_back(choice[i]);

            decide(s, index + 1, dairy, ans);

            dairy.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> res;

        if (digits.empty())
            return res;

        string temp = "";

        decide(digits, 0, temp, res);

        return res;
    }
};
