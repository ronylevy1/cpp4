//Roniki04@gmail.com
#include <iostream>

class MyComplex {
private:
    double real; // Real part
    double imag; // Imaginary part

public:
    MyComplex() : real(0), imag(0) {} // Default constructor

    MyComplex(double real, double imag) : real(real), imag(imag) {} // Constructor

    MyComplex(const MyComplex& other) : real(other.real), imag(other.imag) {} // Copy constructor

    double getReal() const { 
        return real;  // Return the real part
    }
    double getImag() const {
        return imag; // Return the imaginary part
    }

    MyComplex& operator=(const MyComplex& other) {
        if (this != &other) { // If the objects are not the same
            real = other.real; // Copy the real part
            imag = other.imag; // Copy the imaginary part
        }
        return *this;
    }

    MyComplex operator+(const MyComplex& other) const {
        return MyComplex(real + other.real, imag + other.imag); // Return the sum of the two complex numbers
    }

    MyComplex operator-(const MyComplex& other) const {
        return MyComplex(real - other.real, imag - other.imag); // Return the difference of the two complex numbers
    }

    MyComplex operator*(const MyComplex& other) const {
        return MyComplex(real * other.real - imag * other.imag, real * other.imag + imag * other.real); // Return the product of the two complex numbers
    }

    MyComplex operator/(const MyComplex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag; // Calculate the denominator
        return MyComplex((real * other.real + imag * other.imag) / denominator, 
                       (imag * other.real - real * other.imag) / denominator);
    }

    bool operator==(const MyComplex& other) const {
        return real == other.real && imag == other.imag; // Return true if the real and imaginary parts are equal
    }

    bool operator!=(const MyComplex& other) const {
        return !(*this == other); 
    }  

    // implement the operator<
    bool operator>(const MyComplex& other) const {
        return real > other.real || (real == other.real && imag > other.imag);
    } 

    friend std::ostream& operator<<(std::ostream& os, const MyComplex& c) { 
    // Print the real part
    if (c.real == static_cast<int>(c.real)) { 
        os << static_cast<int>(c.real);
    } else {
        os << c.real;
    }

    // Print the imaginary part with sign
    if (c.imag >= 0) {
        os << "+";
    }
    if (c.imag == static_cast<int>(c.imag)) {
        os << static_cast<int>(c.imag);
    } else {
        os << c.imag;
    }
    os << "i"; // Print the imaginary unit

    return os;
}
};