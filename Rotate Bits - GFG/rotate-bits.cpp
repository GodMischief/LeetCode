//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution { public: vector <int> rotate (int N, int D) { D=D%16; int left=((N<<D)|(N>>(16-D)))&((1<<16)-1); int right=((N>>D)|(N<<(16-D)))&((1<<16)-1); return vector<int>{left,right}; } };

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends