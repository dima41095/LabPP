#include <iostream>
#include <clocale>
#include <cmath>  // для функции pow()
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    double num1, num2;
    char operation;
    char choice;  // для выбора продолжения работы
    
    cout << "===== ПРОСТОЙ КАЛЬКУЛЯТОР =====" << endl;
    cout << "Программа поддерживает повторные вычисления!" << endl << endl;
    
    do {
        // Ввод данных
        cout << "Введите первое число: ";
        cin >> num1;
        
        cout << "Введите операцию (+, -, *, /, ^): ";
        cin >> operation;
        
        cout << "Введите второе число: ";
        cin >> num2;
        
        // Вывод результата
        cout << "\nРезультат:" << endl;
        
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
                if(num2 != 0) {
                    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                } else {
                    cout << "ОШИБКА: Деление на ноль невозможно!" << endl;
                }
                break;
            case '^':
                cout << num1 << " ^ " << num2 << " = " << pow(num1, num2) << endl;
                break;
            default:
                cout << "ОШИБКА: Операция '" << operation << "' не поддерживается!" << endl;
                cout << "Доступные операции: +, -, *, /, ^" << endl;
        }
        
        // Спрашиваем пользователя о продолжении
        cout << "\nВыполнить ещё одно вычисление? (y/n): ";
        cin >> choice;
        cout << endl;
        
    } while(choice == 'y' || choice == 'Y');
    
    cout << "Спасибо за использование калькулятора!" << endl;
    return 0;
}