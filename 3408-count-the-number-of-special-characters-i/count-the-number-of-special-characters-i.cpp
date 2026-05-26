class Solution {
public:
    int numberOfSpecialChars(string word) {

        int n = word.size();

        int count = 0;

        unordered_map<char, int> mp;

        for (char ch : word) {
            mp[ch]++;
        }

        for (auto i : mp) {

            char ch = i.first;
            if (islower(ch) && mp.find(ch - 32) != mp.end()) {
                count++;
            }
        }

            return count;
        }
    };