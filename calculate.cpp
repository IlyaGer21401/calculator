#include "calculate.h"

string calculate(string text) {
    string result, value1, value2;
    bool signal = true; /// Флажок. Положение: true - считываем первое число; false - второе.
    char action;

    /// Раздделение на первое число, знак, и второе число
    for(int i = 0; i < text.size();i++) {
        if (i == 0 && text[i] == '-') {
            value1 += text[i];
            continue;
        }
        if (text[i] == '+' || text[i] == '-' || text[i] == '/' || text[i] == 'x') {
            signal = false;
            action = text[i];
            continue;
        }
        if (signal)
            value1 += text[i];
        else
            value2 += text[i];
    }

    double d_value1 = std::stod(value1), d_value2 = std::stod(value2);

    /// Выполняем действие над числами
    if (action == '+')
        result = std::to_string(d_value1 + d_value2);
    else if (action == '-')
        result = std::to_string(d_value1 - d_value2);
    else if (action == 'x')
        result = std::to_string(d_value1 * d_value2);
    else if (action == '/')
        result = std::to_string(d_value1 / d_value2);


    string newResult;
    /// Очищение от нулей в конце после запятой
    {
        string zeros;
        bool sig = false, sig2 = false;
        int count = 0;
        for (int i = 0; i < result.size(); i++) {
            if (result[i] == '.')
                sig = true;
            if (result[i] == '0' && sig) {
                zeros += result[i];
                count++;
                if (count == 3)
                    break;
            } else {
                if (count != 0) {
                    count = 0;
                    newResult += zeros;
                    zeros = "";
                }
                newResult += result[i];
            }
        }
    }
    result = newResult;

    /// Убираем точку если получилось целое число
    if (result[result.size() - 1] == '.') {
        newResult = "";
        for (int i = 0; i < result.size() - 1; ++i) {
            newResult += result[i];
        }
        result = newResult;
    }

    return result;
}