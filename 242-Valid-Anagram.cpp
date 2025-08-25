// This part is solution by using unorderd_map
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
// sort() 
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    bool isAnagram(string s, string t){
        if (s.size() != t.size()){
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s == t){ 
            return true;
        }
    }
};

int main(){

    Solution sol;
    string s_karakteri;
    string t_karakteri;

    cout << "Ilk kelimeyi giriniz: ";
    cin >> s_karakteri;

    cout <<"Ikinci elemani giriniz: ";
    cin >> t_karakteri;

    bool sonuc = sol.isAnagram(s_karakteri,t_karakteri); 
    
    if (sonuc){
        cout << "Girdiginiz kelimeler anagram";
    } else{
        cout <<"Kelimeler anagram degil";
    }

    return 0;
}
*/
