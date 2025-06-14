// EMPLOYEE IMPORTANCE


/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        queue<int> q;
        q.push(id);
        int totalImportance = 0;

        while (!q.empty()) {
            int currentId = q.front();
            q.pop();

            // Look for the employee with this id (linear search)
            for (Employee* emp : employees) {
                if (emp->id == currentId) {
                    totalImportance += emp->importance;

                    // Add their subordinates to the queue
                    for (int subId : emp->subordinates) {
                        q.push(subId);
                    }
                    break; // we found the employee, no need to keep searching
                }
            }
        }

        return totalImportance;
    }
};
