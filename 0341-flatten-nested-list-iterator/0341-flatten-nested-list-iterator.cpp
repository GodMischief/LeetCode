/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<NestedInteger> st;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Push elements from the end of the input list to the stack
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        // Ensure that there is a next element.
        if (!hasNext()) {
            // Handle this case as needed (e.g., throw an exception).
        }
        
        // The top of the stack contains the next integer.
        int result = st.top().getInteger();
        st.pop();
        return result;
    }
    
    bool hasNext() {
        // Continue popping elements from the stack until we find an integer or the stack is empty.
        while (!st.empty()) {
            if (st.top().isInteger()) {
                return true;
            } else {
                // Pop the nested list, and push its elements onto the stack in reverse order.
                vector<NestedInteger> nestedList = st.top().getList();
                st.pop();
                for (int i = nestedList.size() - 1; i >= 0; i--) {
                    st.push(nestedList[i]);
                }
            }
        }
        return false;
    }
};
