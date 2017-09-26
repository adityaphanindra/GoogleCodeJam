#include <algorithm>
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>

bool GetNextJamcoinString(std::string & next_jamcoin_string, const std::string & jamcoin_string) {
    next_jamcoin_string = "1";

    bool carry = true;
    for (int index = jamcoin_string.size() - 2; index >= 1; --index) {
        if (jamcoin_string[index] == '0') {
            if (!carry) {
                next_jamcoin_string += "0";
            } else {
                next_jamcoin_string += "1";
            }
            carry = false;
        } else if (jamcoin_string[index] == '1') {
            if (!carry) {
                next_jamcoin_string += "1";
            } else {
                next_jamcoin_string += "0";
            }
        }
    }
    next_jamcoin_string += "1";

    if (carry) {
        next_jamcoin_string = "";
        return false;
    }

    std::reverse(next_jamcoin_string.begin(), next_jamcoin_string.end());
    assert (jamcoin_string.size() == next_jamcoin_string.size());
    return true;
}

bool IsPrime(const uint64_t & number, uint64_t & nontrivial_divisor) {
    nontrivial_divisor = 1;
    assert (number > 1);

    if (number <= 3) {
        return true;
    }

    if (number % 2 == 0) {
        nontrivial_divisor = 2;
        return false;
    }

    uint64_t root = std::ceil(std::sqrt(static_cast<double>(number)));

    for (uint64_t divisor = 3; divisor <= root; divisor += 2) {
        if (number % divisor == 0) {
            nontrivial_divisor = divisor;
            return false;
        }
    }
    nontrivial_divisor = 1;
    return true;
}

uint64_t ConvertToDecimal(const std::string & jamcoin_string, const int & base) {
    assert (jamcoin_string[0] == '1' && jamcoin_string[jamcoin_string.size() - 1] == '1');
    assert (base >= 2 && base <= 10);

    uint64_t decimal_equivalent = 0;
    uint64_t place_value = 1;
    for (int index = jamcoin_string.size() - 1; index >= 0; --index) {
        if (jamcoin_string[index] == '1') {
            decimal_equivalent += place_value;
        }
        place_value *= base;
    }
    return decimal_equivalent;
}

int main(int argc, char * argv []) {
    assert (argc > 1);

    const std::string input_file = argv[1];
    std::ifstream fin(input_file.c_str(), std::ios::in);
    std::ofstream fout("C.out", std::ios::out);

    int T;
    fin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        fout << "Case #" << case_number + 1 << ": " << std::endl;

        int N = 0, J = 0;
        fin >> N >> J;

        int count_of_jamcoin_strings = 0;

        std::string jamcoin_string = "1";
        for (int index = 1; index < N - 1; ++index) {
            jamcoin_string += "0";
        }
        jamcoin_string += "1";

        std::string next_jamcoin_string = "";
        while (GetNextJamcoinString(next_jamcoin_string, jamcoin_string)) {
            jamcoin_string = next_jamcoin_string;

            std::vector<uint64_t> nontrivial_divisors;
            std::vector<uint64_t> decimal_equivalents;
            bool prime_reached = false;
            for (int base = 2; base <= 10; ++base) {
                uint64_t nontrivial_divisor = 1;
                uint64_t decimal_equivalent = ConvertToDecimal(jamcoin_string, base);
                decimal_equivalents.push_back(decimal_equivalent);
                if (!IsPrime(decimal_equivalent, nontrivial_divisor)) {
                    nontrivial_divisors.push_back(nontrivial_divisor);
                } else {
                    prime_reached = true;
                    break;
                }
            }

            if (prime_reached) {
                continue;
            }

            assert (nontrivial_divisors.size() == 9 && decimal_equivalents.size() == 9);
            fout << jamcoin_string;
//            std::cout << jamcoin_string;
            for (int base = 2; base <= 10; ++base) {
                fout << " " << nontrivial_divisors.at(base-2);
//                std::cout << " " << nontrivial_divisors.at(base-2) << "/"
//                          << decimal_equivalents.at(base-2) << "(" << base << ")" << std::endl;
            }
            fout << std::endl;
//            std::cout << std::endl << std::endl;

            ++count_of_jamcoin_strings;
            if (count_of_jamcoin_strings == J) {
                break;
            }
        }
    }
    fin.close();
    fout.close();
}
