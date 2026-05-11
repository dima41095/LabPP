#include <iostream>
#include <clocale>
#include <cmath>  // для функции pow()
#include <stdexcept>  // для стандартных исключений
using namespace std;

// Калькулятор с поддержкой повторных вычислений и счётчиком операций (+, -, *, /, ^)

// Функция для деления с проверкой через исключение
double divide(double num1, double num2) {
    if(num2 == 0) {
        throw runtime_error("ОШИБКА: Деление на ноль невозможно!");
    }
    return num1 / num2;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    double num1, num2;
    char operation;
    char choice;  // для выбора продолжения работы
    int operationCount = 0;  // СЧЁТЧИК ВЫПОЛНЕННЫХ ОПЕРАЦИЙ
    
    cout << "===== ПРОСТОЙ КАЛЬКУЛЯТОР =====" << endl;
    cout << "Программа поддерживает повторные вычисления!" << endl;
    cout << "Все операции будут подсчитаны." << endl << endl;
    
    do {
        // Ввод данных
        cout << "Введите первое число: ";
        cin >> num1;
        
        cout << "Введите операцию (+, -, *, /, ^): ";
        cin >> operation;
        
        cout << "Введите второе число: ";
        cin >> num2;
        
        // УВЕЛИЧИВАЕМ СЧЁТЧИК ПЕРЕД ВЫПОЛНЕНИЕМ ОПЕРАЦИИ
        operationCount++;
        
        // Вывод результата
        cout << "\n--- Операция #" << operationCount << " ---" << endl;
        cout << "Результат:" << endl;
        
        // БЛОК ОБРАБОТКИ ИСКЛЮЧЕНИЙ
        try {
            switch(operation) {
                case '+':
                    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
                    break;
                case '-':
                    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
                    break;
                case '*':
                    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
                    break;
                case '/':
                    // Используем функцию divide с исключением
                    cout << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
                    break;
                case '^':
                    cout << num1 << " ^ " << num2 << " = " << pow(num1, num2) << endl;
                    break;
                default:
                    throw runtime_error("Операция '" + string(1, operation) + "' не поддерживается!");
            }
        }
        catch(const runtime_error& e) {
            cout << e.what() << endl;
            cout << "Доступные операции: +, -, *, /, ^" << endl;
        }
        
        // Спрашиваем пользователя о продолжении
        cout << "\nВыполнить ещё одно вычисление? (y/n): ";
        cin >> choice;
        cout << endl;
        
    } while(choice == 'y' || choice == 'Y');
    
    // ВЫВОД СТАТИСТИКИ ПРИ ЗАВЕРШЕНИИ
    cout << "========================================" << endl;
    cout << "СТАТИСТИКА РАБОТЫ КАЛЬКУЛЯТОРА:" << endl;
    cout << "Всего выполнено операций: " << operationCount << endl;
    
    if(operationCount > 0) {
        cout << "Спасибо, что воспользовались калькулятором!" << endl;
    } else {
        cout << "Не было выполнено ни одной операции." << endl;
    }
    
    cout << "========================================" << endl;
    return 0;
}