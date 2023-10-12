//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int lenOfLongSubarr(int A[], int N, int K) {
        unordered_map<int, int> cum_sum_dict;
        int cum_sum = 0;
        int max_length = 0;

        for (int i = 0; i < N; i++) {
            cum_sum += A[i];

            if (cum_sum == K) {
                max_length = i + 1;
            }

            if (cum_sum_dict.find(cum_sum - K) != cum_sum_dict.end()) {
                max_length = max(max_length, i - cum_sum_dict[cum_sum - K]);
            }

            if (cum_sum_dict.find(cum_sum) == cum_sum_dict.end()) {
                cum_sum_dict[cum_sum] = i;
            }
        }

        return max_length;
    }
};


//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends