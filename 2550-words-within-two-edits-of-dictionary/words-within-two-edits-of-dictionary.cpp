class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {

         int n = queries.size();
         int m = dictionary.size();

        vector<string> arry; /// return krega final value

        for (int i = 0; i < n;
             i++) { // ye loop all word pr chleega jitne bhi  hai ek
            string q = queries[i];

            for (int j = 0; j <m ;
                 j++) { // ye loop unn word ke har ek element pr chgelga jo
                        // queries mein like note
                string d = dictionary[j];

                int diff = 0;

                for (int k = 0; k < q.size(); k++) {
                    if (q[k] != d[k]) {
                        diff++;
                    }

                    if (diff > 2)
                        break;
                    // ye loop dictionar ke words ke liye
                }
                if (diff <= 2) {
                    arry.push_back(q);
                    break;
                }
            }
        }
        return arry;
    }
};