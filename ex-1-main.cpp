#include <iostream>
#include <iomanip>

#define CPP2_PRIME_UPPER_LIMIT 10000000 //探索する値の上限値。

/* --------------------------------------------------------------- */
/*
* nth_prime
*
* 与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
* 素数を返す。
*
* TODO: この nth_prime 関数を実装せよ。必要であれば他に関数や
* ファイルを作成せよ。
*/
/* -------------------------------------------------------------- */

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
    int x;

	int count = 0;

    for (int i = 0; i < CPP2_PRIME_UPPER_LIMIT; i++) {
        x = a + i*d;

        if (sosu(x)) {
            count++;
        }

        if (count == n) {
            return x;
        }
    }

    return 0;
}

void show_prime(unsigned int a, unsigned int d, unsigned int n, unsigned int ans) {
    int whd = 10;

    int prime = nth_prime(a, d, n);

    if (prime == ans)
    {
        std::cout << std::setw(whd) << "正解です。" << std::endl;
        std::cout << std::setw(whd) << "計算結果と問題の答えは " << std::endl;
        std::cout << prime << " です。" << std::endl << std::endl;
    }
    else
    {
        std::cout << std::setw(whd) << "不正解です。" << std::endl;
        std::cout << std::setw(whd) << "計算結果は " << std::endl;
        std::cout << prime << " です。" << std::endl;
        std::cout << std::setw(whd) << "問題の答えは " << std::endl;
        std::cout << ans << " です。" << std::endl << std::endl;
    }
}

int main() {
	int whd = 10;

    show_prime(367, 186, 151, 92809);

    show_prime(179, 10, 203, 6709);

    show_prime(271, 37, 39, 12037);

    show_prime(103, 230, 1, 103);

    show_prime(27, 104, 185, 93523);

    show_prime(253, 50, 85, 14503);

    show_prime(1, 1, 1, 2);
	
    show_prime(9075, 337, 210, 899429);

    show_prime(307, 24, 79, 5107);

    show_prime(331, 221, 177, 412717);

    show_prime(259, 170, 40, 22699);

    show_prime(269, 58, 102, 25673);

	std::cin.get();
	return 0;
}
