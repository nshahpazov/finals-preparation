#include <iostream>
#include <math.h>

using namespace std;

const int MAX_POLYNOMIAL_SIZE = 256;

template <typename T>
class Polynomial
{
public:
    Polynomial();
    Polynomial(int, T arr[]);
    Polynomial(const Polynomial<T>&);

    Polynomial<T>& operator=(const Polynomial<T>&);
    bool operator==(const Polynomial<T>&);
    bool operator!=(const Polynomial<T>&);

    T operator()(const T) const;

    Polynomial<T> operator+(const Polynomial<T>&);
    Polynomial<T> operator-(const Polynomial<T>&);

    Polynomial<T> operator--(int);

    T& operator[](const int);

    void setDegree(int);

    int degree() const;
    void print() const;

private:
    int power;
    T coefficients[MAX_POLYNOMIAL_SIZE];
};

template <typename T>
Polynomial<T>::Polynomial()
{
    power = 0;
}

template <typename T>
Polynomial<T>::Polynomial(int n, T arr[])
{
    power = n;
    for (int i = 0; i < n; i++) {
        coefficients[i] = arr[i];
    }
}

template <typename T>
Polynomial<T>::Polynomial(const Polynomial& other)
{
    setDegree(other.degree());
    for (int i = 0; i < other.degree(); i++) {
        coefficients[i] = other.coefficients[i];
    }
}

template <typename T>
Polynomial<T>& Polynomial<T>::operator=(const Polynomial& other)
{
    if (this != &other) {
        setDegree(other.degree());
        for (int i = 0; i < other.degree(); i++) {
            coefficients[i] = other.coefficients[i];
        }
    }
    return *this;
}

template <typename T>
bool Polynomial<T>::operator==(const Polynomial<T>& other)
{
    if (power != other.power) {
        return false;
    }
    for (int i = 0; i < power; i++) {
        if (coefficients[i] != other.coefficients[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool Polynomial<T>::operator!=(const Polynomial<T>& other)

{
    return !(*this == other);
}

template <typename T>
T Polynomial<T>::operator()(const T x) const
{
    T result = coefficients[0];
    for (int i = 1; i < power; i++) {
        result += coefficients[i] * pow(x, i);
    }
    return result;
}

template <typename T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T>& other)
{
    int n = max(power, other.degree());
    Polynomial<T> *result = new Polynomial<T>();
    result->setDegree(n);
    
    for (int i = 0; i < n; i++) {
        (*result)[i] = other.coefficients[i] + coefficients[i];
    }
    return *result;
}

template <typename T>
Polynomial<T> Polynomial<T>::operator-(const Polynomial<T>& other)
{
    int n = max(power, other.degree());
    Polynomial<T> *result = new Polynomial<T>();
    result->setDegree(n);
    
    for (int i = 0; i < n; i++) {
        (*result)[i] = other.coefficients[i] - coefficients[i];
    }
    return *result;
}

template <typename T>
Polynomial<T> Polynomial<T>::operator--(int n)
{
    for (int i = 0; i < power - 1; i++) {
        coefficients[i] = coefficients[i + 1];
        coefficients[i] *= (i + 1);
    }
    power--;
    return *this;
}

template <typename T>
T& Polynomial<T>::operator[](const int index)
{
    if (index > degree()) {
        throw runtime_error("The polynomial is of a lower degree");
    }
    return coefficients[index];
}

template <typename T>
void Polynomial<T>::setDegree(int n)
{
    power = n;
}

template <typename T>
int Polynomial<T>::degree() const
{
    return power;
}

template <typename T>
void Polynomial<T>::print() const
{
    if (degree() == 0) {
        cout << 0;
        return;
    }
    cout << coefficients[0];
    for (int i = 1; i < degree(); i++) {
        if (coefficients[i] != 0) {
            cout << "+";
            cout << coefficients[i] << "x^" << i;
        }
    }
    cout << endl;
}

int main()
{
    int arr1[4] = {1, 2, 3, 4};
    Polynomial<int> *poly1 = new Polynomial<int>(4, arr1);
    poly1->print();

    // testing derivative
    (*poly1)--;
    poly1->print();
    
    int arr2[3] = {7, 8, 2};
    Polynomial<int> *poly2 = new Polynomial<int>(3, arr2);
    poly2->print();

    // testing the predefined [] operator
    cout << (*poly1)[2] << endl;
    
    // testing the evaluation of a polynomial
     cout << (*poly1)(2) << endl;
    
    // testing +,- operator
    Polynomial<int> poly3 = *poly1 - *poly2;
    poly3.print();
    
    // testing ==
    bool are_equal = (*poly1) == (*poly1);
    cout << (are_equal ? "yes" : "no") << endl;
    
    return 0;
}

