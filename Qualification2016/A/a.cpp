#include <cassert>
#include <fstream>
#include <iostream>
#include <set>
#include <stdint.h>

std::set<int> digits_seen;

int AddDigitsSeen(const int64_t & M) {
    int64_t value = M;
    for (; value > 0; value /= 10) {
        digits_seen.insert(value % 10);
    }
}

int main() {
    std::ifstream fin("A-large.in", std::ios::in);
    std::ofstream fout("A.out", std::ios::out);
    int T;

    fin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        digits_seen.clear();

        int64_t N;
        fin >> N;

        if (N == 0) {
            fout << "Case #"<< case_number + 1 << ": " << "INSOMNIA" << std::endl;
            continue;
        }
        int64_t i = 1;
        while (true) {
            int64_t M = i * N;
            assert(M >= 0);

            AddDigitsSeen(M);

            if (digits_seen.size() == 10) {
                fout << "Case #"<< case_number + 1 << ": " << M << std::endl;
                break;
            }
            ++i;
        }
    }
    fin.close();
    fout.close();
}
