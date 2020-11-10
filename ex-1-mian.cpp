#incude <iostream>
#incude <iomanip>

#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。

/*--------------------------------------------------------*/
/*
 *nth_prime
 *
 * 与えられた正整数aとdとnに対して、この等差数列に含まれる
 * n番目の素数を返す。
 *
 * TODO: このnth_prime関数を実装せよ。必要であれば
 * 他に関数やファイルを作成せよ。
 *
 */
/*--------------------------------------------------------*/

bool sosu(unsigned int x) {
	if(x < 2) {
		return 0;
	}

	if(x == 2) {
		return 1;
	}

	for(unsigned int i = 2; i*i <= x; i++) {
		if(x%i == 0) {
			return 0;
		}
	}

	return 1;
}

int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	unsigned int x;

	unsigned int count = 0;

	for(int i = 0;i < CPP2_PRIME_UPPER_LIMIT; i++) {
		x = a + d*i;

		if(sosu(x)) {
			count++;
		}

		if(count == n) {
			return x;
		}
	}

	return 0;
}

int main() {
	int whd = 5;

	std::cout << std::setw(whd * 4) << "367 186 151" << std::endl;
	std::cout << std::setw(whd * 2) << nth_prime(367, 186, 151);
	std::cout << std::setw(whd * 2) << "92809" << std::endl << std::endl;

	std::cout << std::setw(whd * 4) << "179 10 203" << std::endl;
        std::cout << std::setw(whd * 2) << nth_prime(367, 10, 203);
        std::cout << std::setw(whd * 2) << "6709" << std::endl << std::endl;

	std::cout << std::setw(whd * 4) << "271 37 39" << std::endl;
        std::cout << std::setw(whd * 2) << nth_prime(271, 37, 39);
        std::cout << std::setw(whd * 2) << "12037" << std::endl << std::endl;

	std::cout << std::setw(whd * 4) << "103 230 1" << std::endl;
        std::cout << std::setw(whd * 2) << nth_prime(103, 230, 1);
        std::cout << std::setw(whd * 2) << "103" << std::endl << std::endl;

        std::cout << std::setw(whd * 4) << "27 104 185" << std::endl;
        std::cout << std::setw(whd * 2) << nth_prime(27, 104, 185);
        std::cout << std::setw(whd * 2) << "93523" << std::endl << std::endl;

	std::cout << std::setw(whd * 4) << "253 50 85" << std::endl;
        std::cout << std::setw(whd * 2) << nth_prime(253, 50, 85);
        std::cout << std::setw(whd * 2) << "14503" << std::endl << std::endl;

        std::cout << std::setw(whd * 4) << "1 1 1" << std::endl;
        std::cout << std::setw(whd * 2) << nth_prime(1, 1, 1);
        std::cout << std::setw(whd * 2) << "2" << std::endl << std::endl;

        std::cout << std::setw(whd * 4) << "9075 337 210" << std::endl;
        std::cout << std::setw(whd * 2) << nth_prime(9075, 337, 210);
        std::cout << std::setw(whd * 2) << "899429" << std::endl << std::endl;

	std::cout << std::setw(whd * 4) << "307 24 79" << std::endl;
        std::cout << std::setw(whd * 2) << nth_prime(307, 24, 79);
        std::cout << std::setw(whd * 2) << "5107" << std::endl << std::endl;

        std::cout << std::setw(whd * 4) << "331 221 177" << std::endl;
        std::cout << std::setw(whd * 2) << nth_prime(331, 221, 177);
        std::cout << std::setw(whd * 2) << "412717" << std::endl << std::endl;

        std::cout << std::setw(whd * 4) << "259 170 40" << std::endl;
        std::cout << std::setw(whd * 2) << nth_prime(259, 170, 40);
        std::cout << std::setw(whd * 2) << "22699" << std::endl << std::endl;

        std::cout << std::setw(whd * 4) << "" << std::endl;
        std::cout << std::setw(whd * 2) << nth_prime(269, 58, 102);
        std::cout << std::setw(whd * 2) << "25673" << std::endl << std::endl;



	std::cin.get();
	return 0;
}
