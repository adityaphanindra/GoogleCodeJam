#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool descendFunction(double i, double j) { 
	return (i > j); 
}

int main() {
	ifstream fin("D-large.in");
	ofstream fout("D-large.out");

	int T;
	fin >> T;

	for(int caseNumber = 1; caseNumber <= T; caseNumber++) {
		int war = 0, dwar = 0;
		int N;

		fin >> N;

		vector<double> n, k;

		for(int index = 0; index < N; index++) {
			double weight;
			fin >> weight;
			n.push_back(weight);
		}

		for(int index = 0; index < N; index++) {
			double weight;
			fin >> weight;
			k.push_back(weight);
		}

		sort(n.begin(), n.end(), descendFunction);
		sort(k.begin(), k.end());

		vector<double> ncurrent(n.size()), kcurrent(k.size());
		copy(n.begin(), n.end(), ncurrent.begin());
		copy(k.begin(), k.end(), kcurrent.begin());

		for(double next : ncurrent) {
			int kindex = 0;
			for(kindex = 0; kindex < kcurrent.size(); kindex++) {
				if(kcurrent[kindex] > next) {
					break;
				}
			}
			if(kindex == kcurrent.size()) {				
				war++;
				kcurrent.erase(kcurrent.begin());
			} else {
				
				kcurrent.erase(kcurrent.begin() + kindex);
			}
		}

		sort(n.begin(), n.end(), descendFunction);
		sort(k.begin(), k.end(), descendFunction);
		
		for(int nindex = 0; nindex < n.size(); nindex++) {
			int kindex = 0;
			for(kindex = 0; kindex < k.size(); kindex++) {
				if(n[nindex] > k[kindex]) {
					dwar++;
					//cout << n[nindex] << " " << k[kindex] << endl;
					break;
				}
			}
			if(kindex == k.size()) {
				break;
			} else {
				//cout << n[nindex] << " " << kindex << endl;
				k.erase(k.begin(), k.begin() + kindex + 1);
			}
		}

		fout << "Case #" << caseNumber << ": " << dwar << " " << war << endl;
	}

	fin.close();
	fout.close();
}