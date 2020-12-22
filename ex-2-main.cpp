#include <iostream>
#include <string>

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

        bool judgment(char c);

        int tacit(int digit, int num);

        //メソッド同士の足し算を定義
        //friend mcxi operator+(mcxi a, mcxi b);//例：a0＋b0の計算

        //mcxiの計算結果をstringに直すモノを定義
        //std::string to_string() const;
    };

    mcxi::mcxi(const std::string& s) : value_(0)
    {
        //int digit = *pos - '0';で実行可能

        int digit = 0;
        int unit = 0;
        int count = 0;

        for (auto pos = s.begin(); pos != s.end(); pos++) {
            if (judgment(*pos))
            {
                unit = trans(*pos);
                value_ += tacit(digit, 1)*unit;
                digit = 0;
            }
            else
            {
                if (digit == 0)
                {
                    digit = trans(*pos);
                }
                else
                {
                    count++;
                }
            }
        }

        if (count != 0)
        {
            value_ = 0;
        }

        std::cout << "value_" << value_ << std::endl << std::endl;
    }

    int mcxi::trans(char c)
    {
        switch (c)
        {
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
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

    bool mcxi::judgment(char c)
    {
        switch (c)
        {
        case 'm':
            return true;
            break;
        case 'c':
            return true;
            break;
        case 'x':
            return true;
            break;
        case 'i':
            return true;
            break;
        default:
            break;
        }

        return false;
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

    //mcxi operator+(mcxi a, mcxi b)
    //{
        //mcxi result();

        //result() = a + b;

        //return result();
    //}

    //std::string mcxi::to_string() const{return std::string();}
} //namespace cpp2

int main() {
    cpp2::mcxi a0("xi");
    cpp2::mcxi b0("x9i");
    //cpp2::mcxi result0 = a0 + b0;
    //std::cout<< "3x" << " " << result0.to_string() << std::endl;

    cpp2::mcxi a1("i");
    cpp2::mcxi b1("9i");
    //cpp2::mcxi result1 = a1 + b1;
    //std::cout<< "x" << " " << result1.to_string() << std::endl;
    
    cpp2::mcxi a2("c2x2i");
    cpp2::mcxi b2("4c8x8i");
    //cpp2::mcxi result2 = a2 + b2;
    //std::cout<< "6cx" << " " << result2.to_string() << std::endl;
    
    cpp2::mcxi a3("m2ci");
    cpp2::mcxi b3("4m7c9x8i");
    //cpp2::mcxi result3 = a3 + b3;
    //std::cout<< "5m9c9x9i" << " " << result3.to_string() << std::endl;

    cpp2::mcxi a4("9c9x9i");
    cpp2::mcxi b4("i");
    //cpp2::mcxi result4 = a4 + b4;
    //std::cout<< "m" << " " << result4.to_string() << std::endl;

    cpp2::mcxi a5("i");
    cpp2::mcxi b5("9m9c9x8i");
    //cpp2::mcxi result5 = a5 + b5;
    //std::cout<< "9m9c9x9i" << " " << result5.to_string() << std::endl;

    cpp2::mcxi a6("m");
    cpp2::mcxi b6("i");
    //cpp2::mcxi result6 = a6 + b6;
    //std::cout<< "mi" << " " << result6.to_string() << std::endl;

    cpp2::mcxi a7("i");
    cpp2::mcxi b7("m");
    //cpp2::mcxi result7 = a7 + b7;
    //std::cout<< "mi" << " " << result7.to_string() << std::endl;

    cpp2::mcxi a8("m9i");
    cpp2::mcxi b8("i");
    //cpp2::mcxi result8 = a8 + b8;
    //std::cout<< "mx" << " " << result8.to_string() << std::endl;

    cpp2::mcxi a9("9m8c7xi");
    cpp2::mcxi b9("c2x8i");
    //cpp2::mcxi result9 = a9 + b9;
    //std::cout<< "9m9c9x9i" << " " << result9.to_string() << std::endl;

    cpp2::mcxi a10("25i");

    std::cin.get();
    return 0;
}