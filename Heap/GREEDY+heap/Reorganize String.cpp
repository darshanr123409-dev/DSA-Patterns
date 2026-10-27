#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;

        // Step 1: Count frequency of each character
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        
        // Step 2: Store {frequency, character} in max heap
        priority_queue<pair<int, char>> pq;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({it->second, it->first});
        }

        string res = "";
        int seat = 0;

        // Step 3: Build the reorganized string
        while (!pq.empty()) {
            pair<int, char> p = pq.top();
            pq.pop();

            // If the character differs from the previous character
            if (seat == 0 || res[seat - 1] != p.second) {
                res.push_back(p.second);
                seat++;

                p.first--;

                if (p.first > 0) {
                    pq.push(p);
                }
            }
            else {
                // No alternative character is available
                if (pq.empty()) {
                    return "";
                }

                // Pick another character
                pair<int, char> p2 = pq.top();
                pq.pop();

                res.push_back(p2.second);
                seat++;

                p2.first--;

                if (p2.first > 0) {
                    pq.push(p2);
                }

                // Put the unused character back
                pq.push(p);
            }
        }

        // Step 4: Return the answer
        return res;
    }
};