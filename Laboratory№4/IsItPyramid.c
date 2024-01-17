#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i< n; i++){
        scanf("%d", &arr[i]);
    }

    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (2*i+2<n){
            if (arr[i] > arr[2*i+1] || arr[i] > arr[2*i+2]){
                flag = 0;
            }
        }
    }
    if (flag == 1){
        printf("YES");
    }
    else {
        printf("NO");
    }

    return 0;
}