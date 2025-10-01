#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

void fillArray(int* matrix, int n, int corner)
{
    int value = 1;

    for (int diag = 0; diag < 2 * n - 1; diag++)
    {
        switch (corner)
        {
        case 1: // top-left
            if (diag % 2 == 0)
            {
                for (int i = 0; i <= diag; i++)
                {
                    int j = diag - i;
                    if (i < n && j < n) matrix[i * n + j] = value++;
                }
            }
            else
            {
                for (int i = diag; i >= 0; i--)
                {
                    int j = diag - i;
                    if (i < n && j < n) matrix[i * n + j] = value++;
                }
            }
            break;

        case 2: // top-right
            if (diag % 2 == 0)
            {
                for (int i = 0; i <= diag; i++)
                {
                    int j = diag - i;
                    if (i < n && j < n) matrix[i * n + (n - 1 - j)] = value++;
                }
            }
            else
            {
                for (int i = diag; i >= 0; i--)
                {
                    int j = diag - i;
                    if (i < n && j < n) matrix[i * n + (n - 1 - j)] = value++;
                }
            }
            break;

        case 3: // bot-left
            if (diag % 2 == 0)
            {
                for (int i = 0; i <= diag; i++)
                {
                    int j = diag - i;
                    if (i < n && j < n) matrix[(n - 1 - i) * n + j] = value++;
                }
            }
            else
            {
                for (int i = diag; i >= 0; i--)
                {
                    int j = diag - i;
                    if (i < n && j < n) matrix[(n - 1 - i) * n + j] = value++;
                }
            }
            break;

        case 4: // bot-right
            if (diag % 2 == 0)
            {
                for (int i = 0; i <= diag; i++)
                {
                    int j = diag - i;
                    if (i < n && j < n) matrix[(n - 1 - i) * n + (n - 1 - j)] = value++;
                }
            }
            else
            {
                for (int i = diag; i >= 0; i--)
                {
                    int j = diag - i;
                    if (i < n && j < n) matrix[(n - 1 - i) * n + (n - 1 - j)] = value++;
                }
            }
            break;
        }
    }
}

void printMatrix(int* matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i * n + j] << "\t";
        }
        cout << endl;
    }
}

void saveToFile(int* matrix, int n)
{
    ofstream file("output.txt");
    if (file.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                file << matrix[i * n + j] << "\t";
            }
            file << endl;
        }
        file.close();
        cout << "Массив сохранен в файл output.txt\n";
    }
    else
    {
        cout << "Ошибка открытия файла!\n";
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n;
    cout << "Введите число N: ";
    cin >> n;
    if (n > 300)
    {
        cout << endl << "НЕТ!";
        return 0;
    }

    int corner;
    cout << "Выберите начальный угол:\n";
    cout << "1 - Верхний левый\n";
    cout << "2 - Верхний правый\n";
    cout << "3 - Нижний левый\n";
    cout << "4 - Нижний правый\n";
    cout << "Ваш выбор: ";
    cin >> corner;

    int* matrix = new int[n * n];

    fillArray(matrix, n, corner);

    cout << "\nПолученная матрица:" << endl;
    printMatrix(matrix, n);

    saveToFile(matrix, n);

    delete[] matrix;
    return 0;
}
