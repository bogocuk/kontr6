#include <iostream>
#include <vector>
#include <algorithm>
#include <clocale>

using namespace std;

// 1. сортировка вектора


vector<int> sortVector(vector<int> v) {

    sort(v.begin(), v.end());

    return v;
}

// 2. вывод в обратном порядке


vector<int> reverseVector(vector<int> v) {

    reverse(v.begin(), v.end());

    return v;
}

// 3. сумма элементов


int sum(vector<int> arr, int n) {

    int s = 0;

    for (int i = 0; i < n; i++) {
        s += arr[i];
    }

    return s;
}


// 4. частота числа


int findFrequency(vector<int> arr, int x) {

    int count = 0;

    for (int num : arr) {

        if (num == x)
            count++;
    }

    return count;
}



int main() {

    setlocale(LC_ALL, "Russian");

 

    cout << "ЗАДАНИЕ 1. STL"
        << endl;

    

    // сортировка и reverse
    

    vector<int> arr = { 5, 2, 9, 1, 7 };

    vector<int> sorted = sortVector(arr);

    cout << "\n1. Сортировка вектора"
        << endl;

    cout << "Отсортированный вектор: ";

    for (int x : sorted)
        cout << x << " ";

    cout << endl;

    vector<int> reversed =
        reverseVector(sorted);

    cout << "Вектор в обратном порядке: ";

    for (int x : reversed)
        cout << x << " ";

    // СУММА ЭЛЕМЕНТОВ


    cout << "\n\n2. Сумма элементов"
        << endl;

    cout << "Сумма = "
        << sum(arr, arr.size())
        << endl;


    // частота числа


    vector<int> arr2 =
    { 1, 2, 3, 2, 4, 2, 5 };

    int x = 2;

    cout << "\n3. Частота числа"
        << endl;

    cout << "Частота числа "
        << x
        << " = "
        << findFrequency(arr2, x)
        << endl;

    return 0;
}



#include <iostream>
#include <chrono>
#include <cmath>
#include <clocale>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main() {

    setlocale(LC_ALL, "Russian");

    cout << "ЗАДАНИЕ 2. БИБЛИОТЕКА EIGEN" << endl;


    // 1. УМНОЖЕНИЕ МАТРИЦ 500x500
    // СРАВНЕНИЕ EIGEN И ОБЫЧНОГО C++
   

    const int SIZE = 500;

    cout << "\n1. Умножение матриц 500x500" << endl;

    // EIGEN 

    MatrixXd A = MatrixXd::Random(SIZE, SIZE);
    MatrixXd B = MatrixXd::Random(SIZE, SIZE);

    auto startEigen =
        chrono::high_resolution_clock::now();

    MatrixXd C = A * B;

    auto endEigen =
        chrono::high_resolution_clock::now();

    chrono::duration<double> durationEigen =
        endEigen - startEigen;

    cout << "\n[EIGEN]" << endl;

    cout << "Время выполнения: "
        << durationEigen.count()
        << " секунд" << endl;

    // ОБЫЧНЫЙ C++ 

    vector<vector<double>> A1(SIZE,
        vector<double>(SIZE));

    vector<vector<double>> B1(SIZE,
        vector<double>(SIZE));

    vector<vector<double>> C1(SIZE,
        vector<double>(SIZE, 0));

    // Заполнение случайными числами

    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {

            A1[i][j] = rand() % 100;
            B1[i][j] = rand() % 100;
        }
    }

    auto startCpp =
        chrono::high_resolution_clock::now();

    // Умножение матриц

    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {

            for (int k = 0; k < SIZE; k++) {

                C1[i][j] +=
                    A1[i][k] * B1[k][j];
            }
        }
    }

    auto endCpp =
        chrono::high_resolution_clock::now();

    chrono::duration<double> durationCpp =
        endCpp - startCpp;

    cout << "\n[ОБЫЧНЫЙ C++]" << endl;

    cout << "Время выполнения: "
        << durationCpp.count()
        << " секунд" << endl;


    
    // 2. СКАЛЯРНОЕ ПРОИЗВЕДЕНИЕ И НОРМА ВЕКТОРА
    // СРАВНЕНИЕ С РУЧНЫМ ВЫЧИСЛЕНИЕМ
   

    cout << "\n====================================" << endl;
    cout << "2. Скалярное произведение и норма"
        << endl;
    cout << "====================================" << endl;

    const int n = 1000;

    VectorXd x = VectorXd::Random(n);
    VectorXd y = VectorXd::Random(n);

    // EIGEN 

    double dotProduct =
        x.dot(y);

    double normX =
        x.norm();

    // РУЧНОЕ ВЫЧИСЛЕНИЕ 

    double manualDot = 0;

    for (int i = 0; i < n; i++) {

        manualDot +=
            x(i) * y(i);
    }

    double manualNorm = 0;

    for (int i = 0; i < n; i++) {

        manualNorm +=
            x(i) * x(i);
    }

    manualNorm =
        sqrt(manualNorm);

    cout << "\n[EIGEN]" << endl;

    cout << "Скалярное произведение = "
        << dotProduct << endl;

    cout << "Норма вектора x = "
        << normX << endl;

    cout << "\n[РУЧНОЕ ВЫЧИСЛЕНИЕ]" << endl;

    cout << "Скалярное произведение = "
        << manualDot << endl;

    cout << "Норма вектора x = "
        << manualNorm << endl;

    return 0;
}




#include <iostream>
#include <clocale>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");


    cv::Mat image =
        cv::imread("image.jpg");


    if (image.empty()) {

        cerr << "Ошибка: не удалось загрузить изображение."
            << endl;

        return -1;
    }


    cv::namedWindow(
        "Исходное изображение",
        cv::WINDOW_NORMAL
    );

    cv::namedWindow(
        "Обработанное изображение",
        cv::WINDOW_NORMAL
    );

    // Перевод в оттенки серого
    cv::Mat grayImage;

    cv::cvtColor(
        image,
        grayImage,
        cv::COLOR_BGR2GRAY
    );

    // Размытие по Гауссу
    cv::Mat blurredImage;

    cv::GaussianBlur(
        grayImage,
        blurredImage,
        cv::Size(5, 5),
        0
    );

    // Отображение изображений
    cv::imshow(
        "Исходное изображение",
        image
    );

    cv::imshow(
        "Обработанное изображение",
        blurredImage
    );

    // Ожидание нажатия клавиши
    cv::waitKey(0);

    return 0;
}