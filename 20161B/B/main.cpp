#include <cassert>
#include <iostream>
#include <string>

typedef unsigned long long ull;

#define ABS_DIFF(x, y)  ( (x > y) ? (x - y) : (y - x) )
#define MIN(x, y) ( (x < y ) ? x : y )

int main(int, char **) {
    int T = 0;
    std::cin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        std::string C, J;

        std::cin >> C >> J;

        int state = 0;

        std::string current_C, current_J, current_C2, current_J2;

        for (size_t index = 0; index < C.size(); ++index) {
            char c = C.at(index);
            char j = J.at(index);
            char c2 = C.at(index);
            char j2 = J.at(index);

            if (state == 0) {
                if (c == '?' && j == '?') {
                    c = j = '0';
                    c2 = j2 = '0';
                } else if (c == '?') {
                    c = j;
                    c2 = j2;
                } else if (j == '?') {
                    j = c;
                    j2 = c2;
                } else if (c != j) {
                    state = c > j ? -1 : 1;
                    if (index > 0) {
                        if (c > j && J.at(index - 1) == '?') {
                            current_J2.at(index - 1) -= '1';
                        } else if (c < j && C.at(index - 1) == '?') {
                            current_C2.at(index - 1) -= '1';
                        }
                    }
                }
            } else if (state == -1) {
                if (c == '?' && j == '?') {
                    c = '0';
                    j = '9';
                    c2 = '9';
                    j2 = '0';
                } else if (c == '?') {
                    c = '0';
                    c2 = '9';
                } else if (j == '?') {
                    j = '9';
                    j2 = '0';
                }
            } else if (state == 1) {
                if (c == '?' && j == '?') {
                    c = '9';
                    j = '0';
                    c2 = '0';
                    j2 = '9';
                } else if (c == '?') {
                    c = '9';
                    c2 = '0';
                } else if (j == '?') {
                    j = '0';
                    j2 = '9';
                }
            }
            assert (c != '?' && j != '?' && c2 != '?' && j2 != '?');
            current_C += c;
            current_J += j;
            current_C2 += c2;
            current_J2 += j2;
        }
        ull C1 = 0, J1 = 0, C2 = 0, J2 = 0;
        for (size_t index = 0; index < current_C.size(); ++index) {
            C1 = C1 * 10 + (current_C.at(index) - '0');
            J1 = J1 * 10 + (current_C.at(index) - '0');
            C2 = C2 * 10 + (current_C.at(index) - '0');
            J2 = J2 * 10 + (current_C.at(index) - '0');
        }

        if ( ABS_DIFF(C1, J1) < ABS_DIFF(C2, J2) ) {
            std::cout << "Case #" << case_number + 1 << ": " << current_C << " " << current_J << std::endl;
        } else if ( ABS_DIFF(C1, J1) > ABS_DIFF(C2, J2) ) {
            std::cout << "Case #" << case_number + 1 << ": " << current_C2 << " " << current_J2 << std::endl;
        } else if (current_C != current_C2 ) {
            if (current_C < current_C2) {
                std::cout << "Case #" << case_number + 1 << ": " << current_C << " " << current_J << std::endl;
            } else {
                std::cout << "Case #" << case_number + 1 << ": " << current_C2 << " " << current_J2 << std::endl;
            }
        } else {
            if (current_J < current_J2) {
                std::cout << "Case #" << case_number + 1 << ": " << current_C << " " << current_J << std::endl;
            } else {
                std::cout << "Case #" << case_number + 1 << ": " << current_C2 << " " << current_J2 << std::endl;
            }
        }
    }
    exit (0);
}
