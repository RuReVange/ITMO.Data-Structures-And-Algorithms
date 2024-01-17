#include <iostream>
#include <vector>
#include <algorithm>

long long hash() {
    return ((long long)(rand()) << (sizeof(int) * 4)) | rand();
}

int main() {

    int n, m;

    std::cin >> n;
    std::vector<long long > word1(n + 1);

    std::vector<long long > hashTable(100010, 0);
    std::vector<long long > sumCombinations;

    for (int i = 1; i < n + 1 ; ++i) {

        long long  tmp;
        std::cin >> tmp;

        word1[i] = tmp;
        hashTable[word1[i]] = hash();

    }

    std::cin >> m;
    std::vector<long long > word2(m + 1);

    for (int i = 1; i < m + 1 ; ++i) {

        long long  tmp;
        std::cin >> tmp;

        word2[i] = tmp;
        hashTable[word2[i]] = hash();

    }


    for (int i = 1; i < n + 1; ++i) {

        word1[i] = word1[i - 1] + hashTable[word1[i]];

    }

    for (int i = 1; i < m + 1; ++i) {

        word2[i] = word2[i - 1] + hashTable[word2[i]];

    }

    for (int i = 0; i < n + 1; ++i) {

        for (int j = i; j < n + 1 ; ++j) {

            sumCombinations.push_back(word1[j] - word1[i]);

        }

    }

    std::sort(sumCombinations.begin(), sumCombinations.end());
    long long result = 0;

    for (int i = 0; i < m + 1; ++i) {

        for (int j = i; j < m + 1; ++j) {

            long long  dif = word2[j] - word2[i];

            if(std::binary_search(sumCombinations.begin(), sumCombinations.end(), dif)) {

                result = (long long)(j - i > result ? j - i : result);

            }

        }

    }

    std::cout << result;

    return 0;

}
