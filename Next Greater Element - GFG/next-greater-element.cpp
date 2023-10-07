//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<long long> nextLargerElement(vector<long long> arr, int n) {
        vector<long long> result(n, -1); 
        stack<pair<long long, int>> st; 

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] > st.top().first) {
                /*If the current element is greater than the top element in the stack
                update the result for the top element and pop it from the stack*/
                result[st.top().second] = arr[i];
                st.pop();
            }
            st.push({arr[i], i});
        }
        return result;
    }
//Code ny ~ Md Sohag Biswas
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends