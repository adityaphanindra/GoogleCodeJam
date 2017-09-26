#include <cassert>
#include <iostream>
#include <string>

int main(int, char **) {
    int T = 0;
    std::cin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        std::string S;
        size_t K;

        std::cin >> S >> K;

        int flips = 0;
        bool success = true;

        for (size_t index = 0; index < S.size() && success; ++index) {
            if (S[index] == '-') {
                for (size_t offset = 0; offset < K; ++offset) {
                    if (index + offset >= S.size()) {
                        success = false;
                        break;
                    }
                    S[index + offset] = S[index + offset] == '+' ? '-' :
                                        S[index + offset] == '-' ? '+' : S[index + offset];
                }
                ++flips;
            }
        }

        if (success) {
            std::cout << "Case #" << case_number + 1 << ": " << flips << std::endl;
        } else {
            std::cout << "Case #" << case_number + 1 << ": " << "IMPOSSIBLE" << std::endl;
        }
    }
    exit (0);
}
