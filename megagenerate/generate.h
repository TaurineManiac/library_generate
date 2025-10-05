#ifndef MEGAGENERATE_MEGAGENERATE_H
#define MEGAGENERATE_MEGAGENERATE_H
#include <any>
#include <iostream>
#include <vector>
#include <vector>
#include <vector>

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

#include <string>

namespace generate {
    DLL_EXPORT std::string generateStringIndex();
    DLL_EXPORT int generateRandomIntNumber(int min,int max);
    DLL_EXPORT std::string generateCurrentDataTime();
    DLL_EXPORT std::string generateRandomString(int max);
    DLL_EXPORT double generateRandomDoubleNumber(double min,double max);
    //=======================================================================
    template <typename T>
    std::string toString(const T& value) {
        if constexpr (std::is_same_v<T, std::string>)
            return value;
        else if constexpr (std::is_same_v<T, const char*>)
            return std::string(value); // ✅ добавлено
        else if constexpr (std::is_same_v<T, char*>)
            return std::string(value); // ✅ добавлено
        else if constexpr (std::is_same_v<T, bool>)
            return value ? "true" : "false";
        else if constexpr (std::is_same_v<T, char>)
            return std::string(1, value);
        else
            return std::to_string(value); // работает для int, float, double
    }

    template <typename T>
    constexpr  bool isConvertibleToString = std::is_convertible_v<T, std::string>;

    template <typename T>
    constexpr bool isCorrectType = isConvertibleToString<T> || std::is_same_v<T, int> ||
        std::is_same_v<T, float> || std::is_same_v<T, double> || std::is_same_v<T, bool> || std::is_same_v<T, char>;

    template<typename ... Args>
    DLL_EXPORT int generateChooseMenu(int startPoint,bool isNegativeBeOnTop,Args... args) {
        try {
            if (!(isCorrectType<Args> && ...)) {
                return -666;
            }
            std::vector<std::string> rows={toString(args)...};
            int counter=0;
            if (isNegativeBeOnTop) {
                int ii = startPoint;
                for (int i=0;i<rows.size();i++) {
                    std::cout << ii << ". " <<rows[i] << std::endl;
                    ii++;
                    counter++;
                }
            }
            else {
                if (abs(startPoint)>= rows.size()) {
                    int ii = startPoint;
                    for (int i=0;i<rows.size();i++) {
                        std::cout << ii << ". " <<rows[i] << std::endl;
                        ii++;
                        counter++;
                    }
                }
                else {
                    int position = std::abs(startPoint)+1;

                    int ii = 1;
                    for (int i = position; i < rows.size(); i++) {
                        std::cout << ii << ". " << rows[i] << std::endl;
                        ii++;
                        counter++;
                    }

                    ii = 0;
                    for (int i = 0; i < position; i++) {
                        std::cout << ii << ". " << rows[i] << std::endl;
                        ii--;
                        counter++;
                    }
                }
            }
            return counter;
        }
        catch (...) {
            std::cout << "Произошла ошибка!" << std::endl;
            return -666;
        }

    }
    //========================================================================
}

#endif // MEGAGENERATE_MEGAGENERATE_H