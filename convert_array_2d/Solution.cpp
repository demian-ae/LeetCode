/*
Link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/

Approach: 
    See it as a machine, that puts numbers in containers depending on a filter, 

    The filter will be associate to the result array positions. 
    The filter will be a set, in order to check that the number is not already in the array in O(1)

    Just iterate through the array and then through the filter.

    Time Complexity: O(n^2), the worst case it's that nums = [1,1,1,1,1,1,1,1,1,1,1,1,1,...]
                                so our filter will be filter = [{1},{1},{1},{1},{1},{1},...]
                                and for the last positions we have to iterate through filter
                                but, the constraints are: 
                                1 <= nums.length <= 200
                                1 <= nums[i] <= nums.length    ... so it's relatively fast
*/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res; 
        vector<unordered_set<int>> filter;

        res.push_back({nums[0]});
        filter.push_back({nums[0]});

        int m = 1;
        int n = nums.size();

        for(int i=1; i<n; i++){
            int curr = nums[i];
            int j = 0;
            for(; j<m; j++){
                if(!filter[j].count(curr)){
                    res[j].push_back(curr);
                    filter[j].insert(curr);
                    break;
                }
            }
            if(j==m){
                m++;
                filter.push_back({curr});
                res.push_back({curr});
            }
        }
        return res; 
    }
};