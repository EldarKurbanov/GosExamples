//Заголовки и прочее
#include <iostream>
#include <random>
#include <iomanip>

using namespace std;
//Конец заголовоков

//Вспомогательные функции для задач

int count_digits(int number) {
    int count = 0;
    while (number > 0) {
        number /= 10;
        count++;
    }
    return count;
}

int count_digits(double number) {
    return count_digits((int) number);
}

int** two_dimensional_int_array(const int N, const int M, const int MIN_RND, const int MAX_RND) {
    //Узнаём сколько знаков в минимальном и максимальном числе, чтобы сделать красивый вывод чисел
    const int digits_max = max(count_digits(abs(MIN_RND)), count_digits(abs(MAX_RND)));

    //Настройка генератора случайных чисел
    random_device rnd_device;
    mt19937_64 rnd_engine(rnd_device());
    uniform_int_distribution<int> randomizer(MIN_RND, MAX_RND);
    //Конец настройки генератора случайных чисел

    //Матрица из случайных чисел
    cout << "Сгененированная матрица:" << endl;
    int** A = new int*[N];
    for(int y = 0; y < N; y++) {
        A[y] = new int[M];
        for(int x = 0; x < M; x++) {
            A[y][x] = randomizer(rnd_engine);
            cout << setfill(' ') << setw(digits_max + 1) << A[y][x]; //красивый вывод матрицы
        }
        cout << endl;
    }
    cout << endl;
    return A;
}

float** two_dimensional_float_array(const int N, const int M, const float MIN_RND, const float MAX_RND, const int decimals) {
    //Узнаём сколько знаков в минимальном и максимальном числе, чтобы сделать красивый вывод чисел
    const int digits_max = max(count_digits(abs(MIN_RND)), count_digits(abs(MAX_RND)));
    //Настройка генератора случайных чисел
    random_device rnd_device;
    mt19937_64 rnd_engine(rnd_device());
    uniform_real_distribution<float> randomizer(MIN_RND, MAX_RND);
    //Конец настройки генератора случайных чисел

    //Матрица из случайных чисел
    cout << "Сгененированная матрица:" << endl;
    float** A = new float*[N];
    for(int y = 0; y < N; y++) {
        A[y] = new float[M];
        for(int x = 0; x < M; x++) {
            A[y][x] = randomizer(rnd_engine);
            cout << setfill(' ') << setw(digits_max + decimals + 2) << setprecision(decimals) << A[y][x]; //красивый вывод матрицы
        }
        cout << endl;
    }
    cout << endl;
    return A;
}

float** three_d_point_array(const int N, const float MIN_RND, const float MAX_RND, const int decimals) {
    //Узнаём сколько знаков в минимальном и максимальном числе, чтобы сделать красивый вывод чисел
    const int digits_max = max(count_digits(abs(MIN_RND)), count_digits(abs(MAX_RND)));
    //Настройка генератора случайных чисел
    random_device rnd_device;
    mt19937_64 rnd_engine(rnd_device());
    uniform_real_distribution<float> randomizer(MIN_RND, MAX_RND);
    //Конец настройки генератора случайных чисел

    //Матрица из случайных чисел
    cout << "Сгененированные 3D точки:" << endl;
    float** A = new float*[N];
    for(int y = 0; y < N; y++) {
        A[y] = new float[3];
        for(int x = 0; x < 3; x++) {
            A[y][x] = randomizer(rnd_engine);
            cout << setfill(' ') << setw(digits_max + decimals + 2) << setprecision(decimals) << A[y][x]; //красивый вывод матрицы
        }
        cout << endl;
    }
    cout << endl;
    return A;
}

// Функция быстрой сортировки по убыванию строк массива по суммам каждой строки
// Если не надо по убыванию поменяй в функции знаки >= и <= местами (они встречаются всего в двух местах) (обычные < и > не трогать!)
// Это обычная быстрая сортировка, только во время swap'а элементов, ещё и строки в массиве переставляются
void quickSortSumRowsFloatReverse(float **array, float *sums, int left, int right, const int M) {
    float pivot; // разрешающий элемент
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    pivot = sums[left];
    float temp[M];
    for (int i = 0; i < M; ++i) {
        temp[i] = array[left][i];
    }
    while (left < right) // пока границы не сомкнутся
    {
        while ((sums[right] <= pivot) && (left < right))
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            sums[left] = sums[right]; // перемещаем элемент [right] на место разрешающего
            for (int i = 0; i < M; ++i) {
                array[left][i] = array[right][i];
            }
            left++; // сдвигаем левую границу вправо
        }
        while ((sums[left] >= pivot) && (left < right))
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            sums[right] = sums[left]; // перемещаем элемент [left] на место [right]
            for (int i = 0; i < M; ++i) {
                array[right][i] = array[left][i];
            }
            right--; // сдвигаем правую границу вправо
        }
    }
    sums[left] = pivot; // ставим разрешающий элемент на место
    for (int i = 0; i < M; ++i) {
        array[left][i] = temp[i];
    }
    int _pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < _pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
        quickSortSumRowsFloatReverse(array, sums, left, _pivot - 1, M);
    if (right > _pivot)
        quickSortSumRowsFloatReverse(array, sums, _pivot + 1, right, M);
}
//Конец вспомогательных функций для задач

//Секция задач

// Билет 1, задание 3
void task1_3() {
    // Константы к данному заданию
    const int N = 5;
    const int M = 5;

    //Двумерная матрица со случайными числами
    int** A = two_dimensional_int_array(N, M, -100, 100);

    //Само задание
    int count = 0;
    for(int y = 0; y < N; y++) {
        int sum = 0;
        for(int x = 0; x < M; x++) {
            sum += A[y][x];
        }
        if(sum < 0) {
            count++;
        }
    }
    cout << "Количество строк матрицы с отрицательной суммой элементов: " << count << endl;
}

void task7_3() {
    // Константы к данному заданию
    const int M = 5;
    const int N = 2;

    //Двумерная матрица со случайными числами
    float** Data = two_dimensional_float_array(M, N, -20, 20, 4);

    //Само задание
    float *sums = new float[M];
    for(int y = 0; y < M; y++) {
        float sum = 0;
        for(int x = 0; x < N; x++) {
            sum += Data[y][x];
        }
        sums[y] = sum;
    }
    //сортируем быстрой сортировкой, хотя можно вообще любую прикрутить. просто быстрая круче ¯\_(ツ)_/¯
    quickSortSumRowsFloatReverse(Data, sums, 0, M - 1, M);
    cout << "Отсортированный массив:" << endl;
    for(int y = 0; y < M; y++) {
        for(int x = 0; x < N; x++) {
            cout << setfill(' ') << setw(8) << Data[y][x]; //красивый вывод матриц
        }
        cout << endl;
    }
    cout << endl;
}

void task9_3() {
    //Константы к данному заданию
    const int N = 5;

    //Массив со случайными точками пространства
    float** P = three_d_point_array(N, -2, 10, 2);

    //Определяем максимальные и минимальные точки в данном массиве
    float min_X = P[0][0], min_Y = P[0][1], min_Z = P[0][2];
    float max_X = P[0][0], max_Y = P[0][1], max_Z = P[0][2];
    for (int i = 1; i < N; ++i) {
        min_X = min(min_X, P[i][0]);
        max_X = max(max_X, P[i][0]);
        min_Y = min(min_Y, P[i][1]);
        max_Y = max(max_Y, P[i][1]);
        min_Z = min(min_Z, P[i][2]);
        max_Z = max(max_Z, P[i][2]);
    }

    float P1[] = {min_X, min_Y, min_Z};
    float P2[] = {min_X, max_Y, min_Z};
    float P3[] = {max_X, max_Y, min_Z};
    float P4[] = {max_X, min_Y, min_Z};
    float P5[] = {max_X, max_Y, max_Z};
    float P6[] = {min_X, max_Y, max_Z};
    float P7[] = {min_X, min_Y, max_Z};
    float P8[] = {max_X, min_Y, max_Z};

    cout << "Параллепипед: " << endl;
    cout << "P1: [" << P1[0] << ", " << P1[1] << ", " << P1[2] << "];" << endl;
    cout << "P2: [" << P2[0] << ", " << P2[1] << ", " << P2[2] << "];" << endl;
    cout << "P3: [" << P3[0] << ", " << P3[1] << ", " << P3[2] << "];" << endl;
    cout << "P4: [" << P4[0] << ", " << P4[1] << ", " << P4[2] << "];" << endl;
    cout << "P5: [" << P5[0] << ", " << P5[1] << ", " << P5[2] << "];" << endl;
    cout << "P6: [" << P6[0] << ", " << P6[1] << ", " << P6[2] << "];" << endl;
    cout << "P7: [" << P7[0] << ", " << P7[1] << ", " << P7[2] << "];" << endl;
    cout << "P8: [" << P8[0] << ", " << P8[1] << ", " << P8[2] << "]." << endl << endl;

    cout << "Размеры паралллепипеда:" << endl;
    cout << "По оси X: " << abs(abs(max_X) - abs(min_X)) << ';' << endl;
    cout << "По оси Y: " << abs(abs(max_Y) - abs(min_Y)) << ';' << endl;
    cout << "По оси Z: " << abs(abs(max_Z) - abs(min_Z)) << '.' << endl;
}

//Конец секции задач

//Функция запуска. Просто подставь сюда название нужного метода
int main() {
    task9_3();
    return EXIT_SUCCESS;
}