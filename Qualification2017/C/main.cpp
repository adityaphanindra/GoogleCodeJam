#include <cassert>
#include <iostream>
#include <string>
typedef unsigned long long ull;
int main(int, char **) {
    int T = 0;
    std::cin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        ull N, K;
        std::cin >> N >> K;

        ull prev_maxLR = N / 2;
        ull prev_minLR = N - 1 - prev_maxLR;
        for (ull l = K; l > 1; l = l / 2) {
            ull maxLR = 0;
            ull minLR = 0;
            ull next_maxLR = 0;
            if (l % 2 == 0) {
                next_maxLR = prev_maxLR;
            } else {
                next_maxLR = prev_minLR;
            }

            maxLR = next_maxLR / 2;
            if (next_maxLR - maxLR > 1) {
                minLR = next_maxLR - 1 - maxLR;
            } else {
                minLR = 0;
            }
            prev_maxLR = maxLR;
            prev_minLR = minLR;
        }

        std::cout << "Case #" << case_number + 1 << ": " << prev_maxLR << " " << prev_minLR << std::endl;
    }
    exit (0);
}
