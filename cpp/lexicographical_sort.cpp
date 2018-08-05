#include <map>
#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int digits(int number) {
    int digits = 0;
    if (number < 0) {
        digits = 1;
    }
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

int intPower(int number, int n) {
    int result = 1;
    while (n--) {
        result *= number;
    }
    return result;
}

int nth(int number, int n) {
    int len = digits(number);
    return (number / intPower(10, len - n)) % 10;
}

int add_zeros(int number, int n) {
    int length = digits(number);
    while (length++ < n) {
        number *= 10;
    }
    return number;
}

int cmp(int a, int b) {
    int len_a = digits(a);
    int len_b = digits(b);
    if (len_a < len_b) {
        a = add_zeros(a, len_b);
    } else if (len_b < len_a) {
        b = add_zeros(b, len_a);
    }
    
    int n = digits(a);
    for (int i = 0; i < n; i++) {
        int nth_a = nth(a, i + 1), nth_b = nth(b, i + 1);
        if (nth_a < nth_b) {
            return -1;
        } else if (nth_a > nth_b) {
            return 1;
        }
    }
    return 0;
}

void sort(int* arr, int n)
{
    int min, min_i, i, j, tmp;
    for (i = 0; i < n; i++) {
        min = *(arr + i);
        min_i = i;
        for (j = i + 1; j < n; j++) {
            if (cmp(*(arr + j), min) <= 0) {
                min = *(arr + j);
                min_i = j;
            }
        }
        tmp = *(arr + i);
        *(arr + i) = *(arr + min_i);
        *(arr + min_i) = tmp;
    }
}

int main()
{
    int arr[] = {71, 76, 705, 4, 3, 2, 1};
    sort(arr, 7);
    for (int i = 0; i < 7; i++) {
         cout << arr[i] << endl;
    }
    return 0;
}
