#include <stdio.h>
#include <string.h>

int main() {

    int amount_of_strings;
    scanf("%d", &amount_of_strings);

    int len_of_strings;
    scanf("%d", &len_of_strings);

    int radix_phaze;
    scanf("%d", &radix_phaze);

    char arr[amount_of_strings][len_of_strings];
    char result[amount_of_strings][len_of_strings];
    int help_arr[26];

    for (int i = 0; i < amount_of_strings; i++){
        scanf("%s", &arr[i]);
    }

    int position = len_of_strings - 1;
    for (int i = position; i >= 0  ; i--){

        if (radix_phaze == 0){
            break;
        }

        for (int i = 0; i < 26; i++) {
            help_arr[i] = 0;
        }

        for (int j = 0; j < amount_of_strings; j++) {
            help_arr[(int)arr[j][i]-97] += 1;
        }

        int counter = 0;
        for (int j = 0; j < 26; j++){
            int tmp = help_arr[j];
            help_arr[j] = counter;
            counter += tmp;
        }

        for (int j = 0; j < amount_of_strings; j++){
            for (int k = 0; k < len_of_strings; k++){
                result[help_arr[(int)arr[j][i]-97]][k] = arr[j][k];
            }
            help_arr[(int)arr[j][i]-97] += 1;
        }

        for (int j = 0; j < amount_of_strings; j++){
            for (int k = 0; k < len_of_strings; k++) {
                arr[j][k] = result[j][k];
            }
        }
        radix_phaze-=1;

    }

    for (int i = 0; i<amount_of_strings; i++){
        for( int j = 0; j < len_of_strings; j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}