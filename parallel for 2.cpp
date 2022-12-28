// parallel for.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <omp.h>
int main()
{
    int id;
    int i = 0;
    int n = 100;
    int idcount=0;
    int cc = 0;
    int c = 0;
    int ccc = 0;
    int size = 0;
    int* a = new int[n];
    int* b = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = 1;
        b[i] = 2;
    }
    printf("Mas a=\n");
    for (int ii = 0; ii < n; ii++) {
        printf("%d ", a[ii]);
    }
    printf("\nMas b=\n");
    for (int ii = 0; ii < n; ii++) {
        printf("%d ", b[ii]);
    }
    printf("\n");
    
    double t2= omp_get_wtime();
#pragma omp parallel for reduction (+:c) 
    for (int p = 0; p < n; p++) {
        c = c + a[p] * b[p];
    }
    double t3= omp_get_wtime();
    printf("\n total: %d", c);
    printf("\n Reduction time: %f", t3 - t2);
    for (int h = 0; h < n; h++) {
        ccc = ccc + a[h] * b[h];
    }
    double t4= omp_get_wtime();
    printf("\n total: %d", ccc);
    printf("\n Serial time: %f", t4 - t3);
    
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
