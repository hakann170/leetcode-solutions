#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    vector <int> twoSum(vector <int> &nums, int target){
        unordered_map <int,int> map;

        for (int i=0; i<nums.size(); i++){
            int current_num = nums[i];
            int complement = target - current_num;

            if (map.count(complement)){
                return {map[complement],i};
            }
            map[current_num] = i;
        }
        return {};
    }
};

int main(){

    Solution sol;
    int target = 9;
    vector <int> vector1 = {2,6,4,9,7,10};
    vector <int> result = sol.twoSum(vector1,target);

    cout << "Indexes for given target: " << result[0] << " " << result[1];

    return 0;
}
