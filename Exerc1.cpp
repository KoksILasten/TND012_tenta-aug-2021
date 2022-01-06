//=======================================================
// TND012, exam: Exercise 1
// Name: Magnus Kling
// Personal number: 0012011151
// LiU-id: Magkl572
//=======================================================
// Write your name, personal number, and LiU-id

/* Input:
 0 220 56 66928 -777 777 1184 63020 5566 2620 1111 6368 -6666 12285 9876 10744 17296 8853 76084 6232 STOP
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

std::vector<int> read() {
	std::vector<int> list;
	int i = 0;
	while (std::cin >> i) {
		if (i <= 0) {
			continue;
		}
		list.push_back(i);
	}
	return list;
}

int cal_div_sums(int s) {
	int sum = 1;

	for (int i = 0; i < sqrt(s); i++) {
		if (s % i == 0) {
			if (i != (s / i)) {
				sum += (i + s / i);
			}
			else {
				sum += i;
			}
		}
	}
	return sum;
}

void display(std::vector<int>& List) {
	std::cout << std::setw(22) << "Bizarre relations"
		<< std::setw(28) << "No bizarre relations\n";


}

int main() {

	std::cout << "Enter the input list:\n";

	std::vector<int> list = read();


}
