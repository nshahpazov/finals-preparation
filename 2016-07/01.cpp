#include <map>
#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <utility>
#include <math.h>
#include <string.h>

using namespace std;

/*
 Задача 1 .
 Дадена е квадратна матрица от дробни числа с размерност 11×11.Казваме,че два елемента на матрицата са симетрични , ако те са разположени симетрично относно (1) главния диагонал, (2) вторичния диагонал, или (3) пресечната точка на двата диагонала на матрицата. На всеки елемент от матрицата съответстват най­много три симетрични елемента. С ъвкупност, състояща се от елемент на матрицата заедно с всички негови симетрични елементи, наричаме симетрична група.
 
 
 Да се състави функция, която променя матрицата така, че в всеки елемент   от матрицата се заменя със средно­аритметичната стойност на елементите в неговата симетрична група.
*/

const int n = 3;
bool marked[n][n];
double a[n][n];

void transform()
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int factor = i == j ? 2 : 3;
            if (!marked[i][j]) {
                double result = a[i][j] + a[n - j - 1][n - i - 1];
                result += (i != j) ? a[j][i] : 0;
                
                a[i][j] = a[j][i] = a[n - j - 1][n-i - 1] = result / factor;
                marked[i][j] = marked[j][i] = marked[n - j - 1][n - i - 1] = true;
            }
        }
    }
}

int main()
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    transform();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << ", ";
        }
        cout << endl;
    }
    return 0;
}
