//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int maxSumIS(int arr[], int n) {
        int dp[n];
        int maxSum = arr[0];  // Initialize maxSum to the first element

        for (int i = 0; i < n; i++) {
            dp[i] = arr[i];  // Initialize each element as itself
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) {
                    dp[i] = dp[j] + arr[i];
                }
            }
            maxSum = max(maxSum, dp[i]);  // Update maxSum
        }

        return maxSum;
    }
};



//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends