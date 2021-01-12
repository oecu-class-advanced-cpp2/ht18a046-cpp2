#include <iostream>
#include <string>
#include <sstream>

namespace cpp2 {
    /*---------------------------------------------*/
    /*
    * mxci
    * 
    * mcxi記法を解析するクラスです。
    * 
    * mcxiの数値と文字の対応表
    * m : 1000
    * c :  100
    * x :   10
    * i :    1
    * 
    * 有効数字
    * 2から9まで
    * 
    * mcxiの文字は一つの文字列にそれぞれ一つまで
    * 
    * 指定された文字列を解析して、オブジェクトを初期化します。
    * 以下の場合には例外が創出されます。
    * 
    * 1.[2 - 9, m, c, x, i] 以外の文字が出現した場合
    * 2. 2 文字続けて数字(2 - 9) が出現した場合
    * 3. m, c, x, i がこの順序で出現しなかった場合
    * ただし、例えば mx のように、特定の文字をスキップする事は許容されます。
    */
    /*---------------------------------------------*/
    class mcxi
    {
    private:
        //mcxiの数値を格納する変数
        int value_;

    public:
        //mcxiのコンストラクタを定義
        mcxi(const std::string& s);//コンストラクタ

        int trans(char c);

        int tacit(int digit, int num);

        //メソッド同士の足し算を定義
        friend mcxi operator+(mcxi a, mcxi b);//例：a0＋b0の計算

        int getvalue_() { return value_; }

        int setvalue_(mcxi a, mcxi b);

        //mcxiの計算結果をstringに直すモノを定義
        std::string to_string() const;
    };

    mcxi::mcxi(const std::string& s) : value_(0)
    {
        int digit = 0;
        int unit = 0;
        int before_unit = 0;
        int count_NUM = 0;
        int count_MCXI = 0;

        for (auto pos = s.begin(); pos != s.end(); pos++) {
            if (*pos >= '2' && *pos <= '9')
            {
                if (digit == 0)
                {
                    digit = *pos - '0';
                }
                else
                {
                    //重複した数値を弾く為のカウント
                    count_NUM++;
                }
            }
            else
            {
                unit = trans(*pos);
                if (value_ == 0 || before_unit > unit)
                {
                    before_unit = unit;
                    value_ += tacit(digit, 1)*unit;
                }
                else
                {
                    //重複した文字と順序が乱れた文字を弾く為のカウント
                    count_MCXI++;
                }
                digit = 0;
            }
        }

        if (count_NUM != 0 || count_MCXI != 0)
        {
            value_ = 0;
        }
    }

    int mcxi::trans(char c)
    {
        switch (c)
        {
        case 'm':
            return 1000;
            break;
        case 'c':
            return 100;
            break;
        case 'x':
            return 10;
            break;
        case 'i':
            return 1;
            break;
        default:
            break;
        }

        return 0;
    }

    int mcxi::tacit(int digit, int num)
    {
        if (digit >= 2 && digit <= 9)
        {
            return digit;
        }
        else
        {
            return num;
        }

        return 0;
    }

    mcxi operator+(mcxi a, mcxi b)
    {
        cpp2::mcxi result("");

        result.setvalue_(a, b);

        return result;
    }

    int mcxi::setvalue_(mcxi a, mcxi b)
    {
        value_ = a.getvalue_() + b.getvalue_();

        return value_;
    }

    std::string mcxi::to_string() const
    {
        std::stringstream key;

        int m = value_ / 1000;
        int c = value_ / 100 - m * 10;
        int x = value_ / 10 - (m * 100 + c * 10);
        int i = value_ / 1 - (m * 1000 + c * 100 + x * 10);

        if (m == 1) {
            key << 'm';
        }

        if (m > 1) {
            key << m;
            key << 'm';
        }

        if (c == 1) {
            key << 'c';
        }

        if (c > 1) {
            key << c;
            key << 'c';
        }

        if (x == 1) {
            key << 'x';
        }

        if (x > 1) {
            key << x;
            key << 'x';
        }

        if (i == 1) {
            key << 'i';
        }

        if (i > 1) {
            key << i;
            key << 'i';
        }

        return key.str();
    }
} //namespace cpp2


int main() {
    std::cout << "番号 答 計算結果" << std::endl;

    cpp2::mcxi a0("xi");
    cpp2::mcxi b0("x9i");
    cpp2::mcxi result0 = a0 + b0;
    std::cout << "No.0 " << "3x" << " " << result0.to_string() << std::endl;

    cpp2::mcxi a1("i");
    cpp2::mcxi b1("9i");
    cpp2::mcxi result1 = a1 + b1;
    std::cout << "No.1 " << "x" << " " << result1.to_string() << std::endl;
    
    cpp2::mcxi a2("c2x2i");
    cpp2::mcxi b2("4c8x8i");
    cpp2::mcxi result2 = a2 + b2;
    std::cout << "No.2 " << "6cx" << " " << result2.to_string() << std::endl;
    
    cpp2::mcxi a3("m2ci");
    cpp2::mcxi b3("4m7c9x8i");
    cpp2::mcxi result3 = a3 + b3;
    std::cout << "No.3 " << "5m9c9x9i" << " " << result3.to_string() << std::endl;

    cpp2::mcxi a4("9c9x9i");
    cpp2::mcxi b4("i");
    cpp2::mcxi result4 = a4 + b4;
    std::cout << "No.4 " << "m" << " " << result4.to_string() << std::endl;

    cpp2::mcxi a5("i");
    cpp2::mcxi b5("9m9c9x8i");
    cpp2::mcxi result5 = a5 + b5;
    std::cout << "No.5 " << "9m9c9x9i" << " " << result5.to_string() << std::endl;

    cpp2::mcxi a6("m");
    cpp2::mcxi b6("i");
    cpp2::mcxi result6 = a6 + b6;
    std::cout << "No.6 " << "mi" << " " << result6.to_string() << std::endl;

    cpp2::mcxi a7("i");
    cpp2::mcxi b7("m");
    cpp2::mcxi result7 = a7 + b7;
    std::cout << "No.7 " << "mi" << " " << result7.to_string() << std::endl;

    cpp2::mcxi a8("m9i");
    cpp2::mcxi b8("i");
    cpp2::mcxi result8 = a8 + b8;
    std::cout << "No.8 " << "mx" << " " << result8.to_string() << std::endl;

    cpp2::mcxi a9("9m8c7xi");
    cpp2::mcxi b9("c2x8i");
    cpp2::mcxi result9 = a9 + b9;
    std::cout << "No.9 " << "9m9c9x9i" << " " << result9.to_string() << std::endl;

    cpp2::mcxi a10("m284i");
    cpp2::mcxi b10("mmccccxxi");
    cpp2::mcxi c10("cixmcicx");

    std::cin.get();
    return 0;
}
