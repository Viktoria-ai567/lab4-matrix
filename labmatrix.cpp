#include <iostream>
#include <vector>

using namespace std;

// Класс для представления диагональной матрицы
class DiagonalMatrix {
private:
    vector<int> diag; // Вектор для хранения значений диагональных элементов
    int size;         // Размер матрицы (количество диагональных элементов)

public:
    // Конструктор: инициализация матрицы заданного размера n
    DiagonalMatrix(int n) : size(n) {
        diag.resize(n); // Резервируем память для вектора диагональных элементов
    }

    // Установка значения диагонального элемента
    void setElement(int i, int val) {
        // Проверяем допустимость индекса
        if (i >= 0 && i < size) {
            diag[i] = val; // Записываем значение в вектор
        }
    }

    // Получение значения диагонального элемента
    // Возвращает 0 для индексов вне диагонали
    int getElement(int i) const {
        // Проверяем допустимость индекса
        if (i >= 0 && i < size) {
            return diag[i]; // Возвращаем значение диагонального элемента
        }
        return 0; // Возвращаем 0, если индекс вне диагонали
    }

    // Получение размера матрицы
    int getSize() const {
        return size; // Возвращаем размер матрицы
    }

    // Перегрузка оператора сложения для диагональных матриц
    DiagonalMatrix operator+(const DiagonalMatrix& other) const {
        DiagonalMatrix result(size); // Создаем новую матрицу результата
        for (int i = 0; i < size; ++i) {
            // Суммируем соответствующие диагональные элементы
            result.setElement(i, this->getElement(i) + other.getElement(i));
        }
        return result; // Возвращаем полученную матрицу
    }

    // Перегрузка оператора вычитания для диагональных матриц
    DiagonalMatrix operator-(const DiagonalMatrix& other) const {
        DiagonalMatrix result(size); // Создаем новую матрицу результата
        for (int i = 0; i < size; ++i) {
            // Вычитаем соответствующие диагональные элементы
            result.setElement(i, this->getElement(i) - other.getElement(i));
        }
        return result; // Возвращаем полученную матрицу
    }

    // Перегрузка оператора умножения для диагональных матриц
    DiagonalMatrix operator*(const DiagonalMatrix& other) const {
        DiagonalMatrix result(size); // Создаем новую матрицу результата
        for (int i = 0; i < size; ++i) {
            // Умножаем соответствующие диагональные элементы
            result.setElement(i, this->getElement(i) * other.getElement(i));
        }
        return result; // Возвращаем полученную матрицу
    }

    // Вывод матрицы в консоль
    void print() const {
        for (int i = 0; i < size; ++i) { // Проходим по строкам
            for (int j = 0; j < size; ++j) { // Проходим по столбцам
                // Если элемент на главной диагонали, выводим его значение
                if (i == j) {
                    cout << getElement(i) << " ";
                } else {
                    cout << 0 << " "; // Для всех остальных позиций выводим 0
                }
            }
            cout << endl; // Новый ряд матрицы
        }
    }
};

int main() {
    system("chcp 1251"); // Установка кодировки консоли для корректного отображения символов
    system("cls");        // Очистка экрана

    int size;   // Переменная для хранения размера матриц
    cout << "Enter the size of the diagonal matrices: ";
    cin >> size;

    DiagonalMatrix matrix1(size); // Создаем первую диагональную матрицу
    DiagonalMatrix matrix2(size); // Создаем вторую диагональную матрицу

    // Ввод элементов первой диагональной матрицы
    cout << "Enter the elements of the first diagonal matrix:\n";
    for (int i = 0; i < size; ++i) {
        int val; // Переменная для хранения вводимого значения
        cin >> val; // Считываем значение
        matrix1.setElement(i, val); // Устанавливаем значение в первую матрицу
    }

    // Ввод элементов второй диагональной матрицы
    cout << "Enter the elements of the second diagonal matrix:\n";
    for (int i = 0; i < size; ++i) {
        int val; // Переменная для хранения вводимого значения
        cin >> val; // Считываем значение
        matrix2.setElement(i, val); // Устанавливаем значение во вторую матрицу
    }

    // Выполняем операции над матрицами
    DiagonalMatrix sum = matrix1 + matrix2; // Сумма матриц
    DiagonalMatrix diff = matrix1 - matrix2; // Разность матриц
    DiagonalMatrix prod = matrix1 * matrix2; // Произведение матриц

    // Вывод результатов
    cout << "The sum of the matrices:\n";
    sum.print(); 

    cout << "Matrix difference:\n";
    diff.print(); 

    cout << "The product of matrices:\n";
    prod.print(); 

    return 0;
}

