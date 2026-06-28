class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
int n = arr.size();

int prev=1;
sort(arr.begin(),arr.end());

for(int  i =1;i<n;i++){
  
 
int  current = min(arr[i], prev + 1);

 prev  = current;
}

return prev;

    }
};