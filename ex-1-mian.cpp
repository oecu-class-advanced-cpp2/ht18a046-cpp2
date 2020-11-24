#include <iostream>
#include <iomanip>
#include <cstring>

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

template<class T>
T nth_prime(T a, T d, T n) {
    unsigned int x;

	unsigned int count = 0;

    try
    {
        if (typeid(a).name() != typeid(x).name()) {
            throw "a�̒l�͐��l�ł͂���܂���B";
        }
        if (typeid(d).name() != typeid(x).name()) {
            throw "d�̒l�͐��l�ł͂���܂���B";
        }
        if (typeid(n).name() != typeid(x).name()) {
            throw "n�̒l�͐��l�ł͂���܂���B";
        }

        for (int i = 0; i < CPP2_PRIME_UPPER_LIMIT; i++) {
            x = a + i*d;

            if (sosu(x)) {
                count++;
            }

            if (typeid(n).name() != typeid(x).name() && count == n) {
                return x;
            }
        }
    }
    catch (char* err)
    {
        return err;
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

	std::cout << std::setw(whd * 4) << "269 58 102" << std::endl;
	std::cout << std::setw(whd * 2) << nth_prime(269, 58, 102);
    std::cout << std::setw(whd * 2) << "25673" << std::endl << std::endl;

    std::cout << std::setw(whd * 4) << "a b c" << std::endl;
    std::cout << std::setw(whd * 2) << nth_prime("a", "b", "c");
    std::cout << std::setw(whd * 2) << "��O�̏���" << std::endl << std::endl;


	std::cin.get();
	return 0;
}
