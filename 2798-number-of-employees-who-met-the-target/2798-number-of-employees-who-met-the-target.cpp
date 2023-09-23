class Solution {
public:
  int numberOfEmployeesWhoMetTarget(std::vector<int>& hours, int target) {
    int count = 0; // Initialize a count variable to 0

    // Iterate through the 'hours' vector
    for (int hour : hours) {
      // Check if the current 'hour' is greater than or equal to the 'target'
      if (hour >= target) {
        count++; // Increment the count if the condition is met
      }
    }

    return count; // Return the final count
  }
};
