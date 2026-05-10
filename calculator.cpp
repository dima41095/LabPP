#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    double num1, num2;
    char operation;
    
    cout << "===== ПРОСТОЙ КАЛЬКУЛЯТОР =====" << endl;
    cout << "Введите первое число: ";
    cin >> num1;
    
    cout << "Введите операцию (+, -, *, /): ";
    cin >> operation;
    
    cout << "Введите второе число: ";
    cin >> num2;
    
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
        default:
            cout << "ОШИБКА: Операция '" << operation << "' не поддерживается!" << endl;
            cout << "Доступные операции: +, -, *, /" << endl;
    }
    
    cout << "\nСпасибо за использование калькулятора!" << endl;
    return 0;
}