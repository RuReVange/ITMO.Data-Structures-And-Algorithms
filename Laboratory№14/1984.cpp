#include <iostream>
#include <string>
#include <vector>
using namespace std;

void buildPrefixFunction(string& pattern, vector<int>& pi) {
    int i = 1; int j = 0;
    while (i < pattern.length()){
        if (pattern[i] == pattern[j]){
            pi[i+1] = j+1;
            ++i; ++j;
        }
        else {
            if (j>0) { j = pi[j];}
            else { pi[i+1] = 0; ++i;}
        }
    }
}

void KMP_Matcher(string& text, string& pattern, vector<int>& pi, int& counter, vector <int>& indexes) {
    buildPrefixFunction(pattern, pi);
    int i = 0; int j = 0;
    int n = (int)text.size();
    int m = (int)pattern.length();
    while (i < n) {
        if (text[i] == pattern[j]) {
            ++i; ++j;
            if (j == m) {
                ++counter;
                indexes.push_back(i - m);
                j = 0;
            }
        }
        else {
            if (j > 0) { j = pi[j]; }
            else { ++i; }
        }
    }
}

int main() {
    string txt;
    string pattern;
    int counter = 0;
    vector <int> substringIndex;
    cin >> txt >> pattern;
    vector <int> pi((int)pattern.size()+1, 0);
    KMP_Matcher(txt, pattern, pi, counter, substringIndex);
    cout << counter << endl;
    for(int i = 0; i < substringIndex.size(); ++i){
        cout << substringIndex[i] << " ";
    }
    return 0;
}
