// parallel for.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <omp.h>
int main()
{
    int id;
    int i = 0;
    int n = 800000;
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
    /*double t1 = omp_get_wtime();
    #pragma omp parallel  private(id) shared(cc)
    {
    int id = omp_get_thread_num();
    idcount = omp_get_num_threads();
    size = n / idcount;
    for (int j = 0; j < size; j++) {
        cc =cc+ b[j + id * size]*a[j + id * size];
        }
    //printf("%d from %d, ", cc, id);
    }*/
    double t2= omp_get_wtime();
    //printf("\n total: %d", cc);
    //printf("\n time: %f", t2-t1);
#pragma omp parallel for reduction (+:c) 
    for (int p = 0; p < n; p++) {
        c = c + a[p] * b[p];
    }
    double t3= omp_get_wtime();
    printf("\n total: %d", c);
    printf("\n time: %f", t3 - t2);
    for (int h = 0; h < n; h++) {
        ccc = ccc + a[h] * b[h];
    }
    double t4= omp_get_wtime();
    printf("\n total: %d", ccc);
    printf("\n time: %f", t4 - t3);
    /*for (int ii = 0; ii < n; ii++) {
        printf("%d\n ", c[ii]);
    }
    double t2 = omp_get_wtime();
    printf("Time 1=%f\n", t2 - t1);

#pragma omp parallel for
    for (int p = 0; p < n; p++) {
        d[p] = a[p] + b[p];
    }

    for (int jj = 0; jj < n; jj++) {
        printf("%d\n ", d[jj]);
    }
    double t3 = omp_get_wtime();
    printf("Time 2=%f\n", t3 - t2);
    for (int kk = 0; kk < n; kk++) {
        e[kk] = a[kk] + b[kk];
    }
    for (int pp = 0; pp < n; pp++) {
        printf("%d\n ", e[pp]);
    }
    double t4 = omp_get_wtime();
    printf("Time 3=%f\n", t4 - t3);*/
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
