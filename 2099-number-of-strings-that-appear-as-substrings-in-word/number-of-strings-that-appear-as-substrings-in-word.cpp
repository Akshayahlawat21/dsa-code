class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        int count = 0;

        // Loop through every pattern
        for (int k = 0; k < patterns.size(); k++) {

            string pat = patterns[k];

            // If pattern is longer than word, it can't be a substring
            if (pat.length() > word.length()) {
                continue;
            }

            // Check every possible starting position
            for (int i = 0; i + pat.length() <= word.length(); i++) {

                int j;

                // Compare character by character
                for (j = 0; j < pat.length(); j++) {
                    if (word[i + j] != pat[j]) {
                        break;
                    }
                }

                // Full match found
                if (j == pat.length()) {
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};