#include <cassert>
#include <iostream>
#include <string>

int main(int, char **) {
    int T = 0;
    std::cin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        std::string C;
        std::cin >> C;

        std::string M;
        for (char c : C)
        {
            if (M.empty())
            {
                M = c;
                continue;
            }
            if (M.at(0) <= c)
            {
                M = c + M;
            }
            else
            {
                M += c;
            }
        }

        assert (C.size() == M.size());
        std::cout << "Case #" << case_number + 1 << ": " << M << std::endl;
    }
    exit (0);
}
