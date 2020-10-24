#ifndef OOP_EXERCISE_02_COMPLEX_H
#define OOP_EXERCISE_02_COMPLEX_H

#include <iostream>

class TComplex {
    public:
        float radius;
        float angle;

        TComplex(float r, float a);

        friend TComplex operator*(const TComplex& a, const TComplex& b);
        friend TComplex operator/(const TComplex& a, const TComplex& b);
        friend TComplex operator+(const TComplex& a, const TComplex& b);
        friend TComplex operator-(const TComplex& a, const TComplex& b);
        friend bool operator==(const TComplex& a, const TComplex& b);
        friend bool operator!=(const TComplex& a, const TComplex& b);
        friend bool operator<(const TComplex& a, const TComplex& b);
        friend bool operator>(const TComplex& a, const TComplex& b);
        friend bool operator<=(const TComplex& a, const TComplex& b);
        friend bool operator>=(const TComplex& a, const TComplex& b);
        friend std::ostream &operator<<(std::ostream &os, const TComplex& a);
        
        friend bool Equ(const TComplex& a, const TComplex& b);
        friend bool Conj(const TComplex& a, const TComplex& b);
};

    TComplex operator*(const TComplex& a, const TComplex& b);
    TComplex operator/(const TComplex& a, const TComplex& b);
    TComplex operator+(const TComplex& a, const TComplex& b);
    TComplex operator-(const TComplex& a, const TComplex& b);
    bool operator==(const TComplex& a, const TComplex& b);
    bool operator!=(const TComplex& a, const TComplex& b);
    bool operator<(const TComplex& a, const TComplex& b);
    bool operator>(const TComplex& a, const TComplex& b);
    bool operator<=(const TComplex& a, const TComplex& b);
    bool operator>=(const TComplex& a, const TComplex& b);
    std::ostream &operator<<(std::ostream &os, const TComplex& a);

    bool Equ(const TComplex& a, const TComplex& b);
    bool Conj(const TComplex& a, const TComplex& b);

    TComplex operator"" _complex(const char* str, size_t s);

    float ToImaginary(const float& radius, const float& angle);
    float ToReal(const float& radius, const float& angle);
    float ToRadius(const float& real, const float& imaginary);
    float ToAngle(const float& radius, const float& imaginary);
    bool FloatEqu(const float& a, const float& b);

#endif //OOP_EXERCISE_02_COMPLEX_H 