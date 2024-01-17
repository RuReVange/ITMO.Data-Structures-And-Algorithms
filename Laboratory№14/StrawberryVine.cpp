#include <iostream>
#include <string>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    string text;
    cin >> text;

    int counter = 0;
    int word1, word2, len;
    for (int req = 0; req < m; ++req){
        int flag = 0;
        cin >> word1 >> word2 >> len;
        word1--; word2--;
        for (int i = 0; i < len; ++i){
            if (text[word1+i] != text[word2+i]){
                flag = 1;
            }
        }
        if (!flag){
            ++counter;
        }
    }

    cout << counter;

    return 0;
}
