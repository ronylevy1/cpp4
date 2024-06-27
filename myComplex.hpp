//Roniki04@gmail.com
#include <iostream>

class MyComplex {
private:
    double real;
    double imag;

public:
    // קונסטרקטור ברירת מחדל
    MyComplex() : real(0), imag(0) {}

    // קונסטרקטור עם פרמטרים
    MyComplex(double real, double imag) : real(real), imag(imag) {}

    // קונסטרקטור העתקה
    MyComplex(const MyComplex& other) : real(other.real), imag(other.imag) {}

    // גטרים
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // אופרטור השמה
    MyComplex& operator=(const MyComplex& other) {
        if (this != &other) {
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }

    // אופרטור חיבור
    MyComplex operator+(const MyComplex& other) const {
        return MyComplex(real + other.real, imag + other.imag);
    }

    // אופרטור חיסור
    MyComplex operator-(const MyComplex& other) const {
        return MyComplex(real - other.real, imag - other.imag);
    }

    // אופרטור כפל
    MyComplex operator*(const MyComplex& other) const {
        return MyComplex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // אופרטור חילוק
    MyComplex operator/(const MyComplex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return MyComplex((real * other.real + imag * other.imag) / denominator, 
                       (imag * other.real - real * other.imag) / denominator);
    }

    // אופרטור השוואה
    bool operator==(const MyComplex& other) const {
        return real == other.real && imag == other.imag;
    }

    bool operator!=(const MyComplex& other) const {
        return !(*this == other);
    }

        friend std::ostream& operator<<(std::ostream& os, const MyComplex& c) {
        // פונקציה פנימית לעיצוב מספרים
        auto printFormatted = [](std::ostream& os, double value) {
            if (value == static_cast<int>(value)) {
                os << static_cast<int>(value);
            } else {
                os << value;
            }
        };

        printFormatted(os, c.real);
        if (c.imag >= 0) {
            os << "+";
        }
        printFormatted(os, c.imag);
        os << "i";
        
        return os;
    }
};