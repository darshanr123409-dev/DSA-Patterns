#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<int> findAnagrams(string s, string p) {

    vector<int> ans;

    if (p.length() > s.length())
        return ans;

    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;

    // Frequency of p
    for (char ch : p) {
        mp1[ch]++;
    }

    int windowSize = p.length();

    // First window
    for (int i = 0; i < windowSize; i++) {
        mp2[s[i]]++;
    }

    // Check first window
    if (mp1 == mp2) {
        ans.push_back(0);
    }

    // Sliding window
    for (int i = windowSize; i < s.length(); i++) {

        // Add new character
        mp2[s[i]]++;

        // Remove old character
        char oldChar = s[i - windowSize];

        mp2[oldChar]--;

        // Remove if frequency becomes 0
        if (mp2[oldChar] == 0) {
            mp2.erase(oldChar);
        }

        // Compare
        if (mp1 == mp2) {
            ans.push_back(i - windowSize + 1);
        }
    }

    return ans;
}
};