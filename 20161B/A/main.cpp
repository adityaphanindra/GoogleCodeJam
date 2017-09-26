#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <string>

int main(int, char **) {
    int T = 0;
    std::cin >> T;

    std::map<int, std::string> spellings;
    spellings[0] = "ZERO";
    spellings[1] = "ONE";
    spellings[2] = "TWO";
    spellings[3] = "THREE";
    spellings[4] = "FOUR";
    spellings[5] = "FIVE";
    spellings[6] = "SIX";
    spellings[7] = "SEVEN";
    spellings[8] = "EIGHT";
    spellings[9] = "NINE";

    for (int case_number = 0; case_number < T; ++case_number) {
        std::string S;
        std::cin >> S;

        std::vector<int> char_counts(26);

        for (int char_index = 0; char_index < 26; ++char_index) {
            char_counts[char_index] = 0;
        }
        for (char c : S) {
            ++char_counts[c - 'A'];
        }

        std::vector<int> count(10);

        for (int digit_index = 0; digit_index < 10; ++digit_index) {
            count[digit_index] = 0;
        }

        count[0] = char_counts['Z' - 'A'];
        count[2] = char_counts['W' - 'A'];
        count[4] = char_counts['U' - 'A'];
        count[6] = char_counts['X' - 'A'];
        count[8] = char_counts['G' - 'A'];

        for (int digit = 0; digit <= 9; ++digit) {
            if (digit % 2 == 1) {
                continue;
            }
            std::string spelling = spellings[digit];

            for (char c : spelling) {
                char_counts[c - 'A'] -= count[digit];
            }
        }

        count[1] = char_counts['O' - 'A'];
        count[3] = char_counts['T' - 'A'];
        count[5] = char_counts['F' - 'A'];
        count[7] = char_counts['S' - 'A'];

        for (int digit = 0; digit <= 9; ++digit) {
            if ( !(digit == 1 || digit == 3 || digit == 5 || digit == 7) ) {
                continue;
            }
            std::string spelling = spellings[digit];

            for (char c : spelling) {
                char_counts[c - 'A'] -= count[digit];
            }
        }

        count[9] = char_counts['I' - 'A'];

        std::string number = "";
        for (int digit = 0; digit <= 9; ++digit) {
            for (int index = 0; index < count[digit]; ++index) {
                number += '0' + digit;
            }
        }
        std::cout << "Case #" << case_number + 1 << ": " << number << std::endl;
    }
    exit (0);
}

