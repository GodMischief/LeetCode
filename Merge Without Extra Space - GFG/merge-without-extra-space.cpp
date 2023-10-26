//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends

class Solution {
public:
    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m) {
        int i = n - 1; // Index for arr1
        int j = 0;     // Index for arr2

        while (i >= 0 && j < m) {
            if (arr1[i] > arr2[j]) {
                // Swap arr1[i] and arr2[j] and move to the previous element of arr1.
                swap(arr1[i], arr2[j]);
                i--;
            } else {
                j++;
            }
        }

        // Sort both arrays individually.
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};


//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends