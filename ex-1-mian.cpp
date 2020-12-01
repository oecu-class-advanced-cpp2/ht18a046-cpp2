#include <iostream>
#include <iomanip>

#define CPP2_PRIME_UPPER_LIMIT 10000000 //�T������l�̏���l�B

/* --------------------------------------------------------------- */
/*
* nth_prime
*
* �^����ꂽ������ a �� d �� n �ɑ΂��āA���̓�������Ɋ܂܂�� n �Ԗڂ�
* �f����Ԃ��B
*
* TODO: ���� nth_prime �֐�����������B�K�v�ł���Α��Ɋ֐���
* �t�@�C�����쐬����B
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
        std::cout << std::setw(whd) << "�����ł��B" << std::endl;
        std::cout << std::setw(whd) << "�v�Z���ʂƖ��̓����� " << std::endl;
        std::cout << prime << " �ł��B" << std::endl << std::endl;
    }
    else
    {
        std::cout << std::setw(whd) << "�s�����ł��B" << std::endl;
        std::cout << std::setw(whd) << "�v�Z���ʂ� " << std::endl;
        std::cout << prime << " �ł��B" << std::endl;
        std::cout << std::setw(whd) << "���̓����� " << std::endl;
        std::cout << ans << " �ł��B" << std::endl << std::endl;
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
