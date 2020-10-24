#include "Complex.h"
#include <cmath>
#include <cstring>

TComplex::TComplex(float r, float a) : radius(r), angle(a) {}

TComplex operator*(const TComplex& a, const TComplex& b) {
    float radiusRes;
    float angleRes;
    radiusRes = a.radius * b.radius;
    angleRes = a.angle + b.angle;
    TComplex res(radiusRes, angleRes);
    return(res);
}

TComplex operator/(const TComplex& a, const TComplex& b) {

    float radiusRes;
    float angleRes;
    radiusRes = a.radius / b.radius;
    angleRes = a.angle - b.angle;
    TComplex res(radiusRes, angleRes);
    return(res);
}

TComplex operator+(const TComplex& a, const TComplex& b) {
    float radiusRes;
    float angleRes;
    radiusRes = a.radius + b.radius;
    angleRes = a.angle + b.angle;
    TComplex res(radiusRes, angleRes);
    return(res);
}

TComplex operator-(const TComplex& a, const TComplex& b) {
    float radiusRes;
    float angleRes;
    radiusRes = a.radius - b.radius;
    angleRes = a.angle - b.angle;
    TComplex res(radiusRes, angleRes);
    return(res);
}

bool operator==(const TComplex& a, const TComplex& b) {
    float realA = ToReal(a.radius, a.angle);
    float realB = ToReal(b.radius, b.angle);
    if (FloatEqu(realA, realB)) {
        return(true);
    }
    else return(false);
}

bool operator!=(const TComplex& a, const TComplex& b) {
    return(!(a == b));
}

bool operator<(const TComplex& a, const TComplex& b) {
    float realA = ToReal(a.radius, a.angle);
    float realB = ToReal(b.radius, b.angle);
    if (a == b) {
        return(false);
    }
    else if (realA > realB) {
        return(false);
    } 
    else return(true);
}

bool operator>(const TComplex& a, const TComplex& b) {
    return(!(a < b));  
}

bool operator<=(const TComplex& a, const TComplex& b) {
    if (a == b) {
        return(true);
    }
    else return(a < b);
}

bool operator>=(const TComplex& a, const TComplex& b) {
    if (a == b) {
        return(true);
    }
    else return(a > b);
}

std::ostream &operator<<(std::ostream &os, const TComplex& a) {
    os << "(" << a.radius << " , " << a.angle << ")";
    return(os);
}

bool Equ(const TComplex& a, const TComplex& b) {
    if (FloatEqu(a.radius, b.radius) && FloatEqu(a.angle, b.angle)) {
        return(true);
    }
    else return(false);
}

bool Conj(const TComplex& a, const TComplex& b) {
    float angle = b.angle;
    angle *= (-1);
    if (FloatEqu(a.angle, angle) && (FloatEqu(a.radius, b.radius))) {
        return(true);
    }
    else return(false);
}

TComplex operator"" _complex(const char* str, size_t s) {
    float radius = 0.0;
    float angle = 0.0;
    float del = 0.1;
    bool key1 = false;
    bool key2 = false;
    bool key3 = false;
    for (short i = 0; i < s; ++i) {
        if ((str[i] == ',') || (str[i] == ' ')) {
            key1 = true;
            key2 = false;
            continue;
        }
        else if (str[i] == '.') {
            key2 = true;
            del = 0.1;
            continue;
        }
        else if ((str[i] == '-') && (key1 = true)) {
            key3 = true;
            continue;
        }
        switch(key1) {
            case false:
            switch(key2) {
                case false:
                radius = radius * 10.0 + (float)(str[i] - '0');
                break;
                case true:
                radius = radius + (del * (float)(str[i] - '0'));
                del *= 0.1;
                break;
            }
            break;
            case true:
            switch(key2) {
                case false:
                angle = angle * 10.0 + (float)(str[i] - '0');
                break;
                case true:
                angle = angle + (del * (float)(str[i] - '0'));
                del *= 0.1;
                break;
            }
            break;
        }
    }
    if (key3 == true) {
        angle = -angle;
    }
    TComplex result(radius, angle);
    return(result);
}

float ToReal(const float& radius, const float& angle) {
    float real;
    real = radius * cosf(angle);
    return(real);
}

bool FloatEqu(const float& a, const float& b) {
    float eps = 0.00000001;
    if (fabsf(a - b) <= eps) return(true);
    else return(false);
}
