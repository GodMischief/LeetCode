//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        const int MOD = 1000000007;
        
        // Create an array to store the number of ways to reach each step
        vector<long long> dp(n + 1, 0);

        // Base cases
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        // Calculate the number of ways for each step from 3 to n
        for (int i = 3; i <= n; ++i)
        {
            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
        }

        return dp[n];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends