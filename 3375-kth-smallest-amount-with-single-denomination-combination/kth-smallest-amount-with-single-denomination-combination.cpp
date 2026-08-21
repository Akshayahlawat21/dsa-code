// class Solution {
// public:

//  void solve(int n ,vector<int>& coins, int k , long long &finalAns){

//     set<long long > see;

//     for( int i =1;i<n+1;i++){
//          for (auto it : coins){
//            see.insert((long long)it * i);
//          }

//     }
//     auto it = next(see.begin(), k - 1); 
//  finalAns = *it;                                   




//  }

//     // long long findKthSmallest(vector<int>& coins, int k) {
//         int n =coins.size(); 

//         long long finalAns = 0;

//         solve(n , coins,k , finalAns );

//         return finalAns;
        
//     }
// };


class Solution {
private:
    // Helper function: Yeh batata hai ki 'mid' number tak kitne unique multiples hain
    long long countMultiples(long long mid, const std::vector<int>& coins) {
        long long count = 0;
        int n = coins.size();
        int totalSubsets = 1 << n; // 2^n combinations (Bitmasking)

        // 1 se lekar 2^n - 1 tak chalenge (khali subset chhod kar)
        for (int i = 1; i < totalSubsets; ++i) {
            long long currentLcm = 1;
            int elementsInSubset = 0;

            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) { // Agar j-th coin is subset ka hissa hai
                    currentLcm = std::lcm(currentLcm, (long long)coins[j]);
                    elementsInSubset++;
                    
                    // Agar LCM hamare mid se bada ho gaya, toh aage check karne ka fayda nahi
                    if (currentLcm > mid) break; 
                }
            }

            // Inclusion-Exclusion Rule:
            // Odd number of elements hain toh add karo (+), Even hain toh subtract karo (-)
            if (elementsInSubset % 2 == 1) {
                count += mid / currentLcm;
            } else {
                count -= mid / currentLcm;
            }
        }
        return count;
    }

public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        // Binary search ki range setup ki
        long long low = 1;
        long long high = (long long)*min_element(coins.begin(), coins.end()) * k; // Max possible upper limit
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            // Agar mid tak k ya k se zyada multiples mil rahe hain
            if (countMultiples(mid, coins) >= k) {
                ans = mid;        // Yeh ek valid answer ho sakta hai
                high = mid - 1;   // Aur chota answer dhoondne ki koshish karo
            } else {
                low = mid + 1;    // Multiples kam hain, range badhao
            }
        }

        return ans;
    }
};
