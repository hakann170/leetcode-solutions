#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution{
public:
    bool fonksiyon(string s){
        stack <char> yeni_stack;

        for (char c:s){
            if (c== '(' || c == '{' || c == '['){
                yeni_stack.push(c);
            }
            else{
                if (yeni_stack.empty()){
                    return false;
                }

                char topChar = yeni_stack.top();

                if (c == ')' && topChar != '('){
                    return false;
                }

                if (c == '}' && topChar != '{'){
                    return false;
                }

                if (c == ']' && topChar != '['){
                    return false;
                }
                yeni_stack.pop();
            }
        }
        if (yeni_stack.empty()){
            return true;
        }
    }
};

int main(){
    
    Solution sol;
    cout << boolalpha;

    string string1 = "{([])}";

    cout << sol.fonksiyon(string1);
}
