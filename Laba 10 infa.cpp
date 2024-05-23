#include <iostream>
#include <string>

using namespace std;

int main() {

    setlocale(LC_ALL, "RU");
    system("chcp 1251>nul");

    int n, k;
    cout << "Введите кол-во строк: "; cin >> n;
    cin.ignore(256, '\n'); // Очистка буфера после ввода числа

    string* dynamicArray = new string[n];

    for (int i = 0; i < n; ++i) {
        cout << "Введите " << i + 1 << "-ую строку: "; getline(cin, dynamicArray[i]);
    }


    cout << "Введите кол-во строк для удаления (K): "; cin >> k;

    if (k >= 0 && k <= n) {
        for (int i = k; i < n; ++i) {
            dynamicArray[i - k] = move(dynamicArray[i]);
        }

        for (int i = n - k; i < n; ++i) {
            dynamicArray[i] = "";
        }
    }
    else {
        cout << "Недопустимое значение K. Введите новое: "; cin >> k;
    }

    cout << "Массив после удаления первых " << k << " строк: ";
    for (int i = 0; i < n - k; ++i) {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;

    delete[] dynamicArray;

    system("pause");
    return 0;
}
