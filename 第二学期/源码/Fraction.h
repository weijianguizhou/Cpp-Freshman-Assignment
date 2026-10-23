class Fraction {
private:
    int numerator;
    int denominator;
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
public:
    Fraction(int x = 0, int y = 1) : numerator(x), denominator(y) {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        if (numerator == 0) {
            denominator = 1;
        } else {
            int d = gcd(abs(numerator), abs(denominator));
            numerator /= d;
            denominator /= d;
        }
    }
    void show(){
        cout<<numerator<<"/"<<denominator<<endl;
    }
}; 

