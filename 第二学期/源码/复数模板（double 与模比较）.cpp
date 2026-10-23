#include <cmath>
#include <iostream>
using namespace std;

template <typename T>
class Complex {
private:
    T real;
    T imag;

public:
    Complex(T r = 0, T i = 0) : real(r), imag(i) {}

    T modulus() const {
        return sqrt(real * real + imag * imag);
    }

    // 运算符重载的形参用 const 引用，临时对象（如 c1+c2 的结果）才能继续参与运算
    Complex<T> operator+(const Complex<T>& c) const {
        return Complex<T>(real + c.real, imag + c.imag);
    }

    Complex<T> operator-(const Complex<T>& c) const {
        return Complex<T>(real - c.real, imag - c.imag);
    }

    Complex<T> operator*(const Complex<T>& c) const {
        return Complex<T>(real * c.real - imag * c.imag, real * c.imag + c.real * imag);
    }

    Complex<T> operator/(const Complex<T>& c) const {
        return Complex<T>((real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag),
                          (imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag));
    }

    bool operator<(const Complex<T>& c) const {
        return ((real * real + imag * imag) < (c.real * c.real + c.imag * c.imag));
    }

    bool operator==(const Complex<T>& c) const {
        return ((real * real + imag * imag) == (c.real * c.real + c.imag * c.imag));
    }

    bool operator>(const Complex<T>& c) const {
        return ((real * real + imag * imag) > (c.real * c.real + c.imag * c.imag));
    }

    friend ostream& operator<<(ostream& os, const Complex<T>& c) {
        if (c.imag > 0) {
            os << c.real << " " << "+" << " " << c.imag << "i";
            return os;
        }
        if (c.imag < 0) {
            os << c.real << " " << "-" << " " << (-c.imag) << "i";
            return os;
        }
        os << c.real;
        return os;
    }

    friend istream& operator>>(istream& is, Complex<T>& c) {
        is >> c.real >> c.imag;
        return is;
    }
};

int main() {
    Complex<double> c1, c2;
    cin >> c1 >> c2;
    cout << c1 << '\n' << c2 << endl;
    cout << c1.modulus() << '\n' << c2.modulus() << endl; // 模的输出
    if (c1 > c2) cout << c1 + c2 << endl;
    else cout << c1 * c2 << endl;
    return 0;
}
