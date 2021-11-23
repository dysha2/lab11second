// lab11second.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<thread>
#include <windows.h>
#include <iostream>
#include "lab11second.h"
using namespace std;
int* matric = new int[5, 5];


DWORD CALLBACK loop1(LPVOID lParameter) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 5; i++) {
        matric[0, i] = rand() % 999 + 1;
    }
    return 0;
}
DWORD CALLBACK loop2(LPVOID lParameter) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 5; i++) {
        matric[1, i] = rand() % 999 + 1;
    }
    return 0;
}
DWORD CALLBACK loop3(LPVOID lParameter) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 5; i++) {
        matric[2, i] = rand() % 999 + 1;
    }
    return 0;
}
DWORD CALLBACK loop4(LPVOID lParameter) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 5; i++) {
        matric[3, i] = rand() % 999 + 1;
    }
    return 0;
}
DWORD CALLBACK loop5(LPVOID lParameter) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 5; i++) {
        matric[4, i] = rand() % 999 + 1;
    }
    return 0;
}
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    HANDLE thread1 = CreateThread(NULL, NULL, loop1, NULL, 0, NULL);
    HANDLE thread2 = CreateThread(NULL, NULL, loop2, NULL, 0, NULL);
    HANDLE thread3 = CreateThread(NULL, NULL, loop3, NULL, 0, NULL);
    HANDLE thread4 = CreateThread(NULL, NULL, loop4, NULL, 0, NULL);
    HANDLE thread5 = CreateThread(NULL, NULL, loop5, NULL, 0, NULL);
    Sleep(1000);
    int min=1000, max=0, QuentityOfDoubleDigit=0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matric[i, j] > max) max = matric[i, j];
            if (matric[i, j] < min) min = matric[i, j];
            if ((matric[i, j] > 9)&&(matric[i, j] < 100)) ++QuentityOfDoubleDigit;
            cout << matric[i, j] << " ";
        }
        cout << "\n";
    }
    cout << "\nМаксимальное число = " << max;
    cout << "\nМинимальное число = " << min;
    cout << "\nКол-во двухзначных чисел = " << QuentityOfDoubleDigit;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
