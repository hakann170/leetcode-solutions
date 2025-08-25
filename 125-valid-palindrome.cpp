#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution{
private:
    string terscevir(string &metin){
        stack <char> karakter_yigini;

        for (char c:metin){
            karakter_yigini.push(c);
        }

        string ters_metin = "";

        while (!karakter_yigini.empty()){
        ters_metin += karakter_yigini.top();
        karakter_yigini.pop();
        }
    return ters_metin;
    }
public:
    bool isPalindrome(string s){
        string temiz_metin = "";
        for (char c:s){
            if (isalnum(c)){
                temiz_metin += tolower(c);
            }
        }
        string ters_metin = terscevir(temiz_metin);
        return ters_metin == temiz_metin;
    }
};

int main(){

Solution sol;
cout << "Kontrol etmek istediginiz metni giriniz: " << endl;
string karakter;
getline(cin,karakter);

bool sonuc = sol.isPalindrome(karakter);
if (sonuc){
    cout << "Girilen karakter palindrom bir karakterdir.";
}else{
    cout << "Girilen karakter palindrom degildir.";
}

}
