#include <QApplication>
#include "./ui_calculator.h"
#include "calculatormainwindow.h"



int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CalculatorMainWindow *window = new CalculatorMainWindow(nullptr);
    Ui::MainWindow calculator;
    calculator.setupUi(window);
    window->lineEdit = calculator.lineEdit;
    window->show();
    return QApplication::exec();
}
