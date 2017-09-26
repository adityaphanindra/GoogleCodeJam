#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <string>

int main(int, char **) {
    int T = 0;
    std::cin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        int R, C;

        std::cin >> R >> C;

        char cake[R][C];

        for (int row = 0; row < R; ++row) {
            for (int col = 0; col < C; ++col) {
                std::cin >> cake[row][col];
            }
        }

        bool blankRows[R];
        for (int row = 0; row < R; ++row) {
            char replacement = '?';
            for (int col = 0; col < C; ++col) {
                if (cake[row][col] == '?') {
                    cake[row][col] = replacement;
                } else {
                    if (replacement == '?') {
                        replacement = cake[row][col];
                        for (int col_prev = 0; col_prev < col; ++col_prev) {
                            cake[row][col_prev] = replacement;
                        }
                    } else {
                        replacement = cake[row][col];
                    }
                }
            }

            for (int col = 1; col < C; ++col) {
                replacement = cake[row][0];
                assert (cake[row][col] != '?' || replacement == '?');
            }

            if (replacement != '?') {
                blankRows[row] = false;
            } else {
                blankRows[row] = true;
            }
        }

        for (int row = 0; row < R; ++row) {
            if (blankRows[row]) {
                bool found_non_blank = false;
                int row_non_blank = 0;
                for (row_non_blank = row; row_non_blank >= 0; --row_non_blank) {
                    if (!blankRows[row_non_blank]) {
                        found_non_blank = true;
                        break;
                    }
                }

                if (!found_non_blank) {
                    for (row_non_blank = row + 1; row_non_blank < R; ++row_non_blank) {
                        if (!blankRows[row_non_blank]) {
                            found_non_blank = true;
                            break;
                        }
                    }
                }

                assert (found_non_blank && row_non_blank >= 0 && row_non_blank < R && row_non_blank != row);
                for (int col = 0; col < C; ++col) {
                    cake[row][col] = cake[row_non_blank][col];
                }
                blankRows[row] = false;
            }
        }

        std::cout << "Case #" << case_number + 1 << ":" << std::endl;
        for (int row = 0; row < R; ++row) {
            for (int col = 0; col < C; ++col) {
                std::cout << cake[row][col];
            }
            std::cout << std::endl;
        }
    }
    exit (0);
}

