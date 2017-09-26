#include <cassert>
#include <iostream>
#include <string>

int main(int, char **) {
    int T = 0;
    std::cin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        std::string N;
        std::cin >> N;

        for (size_t head = 0, next_char_index = 1; next_char_index < N.size(); ++next_char_index) {
            if (N[head] < N[next_char_index]) {
                head = next_char_index;
                continue;
            }
            else if (N[head] == N[next_char_index]) {
                continue;
            }
            else if (N[head] > N[next_char_index]) {
                // discontinuity, char_index + 1 to end = 9
                N[head] = N[head] - 1;

                for (size_t index = head + 1; index < N.size(); ++index) {
                    N[index] = '9';
                }
            }
        }

        N.erase(0, std::min(N.find_first_not_of('0'), N.size() - 1));

        std::cout << "Case #" << case_number + 1 << ": " << N << std::endl;
    }
    exit (0);
}
