#include "generate.h"
#include <string>
#include <iostream>
#include <cctype>
#include <random>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <locale>

namespace generate {

    // Генерация строки-индекса
    std::string generateStringIndex() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 999999);
        int num = dis(gen);
        std::ostringstream oss;
        oss << std::setw(6) << std::setfill('0') << num;
        return oss.str();
    }

    // Получение текущего времени в формате "YYYY-MM-DD HH:MM:SS"
    std::string generateCurrentDataTime() {
        std::time_t now = std::time(nullptr);
        std::tm* ltm = std::localtime(&now);
        std::ostringstream oss;
        oss << std::put_time(ltm, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }

    // Генерация случайного числа в диапазоне [min, max]
    int generateRandomNumber(int min, int max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }

    std::string generateRandomString(int max){
        std::string str="";
        int maxsize=generateRandomNumber(1,max);
        for(int i=0;i<maxsize;i++){
            int ASCII = generateRandomNumber(97,122);
            str+=(char)ASCII;
        }
        return str;
    }
}