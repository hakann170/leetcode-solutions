#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution{
public:
    bool containsDublicate(vector <int> &nums){
        unordered_set < int> set;

        for (int i: nums){
            if (set.count(i)){
                return true;
            }
            set.insert(i);
        }
        return false;
    }
};

int main(){

    vector <int> vector1 = {10,11,17,19,20,21};
    vector <int> vector2 = {7,9,6,4,1,7};
    Solution sol;
    cout << boolalpha;

    bool result1 = sol.containsDublicate(vector1);
    bool result2 = sol.containsDublicate(vector2);
    
    cout << "Result for first vector: " << result1 << endl;
    cout << "Result for second vector: " << result2;

    return 0;
}
