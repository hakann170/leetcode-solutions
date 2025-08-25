#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.length() != t.length()) {
            return false; 
        }

        unordered_map<char, int> freq_map; 

        for (char c : s) {
            freq_map[c]++; 
        }

        for (char c : t) { 
            freq_map[c]--;

            if (freq_map[c] < 0) {
                return false;
            }
        }
        
        return true;
    }
};

int main(){

Solution sol;

string s_karakteri;
string t_karakteri;

cout << "ilk karakteri giriniz: " << endl;
getline(cin, s_karakteri);

cout << "ikinci karakteri giriniz: " << endl;
getline(cin, t_karakteri);

bool result = sol.isAnagram(s_karakteri,t_karakteri);

if (result){
    cout <<"Girilen karakterler anagram.";
}else{
    cout <<"Grilen karakterler anagram degil.";
}
    return 0;
}
