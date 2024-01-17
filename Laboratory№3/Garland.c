#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    double a;
    scanf("%lf", &a);

    double left_lamp = 0;
    double right_lamp = a;
    double last_a = -1;

    while ((right_lamp - left_lamp) > 0.001 / (n-1)){
        double mid = (left_lamp + right_lamp) / 2;
        double prev_value = a;
        double cur_value = mid;
        double aboveZeroLevel;
        if (cur_value > 0) {
            aboveZeroLevel = 1;
        } else {
            aboveZeroLevel = 0;
        }
        for (int i = 3; i < n+1; i++){
            double next_value = 2 * cur_value - prev_value + 2;
            if (aboveZeroLevel > 0 && next_value > 0){
                aboveZeroLevel = 1;
            } else {
                aboveZeroLevel = 0;
            }

            prev_value = cur_value;
            cur_value = next_value;
        }
        if (aboveZeroLevel) {
            right_lamp = mid;
            last_a = cur_value;
        }
        else {
            left_lamp = mid;
        }

    }
    if (last_a > -1){
        printf("%.2f", last_a);
    }
    return 0;
}