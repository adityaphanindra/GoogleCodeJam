#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

typedef unsigned int uint;

std::string increment(std::string number) {
	if(number == "")
		return "1";

	uint index = 0;
	uint size = number.size();

	while(index < size) {
		if(number[index] == '9') {
			number[index] = '0';
			index++;
			continue;
		}
		else {
			number[index] = number[index]++;
			return number;
		}
	}

	if(index == size) {
		number = "1" + number;
	}
	return number;
}

bool limitReached(std::string input, std::string limit) {
	if(input.size() < limit.size())
		return false;

	if(input.size() > limit.size())
		return true;

	for(int i = 0; i < input.size(); i++) {
		if(input[i] > limit[i]) {
			return true;
		}
		if(input[i] < limit[i]) {
			return false;
		}
	}

	return true;
}

std::string reverse(std::string input) {
	return std::string(number.rbegin(), number.rend());
}

bool isPalindrome(std::string number) {
	if(number == reverse(number))
		return true;
	else
		return false;
}

std::string nextPalindrome(std::string number) {
	std::string halfNumber = "";
	char mid = ' ';
	uint size = number.length();
	halfNumber = number.substr(0, size/2);
	std::string next = "";

	if(size % 2 != 0) {
		mid = number[size/2];

		if(mid != '9') {
			mid++;
			next = halfNumber + std::string(mid) + reverse(halfNumber);
		} else {
			mid = '0';
			halfNumber = increment(halfNumber);
			next = halfNumber + reverse(halfNumber);
		}
	}
	else
	{
		std::string nextHalf = increment(halfNumber);
		if(nextHalf.size() > halfNumber) {
			nextHalf = nextHalf.substr(0, nextHalf.size()-1);
			next = nextHalf + "0" + reverse(nextHalf);
		} else {
			next = nextHalf + reverse(nextHalf);
		}
	}
	return next;
}

int main() {
	std::ifstream fin("C.in");
	std::ofstream fout("C.out");

	uint T;

	fin >> T;

	for(uint caseNumber = 1; caseNumber <= T; caseNumber++) {
		std::string min, max;
		fin >> min >> max;

		std::string number = min;
		while(!limitReached(number,max)) {
			if(isPalindrome(number)) {
				std::string root = sqrt(number);
			}

		}
	}

	fin.close();
	fout.close();

}