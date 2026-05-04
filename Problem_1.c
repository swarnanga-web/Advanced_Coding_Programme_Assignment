#include <stdio.h>
#include <string.h>

#define MAX 200005

int main() {
    char s[MAX];
    printf("Input: ");
scanf("%s", s);

    int n = strlen(s);
    char t[2 * MAX];
    strcpy(t, s);
    strcat(t, s);

    int freq[26] = {0};
    int left = 0, max_sum = 0, current_sum = 0;

    for (int right = 0; right < 2 * n; right++) {
        int idx = t[right] - 'a';

        freq[idx]++;
        current_sum += (idx + 1);

        while (freq[idx] > 1) {
            int lidx = t[left] - 'a';
            freq[lidx]--;
            current_sum -= (lidx + 1);
            left++;
        }
        while (right - left + 1 > n) {
            int lidx = t[left] - 'a';
            freq[lidx]--;
            current_sum -= (lidx + 1);
            left++;
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    printf("%d\n", max_sum);
    return 0;
}
