//
// Created by User on 05.03.2023.
//

#ifndef TASK_1_CALCULATORMAINWINDOW_H
#define TASK_1_CALCULATORMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include "calculate.h" /// Сдесь делаются расчеты

class CalculatorMainWindow : public QMainWindow {
    Q_OBJECT
public:
    QLineEdit* lineEdit = nullptr;
    CalculatorMainWindow(QWidget* parent = nullptr): QMainWindow(parent) {}
    /// Маячок, который следит за окончанием счета (Дает разрешение на очищение экрана)
    bool newLine = false;
public slots:
    void add0() {
        /// Проверка на ввод "-0"
        if (lineEdit->text().toStdString()[0] == '-' && lineEdit->text().toStdString().size() == 1)
            return;
        /// Проверка на дублирование нуля
        if (lineEdit->text().toStdString().size() != 0) {
            if (lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == '0')
                return;
        }
        /// Проверка на новую строку.
        if (newLine) {
            AC();
            newLine = false;
        }
        lineEdit->setText(lineEdit->text() + "0");
    }
    void add1() {
        /// Проверка на новую строку.
        if (newLine) {
            AC();
            newLine = false;
        }
        lineEdit->setText(lineEdit->text() + "1");
    }
    void add2() {
        /// Проверка на новую строку.
        if (newLine) {
            AC();
            newLine = false;
        }
        lineEdit->setText(lineEdit->text() + "2");
    }
    void add3() {
        /// Проверка на новую строку.
        if (newLine) {
            AC();
            newLine = false;
        }
        lineEdit->setText(lineEdit->text() + "3");
    }
    void add4() {
        /// Проверка на новую строку.
        if (newLine) {
            AC();
            newLine = false;
        }
        lineEdit->setText(lineEdit->text() + "4");
    }
    void add5() {
        /// Проверка на новую строку.
        if (newLine) {
            AC();
            newLine = false;
        }
        lineEdit->setText(lineEdit->text() + "5");
    }
    void add6() {
        /// Проверка на новую строку.
        if (newLine) {
            AC();
            newLine = false;
        }
        lineEdit->setText(lineEdit->text() + "6");
    }
    void add7() {
        /// Проверка на новую строку.
        if (newLine) {
            AC();
            newLine = false;
        }
        lineEdit->setText(lineEdit->text() + "7");
    }
    void add8() {
        /// Проверка на новую строку.
        if (newLine) {
            AC();
            newLine = false;
        }
        lineEdit->setText(lineEdit->text() + "8");
    }
    void add9() {
        /// Проверка на новую строку.
        if (newLine) {
            AC();
            newLine = false;
        }
        lineEdit->setText(lineEdit->text() + "9");
    }
    void addPlus() {
        if (newLine)
            newLine = false;
        /// Проверка на пустую строку и отрицательное число
        if (lineEdit->text().toStdString() == "" || lineEdit->text().toStdString() == "-")
            return;
        /// Проверка на повторяющийся знак действия
        if (lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == '-' ||
            lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == '+' ||
            lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == '/' ||
            lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == 'x')
            return;
        lineEdit->setText(lineEdit->text() + "+");
    }
    void addMinus() {
        if (newLine)
            newLine = false;
        /// Проверка на пустую строку и отрицательное число
        if (lineEdit->text().toStdString() == "-")
            return;
        /// Проверка на повторяющийся знак действия
        if (lineEdit->text().toStdString().size() != 0) {
            if (lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == '-' ||
                lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == '+' ||
                lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == '/' ||
                lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == 'x')
                return;
        }

        lineEdit->setText(lineEdit->text() + "-");
    }
    void addMultiply() {
        if (newLine)
            newLine = false;
        /// Проверка на пустую строку и отрицательное число
        if (lineEdit->text().toStdString() == "" || lineEdit->text().toStdString() == "-")
            return;
        /// Проверка на повторяющийся знак действия
        if (lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == '-' ||
            lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == '+' ||
            lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == '/' ||
            lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == 'x')
            return;
        lineEdit->setText(lineEdit->text() + "x");
    }
    void addDivision() {
        if (newLine)
            newLine = false;
        /// Проверка на пустую строку и отрицательное число
        if (lineEdit->text().toStdString() == "" || lineEdit->text().toStdString() == "-")
            return;
        /// Проверка на повторяющийся знак действия
        if (lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == '-' ||
            lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == '+' ||
            lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == '/' ||
            lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == 'x')
            return;
        lineEdit->setText(lineEdit->text() + "/");
    }
    void addEqually() {
        /// Проверка на пустую строку и на отрицательное число
        if (lineEdit->text().toStdString() == "" || lineEdit->text().toStdString() == "-")
            return;
        /// Проверка на наличие второго числа
        if (lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == '-' ||
            lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == '+' ||
            lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == '/' ||
            lineEdit->text().toStdString()[lineEdit->text().toStdString().size() - 1] == 'x')
            return;
        /// Проверка на наличие хоть одного знака действия
        {
            bool sig = true;
            for (auto i = 0; i < lineEdit->text().toStdString().size(); i++) {
                if (lineEdit->text().toStdString()[i] == '+' || lineEdit->text().toStdString()[i] == '-' && i != 0 ||
                    lineEdit->text().toStdString()[i] == 'x' || lineEdit->text().toStdString()[i] == '/') {
                    sig = false;
                    break;
                }
            }
            if (sig)
                return;
        }

        /// Конвертация в string
        string str = calculate(lineEdit->text().toStdString());

        /// Очищение дисплэя
        AC();

        /// Вывод результата функции calculate на экран по символьно
        for (char i : str)
            lineEdit->setText(lineEdit->text() + i);
        newLine = true;
    }
    void AC() {lineEdit->setText("");}
};

#endif //TASK_1_CALCULATORMAINWINDOW_H