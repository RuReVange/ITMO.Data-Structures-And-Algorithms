#include <iostream>
#include <string>

int main() {

    using namespace std;
    int counter;
    cin >> counter;
    for (int k = 0; k < counter; k++){
        string hemingLine;
        cin >> hemingLine;
        hemingLine = '-' + hemingLine;
        string checkBit;
        string result;
        int bit = 0;

        for(int i = 1 ; i < hemingLine.length() ; i*=2){
            int count = 0;
            for (int j = i+1 ; j < hemingLine.length() ; j++) {
                if ((j & (1 << bit)) != 0){
                    if(hemingLine[j] == '1') count++;
                }
            }

            if((count & 1) != 0){
                if (hemingLine[i] == '1')
                    checkBit += '0';
                else
                    checkBit += "1";//wrong
            }
            else{
                if(hemingLine[i] == '0')
                    checkBit += "0";
                else
                    checkBit += "1";
            }
            bit++;
        }

        int flag = 0;
        for (int m = 0; m < checkBit.length(); m++){
            if (checkBit[m] == '1'){
                flag += 1;
                break;
            }
        }

        int power = 1;

        if(flag != 0){
            int wrongbit = 0;

            for(int i = 0 ; i < checkBit.length() ; i++){
                if(checkBit[i] =='1') {
                    wrongbit+=power;
                }
                power*=2;
            }
            power = 1;
            for (int i = 1; i < hemingLine.length(); i++){
                char curr = hemingLine[i];
                if (i == power){
                    power *= 2;
                }
                else{
                    if (i != wrongbit){
                        result += curr;
                    }
                    else {
                        if (curr == '0'){
                            result += '1';
                        } else {
                            result += '0';
                        }
                    }
                }
            }
        }
        else {
            for (int i = 1; i < hemingLine.length(); i++) {
                char curr = hemingLine[i];
                if (i == power) {
                    power *= 2;
                } else {
                    result += curr;
                }
            }
        }
        cout << result << endl;

    }

    return 0;
}