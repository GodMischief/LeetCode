//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long trappingWater(int arr[], int n) {
        if (n <= 2) {
            return 0;
        }
        long long result = 0;
        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (arr[left] < arr[right]) {
                left_max = max(left_max, arr[left]);
                result += left_max - arr[left];
                left++;
            } else {
                right_max = max(right_max, arr[right]);
                result += right_max - arr[right];
                right--;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends