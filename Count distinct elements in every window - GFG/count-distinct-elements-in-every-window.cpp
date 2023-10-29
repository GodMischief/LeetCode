//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
public:
    vector<int> countDistinct(int A[], int n, int k) {
        vector<int> result;
        unordered_map<int, int> count; //Hash map to store the count of elements
        int distinctCount = 0;

        for (int i = 0; i < k; i++) {
            if (count[A[i]] == 0) {
                distinctCount++;
            }
            count[A[i]]++;
        }
        result.push_back(distinctCount);

        for (int i = k; i < n; i++) {
            if (count[A[i - k]] == 1) {
                distinctCount--;
            }
            count[A[i - k]]--;

            if (count[A[i]] == 0) {
                distinctCount++;
            }
            count[A[i]]++;

            result.push_back(distinctCount);
        }

        return result;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends