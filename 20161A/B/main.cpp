#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>

int main(int, char **) {
    int T = 0;
    std::cin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        int N;
        std::cin >> N;

        std::map<int, int> counter;

        for (int row = 0; row < 2*N - 1; ++row) {
            for (int col = 0; col < N; ++col) {
                int height;
                std::cin >> height;
                if (counter.find(height) == counter.end()) {
                    counter[height] = 1;
                } else {
                    counter[height] += 1;
                }
            }
        }

        std::set<int> missing;
        for (std::pair<int,int> height_count : counter) {
            if (height_count.second % 2 == 1) {
                missing.insert(height_count.first);
            }
        }

        assert (missing.size() == N);

        std::cout << "Case #" << case_number + 1 << ":";
        for (auto height : missing) {
            std::cout << " " << height;
        }
        std::cout << std::endl;
    }
    exit (0);
}
