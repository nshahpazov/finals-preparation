#include <iostream>
#include <string.h>

using namespace std;

/*
Даден е символен низ с дължина n, съдържащ само малки латински букви. Напишете функция void check(const char* str), която проверява дали съществува позиция в низа, такава че, ако се започне четене от тази позиция и четенето продължи до края и след това (при необходимост) циклично се прехвърли в началото на низа, може да се прочете палиндром с дължина равна на n (дължината на входния низ). Ако такава позиция съществува, функцията да извежда на екрана нейния номер и намереният палиндром, ограден в кръгли скоби. Ако такава позиция не съществува, функцията да извежда на екрана текста "NO".
Примери:
Вход: orrobborrow
Вход: borroworrob Вход: booo
Изход: 5 (borroworrob) Изход: 0 (borroworrob) Изход: NO
*/

bool is_palindrome(const char* str)
{
    size_t len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

char* swap(const char* str, const int separator)
{
    char* result = new char[strlen(str)];
    strcpy(result, str);
    size_t len = strlen(str);
    result[separator] = str[separator];
    for (int i = 0; i < len; i++) {
        result[i] = str[(separator + i + 1)%len];
    }
    return result;
}

void check(const char* str)
{
    size_t len = strlen(str);
    char *swapped;

    if (is_palindrome(str)) {
        cout << 0 << "(" << str << ")" << endl;
        return;
    }

    for (int i = 1; i < len; i++) {
        swapped = swap(str, i);
        if (is_palindrome(swapped)) {
            cout << i << "(" << swapped << ")" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main()
{
    check("booo");
    return 0;
}
